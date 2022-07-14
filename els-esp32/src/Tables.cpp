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

#define LEDS(bits) .leds { .all = bits }

//
// INCH THREAD DEFINITIONS
//
// Each row in the table defines a standard imperial thread, with the display data,
// LED indicator states and gear ratio fraction to use.
//
#if defined(LEADSCREW_TPI)
#define TPI_NUMERATOR(tpi) ((int64_t)LEADSCREW_TPI*STEPPER_RESOLUTION*STEPPER_MICROSTEPS*10)
#define TPI_DENOMINATOR(tpi) ((int64_t)tpi*ENCODER_RESOLUTION)
#endif
#if defined(LEADSCREW_HMM)
#define TPI_NUMERATOR(tpi) ((int64_t)254*100*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define TPI_DENOMINATOR(tpi) ((int64_t)tpi*ENCODER_RESOLUTION*LEADSCREW_HMM)
#endif
#define TPI_FRACTION(tpi) .numerator = TPI_NUMERATOR(tpi), .denominator = TPI_DENOMINATOR(tpi)

const FEED_THREAD inch_thread_table[] =
{
 { .display = {BLANK, BLANK, BLANK, EIGHT}, LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(80) },
 { .display = {BLANK, BLANK, BLANK, NINE},  LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(90) },
 { .display = {BLANK, BLANK, ONE,   ZERO},  LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(100) },
 { .display = {BLANK, BLANK, ONE,   ONE},   LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(110) },
 { .display = {BLANK, ONE, ONE|POINT,FIVE}, LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(115) },
 { .display = {BLANK, BLANK, ONE,   TWO},   LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(120) },
 { .display = {BLANK, BLANK, ONE,   THREE}, LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(130) },
 { .display = {BLANK, BLANK, ONE,   FOUR},  LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(140) },
 { .display = {BLANK, BLANK, ONE,   SIX},   LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(160) },
 { .display = {BLANK, BLANK, ONE,   EIGHT}, LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(180) },
 { .display = {BLANK, BLANK, ONE,   NINE},  LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(190) },
 { .display = {BLANK, BLANK, TWO,   ZERO},  LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(200) },
 { .display = {BLANK, BLANK, TWO,   FOUR},  LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(240) },
 { .display = {BLANK, BLANK, TWO,   SIX},   LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(260) },
 { .display = {BLANK, BLANK, TWO,   SEVEN}, LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(270) },
 { .display = {BLANK, BLANK, TWO,   EIGHT}, LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(280) },
 { .display = {BLANK, BLANK, THREE, TWO},   LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(320) },
 { .display = {BLANK, BLANK, THREE, SIX},   LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(360) },
 { .display = {BLANK, BLANK, FOUR,  ZERO},  LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(400) },
 { .display = {BLANK, BLANK, FOUR,  FOUR},  LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(440) },
 { .display = {BLANK, BLANK, FOUR,  EIGHT}, LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(480) },
 { .display = {BLANK, BLANK, FIVE,  SIX},   LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(560) },
 { .display = {BLANK, BLANK, SIX,   FOUR},  LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(640) },
 { .display = {BLANK, BLANK, SEVEN, TWO},   LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(720) },
 { .display = {BLANK, BLANK, EIGHT, ZERO},  LEDS(LED_THREAD | LED_TPI), TPI_FRACTION(800) },
};



//
// INCH FEED DEFINITIONS
//
// Each row in the table defines a standard imperial feed rate, with the display data,
// LED indicator states and gear ratio fraction to use.
//

#if defined(LEADSCREW_TPI)
#define THOU_IN_NUMERATOR(thou) ((int64_t)thou*LEADSCREW_TPI*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define THOU_IN_DENOMINATOR(thou) ((int64_t)ENCODER_RESOLUTION*1000)
#endif
#if defined(LEADSCREW_HMM)
#define THOU_IN_NUMERATOR(thou) ((int64_t)thou*254*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define THOU_IN_DENOMINATOR(thou) ((int64_t)ENCODER_RESOLUTION*100*LEADSCREW_HMM)
#endif
#define THOU_IN_FRACTION(thou) .numerator = THOU_IN_NUMERATOR(thou), .denominator = THOU_IN_DENOMINATOR(thou)

