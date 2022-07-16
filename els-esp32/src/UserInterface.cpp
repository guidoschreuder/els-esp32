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


#include "UserInterface.h"

const MESSAGE STARTUP_MESSAGE_2 =
{
  .message = { LETTER_E, LETTER_L, LETTER_S, DASH, ONE | POINT, FOUR | POINT, ZERO, ZERO },
  .displayTime = (uint16_t)(UI_REFRESH_RATE_HZ * 1.5),
  .next = NULL,
};

const MESSAGE STARTUP_MESSAGE_1 =
{
  .message = { LETTER_C, LETTER_L, LETTER_O, LETTER_U, LETTER_G, LETTER_H, FOUR, TWO },
  .displayTime = (uint16_t)(UI_REFRESH_RATE_HZ * 1.5),
  .next = &STARTUP_MESSAGE_2,
};

const MESSAGE SETTINGS_MESSAGE_2 =
{
  .message = { LETTER_S, LETTER_E, LETTER_T, LETTER_T, LETTER_I, LETTER_N, LETTER_G, LETTER_S },
  .displayTime = (uint16_t)(UI_REFRESH_RATE_HZ * .5),
  .next = NULL,
};

const MESSAGE SETTINGS_MESSAGE_1 =
{
  .message = { BLANK, BLANK, BLANK, LETTER_N, LETTER_O, BLANK, BLANK, BLANK },
  .displayTime = (uint16_t)(UI_REFRESH_RATE_HZ * .5),
  .next = &SETTINGS_MESSAGE_2,
};

extern const MESSAGE BACKLOG_PANIC_MESSAGE_2;
const MESSAGE BACKLOG_PANIC_MESSAGE_1 =
{
  .message = { LETTER_T, LETTER_O, LETTER_O, BLANK, LETTER_F, LETTER_A, LETTER_S, LETTER_T },
  .displayTime = (uint16_t)(UI_REFRESH_RATE_HZ * .5),
  .next = &BACKLOG_PANIC_MESSAGE_2,
};
const MESSAGE BACKLOG_PANIC_MESSAGE_2 =
{
  .message = { BLANK, LETTER_R, LETTER_E, LETTER_S, LETTER_E, LETTER_T, BLANK, BLANK },
  .displayTime = (uint16_t)(UI_REFRESH_RATE_HZ * .5),
  .next = &BACKLOG_PANIC_MESSAGE_1,
};



const uint16_t VALUE_BLANK[4] = { BLANK, BLANK, BLANK, BLANK };

UserInterface :: UserInterface(ControlPanel *controlPanel, Core *core, FeedTableFactory *feedTableFactory)
{
    this->controlPanel = controlPanel;
    this->core = core;
    this->feedTableFactory = feedTableFactory;

    this->metric = false; // start out with imperial
    this->thread = false; // start out with feeds
    this->reverse = false; // start out going forward

    this->feedTable = NULL;

    this->keys.all = 0xff;

    // initialize the core so we start up correctly
    core->set_state(true, this->reverse, loadFeedTable());

    setMessage(&STARTUP_MESSAGE_1);
}

const FEED_THREAD *UserInterface::loadFeedTable()
{
    this->feedTable = this->feedTableFactory->getFeedTable(this->metric, this->thread);
    return this->feedTable->current();
}

LED_REG UserInterface::calculateLEDs()
{
    // get the LEDs for this feed
    LED_REG leds = feedTable->current()->leds;

    if( this->core->isPowerOn() )
    {
        // and add a few of our own
        leds.bit.POWER = 1;
        leds.bit.REVERSE = this->reverse;
        leds.bit.FORWARD = ! this->reverse;
    }
    else
    {
        // power is off
        leds.all = 0;
    }

    return leds;
}

void UserInterface :: setMessage(const MESSAGE *message)
{
    this->message = message;
    this->messageTime = message->displayTime;
}

void UserInterface :: overrideMessage( void )
{
    if( this->message != NULL )
    {
        if( this->messageTime > 0 ) {
            this->messageTime--;
            controlPanel->setMessage(this->message->message);
        }
        else {
            this->message = this->message->next;
            if( this->message == NULL )
                controlPanel->setMessage(NULL);
            else
                this->messageTime = this->message->displayTime;
        }
    }
}

void UserInterface :: clearMessage( void )
{
    this->message = NULL;
    this->messageTime = 0;
    controlPanel->setMessage(NULL);
}

void UserInterface :: panicStepBacklog( void )
{
    setMessage(&BACKLOG_PANIC_MESSAGE_1);
}

void UserInterface :: loop( void )
{
    // read the RPM up front so we can use it to make decisions
    uint16_t currentRpm = core->getRPM();

    // display an override message, if there is one
    overrideMessage();

    // read keypresses from the control panel
    keys = controlPanel->getKeys();

    // respond to keypresses
    if( currentRpm == 0 )
    {
        // these keys should only be sensitive when the machine is stopped
        if( keys.bit.POWER ) {
            this->core->set_state(!this->core->isPowerOn(), this->reverse, this->feedTable->current());
            clearMessage();
        }

        // these should only work when the power is on
        if( this->core->isPowerOn() ) {
            if( keys.bit.IN_MM )
            {
                this->metric = ! this->metric;
                this->core->set_state(this->core->isPowerOn(), this->reverse, loadFeedTable());
            }
            if( keys.bit.FEED_THREAD )
            {
                this->thread = ! this->thread;
                this->core->set_state(this->core->isPowerOn(), this->reverse, loadFeedTable());
            }
            if( keys.bit.FWD_REV )
            {
                this->reverse = ! this->reverse;
                this->core->set_state(this->core->isPowerOn(), this->reverse, this->feedTable->current());
            }
            if( keys.bit.SET )
            {
                setMessage(&SETTINGS_MESSAGE_1);
            }
        }
    }

#ifdef IGNORE_ALL_KEYS_WHEN_RUNNING
    if( currentRpm == 0 )
        {
#endif // IGNORE_ALL_KEYS_WHEN_RUNNING

        // these should only work when the power is on
        if( this->core->isPowerOn() ) {
            // these keys can be operated when the machine is running
            if( keys.bit.UP )
            {
                this->core->set_state(this->core->isPowerOn(), this->reverse, this->feedTable->next());
            }
            if( keys.bit.DOWN )
            {
                this->core->set_state(this->core->isPowerOn(), this->reverse, this->feedTable->previous());
            }
        }

#ifdef IGNORE_ALL_KEYS_WHEN_RUNNING
    }
#endif // IGNORE_ALL_KEYS_WHEN_RUNNING

    // update the control panel
    controlPanel->setLEDs(calculateLEDs());
    controlPanel->setValue(feedTable->current()->display);
    controlPanel->setRPM(currentRpm);

    if( ! core->isPowerOn() )
    {
        controlPanel->setValue(VALUE_BLANK);
    }

    controlPanel->refresh();
}
