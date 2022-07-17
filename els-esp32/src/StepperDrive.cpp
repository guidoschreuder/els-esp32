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


#include "StepperDrive.h"

StepperDrive :: StepperDrive(void)
{
    //
    // Set up global state variables
    //
    this->currentPosition = 0;
    this->desiredPosition = 0;
}

void StepperDrive :: initHardware(void)
{
    // setup direction and enable pins
    gpio_config_t io_conf_output = {
        .pin_bit_mask = (1ULL << DIRECTION_GPIO) | (1ULL << ENABLE_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = gpio_pullup_t::GPIO_PULLUP_DISABLE,
        .pull_down_en = gpio_pulldown_t::GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    ESP_ERROR_CHECK(gpio_config(&io_conf_output));

    // setup alarm pin
    gpio_config_t io_conf_input = {
        .pin_bit_mask = (1ULL << ALARM_GPIO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = gpio_pullup_t::GPIO_PULLUP_DISABLE,
        .pull_down_en = gpio_pulldown_t::GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    ESP_ERROR_CHECK(gpio_config(&io_conf_input));

    // Setup RMT for step pin
    bool invert_step = false;
#ifdef INVERT_STEP_PIN
    invert_step = true;
#endif

    rmt_config_t dev_config = RMT_DEFAULT_CONFIG_TX((gpio_num_t) STEP_GPIO, STEPPER_RMT_CHANNEL);
    dev_config.clk_div = 8;
    dev_config.tx_config.idle_level = invert_step ? RMT_IDLE_LEVEL_HIGH : RMT_IDLE_LEVEL_LOW;

    ESP_ERROR_CHECK(rmt_config(&dev_config));
    ESP_ERROR_CHECK(rmt_driver_install(STEPPER_RMT_CHANNEL, 0, 0));

    uint32_t cntr_clk_hz;
    rmt_get_counter_clock(STEPPER_RMT_CHANNEL, &cntr_clk_hz);
    uint16_t pulse_length = cntr_clk_hz * STEPPER_CYCLE_US / 1000000;

    // init pulse
    for (int i = 0; i < MAX_BUFFERED_STEPS; i++) {
        this->pulses[i] = {{{pulse_length, invert_step ? 0u : 1u, pulse_length, invert_step ? 1u : 0u}}};
    }

    GPIO_CLEAR_DIRECTION;

    setEnabled(true);
}






