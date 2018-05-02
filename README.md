# drv_ads1263 README

This project is purposed to implement driver for [ADS1263](http://www.ti.com/product/ADS1263)

## Who develop this

This driver develop by [Lab409](http://lab409.ru):

* Natalia Bannikova

* Danil Borchevkin

## Licence

BSD-2 Clause. See LICENCE file for additional information

## What's included

* ***./ads1263.h*** - header file of the driver 

* ***./ads1263.c*** - code file of the driver 

* ***./LICENCE*** - licence file

* ***./README.md*** - this file  

## Embedding information

For work with this driver you should finish followning steps:

1. Clone this repository

1. Include ***ads1263.h*** and ***ads1263.c*** into your project

1. For work with [ADS1263](http://www.ti.com/product/ADS1263) you have to setup SPI of your MCU to ***CPOL = 0***  and ***CPHA = 1***. If there is some problem with it please read following:

    * **CS** active state is *LOW*

    * **SCLK** is *LOW* if inactive. Input data to the ADC is latched on the *falling SCLK edge* and data output from the ADC is updated on the *rising SCLK edge*.

    * The ADC latches input data on the *falling edge of SCLK*. During direct-mode data readback, when no command is intended, keep **DIN* in  *LOW* state.

1. Define  ```ads1263_t ads1263``` (often in global scope)

1. Define and implement following functions with signatures (names of functions may be specific for you):

    * ```spiTransfer(uint8_t tx, uint8_t rx, uint8_t len)``` - transfer data over SPI

    * ```setCS(uint8_t state)``` - control CS line. When ```state``` equals to ```1``` a state of line is *HIGH*

    * ```setReset(uint8_t state)``` - control RESET line. When ```state``` equals to ```1``` a state of line is *HIGH*

    * ```delayMs(uint32_t delay)``` - delay in milliseconds

1. Init main structure with pointers to your implemented functions at prevous step:

    ```c
    ads1263.Transfer = spiTransfer;
    ads1263.SetCS = setCS;
    ads1263.SetReset = setReset;
    ads1263.DelayMs = delayMs;

    ADS1263_Init(&ads1263);
    ```

1. Explore the ***ads1263.c*** which has Doxygen comments for working with needed functions

## Errata

TBA

## Feedback

Tech questions: danil.borchevkin@lab409.ru

Administrative quiestions: danil.borchevkin@lab409.ru