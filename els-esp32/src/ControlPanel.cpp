// Clough42 Electronic Leadscrew
// https://github.com/clough42/electronic-leadscrew
//
// MIT License
//
// Copyright (c) 2019 James Clough
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <string.h>
#include <driver/gpio.h>
#include <rom/ets_sys.h>

#include "Configuration.h"
#include "ControlPanel.h"

// Time delay to allow CS (STB) line to reach high state and be registered
#define CS_RISE_TIME_US 10

// Time delay after sending read command, before clocking in data
#define DELAY_BEFORE_READING_US 3

// Number of times a key state must be read consecutively to be considered stable
#define MIN_CONSECUTIVE_READS 3

#define CMD_AUTO_INCR 0x40
#define CMD_READ_KEYS 0x42
#define START_LOCATION 0xc0

ControlPanel :: ControlPanel()
{
    this->rpm = 0;
    this->value = NULL;
    this->leds.all = 0;
    this->keys.all = 0;
    this->stableKeys.all = 0;
    this->stableCount = 0;
    this->message = NULL;
    this->brightness = 3;
}

void ControlPanel :: initHardware(void)
{
  esp_err_t ret;

  spi_bus_config_t buscfg = {
      .mosi_io_num = DISP_MOSI_GPIO,
      .miso_io_num = -1,
      .sclk_io_num = DISP_CLK_GPIO,
      .quadwp_io_num = -1,
      .quadhd_io_num = -1,
      .max_transfer_sz = 32,  // this should be more than edequate
      .flags = SPICOMMON_BUSFLAG_GPIO_PINS,
      .intr_flags = 0,
  };
  ret = spi_bus_initialize(DISP_SPI_HOST, &buscfg, SPI_DMA_DISABLED);
  ESP_ERROR_CHECK(ret);

  spi_device_interface_config_t devcfg = {
      .command_bits = 8,
      .address_bits = 0,
      .dummy_bits = 0,
      .mode = 3,                           // SPI mode 3
      .duty_cycle_pos = 0,                 // Use default of 50%
      .cs_ena_pretrans = 100,              // TODO: might need to be tuned
      .cs_ena_posttrans = 0,               // TODO: might need to be tuned
      .clock_speed_hz = 1 * 1000 * 1000,   // Clock out at 1 MHz
      .input_delay_ns = 0,
      .spics_io_num = DISP_CS_GPIO,        // CS pin
      .flags = SPI_DEVICE_HALFDUPLEX | SPI_DEVICE_3WIRE,
      .queue_size = 1,
  };
  ret = spi_bus_add_device(DISP_SPI_HOST, &devcfg, &spi);
  ESP_ERROR_CHECK(ret);
}

uint8_t ControlPanel :: reverse_byte(uint8_t x) {

  static uint8_t table[16] = {
    0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe,
    0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf, };

   return (table[x & 0b1111] << 4) | table[x >> 4];
}

uint8_t ControlPanel :: lcd_char(uint8_t x)
{
    static const uint8_t table[] = {
        ZERO,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        POINT
    };
    if( x < sizeof(table) ) {
        return table[x];
    }
    return table[sizeof(table)-1];
}

void ControlPanel :: sendBrightness() {
    uint16_t briteVal = 0x80;
    if( this->brightness > 0 ) {
        briteVal = 0x87 + this->brightness;
    }

    spi_transaction_t t;
    memset(&t, 0, sizeof(t));       //Zero out the transaction
    t.cmd = reverse_byte(briteVal);

    esp_err_t ret = spi_device_polling_transmit(this->spi, (spi_transaction_t*) &t);
    ESP_ERROR_CHECK(ret);
}

void ControlPanel :: sendAutoIncrement() {
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));       //Zero out the transaction
    t.cmd = reverse_byte(CMD_AUTO_INCR);

    esp_err_t ret = spi_device_polling_transmit(this->spi, (spi_transaction_t*) &t);
    ESP_ERROR_CHECK(ret);
}

