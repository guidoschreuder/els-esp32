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


#include "Tables.h"


//
// INCH THREAD DEFINITIONS
//
// Each row in the table defines a standard imperial thread, with the display data,
// LED indicator states and gear ratio fraction to use.
//
#if defined(LEADSCREW_TPI)
#define TPI_NUMERATOR(tpi) ((uint64_t)LEADSCREW_TPI*STEPPER_RESOLUTION*STEPPER_MICROSTEPS*10)
#define TPI_DENOMINATOR(tpi) ((uint64_t)tpi*ENCODER_RESOLUTION)
#endif
#if defined(LEADSCREW_HMM)
#define TPI_NUMERATOR(tpi) ((uint64_t)254*100*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define TPI_DENOMINATOR(tpi) ((uint64_t)tpi*ENCODER_RESOLUTION*LEADSCREW_HMM)
#endif
#define TPI_FRACTION(tpi) .numerator = TPI_NUMERATOR(tpi), .denominator = TPI_DENOMINATOR(tpi)

const FEED_THREAD inch_thread_table[] =
{
 { .display = {BLANK, BLANK, BLANK, EIGHT}, .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(80) },
 { .display = {BLANK, BLANK, BLANK, NINE},  .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(90) },
 { .display = {BLANK, BLANK, ONE,   ZERO},  .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(100) },
 { .display = {BLANK, BLANK, ONE,   ONE},   .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(110) },
 { .display = {BLANK, ONE, ONE|POINT,FIVE}, .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(115) },
 { .display = {BLANK, BLANK, ONE,   TWO},   .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(120) },
 { .display = {BLANK, BLANK, ONE,   THREE}, .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(130) },
 { .display = {BLANK, BLANK, ONE,   FOUR},  .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(140) },
 { .display = {BLANK, BLANK, ONE,   SIX},   .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(160) },
 { .display = {BLANK, BLANK, ONE,   EIGHT}, .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(180) },
 { .display = {BLANK, BLANK, ONE,   NINE},  .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(190) },
 { .display = {BLANK, BLANK, TWO,   ZERO},  .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(200) },
 { .display = {BLANK, BLANK, TWO,   FOUR},  .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(240) },
 { .display = {BLANK, BLANK, TWO,   SIX},   .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(260) },
 { .display = {BLANK, BLANK, TWO,   SEVEN}, .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(270) },
 { .display = {BLANK, BLANK, TWO,   EIGHT}, .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(280) },
 { .display = {BLANK, BLANK, THREE, TWO},   .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(320) },
 { .display = {BLANK, BLANK, THREE, SIX},   .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(360) },
 { .display = {BLANK, BLANK, FOUR,  ZERO},  .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(400) },
 { .display = {BLANK, BLANK, FOUR,  FOUR},  .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(440) },
 { .display = {BLANK, BLANK, FOUR,  EIGHT}, .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(480) },
 { .display = {BLANK, BLANK, FIVE,  SIX},   .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(560) },
 { .display = {BLANK, BLANK, SIX,   FOUR},  .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(640) },
 { .display = {BLANK, BLANK, SEVEN, TWO},   .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(720) },
 { .display = {BLANK, BLANK, EIGHT, ZERO},  .leds { .all = LED_THREAD | LED_TPI }, TPI_FRACTION(800) },
};



//
// INCH FEED DEFINITIONS
//
// Each row in the table defines a standard imperial feed rate, with the display data,
// LED indicator states and gear ratio fraction to use.
//

#if defined(LEADSCREW_TPI)
#define THOU_IN_NUMERATOR(thou) ((uint64_t)thou*LEADSCREW_TPI*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define THOU_IN_DENOMINATOR(thou) ((uint64_t)ENCODER_RESOLUTION*1000)
#endif
#if defined(LEADSCREW_HMM)
#define THOU_IN_NUMERATOR(thou) ((uint64_t)thou*254*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define THOU_IN_DENOMINATOR(thou) ((uint64_t)ENCODER_RESOLUTION*100*LEADSCREW_HMM)
#endif
#define THOU_IN_FRACTION(thou) .numerator = THOU_IN_NUMERATOR(thou), .denominator = THOU_IN_DENOMINATOR(thou)

