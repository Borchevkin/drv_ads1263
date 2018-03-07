#ifndef INC_ADS1263_H_
#define INC_ADS1263_H_


#include <stdint.h>

/* ____________________ DEFINE Section ____________________ */

/* Registers */
#define ADS1263_ID              (0x00)
#define ADS1263_POWER           (0x01)
#define ADS1263_INTERFACE       (0x02)
#define ADS1263_MODE0           (0x03)
#define ADS1263_MODE1           (0x04)
#define ADS1263_MODE2           (0x05)
#define ADS1263_INPMUX          (0x06)
#define ADS1263_OFCAL0          (0x07)
#define ADS1263_OFCAL1          (0x08)
#define ADS1263_OFCAL2          (0x09)
#define ADS1263_FSCAL0          (0x0A)
#define ADS1263_FSCAL1          (0x0B)
#define ADS1263_FSCAL2          (0x0C)
#define ADS1263_IDACMUX         (0x0D)
#define ADS1263_IDACMAG         (0x0E)
#define ADS1263_REFMUX          (0x0F)
#define ADS1263_TDACP           (0x10)
#define ADS1263_TDACN           (0x11)
#define ADS1263_GPIOCON         (0x12)
#define ADS1263_GPIODIR         (0x13)
#define ADS1263_GPIODAT         (0x14)
#define ADS1263_ADC2CFG         (0x15)
#define ADS1263_ADC2MUX         (0x16)
#define ADS1263_ADC2OFC0        (0x17)
#define ADS1263_ADC2OFC1        (0x18)
#define ADS1263_ADC2FSC0        (0x19)
#define ADS1263_ADC2FSC1        (0x1A)

/* Commands */
#define ADS1263_NOP_CMD         (0x00)
#define ADS1263_RESET_CMD       (0x06)      //Or 0x07
#define ADS1263_START1_CMD      (0x08)      //Or 0x09
#define ADS1263_STOP1_CMD       (0x0A)      //Or 0x0B
#define ADS1263_START2_CMD      (0x0C)      //Or 0x0D
#define ADS1263_STOP2_CMD       (0x0E)      //Or 0x0F
#define ADS1263_RDATA1_CMD      (0x12)      //Or 0x13
#define ADS1263_RDATA2_CMD      (0x14)      //Or 0x15
#define ADS1263_SYOCAL1_CMD     (0x16)
#define ADS1263_SYGCAL1_CMD     (0x17)
#define ADS1263_SFOCAL1_CMD     (0x19)
#define ADS1263_SYOCAL2_CMD     (0x1B)
#define ADS1263_SYGCAL2_CMD     (0x1C)
#define ADS1263_SFOCAL2_CMD     (0x1E)


/* Const */
#define ADS1263_READ_ADD        (0x20)
#define ADS1263_WRITE_ADD       (0x40)

#define ADS1263_HIGH            (1)
#define ADS1263_LOW             (0)



/* ________________________________________________________ */





/* ____________________ Types  Section ____________________ */

typedef struct {
	uint8_t devId;
	uint8_t revId;
} id_t;

typedef struct {
	uint8_t reset;
    uint8_t vBias;
    uint8_t intRef;
} power_t;

typedef struct {
    uint8_t timeOut;
    uint8_t status;
    uint8_t crc;
}   interface_t;

typedef struct {
    uint8_t refRev;
    uint8_t runMode;
    uint8_t chop;
    uint8_t delay;
} mode0_t;

typedef struct {
    uint8_t filter;
    uint8_t sBADC;
    uint8_t sBPol;
    uint8_t sBMag;
} mode1_t;

typedef struct {
    uint8_t byPass;
    uint8_t gain;
    uint8_t dr;
} mode2_t;

typedef struct {
    uint8_t muxP;
    uint8_t muxN;
} inpmux_t;

typedef struct {
    uint32_t ofc;
} ofcal_t;

typedef struct {
    uint32_t fscal;
} fscal_t;

