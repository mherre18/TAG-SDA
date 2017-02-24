#include <RC522.h>

//----- Definicion Inicio y Reseteo ------
RC522::RC522 (uint8_t incio, uint8_t reseteo)
{
  inicio = inicio;
  pinMode(inicio, OUTPUT); // Pin digital para activar
  digitalWrite(inicio, HIGH);

  reseteo = reseteo;
  pinMode(reseteo, OUTPUT); //Pin para resetear
  digitalWrite(reseteo, HIGH);
}

// ---- Definición de pines -----
RC522::RC522 (uint8_t inicio, uint8_t reseteo, uint8_t mosiPin, uint8_t misoPin)
{
  inicio = inicio;
  reseteo = reseteo;
  misoPin = misoPin;
  mosiPin = mosiPin;
  //_clockPin = clockPin;

  pinMode(inicio, OUTPUT);
  digitalWrite(inicio, LOW);
  pinMode(reseteo,OUTPUT;)
  digitalWrite(reseteo,HIGH);

  //pinMode(_clockPin, OUTPUT);
  pinMode(mosiPin, OUTPUT);
  pinMode(misoPin, INPUT);
}

// ----- Reseteo -----

void RC522::reset()
{
	write522(ComReg, PCD_RESETPHASE);
}

// ----- Lectura 1 (Si hay tarjeta en el campo)-----

bool RC522::HayTarjeta()
{
uint8_t Estado;
uint8_t Est[LargoMax];

 Estado = Pregunta1(Est);
   if (Estado == MI_OK)
  {
   return true;
  }
 else
 {
   return false;
 }
}

// ----- Leectura 2 - Lectura del serial -----

bool RC522::LeerSerialTarjeta()
{
  uint8_t Estado;
  uint8_t Est[LargoMax];

Estado = anticoli(Est); // Para evitar colisión, devolver el número de la serie (4 bytes)
memcpy(serNum, Est, 5); // Generar copia binaria de los datos

 if (Estado == MI_OK)
 {
   return true;
 }
 else
 {
   return false;
 }

}

// ----- Escritura 1 ----

void RC522::write522(uint8_t addr, uint8_t val)
{
    digitalWrite(inicio, LOW);
    SPI.transfer((addr<<1)&0x7E); // Formato direccion X000000X
    SPI.transfer(val);
    digitalWrite(inicio, HIGH);
}

// ----- Lectura 3 (Byte de registro) -----
uint8_t RC522::readRC522(uint8_t addr)
{
    uint8_t val;
    digitalWrite(inicio, LOW);
    SPI.transfer(((addr<<1)&0x7E) | 0x80);
    val = SPI.transfer(0x00);
    digitalWrite(inicio, HIGH);
    return val;	// Retorna byte de lectura
}