const FEED_THREAD inch_feed_table[] =
{
 { .display = {POINT, ZERO, ZERO,  ONE},    .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(1) },
 { .display = {POINT, ZERO, ZERO,  TWO},    .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(2) },
 { .display = {POINT, ZERO, ZERO,  THREE},  .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(3) },
 { .display = {POINT, ZERO, ZERO,  FOUR},   .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(4) },
 { .display = {POINT, ZERO, ZERO,  FIVE},   .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(5) },
 { .display = {POINT, ZERO, ZERO,  SIX},    .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(6) },
 { .display = {POINT, ZERO, ZERO,  SEVEN},  .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(7) },
 { .display = {POINT, ZERO, ZERO,  EIGHT},  .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(8) },
 { .display = {POINT, ZERO, ZERO,  NINE},   .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(9) },
 { .display = {POINT, ZERO, ONE,   ZERO},   .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(10) },
 { .display = {POINT, ZERO, ONE,   ONE},    .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(11) },
 { .display = {POINT, ZERO, ONE,   TWO},    .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(12) },
 { .display = {POINT, ZERO, ONE,   THREE},  .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(13) },
 { .display = {POINT, ZERO, ONE,   FIVE},   .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(15) },
 { .display = {POINT, ZERO, ONE,   SEVEN},  .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(17) },
 { .display = {POINT, ZERO, TWO,   ZERO},   .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(20) },
 { .display = {POINT, ZERO, TWO,   THREE},  .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(23) },
 { .display = {POINT, ZERO, TWO,   SIX},    .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(26) },
 { .display = {POINT, ZERO, THREE, ZERO},   .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(30) },
 { .display = {POINT, ZERO, THREE, FIVE},   .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(35) },
 { .display = {POINT, ZERO, FOUR,  ZERO},   .leds { .all = LED_FEED | LED_INCH }, THOU_IN_FRACTION(40) },
};




//
// METRIC THREAD DEFINITIONS
//
// Each row in the table defines a standard metric thread, with the display data,
// LED indicator states and gear ratio fraction to use.
//
#if defined(LEADSCREW_TPI)
#define HMM_NUMERATOR(hmm) ((uint64_t)hmm*10*LEADSCREW_TPI*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define HMM_DENOMINATOR(hmm) ((uint64_t)ENCODER_RESOLUTION*254*100)
#endif
#if defined(LEADSCREW_HMM)
#define HMM_NUMERATOR(hmm) ((uint64_t)hmm*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define HMM_DENOMINATOR(hmm) ((uint64_t)ENCODER_RESOLUTION*LEADSCREW_HMM)
#endif
#define HMM_FRACTION(hmm) .numerator = HMM_NUMERATOR(hmm), .denominator = HMM_DENOMINATOR(hmm)

