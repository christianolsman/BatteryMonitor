#include "Battery.h"



/*******************************************************************************************************************
** Declare program constants, global variables and instantiate INA class                                          **
*******************************************************************************************************************/
const uint32_t SERIAL_SPEED = 115200; ///< Use fast serial speed 

Battery bat;

void setup() 
{
  Serial.begin(SERIAL_SPEED);

  bat.begin('0',"", 300, 20, 110); // instantiate a battery bank with a 300 microOhms resistor, expeced max current of 20 Ampere and battery tank capacity of 110 Amperehours
  

}
void loop() 
{
 Serial.println("Voltage: " + String(bat.getVoltage()) + " V, Current: " + String(bat.getCurrent())+"A");

  delay(5000); // Wait 5 seconds before next reading

} // method loop()
