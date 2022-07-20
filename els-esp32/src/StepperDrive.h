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


#ifndef __STEPPERDRIVE_H
#define __STEPPERDRIVE_H

#include "Configuration.h"
#include <stdint.h>
#include <driver/gpio.h>
#include <driver/rmt.h>

#define GPIO_SET(pin) gpio_set_level((gpio_num_t)pin, 1)
#define GPIO_CLEAR(pin) gpio_set_level((gpio_num_t)pin, 0)
#define GPIO_GET(pin) gpio_get_level((gpio_num_t)pin)

#ifdef INVERT_DIRECTION_PIN
#define GPIO_SET_DIRECTION GPIO_CLEAR(DIRECTION_GPIO)
#define GPIO_CLEAR_DIRECTION GPIO_SET(DIRECTION_GPIO)
#else
#define GPIO_SET_DIRECTION GPIO_SET(DIRECTION_GPIO)
#define GPIO_CLEAR_DIRECTION GPIO_CLEAR(DIRECTION_GPIO)
#endif

#ifdef INVERT_ENABLE_PIN
#define GPIO_SET_ENABLE GPIO_CLEAR(ENABLE_GPIO)
#define GPIO_CLEAR_ENABLE GPIO_SET(ENABLE_GPIO)
#else
#define GPIO_SET_ENABLE GPIO_SET(ENABLE_GPIO)
#define GPIO_CLEAR_ENABLE GPIO_CLEAR(ENABLE_GPIO)
#endif

#ifdef INVERT_ALARM_PIN
#define GPIO_GET_ALARM (GPIO_GET(ALARM_GPIO) == 0)
#else
#define GPIO_GET_ALARM (GPIO_GET(ALARM_GPIO) != 0)
#endif


class StepperDrive
{
private:
    //
    // Current position of the motor, in steps
    //
    int64_t currentPosition;

    //
    // Desired position of the motor, in steps
    //
    int64_t desiredPosition;

    //
    // Is the drive enabled?
    //
    bool enabled;

    rmt_item32_t pulses[MAX_BUFFERED_STEPS];

public:
    StepperDrive();
    void initHardware(void);

    void setDesiredPosition(int64_t);
    void setCurrentPosition(int64_t);

    bool checkStepBacklog();

    void setEnabled(bool);

    bool isAlarm();

    void ISR(void);
};

inline void StepperDrive :: setDesiredPosition(int64_t steps)
{
    this->desiredPosition = steps;
}

inline void StepperDrive :: setCurrentPosition(int64_t position)
{
    this->currentPosition = position;
}

inline bool StepperDrive :: checkStepBacklog()
{
    if( abs(this->desiredPosition - this->currentPosition) > MAX_BUFFERED_STEPS ) {
        setEnabled(false);
        return true;
    }
    return false;
}

inline void StepperDrive :: setEnabled(bool enabled)
{
    this->enabled = enabled;
    if( this->enabled ) {
        GPIO_SET_ENABLE;
    }
    else
    {
        GPIO_CLEAR_ENABLE;
    }
}

inline bool StepperDrive :: isAlarm()
{
#ifdef USE_ALARM_PIN
    return GPIO_GET_ALARM;
#else
    return false;
#endif
}

#define MIN(a,b) (a > b ? b : a)

inline void StepperDrive :: ISR(void)
{
    if(enabled) {
        int64_t pulse_cnt = this->desiredPosition - this->currentPosition;
        if (pulse_cnt == 0) {
            return;
        }

        if (pulse_cnt > 0) {
            pulse_cnt = MIN(pulse_cnt, MAX_BUFFERED_STEPS);
            this->currentPosition += pulse_cnt;
            GPIO_CLEAR_DIRECTION;
        } else {
            pulse_cnt = MIN(-pulse_cnt, MAX_BUFFERED_STEPS);
            this->currentPosition -= pulse_cnt;
            GPIO_SET_DIRECTION;
        }

        // if RMT channel is still busy then return and wait for next cycle
        rmt_channel_status_result_t res;
        rmt_get_channel_status(&res);
        if (res.status[STEPPER_RMT_CHANNEL] == rmt_channel_status_t::RMT_CHANNEL_BUSY) {
            return;
        }

        ESP_ERROR_CHECK(rmt_write_items(STEPPER_RMT_CHANNEL, &this->pulses[0], pulse_cnt, false));

    } else {
        // not enabled; just keep current position in sync
        this->currentPosition = this->desiredPosition;
    }
}

#endif // __STEPPERDRIVE_H
