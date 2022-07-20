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

#include "esp_timer.h"

#include "Encoder.h"
#include "Configuration.h"


Encoder :: Encoder( void )
{
    this->previous = 0;
    this->previous_us = 0;
    this->rpm = 0;
}

void Encoder :: initHardware(void)
{
    ESP32Encoder::useInternalWeakPullResistors = UP;
    ESP32Encoder::isrServiceCpuCore = CORE_SERVICE_CPU_CORE;
    encoder.attachFullQuad(ENCODER_A_GPIO, ENCODER_B_GPIO);
}

uint16_t Encoder :: getRPM(void)
{
    int64_t current_us = esp_timer_get_time();

    if (current_us > previous_us + (1000000 / RPM_CALC_RATE_HZ)) {
      int64_t current = encoder.getCount();
      int64_t count = (current > previous) ? current - previous : previous - current;

      rpm = count * 60 * RPM_CALC_RATE_HZ / ENCODER_RESOLUTION;

      previous = current;
      previous_us = current_us;
    }
    return rpm;
}
