
#include "ads1263.h"



/*!
\brief Creating of Read Register Command
\param [in] regAddress Address of register to read
\param [in] numOfRegToRead Number of register to read (starting from "regAddress" register)
\param [out] readCmd[] Initialized array for read command
*/

void ADS1263_GetReadRegsCmd(uint8_t regAddress, uint8_t numOfRegToRead, uint8_t readCmd[])
{
    readCmd[1] = numOfRegToRead - 1;        //according to datasheet (OPCODE2 byte for RREG Command)
    readCmd[0] = 0x00;
}

/*!
\brief Creating of Write Register Command
\param [in] regAddress Address of register to write
\param [in] numOfRegToWrite Number of register to write (starting from "regAddress" register)
\param [in] data[] Data array
\param [out] writeCmd[] Initialized array for write command
\warning Tricky function. Len of cmd array calculates this way: 2 + numOfRegToWrite. 
*/

//TODO check this function. Very tricky

void ADS1263_GetWriteRegsCmd(uint8_t regAddress, uint8_t numOfRegToWrite, uint8_t data[], uint8_t writeCmd[])
{
    writeCmd[0] = ADS1263_WRITE_ADD | regAddress;
    writeCmd[1] = numOfRegToWrite - 1;       //according to datasheet (OPCODE2 byte for WREG Command)

    for(uint8_t i = 2; i <= numOfRegToWrite + 2; i++)
	{
	    writeCmd[i] = data[i-2];
	}    
}

/*!
\brief Function for reading register data
\param [in] regAddress Address of register to read
\return Value of wanted register
*/

uint8_t ADS1263_ReadReg(uint8_t regAddress)
{
    uint8_t data = 0;
    uint8_t readCmd[3] = {0};
    uint8_t rx[3] = {0};

    readCmd[0] = ADS1263_READ_ADD | regAddress;
    readCmd[1] = 0x00;        //according to datasheet (OPCODE2 byte for RREG Command for one register)
    readCmd[0] = 0x00;

    

    ads1263->Transfer(readIdCmd, rx, 3);

    data = rx[2];

    return data;
}

/*!
\brief Function for writing data to register
\param [in] regAddress Address of register to read
\param [in] data[] Data 
*/

void ADS1263_WriteReg(uint8_t regAddress, uint8_t data)
{
    uint8_t writeCmd[3] = {0};
    uint8_t rx[3] = {0};

    writeCmd[0] = ADS1263_WRITE_ADD | regAddress;
    writeCmd[1] = 0x00;                  //according to datasheet (OPCODE2 byte for WREG Command for one register)
    writeCmd[2] = data;
    
    ads1263->Transfer(writeCmd, rx, 3);
}






/* --------------- Parsing Functions Section --------------- */



/*!
\brief Parsing of ID Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal ID Register value
*/

void ADS1263_ParseIdReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->id.devId = (regVal & 0xE0) >> 5;
    ads1263->id.revId = (regVal & 0x1F); 
}

/*!
\brief Parsing of Power Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal Power Register value
*/

void ADS1263_ParsePowerReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->power.reset      = (regVal & 0x10) >> 4;
    ads1263->power.vBias      = (regVal & 0x02) >> 1;
    ads1263->power.intRef     = (regVal & 0x01);
}

/*!
\brief Parsing of Interface Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal Interface Register value
*/

void ADS1263_ParseInterfaceReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->interface.timeOut    = (regVal & 0x08) >> 3;
    ads1263->interface.status     = (regVal & 0x04) >> 2;
    ads1263->interface.crc        = (regVal & 0x03);
}

/*!
\brief Parsing of Mode0 Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal Mode0 Register value
*/

void ADS1263_ParseMode0Reg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->mode0.refRev       = (regVal & 0x80) >> 7;
    ads1263->mode0.runMode      = (regVal & 0x40) >> 6;   
    ads1263->mode0.chop         = (regVal & 0x30) >> 4;
    ads1263->mode0.delay        = (regVal & 0x0F);
}

/*!
\brief Parsing of Mode1 Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal Mode1 Register value
*/

