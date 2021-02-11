#include <attiny.h>
#include "tinySPI.h"
#include "LoRaWAN.h"
#include "config.h"

ATTINY at = ATTINY();

#include <Arduino.h>

RFM95 rfm(DIO0_PIN, NSS_PIN);
LoRaWAN lora = LoRaWAN(rfm);

unsigned int Frame_Counter_Tx = 0x0000;
int threshold = 0;
int measure();
bool check_state();

void setup()
{
  at.setSleeptime(SLEEPTIME);
  rfm.init();
  lora.setKeys(NwkSkey, AppSkey, DevAddr);

  pinMode(IRLED_PIN, OUTPUT);
  pinMode(IRDIODE_PIN, OUTPUT);
  //pinMode(STATUSLED_PIN, OUTPUT);

  // Calibration
  delay(CALIBRATION_DELAY);
  unsigned long average = 0;
  for (int i = 0; i < CALIBRATION_CYCLES; i++)
  {
    average = average + measure();
  }
  threshold = average / CALIBRATION_CYCLES;
}

void loop()
{
  if (at.checkAction()) // every SLEEPTIME seconds
  {
    uint8_t Data_Length = 0x03;
    uint8_t Data[Data_Length];

    if (check_state() == true) {
      Data[0] = 0xff;
      //digitalWrite(STATUSLED_PIN, HIGH);
    } 
    else {
      Data[0] = 0x00;
      //digitalWrite(STATUSLED_PIN, LOW);
    }

    uint16_t vcc = at.getVoltage();
    Data[1] = (vcc >> 8) & 0xff;
    Data[2] = (vcc & 0xff);
    
    lora.Send_Data(Data, Data_Length, Frame_Counter_Tx);
    Frame_Counter_Tx++;
  }
  at.setSleeptime(SLEEPTIME);
  at.gotoSleep();
}

// Check if mailbox is full or empty
bool check_state()
{
  int average = 0;
  for (int i = 0; i < 5; i++)
  {
    average = average + measure();
    delay(200);
  }
  average = average / 5;

  float deviation = float(average) / float(threshold);
  if (deviation <= (1.00 - MIN_DEVIATION))
    return true;
  else
    return false;
}

// Get value from ir sensor
int measure()
{
  digitalWrite(IRLED_PIN, HIGH);
  digitalWrite(IRDIODE_PIN, HIGH);
  delay(10);

  int measure = analogRead(IRSENS_PIN);

  digitalWrite(IRDIODE_PIN, LOW);
  digitalWrite(IRLED_PIN, LOW);
  delay(10);

  return measure;
}

//interrupt service routine. Incrementing sleep counter
ISR(WDT_vect)
{
  at.incrCycles();
}
