#include <attiny.h>
#include "tinySPI.h"
#include "LoRaWAN.h"
#include "config.h"

ATTINY at = ATTINY();

#include <Arduino.h>

RFM95 rfm(DIO0_PIN, NSS_PIN);

LoRaWAN lora = LoRaWAN(rfm);
unsigned int Frame_Counter_Tx = 0x0000;

void send();

void setup()
{
  at.setSleeptime(32);
  rfm.init();
  lora.setKeys(NwkSkey, AppSkey, DevAddr);
  pinMode(STATUSLED_PIN, OUTPUT);
  send();
}

void loop()
{
  if (at.checkAction()) send();
  at.setSleeptime(32);
  at.gotoSleep();
}

//interrupt service routine. Incrementing sleep counter
ISR(WDT_vect)
{
  at.incrCycles();
}

void send () {  
    digitalWrite(STATUSLED_PIN, HIGH);

    uint8_t Data_Length = 0x02;
    uint8_t Data[Data_Length];

    // measure voltage and send via LoRaWAN (2 byte)
    uint16_t vcc = at.getVoltage();
    Data[0] = (vcc >> 8) & 0xff;
    Data[1] = (vcc & 0xff);

    lora.Send_Data(Data, Data_Length, Frame_Counter_Tx);
    Frame_Counter_Tx++;

  
    digitalWrite(STATUSLED_PIN, LOW);
}