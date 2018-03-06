
#include "ads1263.h"

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

/*!
\brief Creating of Read Register Command
\param [in] regAddress Address of register to read
\param [in] numOfRegToRead Number of register to read (starting from "regAddress" register)
\param [out] readCmd[] Initialized array for read command
*/

void ADS1263_ReadRegCmd(uint8_t regAddress, uint8_t numOfRegToRead, uint8_t readCmd[])
{
    readCmd[0] =  ADS1263_READ_ADD | regAddress;
    readCmd[1] = numOfRegToRead - 1;        //according to datasheet (OPCODE2 byte for RREG Command)
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

void ADS1263_WriteRegCmd(uint8_t regAddress, uint8_t numOfRegToWrite, uint8_t data[], uint8_t writeCmd[])
{
    //len = numOfRegToWrite + 2;

    writeCmd[0] =  ADS1263_WRITE_ADD | regAddress;
    writeCmd[1] = numOfRegToWrite - 1;                  //according to datasheet (OPCODE2 byte for WREG Command)

    for(uint8_t i = 2; i <= numOfRegToWrite + 2; i++)
	{
		writeCmd[i] = data[i-2];
	}    
}


//TODO

void ADS1263_GetAllStates(ads1263_t * ads1263);
{

}

void ADS1263_GetIdState(ads1263_t * ads1263)
{
    uint8_t buffer;
    uint8_t readIdCmd[3] = {0};
    uint8_t rx[3] = {0};

    ADS1263_ReadRegCmd(ADS1263_ID, 1, readIdCmd);

	buffer = ads1263->Transfer(readIdCmd, rx, ADS1263_ONE_REG_STATE_LEN);

    //Keep the DIN (12 pin) input low after the two opcode bytes are sent

	return buffer;
}

void ADS1263_GetPowerState(ads1263_t * ads1263)
{

}

void ADS1263_GetInterfaceState(ads1263_t * ads1263);
void ADS1263_GetMode0State(ads1263_t * ads1263);
void ADS1263_GetMode1State(ads1263_t * ads1263);
void ADS1263_GetMode2State(ads1263_t * ads1263);
void ADS1263_GetInputMuxState(ads1263_t * ads1263);
void ADS1263_GetOffsetCalState(ads1263_t * ads1263);
void ADS1263_GetFSCalState(ads1263_t * ads1263);
void ADS1263_GetIDACMuxState(ads1263_t * ads1263);
void ADS1263_GetIDACMagState(ads1263_t * ads1263);
void ADS1263_GetRefMuxState(ads1263_t * ads1263);
void ADS1263_GetTDACPState(ads1263_t * ads1263);
void ADS1263_GetTDACNState(ads1263_t * ads1263);
void ADS1263_GetGpioConState(ads1263_t * ads1263);
void ADS1263_GetGpioDirState(ads1263_t * ads1263);
void ADS1263_GetGpioDatState(ads1263_t * ads1263);
void ADS1263_GetAdc2CfgState(ads1263_t * ads1263);
void ADS1263_GetAdc2MuxState(ads1263_t * ads1263);
void ADS1263_GetAdc2OffsetCalState(ads1263_t * ads1263);
void ADS1263_GetAdc2FSCalState(ads1263_t * ads1263);


void ADS1263_GetOfCalState(ads1263_t * ads1263);