void ADS1263_ParseMode1Reg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->mode1.filter       = (regVal & 0xE0) >> 5;
    ads1263->mode1.sBADC        = (regVal & 0x10) >> 4;
    ads1263->mode1.sBPol        = (regVal & 0x08) >> 3;
    ads1263->mode1.sBMag        = (regVal & 0x07);
}

/*!
\brief Parsing of Mode2 Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal Mode2 Register value
*/

void ADS1263_ParseMode2Reg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->mode2.byPass       = (regVal & 0x80) >> 7;
    ads1263->mode2.gain         = (regVal & 0x70) >> 4;
    ads1263->mode2.dr           = (regVal & 0x0F);
}

/*!
\brief Parsing of Input Multiplexer Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal Input Multiplexer Register value
*/

void ADS1263_ParseInputMuxReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->inpmux.muxP        = (regVal & 0xF0) >> 4;
    ads1263->inpmux.muxN        = (regVal & 0x0F); 
}

/*!
\brief Parsing of IDAC Multiplexer Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal IDAC Multiplexer Register value
*/

void ADS1263_ParseIDACMuxReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->idacmux.mux2       = (regVal & 0xF0) >> 4;
    ads1263->idacmux.mux1       = (regVal & 0x0F);
}

/*!
\brief Parsing of IDAC Magnitude Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal IDAC Magnitude Register value
*/

void ADS1263_ParseIDACMagReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->idacmag.mag2       = (regVal & 0xF0) >> 4;
    ads1263->idacmag.mag1       = (regVal & 0x0F);
}

/*!
\brief Parsing of  Reference Multiplexer Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal  Reference Multiplexer Register value
*/

void ADS1263_ParseRefMuxReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->idacmux.rMuxP       = (regVal & 0x38) >> 3;
    ads1263->idacmux.rMuxN       = (regVal & 0x07);
}

/*!
\brief Parsing of TDAC Positive Output Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal TDAC Positive Output Register value
*/

void ADS1263_ParseTDACPReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->tdacp.outP     = (regVal & 0x80) >> 7;
    ads1263->tdacp.magP     = (regVal & 0x1F);
}

/*!
\brief Parsing of TDAC Negative Output Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal TDAC Negative Output Register value
*/

void ADS1263_ParseTDACNReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->tdacn.outN     = (regVal & 0x80) >> 7;
    ads1263->tdacn.magN     = (regVal & 0x1F);
}

/*!
\brief Parsing of GPIO Connection Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal  GPIO Connection Register value
*/

void ADS1263_ParseGpioConReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->gpiocon.con7   = (regVal & 0x80) >> 7;
    ads1263->gpiocon.con6   = (regVal & 0x40) >> 6;
    ads1263->gpiocon.con5   = (regVal & 0x20) >> 5;
    ads1263->gpiocon.con4   = (regVal & 0x10) >> 4;
    ads1263->gpiocon.con3   = (regVal & 0x08) >> 3;
    ads1263->gpiocon.con2   = (regVal & 0x04) >> 2;
    ads1263->gpiocon.con1   = (regVal & 0x02) >> 1;
    ads1263->gpiocon.con0   = (regVal & 0x01);
}

/*!
\brief Parsing of GPIO Direction Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal  GPIO Direction Register value
*/

void ADS1263_ParseGpioDirReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->gpiodir.dir7   = (regVal & 0x80) >> 7;
    ads1263->gpiodir.dir6   = (regVal & 0x40) >> 6;
    ads1263->gpiodir.dir5   = (regVal & 0x20) >> 5;
    ads1263->gpiodir.dir4   = (regVal & 0x10) >> 4;
    ads1263->gpiodir.dir3   = (regVal & 0x08) >> 3;
    ads1263->gpiodir.dir2   = (regVal & 0x04) >> 2;
    ads1263->gpiodir.dir1   = (regVal & 0x02) >> 1;
    ads1263->gpiodir.dir0   = (regVal & 0x01);
}

/*!
\brief Parsing of  GPIO Data Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal  GPIO Data Register value
*/

