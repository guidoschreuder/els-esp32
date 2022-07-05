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


#ifndef __CONTROL_PANEL_H
#define __CONTROL_PANEL_H

#include <driver/spi_master.h>


#define ZERO    0b11111100 // 0
#define ONE     0b01100000 // 1
#define TWO     0b11011010 // 2
#define THREE   0b11110010 // 3
#define FOUR    0b01100110 // 4
#define FIVE    0b10110110 // 5
#define SIX     0b10111110 // 6
#define SEVEN   0b11100000 // 7
#define EIGHT   0b11111110 // 8
#define NINE    0b11110110 // 9
#define POINT   0b00000001 // .
#define BLANK   0b00000000

#define LETTER_A 0b11101110
#define LETTER_B 0b00111110
#define LETTER_C 0b10011100
#define LETTER_D 0b01111010
#define LETTER_E 0b10011110
#define LETTER_F 0b10001110
#define LETTER_G 0b10111100
#define LETTER_H 0b01101110
#define LETTER_I 0b00001100
#define LETTER_J 0b01111000
#define LETTER_K 0b10101110
#define LETTER_L 0b00011100
#define LETTER_M 0b10101000
#define LETTER_N 0b11101100
#define LETTER_O 0b11111100
#define LETTER_P 0b11001110
#define LETTER_Q 0b11100110
#define LETTER_R 0b11001100
#define LETTER_S 0b10110110
#define LETTER_T 0b00011110
#define LETTER_U 0b01111100
#define LETTER_V 0b01110100
#define LETTER_W 0b01010100
#define LETTER_X 0b01101100
#define LETTER_Y 0b01110110
#define LETTER_Z 0b11010010

#define DASH 0b00000010

#define LED_TPI 1
#define LED_INCH (1<<1)
#define LED_MM (1<<2)
#define LED_THREAD (1<<3)
#define LED_FEED (1<<4)
#define LED_REVERSE (1<<5)
#define LED_FORWARD (1<<6)
#define LED_POWER (1<<7)

struct LED_BITS
{
    uint16_t TPI:1;
    uint16_t INCH:1;
    uint16_t MM:1;
    uint16_t THREAD:1;
    uint16_t FEED:1;
    uint16_t REVERSE:1;
    uint16_t FORWARD:1;
    uint16_t POWER:1;
};

typedef union LED_REG
{
    uint16_t all;
    struct LED_BITS bit;
} LED_REG;

struct KEY_BITS
{
    uint16_t UP:1;
    uint16_t reserved1:1;
    uint16_t DOWN:1;
    uint16_t IN_MM:1;
    uint16_t FEED_THREAD:1;
    uint16_t FWD_REV:1;
    uint16_t SET:1;
    uint16_t POWER:1;
};

typedef union KEY_REG
{
    uint16_t all;
    struct KEY_BITS bit;
} KEY_REG;


class ControlPanel
{
private:
    spi_device_handle_t spi;

    // Current RPM value; 4 decimal digits
    uint16_t rpm;

    // Current displayed setting value, 4 digits
    const uint16_t *value;

    // Current LED states
    LED_REG leds;

    // current key states
    KEY_REG keys;

    // number of times current key state has been seen
    KEY_REG stableKeys;
    uint16_t stableCount;

    // current override message, or NULL if none
    const uint16_t *message;

    // brightness, levels 1-8, 0=off
    uint16_t brightness;

    // Derived state, calculated internally
    uint16_t sevenSegmentData[8];

    // dummy register, for SPI
    uint16_t dummy;

    void decomposeRPM(void);
    void decomposeValue(void);
    KEY_REG readKeys(void);
    uint8_t reverse_byte(uint8_t);
    uint8_t lcd_char(uint8_t);
    uint16_t receiveByte(void);
    void sendBrightness(void);
    void sendAutoIncrement(void);
    void sendLeds(void);
    void sendData(void);
    bool isValidKeyState(KEY_REG);
    bool isStable(KEY_REG);

public:
    ControlPanel();

    // initialize the hardware for operation
    void initHardware(void);

    // poll the keys and return a mask
    KEY_REG getKeys(void);

    // set the RPM value to display
    void setRPM(uint16_t rpm);

    // set the value to display
    void setValue(const uint16_t *value);

    // set the LED states
    void setLEDs(LED_REG leds);

    // set a message that overrides the display, 8 characters required
    void setMessage(const uint16_t *message);

    // set a brightness value, 0 (off) to 8 (max)
    void setBrightness(uint16_t brightness);

    // refresh the hardware display
    void refresh(void);
};


inline void ControlPanel :: setRPM(uint16_t rpm)
{
    this->rpm = rpm;
}

inline void ControlPanel :: setValue(const uint16_t *value)
{
    this->value = value;
}

inline void ControlPanel :: setLEDs(LED_REG leds)
{
    this->leds = leds;
}


#endif // __CONTROL_PANEL_H