const FEED_THREAD inch_feed_table[] =
{
 { .display = {POINT, ZERO, ZERO,  ONE},    LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(1) },
 { .display = {POINT, ZERO, ZERO,  TWO},    LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(2) },
 { .display = {POINT, ZERO, ZERO,  THREE},  LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(3) },
 { .display = {POINT, ZERO, ZERO,  FOUR},   LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(4) },
 { .display = {POINT, ZERO, ZERO,  FIVE},   LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(5) },
 { .display = {POINT, ZERO, ZERO,  SIX},    LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(6) },
 { .display = {POINT, ZERO, ZERO,  SEVEN},  LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(7) },
 { .display = {POINT, ZERO, ZERO,  EIGHT},  LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(8) },
 { .display = {POINT, ZERO, ZERO,  NINE},   LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(9) },
 { .display = {POINT, ZERO, ONE,   ZERO},   LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(10) },
 { .display = {POINT, ZERO, ONE,   ONE},    LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(11) },
 { .display = {POINT, ZERO, ONE,   TWO},    LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(12) },
 { .display = {POINT, ZERO, ONE,   THREE},  LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(13) },
 { .display = {POINT, ZERO, ONE,   FIVE},   LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(15) },
 { .display = {POINT, ZERO, ONE,   SEVEN},  LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(17) },
 { .display = {POINT, ZERO, TWO,   ZERO},   LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(20) },
 { .display = {POINT, ZERO, TWO,   THREE},  LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(23) },
 { .display = {POINT, ZERO, TWO,   SIX},    LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(26) },
 { .display = {POINT, ZERO, THREE, ZERO},   LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(30) },
 { .display = {POINT, ZERO, THREE, FIVE},   LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(35) },
 { .display = {POINT, ZERO, FOUR,  ZERO},   LEDS(LED_FEED | LED_INCH), THOU_IN_FRACTION(40) },
};




//
// METRIC THREAD DEFINITIONS
//
// Each row in the table defines a standard metric thread, with the display data,
// LED indicator states and gear ratio fraction to use.
//
#if defined(LEADSCREW_TPI)
#define HMM_NUMERATOR(hmm) ((int64_t)hmm*10*LEADSCREW_TPI*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define HMM_DENOMINATOR(hmm) ((int64_t)ENCODER_RESOLUTION*254*100)
#endif
#if defined(LEADSCREW_HMM)
#define HMM_NUMERATOR(hmm) ((int64_t)hmm*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define HMM_DENOMINATOR(hmm) ((int64_t)ENCODER_RESOLUTION*LEADSCREW_HMM)
#endif
#define HMM_FRACTION(hmm) .numerator = HMM_NUMERATOR(hmm), .denominator = HMM_DENOMINATOR(hmm)

