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


#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H


#define DISP_SPI_HOST    HSPI_HOST

//================================================================================
//                                  PINS
// debug pins
#define DEBUG1_GPIO     26
#define DEBUG2_GPIO     27

// encoder pins
#define ENCODER_A_GPIO  19
#define ENCODER_B_GPIO  18

// stepper pins
#define STEP_GPIO       21
#define DIRECTION_GPIO  22
#define ENABLE_GPIO     23
#define ALARM_GPIO      25

// control panel pins
#define DISP_MOSI_GPIO  13
#define DISP_CLK_GPIO   14
#define DISP_CS_GPIO    15



//================================================================================
//                                  LEADSCREW
//
// Define the type and pitch of leadscrew you have in your lathe.  If you have an
// imperial leadscrew, define LEADSCREW_TPI.  If you have a metric leadscrew,
// define LEADSCREW_HMM (pitch in hundredths of a millimeter).  Do not define
// both.
//================================================================================

// For Imperial leadscrews: pitch in Threads Per Inch (TPI)
#define LEADSCREW_TPI 12

// For metric leadscrews: pitch in hundredths of a millimeter (HMM)
// Example: 200hmm = 2mm
//#define LEADSCREW_HMM 200




//================================================================================
//                                STEPPER/SERVO
//
// Define the number of steps and microsteps for your stepper motor, the pin
// polarity of the driver, and whether to use additional features, like servo
// alarm feedback.
//
// NOTE: If you are using a servo drive with something other than a 1:1 drive
// ratio, you can use the STEPPER_MICROSTEPS to compensate.  For example, if you
// have a servo configured for 1000 steps/revolution and it drives the leadscrew
// through a 3:1 reduction, you can set STEPPER_RESOLUTION to 1000 and
// STEPPER_MICROSTEPS to 3.
//================================================================================

// Steps and microsteps
#define STEPPER_MICROSTEPS 8
#define STEPPER_RESOLUTION 200

// Separate step and microstep settings for feed rates.  Redefine these if your
// lathe has a separate feed drive train with a different ratio.
#define STEPPER_MICROSTEPS_FEED STEPPER_MICROSTEPS
#define STEPPER_RESOLUTION_FEED STEPPER_RESOLUTION

// Step, direction and enable pins are normally active-high
// #define INVERT_STEP_GPIO true
// #define INVERT_DIRECTION_GPIO true
#define INVERT_ENABLE_GPIO true
#define INVERT_ALARM_GPIO true

// Enable servo alarm feedback
#define USE_ALARM_GPIO




//================================================================================
//                                 ENCODER
//
// Define the type of encoder you are using on the spindle.  The firmware assumes
// the encoder is turning at a 1:1 ratio with the spindle.
//
// NOTE: the firmware is concerned with the quadrature edge count, which is
// four times the number of pulses.  For example, if you have a 1024 P/R
// encoder, you need to enter 4096 here.
//================================================================================

// Encoder resolution (counts per revolution)
#define ENCODER_RESOLUTION 4096

// Which encoder input to use
#define ENCODER_USE_EQEP1
//#define ENCODER_USE_EQEP2




//================================================================================
//                               CALCULATIONS
//
// Define how calculations should be performed.  Most users will not need to
// touch these settings.
//================================================================================

// Use floating-point math for gear ratios
//#define USE_FLOATING_POINT




//================================================================================
//                                HARDWARE
//
// Define which hardware you're using:
//
//  1 - LaunchXL F280049C with ELS BoostXL v1
//  2 - LaunchXL F280049C with ELS BoostXL v2
//================================================================================

// See hardware version table above
#define HARDWARE_VERSION 2




//================================================================================
//                                FEATURES
//
// Additional features that can be enabled for your configuration.
//================================================================================

// Ignore all key presses when the machine is running.  Normally, only the mode
// and direction keys are ignored.
//#define IGNORE_ALL_KEYS_WHEN_RUNNING




//================================================================================
//                              VALIDATION/TRIP
//
// Validation thresholds and automatic trip behavior.
//================================================================================

// Maximum number of buffered steps
// The ELS can only output steps at approximately 100KHz.  If you ask the ELS to
// output steps faster than this, it will get behind and will stop automatically
// when the buffered step count exceeds this value.
#define MAX_BUFFERED_STEPS 100


//================================================================================
//                               CPU / TIMING
//
// Define the CPU clock, interrupt, and refresh timing.  Most users will not need
// to touch these settings.
//================================================================================

// Frequency of main control loop
#define CONTROL_FREQ_HZ 20000

// Stepper state machine cycle time, in microseconds
// Two cycles are required per step
#define STEPPER_CYCLE_US 5

// User interface refresh rate, in Hertz
#define UI_REFRESH_RATE_HZ 100

// RPM recalculation rate, in Hz
#define RPM_CALC_RATE_HZ 2

#endif // __CONFIGURATION_H
