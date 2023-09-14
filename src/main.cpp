#include <Arduino.h>
#include <Wire.h>
#include <dfRobot_ADS1115.h>

DFRobot_ADS1115 ads(&Wire);

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.print("\nBEGINNING\n");
  ads.setAddr_ADS1115(ADS1115_IIC_ADDRESS1); // 0x48
  ads.setGain(eGAIN_TWOTHIRDS);              // 2/3x gain
  ads.setMode(eMODE_SINGLE);                 // single-shot mode
  ads.setRate(eRATE_128);                    // 128SPS (default)
  ads.setOSMode(eOSMODE_SINGLE);             // Set to start a single-conversion
  ads.init();
}

void loop()
{
  Serial.println("ADS1115 Test");
  int16_t adc0;
  if (ads.checkADS1115())
  {
    adc0 = ads.readVoltage(0);
    Serial.print("A0:");
    Serial.print(adc0);
    Serial.print("mV,  ");
  }
  else
  {
    Serial.println("ADS1115 Disconnected!");
  }

  delay(1000);
}