/*
 * SPIBus.cpp
 *
 *  Created on: Aug 15, 2019
 *      Author: clough
 */

#include "SPIBus.h"

// wait for the current serial shift operation to complete
#define WAIT_FOR_SERIAL while(SpibRegs.SPISTS.bit.INT_FLAG !=1) {}


SPIBus :: SPIBus( void )
{
    mask = 0xffff;
}

void SPIBus :: initHardware(void)
{
/** TODO: UNPORTED start
    // Set up slow speed clock
    EALLOW;
    ClkCfgRegs.LOSPCP.bit.LSPCLKDIV = 0b100; // LPSCLK = SYSCLK/8 = 12.5MHz
    EDIS;

    // Set up SPI B
    SpibRegs.SPICCR.bit.SPISWRESET = 0; // Enter RESET state
    setEightBits();
    SpibRegs.SPICCR.bit.CLKPOLARITY = 1; // data latched on rising edge
    SpibRegs.SPICTL.bit.CLK_PHASE = 0; // normal clocking scheme
    SpibRegs.SPICTL.bit.MASTER_SLAVE = 1; // master
    SpibRegs.SPIBRR.bit.SPI_BIT_RATE = 127; // SPI bit rate = LPSCLK/128 ~ 98Kbps
    setThreeWire();
    SpibRegs.SPICCR.bit.SPISWRESET = 1; // clear reset state; ready to transmit

    EALLOW;

    // Set up muxing for SPIB pins
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0x2;      // select SPIB_SIMO
    GpioCtrlRegs.GPAGMUX2.bit.GPIO24 = 0x1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0x3;      // select SPIB_SOMI
    GpioCtrlRegs.GPAGMUX2.bit.GPIO31 = 0x0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0x3;      // select SPIB_CLK
    GpioCtrlRegs.GPBGMUX1.bit.GPIO32 = 0x0;

    EDIS;
TODO: UNPORTED end */
}

void SPIBus :: setThreeWire( void )
{
/** TODO: UNPORTED start
    SpibRegs.SPIPRI.bit.TRIWIRE = 1; // 3-wire mode
TODO: UNPORTED end */
}

void SPIBus :: setFourWire( void )
{
/** TODO: UNPORTED start
    SpibRegs.SPIPRI.bit.TRIWIRE = 0; // Normal (4-wire) mode
TODO: UNPORTED end */
}

void SPIBus :: setEightBits( void )
{
/** TODO: UNPORTED start
    SpibRegs.SPICCR.bit.SPICHAR = 0x7; // 8 bits
    mask = 0x00ff;                     // set the mask to 8 bits
TODO: UNPORTED end */
}

void SPIBus :: setSixteenBits( void )
{
/** TODO: UNPORTED start
    SpibRegs.SPICCR.bit.SPICHAR = 0xF; // 16 bits
    mask = 0xffff;                     // set the mask to 16 bits
TODO: UNPORTED end */
}

void SPIBus :: sendWord(uint16_t data)
{
/** TODO: UNPORTED start
    SpibRegs.SPICTL.bit.TALK = 1;
    SpibRegs.SPITXBUF = data;
    WAIT_FOR_SERIAL;
    dummy = SpibRegs.SPIRXBUF;
TODO: UNPORTED end */
}

uint16_t SPIBus :: receiveWord(void) {
/** TODO: UNPORTED start
    SpibRegs.SPICTL.bit.TALK = 0;
    SpibRegs.SPITXBUF = dummy;
    WAIT_FOR_SERIAL;
    return SpibRegs.SPIRXBUF & mask; // mask off if we're in 8-bit mode
TODO: UNPORTED end */
  return 0;
}