void ADS1263_ParseGpioDatReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->gpiodat.dat7   = (regVal & 0x80) >> 7;
    ads1263->gpiodat.dat6   = (regVal & 0x40) >> 6;
    ads1263->gpiodat.dat5   = (regVal & 0x20) >> 5;
    ads1263->gpiodat.dat4   = (regVal & 0x10) >> 4;
    ads1263->gpiodat.dat3   = (regVal & 0x08) >> 3;
    ads1263->gpiodat.dat2   = (regVal & 0x04) >> 2;
    ads1263->gpiodat.dat1   = (regVal & 0x02) >> 1;
    ads1263->gpiodat.dat0   = (regVal & 0x01);
}

/*!
\brief Parsing of  GPIO Data Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal  GPIO Data Register value
*/

void ADS1263_ParseAdc2CfgReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->adc2cfg.dr2        = (regVal & 0xC0) >> 6;
    ads1263->adc2cfg.ref2       = (regVal & 0x38) >> 3;
    ads1263->adc2cfg.gain2      = (regVal & 0x07);
}

/*!
\brief Parsing of ADC2 Input Multiplexer Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal ADC2 Input Multiplexer Register value
*/

void ADS1263_ParseAdc2MuxReg(ads1263_t * ads1263, uint8_t regVal)
{
    ads1263->adc2mux.muxP2      = (regVal & 0xF0) >> 4;
    ads1263->adc2mux.muxN2      = (regVal & 0x0F);
}

/* ---------------------------------------------------------- */



/* -------- Reading Register Data Functions Section -------- */



/*!
\brief Function for getting Device Identification Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetIdState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_ID);
    ADS1263_ParseIdReg(ads1263, buffer);
}

/*!
\brief Function for getting Power Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetPowerState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_POWER);
    ADS1263_ParsePowerReg(ads1263, buffer);
}

/*!
\brief Function for getting Interface Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetInterfaceState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_INTERFACE);
    ADS1263_ParseInterfaceReg(ads1263, buffer);
}

/*!
\brief Function for getting Mode0 Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetMode0State(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_MODE0);
    ADS1263_ParseMode0Reg(ads1263, buffer);
}

/*!
\brief Function for getting Mode1 Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetMode1State(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_MODE1);
    ADS1263_ParseMode1Reg(ads1263, buffer);
}

/*!
\brief Function for getting Mode2 Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetMode2State(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_MODE2);
    ADS1263_ParseMode2Reg(ads1263, buffer);
}

/*!
\brief Function for getting Input Multiplexer Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetInputMuxState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_INPMUX);
    ADS1263_ParseInputMuxReg(ads1263, buffer);
}

/*!
\brief Function for getting Offset Calibration Register data

Three registers compose the 24-bit offset calibration word. The
24-bit word is twos complement format, and is internally left-
shifted to align with the 32-bit conversion result. The ADC
subtracts the register value from the 32-bit conversion result
before the full-scale operation.

\param [out] ads1263 Initialized variable of type ads1263_t
\warning final word for register: LSB - OFCAL0 register data, MSB - OFCAL2 register data. Need to test
*/

void ADS1263_GetOffsetCalState(ads1263_t * ads1263)
{
    uint8_t ofcal0 = 0;
    uint8_t ofcal1 = 0;
    uint8_t ofcal2 = 0;

    ofcal0 = ADS1263_ReadReg(ADS1263_OFCAL0);
    ofcal1 = ADS1263_ReadReg(ADS1263_OFCAL1);
    ofcal2 = ADS1263_ReadReg(ADS1263_OFCAL2);

    ads1263->ofcal.ofc   = ofcal2 << 16 | ofcal1 << 8 | ofcal0;
}

/*!
\brief Function for getting Full-Scale Calibration Register data

Three 8-bit registers compose the 24-bit full scale calibration
word. The 24-bit word format is straight binary. The ADC divides
the 24-bit value by 400000h to derive the gain coefficient. The
ADC multiplies the gain coefficient by the 32-bit conversion
result after the offset operation.

\param [out] ads1263 Initialized variable of type ads1263_t
\warning final word for register: LSB - FSCAL0 register data, MSB - FSCAL2 register data. Need to test
*/

void ADS1263_GetFSCalState(ads1263_t * ads1263)
{
    uint8_t fscal0 = 0;
    uint8_t fscal1 = 0;
    uint8_t fscal2 = 0;

    fscal0 = ADS1263_ReadReg(ADS1263_FSCAL0);
    fscal1 = ADS1263_ReadReg(ADS1263_FSCAL1);
    fscal2 = ADS1263_ReadReg(ADS1263_FSCAL2);

    ads1263->fscal.fscal  = fscal2 << 16 | fscal1 << 8 | fscal0;
}

