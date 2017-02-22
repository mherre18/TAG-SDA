#include <rc522_h>
//----- Inicio y Reseteo ------
RC255::RC255 (int incio, int reseteo)
{
  inicio = inicio;
  pinMode(inicio, OUTPUT); // Pin digital para activar
  digitalWrite(inicio, HIGH);

  reseteo = reseteo;
  pinMode(reseteo, OUTPUT); //Pin para resetear
  digitalWrite(reseteo, HIGH);
}
// ----- Lectura ----- (Formato de la dirección debe ser 0xxxxxx0)
byte RC255::readData(byte dir)
{
  byte valor;
  digitalWrite (inicio, LOW);
  SPI.transfer(((dir<<1)&0x7E) | 0x80);
  valor = SPI.transfer(0x00);
  digitalWrite(inicio,HIGH);
  return valor;
}
// ----- Escritura ------ (Formato de la dirección debe ser 0xxxxxx0)
void RC255::writeData(byte dir, byte valor)
{
  digitalWrite(inicio, LOW);
  SPI.transfer((dir<<1)&0x7E);
  SPI.transfer(valor);
  digitalWrite(inicio,HIGH);
}