void ControlPanel :: sendLeds() {
    uint8_t ledMask = this->leds.all;
    uint8_t data[16];
    uint8_t ind = 0;

    for (int i = 0; i < 8; i++) {
      if (this->message != NULL) {
        data[ind++] = this->message[i];
      } else {
        data[ind++] = this->sevenSegmentData[i];
      }
      data[ind++] = (ledMask & 0x80) ? 0x80 : 0x00;
      ledMask <<= 1;
    }

    spi_transaction_t t;
    memset(&t, 0, sizeof(t));       //Zero out the transaction
    t.cmd = reverse_byte(START_LOCATION),
    t.length = (size_t)8 * ind;
    t.tx_buffer = data;

    esp_err_t ret = spi_device_polling_transmit(this->spi, (spi_transaction_t*) &t);
    ESP_ERROR_CHECK(ret);

}

void ControlPanel :: sendData()
{
    sendBrightness();
    sendAutoIncrement();
    sendLeds();
}

void ControlPanel :: decomposeRPM()
{
    uint16_t rpm = this->rpm;
    int i;

    for(i=3; i>=0; i--) {
        this->sevenSegmentData[i] = (rpm == 0 && i != 3) ? 0 : lcd_char(rpm % 10);
        rpm = rpm / 10;
    }
}

void ControlPanel :: decomposeValue()
{
    if( this->value != NULL )
    {
        int i;
        for( i=0; i < 4; i++ )
        {
            this->sevenSegmentData[i+4] = this->value[i];
        }
    }
}

KEY_REG ControlPanel :: readKeys(void)
{
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));       //Zero out the transaction
    t.flags = SPI_TRANS_USE_RXDATA;
    t.cmd = CMD_READ_KEYS;
    t.rxlength = 32;

    esp_err_t ret = spi_device_polling_transmit(this->spi, &t);
    ESP_ERROR_CHECK(ret);

    KEY_REG keyMask;
    keyMask.all =
            (t.rx_data[0] & 0x88) |
            (t.rx_data[1] & 0x88) >> 1 |
            (t.rx_data[2] & 0x88) >> 2 |
            (t.rx_data[3] & 0x88) >> 3;

    return keyMask;
}

KEY_REG ControlPanel :: getKeys()
{
    KEY_REG newKeys;
    static KEY_REG noKeys;

    newKeys = readKeys();
    if( isValidKeyState(newKeys) && isStable(newKeys) && newKeys.all != this->keys.all ) {
        KEY_REG previousKeys = this->keys; // remember the previous stable value
        this->keys = newKeys;

        if( previousKeys.all == 0 ) {     // only act if the previous stable value was no keys pressed
            return newKeys;
        }
    }
    return noKeys;
}

bool ControlPanel :: isValidKeyState(KEY_REG testKeys) {
    // filter out any states with multiple keys pressed (bad communication filter)
    switch(testKeys.all) {
    case 0:
    case 1 << 0:
    case 1 << 2:
    case 1 << 3:
    case 1 << 4:
    case 1 << 5:
    case 1 << 6:
    case 1 << 7:
        return true;
    }

    return false;
}


bool ControlPanel :: isStable(KEY_REG testKeys) {
    // don't trust any read key state until we've seen it multiple times consecutively (noise filter)
    if( testKeys.all != stableKeys.all )
    {
        this->stableKeys = testKeys;
        this->stableCount = 1;
    }
    else
    {
        if( this->stableCount < MIN_CONSECUTIVE_READS )
        {
            this->stableCount++;
        }
    }

    return this->stableCount >= MIN_CONSECUTIVE_READS;
}

void ControlPanel :: setMessage( const uint16_t *message )
{
    this->message = message;
}

void ControlPanel :: setBrightness( uint16_t brightness )
{
    if( brightness > 8 ) brightness = 8;

    this->brightness = brightness;
}

void ControlPanel :: refresh()
{
    decomposeRPM();
    decomposeValue();

    sendData();
}