/*!
\brief Function for getting  IDAC Multiplexer Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetIDACMuxState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_IDACMUX);
    ADS1263_ParseIDACMuxReg(ads1263, buffer);
}

/*!
\brief Function for getting  IDAC Magnitude Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetIDACMagState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_IDACMAG);
    ADS1263_ParseIDACMagReg(ads1263, buffer);
}

/*!
\brief Function for getting Reference Multiplexer Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetRefMuxState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_REFMUX);
    ADS1263_ParseRefMuxReg(ads1263, buffer);
}

/*!
\brief Function for getting TDAC Positive Output Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetTDACPState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_TDACP);
    ADS1263_ParseTDACPReg(ads1263, buffer);
}

/*!
\brief Function for getting TDAC Negative Output Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetTDACNState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_TDACN);
    ADS1263_ParseTDACNReg(ads1263, buffer);
}

/*!
\brief Function for getting  GPIO Connection Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetGpioConState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_GPIOCON);
    ADS1263_ParseGpioConReg(ads1263, buffer);
}

/*!
\brief Function for getting  GPIO Direction Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetGpioDirState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_GPIODIR);
    ADS1263_ParseGpioDirReg(ads1263, buffer);
}

/*!
\brief Function for getting  GPIO Data Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetGpioDatState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_GPIODAT);
    ADS1263_ParseGpioDatReg(ads1263, buffer);
}

/*!
\brief Function for getting ADC2 Configuration Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetAdc2CfgState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_ADC2CFG);
    ADS1263_ParseAdc2CfgReg(ads1263, buffer);
}

/*!
\brief Function for getting ADC2 Input Multiplexer Register data
\param [out] ads1263 Initialized variable of type ads1263_t
*/

void ADS1263_GetAdc2MuxState(ads1263_t * ads1263)
{
    uint8_t buffer = 0;
    buffer = ADS1263_ReadReg(ADS1263_ADC2MUX);
    ADS1263_ParseAdc2MuxReg(ads1263, buffer);
}

/*!
\brief Function for getting  ADC2 Offset Calibration Registers data. 

Two registers compose the ADC2 16-bit offset calibration word. 
The 16-bit word is twos complement format and is internally left-shifted to align with the ADC2 24-bit conversion result.
The ADC subtracts the register value from the conversion result before full-scale operation.

\param [out] ads1263 Initialized variable of type ads1263_t
\warning final word for register: LSB - ADC2OFC0 register data, MSB - ADC2OFC1 register data. Need to test
*/

void ADS1263_GetAdc2OffsetCalState(ads1263_t * ads1263)
{
    uint8_t adc2ofc0 = 0;
    uint8_t adc2ofc1 = 0;

    adc2ofc0 = ADS1263_ReadReg(ADS1263_ADC2OFC0);
    adc2ofc1 = ADS1263_ReadReg(ADS1263_ADC2OFC1);

    ads1263->adc2ofc.ofc2  = adc2ofc1 << 8 | adc2ofc0;
}

/*!
\brief Function for getting  ADC2 Offset Calibration Registers data.

Two registers compose the ADC2 16-bit full scale calibration word. The 16-bit word format is straight binary.  
The ADC divides the 16-bit value by 4000h to derive the scale factor for calibration. 
After the offset operation, the ADC multiplies the scale factor by the conversion result.

\param [out] ads1263 Initialized variable of type ads1263_t
\warning final word for register: LSB - ADC2FSC0 register data, MSB - ADC2FSC1 register data. Need to test
 
*/


void ADS1263_GetAdc2FSCalState(ads1263_t * ads1263)
{
    uint8_t adc2fsc0 = 0;
    uint8_t adc2fsc1 = 0;

    adc2fsc0 = ADS1263_ReadReg(ADS1263_ADC2FSC0);
    adc2fsc1 = ADS1263_ReadReg(ADS1263_ADC2FSC1);

    ads1263->adc2fsc.fsc2  = adc2fsc1 << 8 | adc2fsc0;
}

/* --------------------------------------------------------- */
