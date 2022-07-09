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

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_err.h"
#include "driver/timer.h"

#include "Configuration.h"
#include "SanityCheck.h"
#include "ControlPanel.h"
#include "StepperDrive.h"

#include "Tables.h"
#include "Encoder.h"
#include "Core.h"
#include "UserInterface.h"
#include "Debug.h"

extern "C" {
void app_main();
}

//
// DEPENDENCY INJECTION
//
// Declare all of the main components and wire them together
//

// Debug harness
Debug debug;

// Feed table factory
FeedTableFactory feedTableFactory;

// Control Panel driver
ControlPanel controlPanel;

// Encoder driver
Encoder encoder;

// Stepper driver
StepperDrive stepperDrive;

// Core engine
Core core(&encoder, &stepperDrive);

// User interface
UserInterface userInterface(&controlPanel, &core, &feedTableFactory);

static TaskHandle_t core_service_task_handle;

static bool IRAM_ATTR core_service_timer_isr_callback(void* args) {
    BaseType_t high_task_awoken = pdFALSE;
    vTaskNotifyGiveFromISR(core_service_task_handle, &high_task_awoken);
    return high_task_awoken == pdTRUE;
}

void core_service_task(void *pvParameter) {
    for (;;) {
        // if(xSemaphoreTake(timer_sem, portMAX_DELAY) == pdTRUE) {
        if (ulTaskNotifyTake(pdTRUE, portMAX_DELAY)) {
            // flag entrance to ISR for timing
            debug.begin1();

            // service the Core engine ISR, which in turn services the StepperDrive ISR
            core.ISR();

            // flag exit from ISR for timing
            debug.end1();
        }
    }
}

void ui_task(void *pvParameter) {
    // User interface loop
    for(;;) {
        // mark beginning of loop for debugging
        debug.begin2();

        // check for step backlog and panic the system if it occurs
        if( stepperDrive.checkStepBacklog() ) {
            userInterface.panicStepBacklog();
        }

        // service the user interface
        userInterface.loop();

        // mark end of loop for debugging
        debug.end2();

        // delay
        vTaskDelay(pdMS_TO_TICKS(1000 / UI_REFRESH_RATE_HZ));
    }

}

#define TIMER_DIVIDER (16)

void app_main()
{
    // Initialize peripherals and pins
    debug.initHardware();
    controlPanel.initHardware();
    stepperDrive.initHardware();
    encoder.initHardware();

    // create UI task
    xTaskCreate(&ui_task, "ui_task", 2048, NULL, 4, NULL);

    // create core service task
    xTaskCreatePinnedToCore(core_service_task, "core_service_task", 4096, NULL, configMAX_PRIORITIES - 1, &core_service_task_handle, APP_CPU_NUM);

    // create core service hardware timer
    timer_config_t config = {
        .alarm_en = TIMER_ALARM_EN,
        .counter_en = TIMER_PAUSE,
        .counter_dir = TIMER_COUNT_UP,
        .auto_reload = timer_autoreload_t::TIMER_AUTORELOAD_EN,
        .divider = TIMER_DIVIDER,
    }; // default clock source is APB
    timer_init(TIMER_GROUP_0, TIMER_0, &config);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0);

    timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, TIMER_BASE_CLK / TIMER_DIVIDER / CONTROL_FREQ_HZ);
    timer_enable_intr(TIMER_GROUP_0, TIMER_0);

    timer_isr_callback_add(TIMER_GROUP_0, TIMER_0, core_service_timer_isr_callback, NULL, 0);

    timer_start(TIMER_GROUP_0, TIMER_0);
}
