#ifndef RC522_h
#define RC522_h

#include <Arduino.h>
#include <SPI.h>
//#include <SS.h>

#define LargoMax 16
// ---- Opciones de comunicación -----
#define MI_OK                 0
#define MI_NO                 1
#define MI_ERR                2
// ----- Comandos -----
#define ComReg                0x01
#define PCD_RESETPHASE        0x0F// Reajustar

class RC522
{
public:
  RC522(uint8_t inicio, uint8_t reseteo);
  RC522(uint8_t inicio,uint8_t reseteo, uint8_t mosiPin, uint8_t misoPin);
	bool HayTarjeta();
	uint8_t LeerSerialTarjeta();

  //void inicio();
  void reset();
  void write522(uint8_t dir, uint8_t val);
  uint8_t Pregunta1(uint8_t Modo, uint8_t *TipoTag);
  uint8_t anticoli(uint8_t * serNum);
  uint8_t readRC522(uint8_t addr);



	//void setBitMask(uint8_t reg, uint8_t mask);
	//void clearBitMask(uint8_t reg, uint8_t mask);
	//void calculateCRC(uint8_t *pIndata, uint8_t len, uint8_t *pOutData);
  //uint8_t MFRC522ToCard(uint8_t command, uint8_t *sendData, uint8_t sendLen, uint8_t *backData, uint16_t *backLen);
	//uint8_t auth(uint8_t authMode, uint8_t BlockAddr, uint8_t *Sectorkey, uint8_t *serNum);
	//uint8_t read(uint8_t blockAddr, uint8_t *recvData);
	//uint8_t write(uint8_t blockAddr, uint8_t *writeData);
	//void halt();
	//uint8_t serNum[5];       // Constante para guardar el numero de serie leido.
	//uint8_t AserNum[5];      // Constante para guardar el numero d serie de la secion actual.
  //uint8_t PICCDetection();
  //uint8_t PICCReading();
  //uint8_t Return();

private:
uint8_t _ElegirPin;
uint8_t _reseteo;
uint8_t _mosiPin;
uint8_t _misoPin;
//uint8_t _clockPin;

  };

#endif