const FEED_THREAD metric_thread_table[] =
{
 { .display = {BLANK, POINT,         TWO,   BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(20) },
 { .display = {BLANK, POINT,         TWO,   FIVE},  .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(25) },
 { .display = {BLANK, POINT,         THREE, BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(30) },
 { .display = {BLANK, POINT,         THREE, FIVE},  .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(35) },
 { .display = {BLANK, POINT,         FOUR,  BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(40) },
 { .display = {BLANK, POINT,         FOUR,  FIVE},  .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(45) },
 { .display = {BLANK, POINT,         FIVE,  BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(50) },
 { .display = {BLANK, POINT,         SIX,   BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(60) },
 { .display = {BLANK, POINT,         SEVEN, BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(70) },
 { .display = {BLANK, POINT,         SEVEN, FIVE},  .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(75) },
 { .display = {BLANK, POINT,         EIGHT, BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(80) },
 { .display = {BLANK, ONE,           BLANK, BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(100) },
 { .display = {BLANK, ONE | POINT,   TWO,   FIVE},  .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(125) },
 { .display = {BLANK, ONE | POINT,   FIVE,  BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(150) },
 { .display = {BLANK, ONE | POINT,   SEVEN, FIVE},  .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(175) },
 { .display = {BLANK, TWO,           BLANK, BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(200) },
 { .display = {BLANK, TWO | POINT,   FIVE,  BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(250) },
 { .display = {BLANK, THREE,         BLANK, BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(300) },
 { .display = {BLANK, THREE | POINT, FIVE,  BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(350) },
 { .display = {BLANK, FOUR,          BLANK, BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(400) },
 { .display = {BLANK, FOUR | POINT,  FIVE,  BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(450) },
 { .display = {BLANK, FIVE,          BLANK, BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(500) },
 { .display = {BLANK, FIVE | POINT,  FIVE,  BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(550) },
 { .display = {BLANK, SIX,           BLANK, BLANK}, .leds { .all = LED_THREAD | LED_MM }, HMM_FRACTION(600) },
};



//
// METRIC FEED DEFINITIONS
//
// Each row in the table defines a standard metric feed, with the display data,
// LED indicator states and gear ratio fraction to use.
//
#if defined(LEADSCREW_TPI)
#define HMM_NUMERATOR_FEED(hmm) ((uint64_t)hmm*10*LEADSCREW_TPI*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define HMM_DENOMINATOR_FEED(hmm) ((uint64_t)ENCODER_RESOLUTION*254*100)
#endif
#if defined(LEADSCREW_HMM)
#define HMM_NUMERATOR_FEED(hmm) ((uint64_t)hmm*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define HMM_DENOMINATOR_FEED(hmm) ((uint64_t)ENCODER_RESOLUTION*LEADSCREW_HMM)
#endif
#define HMM_FRACTION_FEED(hmm) .numerator = HMM_NUMERATOR_FEED(hmm), .denominator = HMM_DENOMINATOR_FEED(hmm)

const FEED_THREAD metric_feed_table[] =
{
 { .display = {BLANK, POINT,       ZERO,  TWO},   .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(2) },
 { .display = {BLANK, POINT,       ZERO,  FIVE},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(5) },
 { .display = {BLANK, POINT,       ZERO,  SEVEN}, .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(7) },
 { .display = {BLANK, POINT,       ONE,   ZERO},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(10) },
 { .display = {BLANK, POINT,       ONE,   TWO},   .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(12) },
 { .display = {BLANK, POINT,       ONE,   FIVE},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(15) },
 { .display = {BLANK, POINT,       ONE,   SEVEN}, .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(17) },
 { .display = {BLANK, POINT,       TWO,   ZERO},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(20) },
 { .display = {BLANK, POINT,       TWO,   TWO},   .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(22) },
 { .display = {BLANK, POINT,       TWO,   FIVE},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(25) },
 { .display = {BLANK, POINT,       TWO,   SEVEN}, .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(27) },
 { .display = {BLANK, POINT,       THREE, ZERO},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(30) },
 { .display = {BLANK, POINT,       THREE, FIVE},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(35) },
 { .display = {BLANK, POINT,       FOUR,  ZERO},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(40) },
 { .display = {BLANK, POINT,       FOUR,  FIVE},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(45) },
 { .display = {BLANK, POINT,       FIVE,  ZERO},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(50) },
 { .display = {BLANK, POINT,       FIVE,  FIVE},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(55) },
 { .display = {BLANK, POINT,       SIX,   ZERO},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(60) },
 { .display = {BLANK, POINT,       SEVEN, ZERO},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(70) },
 { .display = {BLANK, POINT,       EIGHT, FIVE},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(85) },
 { .display = {BLANK, ONE | POINT, ZERO,  ZERO},  .leds { .all = LED_FEED | LED_MM }, HMM_FRACTION_FEED(100) },
};





FeedTable::FeedTable(const FEED_THREAD *table, uint16_t numRows, uint16_t defaultSelection)
{
    this->table = table;
    this->numRows = numRows;
    this->selectedRow = defaultSelection;
}

const FEED_THREAD *FeedTable :: current(void)
{
    return &table[selectedRow];
}

const FEED_THREAD *FeedTable :: next(void)
{
    if( this->selectedRow < this->numRows - 1 )
    {
        this->selectedRow++;
    }
    return this->current();
}

const FEED_THREAD *FeedTable :: previous(void)
{
    if( this->selectedRow > 0 )
    {
        this->selectedRow--;
    }
    return this->current();
}

FeedTableFactory::FeedTableFactory(void):
        inchThreads(inch_thread_table, sizeof(inch_thread_table)/sizeof(inch_thread_table[0]), 12),
        inchFeeds(inch_feed_table, sizeof(inch_feed_table)/sizeof(inch_feed_table[0]), 4),
        metricThreads(metric_thread_table, sizeof(metric_thread_table)/sizeof(metric_thread_table[0]), 6),
        metricFeeds(metric_feed_table, sizeof(metric_feed_table)/sizeof(metric_feed_table[0]), 4)
{
}

FeedTable *FeedTableFactory::getFeedTable(bool metric, bool thread)
{
    if( metric )
    {
        if( thread )
        {
            return &this->metricThreads;
        }
        else
        {
            return &this->metricFeeds;
        }
    }
    else
    {
        if( thread )
        {
            return &this->inchThreads;
        }
        else
        {
            return &this->inchFeeds;
        }
    }

}