typedef struct {
    uint8_t mux1;
    uint8_t mux2;
} idacmux_t;

typedef struct {
    uint8_t mag1;
    uint8_t mag2;
} idacmag_t;

typedef struct {
    uint8_t rMuxP;
    uint8_t rMuxN;
} refmux_t;

typedef struct {
    uint8_t outP;
    uint8_t magP;
} tdacp_t;

typedef struct {
    uint8_t outN;
    uint8_t magN;
} tdacn_t;

typedef struct {
    uint8_t con0;
    uint8_t con1;
    uint8_t con2;
    uint8_t con3;
    uint8_t con4;
    uint8_t con5;
    uint8_t con6;
    uint8_t con7;
} gpiocon_t;

typedef struct {
    uint8_t dir0;
    uint8_t dir1;
    uint8_t dir2;
    uint8_t dir3;
    uint8_t dir4;
    uint8_t dir5;
    uint8_t dir6;
    uint8_t dir7;
} gpiodir_t;

typedef struct {
    uint8_t dat0;
    uint8_t dat2;
    uint8_t dat3;
    uint8_t dat4;
    uint8_t dat5;
    uint8_t dat6;
    uint8_t dat7;
} gpiodat_t;

typedef struct {
    uint8_t dr2;
    uint8_t ref2;
    uint8_t gain2;
} adc2cfg_t;

typedef struct {
    uint8_t muxP2;
    uint8_t muxN2;
} adc2mux_t;

typedef struct {
    uint16_t ofc2;
} adc2ofc_t;

typedef struct {
    uint16_t fsc2;
} adc2fsc_t;



typedef struct {
    void (*Transfer)(uint8_t tx[], uint8_t rx[], uint8_t len);
    void (*CS_Out)(uint8_t out);

    id_t id;
    power_t power;
    interface_t interface;
    mode0_t mode0_;
    mode1_t mode1;
    mode2_t mode2;
    inpmux_t inpmux;
    ofcal_t ofcal;
    fscal_t fscal;
    idacmux_t idacmux;
    idacmag_t idacmag;
    refmux_t refmux;
    tdacp_t tdacp;
    tdacn_t tdacn;
    gpiocon_t gpiocon;
    gpiodir_t gpiodir;
    gpiodat_t gpiodat;
    adc2cfg_t adc2cfg;
    adc2mux_t adc2mux;
    adc2ofc_t adc2ofc;
    adc2fsc_t adc2fsc;
} ads1263_t;

/* ________________________________________________________ */





/* __________________ Prototypes Section __________________ */

uint8_t ADS1263_ReadReg(uint8_t regAddress);
void ADS1263_WriteReg(uint8_t regAddress, uint8_t data);

void ADS1263_GetReadRegsCmd(uint8_t regAddress, uint8_t numOfRegToRead, uint8_t readCmd[]);
void ADS1263_GetWriteRegsCmd(uint8_t regAddress, uint8_t numOfRegToWrite, uint8_t data[], uint8_t writeCmd[]);

/*          Reading Register Data Functions Section          */

void ADS1263_GetIdState(ads1263_t * ads1263);
void ADS1263_GetPowerState(ads1263_t * ads1263);
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

/* --------------------------------------------------------- */



/*                 Parsing Functions Section                 */

void ADS1263_ParseIdReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParsePowerReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseInterfaceReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseMode0Reg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseMode1Reg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseMode2Reg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseInputMuxReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseIDACMuxReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseIDACMagReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseRefMuxReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseTDACPReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseTDACNReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseGpioConReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseGpioDirReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseGpioDatReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseAdc2CfgReg(ads1263_t * ads1263, uint8_t regVal);
void ADS1263_ParseAdc2MuxReg(ads1263_t * ads1263, uint8_t regVal);

/* -------------------------------------------------------- */


/* ________________________________________________________ */


#endif /* INC_ADS1263_H_ */