const FEED_THREAD metric_thread_table[] =
{
 { .display = {BLANK, POINT,         TWO,   BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(20) },
 { .display = {BLANK, POINT,         TWO,   FIVE},  LEDS(LED_THREAD | LED_MM), HMM_FRACTION(25) },
 { .display = {BLANK, POINT,         THREE, BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(30) },
 { .display = {BLANK, POINT,         THREE, FIVE},  LEDS(LED_THREAD | LED_MM), HMM_FRACTION(35) },
 { .display = {BLANK, POINT,         FOUR,  BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(40) },
 { .display = {BLANK, POINT,         FOUR,  FIVE},  LEDS(LED_THREAD | LED_MM), HMM_FRACTION(45) },
 { .display = {BLANK, POINT,         FIVE,  BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(50) },
 { .display = {BLANK, POINT,         SIX,   BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(60) },
 { .display = {BLANK, POINT,         SEVEN, BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(70) },
 { .display = {BLANK, POINT,         SEVEN, FIVE},  LEDS(LED_THREAD | LED_MM), HMM_FRACTION(75) },
 { .display = {BLANK, POINT,         EIGHT, BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(80) },
 { .display = {BLANK, ONE,           BLANK, BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(100) },
 { .display = {BLANK, ONE | POINT,   TWO,   FIVE},  LEDS(LED_THREAD | LED_MM), HMM_FRACTION(125) },
 { .display = {BLANK, ONE | POINT,   FIVE,  BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(150) },
 { .display = {BLANK, ONE | POINT,   SEVEN, FIVE},  LEDS(LED_THREAD | LED_MM), HMM_FRACTION(175) },
 { .display = {BLANK, TWO,           BLANK, BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(200) },
 { .display = {BLANK, TWO | POINT,   FIVE,  BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(250) },
 { .display = {BLANK, THREE,         BLANK, BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(300) },
 { .display = {BLANK, THREE | POINT, FIVE,  BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(350) },
 { .display = {BLANK, FOUR,          BLANK, BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(400) },
 { .display = {BLANK, FOUR | POINT,  FIVE,  BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(450) },
 { .display = {BLANK, FIVE,          BLANK, BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(500) },
 { .display = {BLANK, FIVE | POINT,  FIVE,  BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(550) },
 { .display = {BLANK, SIX,           BLANK, BLANK}, LEDS(LED_THREAD | LED_MM), HMM_FRACTION(600) },
};



//
// METRIC FEED DEFINITIONS
//
// Each row in the table defines a standard metric feed, with the display data,
// LED indicator states and gear ratio fraction to use.
//
#if defined(LEADSCREW_TPI)
#define HMM_NUMERATOR_FEED(hmm) ((int64_t)hmm*10*LEADSCREW_TPI*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define HMM_DENOMINATOR_FEED(hmm) ((int64_t)ENCODER_RESOLUTION*254*100)
#endif
#if defined(LEADSCREW_HMM)
#define HMM_NUMERATOR_FEED(hmm) ((int64_t)hmm*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define HMM_DENOMINATOR_FEED(hmm) ((int64_t)ENCODER_RESOLUTION*LEADSCREW_HMM)
#endif
#define HMM_FRACTION_FEED(hmm) .numerator = HMM_NUMERATOR_FEED(hmm), .denominator = HMM_DENOMINATOR_FEED(hmm)

const FEED_THREAD metric_feed_table[] =
{
 { .display = {BLANK, POINT,       ZERO,  TWO},   LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(2) },
 { .display = {BLANK, POINT,       ZERO,  FIVE},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(5) },
 { .display = {BLANK, POINT,       ZERO,  SEVEN}, LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(7) },
 { .display = {BLANK, POINT,       ONE,   ZERO},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(10) },
 { .display = {BLANK, POINT,       ONE,   TWO},   LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(12) },
 { .display = {BLANK, POINT,       ONE,   FIVE},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(15) },
 { .display = {BLANK, POINT,       ONE,   SEVEN}, LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(17) },
 { .display = {BLANK, POINT,       TWO,   ZERO},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(20) },
 { .display = {BLANK, POINT,       TWO,   TWO},   LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(22) },
 { .display = {BLANK, POINT,       TWO,   FIVE},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(25) },
 { .display = {BLANK, POINT,       TWO,   SEVEN}, LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(27) },
 { .display = {BLANK, POINT,       THREE, ZERO},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(30) },
 { .display = {BLANK, POINT,       THREE, FIVE},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(35) },
 { .display = {BLANK, POINT,       FOUR,  ZERO},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(40) },
 { .display = {BLANK, POINT,       FOUR,  FIVE},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(45) },
 { .display = {BLANK, POINT,       FIVE,  ZERO},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(50) },
 { .display = {BLANK, POINT,       FIVE,  FIVE},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(55) },
 { .display = {BLANK, POINT,       SIX,   ZERO},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(60) },
 { .display = {BLANK, POINT,       SEVEN, ZERO},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(70) },
 { .display = {BLANK, POINT,       EIGHT, FIVE},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(85) },
 { .display = {BLANK, ONE | POINT, ZERO,  ZERO},  LEDS(LED_FEED | LED_MM), HMM_FRACTION_FEED(100) },
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
