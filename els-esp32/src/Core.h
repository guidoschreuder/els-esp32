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


#ifndef __CORE_H
#define __CORE_H

#include "StepperDrive.h"
#include "Encoder.h"
#include "ControlPanel.h"
#include "Tables.h"
#include <freertos/queue.h>

enum POWER {
  OFF = 0,
  ON = 1,
};

enum DIRECTION {
  CW = 0,
  CCW = 1,
};

typedef struct state_t {
  POWER     power : 1;
  DIRECTION direction : 1;
  uint32_t  feed : 30;
} state_t;

class Core
{
private:
    Encoder *encoder;
    StepperDrive *stepperDrive;
    QueueHandle_t state_queue;

    state_t state;

    int64_t feedRatio(int64_t);

public:
    Core( Encoder *encoder, StepperDrive *stepperDrive );

    void set_state(bool, bool, const FEED_THREAD*);

    uint16_t getRPM(void);

    bool isAlarm();
    bool isPowerOn();

    void ISR( void );
};

inline uint16_t Core :: getRPM(void)
{
    return encoder->getRPM();
}

inline bool Core :: isAlarm()
{
    return this->stepperDrive->isAlarm();
}

inline bool Core :: isPowerOn()
{
    return this->state.power == ON;
}

inline int64_t Core :: feedRatio(int64_t count)
{
    if (state.feed == 0) {
        return 0;
    }
    FEED_THREAD *feed = (FEED_THREAD*) (uint64_t) state.feed;
#ifdef USE_FLOATING_POINT
    return ((float)count) * this->feed * feedDirection;
#else // USE_FLOATING_POINT
    return ((long long)count) * feed->numerator / feed->denominator * (state.direction == CW ? 1 : -1);
#endif // USE_FLOATING_POINT
}

#define SIGN(x) ((x > 0) - (x < 0))

inline void Core :: ISR( void )
{
    state_t new_state;
    bool state_received = (xQueueReceive(this->state_queue, &new_state, 0) == pdTRUE);

    if (!state_received && this->state.feed == 0) {
        return;
    }

    state_t old_state = this->state;
    this->state = new_state;

    // read the encoder
    int64_t spindlePosition = encoder->getPosition();

    // calculate the desired stepper position
    int64_t desiredSteps = feedRatio(spindlePosition);
    stepperDrive->setDesiredPosition(desiredSteps);

    // if the feed or direction changed, reset sync to avoid a big step
    if(old_state.feed != this->state.feed || old_state.direction != this->state.direction) {
        stepperDrive->setCurrentPosition(desiredSteps);
    }

    // service the stepper drive state machine
    stepperDrive->setEnabled(this->isPowerOn());
    stepperDrive->ISR();
}


#endif // __CORE_H
