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
#include "esp_timer.h"
#include "esp_err.h"

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

void core_service_timer_isr(void* args);

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


void app_main()
{
    // Initialize peripherals and pins
    debug.initHardware();
    controlPanel.initHardware();
    stepperDrive.initHardware();
    encoder.initHardware();

    // create UI task
    xTaskCreate(&ui_task, "ui_task", 2048, NULL, 4, NULL);

    // create core service timer
    const esp_timer_create_args_t service_timer_args = {
            .callback = &core_service_timer_isr,
            /* name is optional, but may help identify the timer when debugging */
            .arg = NULL,
            .dispatch_method = esp_timer_dispatch_t::ESP_TIMER_TASK,
            .name = "core service",
            .skip_unhandled_events = true,
    };
    esp_timer_handle_t service_timer;
    ESP_ERROR_CHECK(esp_timer_create(&service_timer_args, &service_timer));
    // TODO: maximum frequency of ESP32 timer is 20kHz
    // therefore we never reach to 200kHz required
    //
    ESP_ERROR_CHECK(esp_timer_start_periodic(service_timer, STEPPER_CYCLE_US));
}

void IRAM_ATTR core_service_timer_isr(void* args)
{
    // flag entrance to ISR for timing
    debug.begin1();

    // service the Core engine ISR, which in turn services the StepperDrive ISR
    core.ISR();

    // flag exit from ISR for timing
    debug.end1();

}
