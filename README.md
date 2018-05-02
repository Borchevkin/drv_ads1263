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

For worrk with this driver you should finish followning steps:

1. Clone this repository

1. Include ***ads1263.h*** and ***ads1263.c*** into your project

1. For work with [ADS1263](http://www.ti.com/product/ADS1263) you have to setup SPI of your MCU to ***CPOL = 0***  and ***CPHA = 1***. If there is some problem with it please read following:

    * **CS** active state is *LOW*

    * **SCLK** is *LOW* if inactive. Input data to the ADC is latched on the *falling SCLK edge* and data output from the ADC is updated on the *rising SCLK edge*.

    * The ADC latches input data on the *falling edge of SCLK*. During direct-mode data readback, when no command is intended, keep **DIN* in  *LOW* state.

1. Implement following functions: 

    * TBA

    * TBA

    * TBA

1. Init main structure with pointers to your implemented functions at prevous step

1. Explore the ***ads1263.c*** which has Doxygen comments for working with needed functions

## Errata

TBA

## Feedback

Tech questions: danil.borchevkin@lab409.ru

Administrative quiestions: danil.borchevkin@lab409.ru