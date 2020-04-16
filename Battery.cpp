/*
  Battery.cpp - Library for measuring and reporting fluid level
  Created by Christian Olsman 30 of March 2020.

*/

#include "Arduino.h"
#include "Battery.h"
#include <INA.h>


/**************************************************************************/
/*!
    @brief  Empty constructor. See begin instead            
*/
/**************************************************************************/

Battery::Battery(){}

/**************************************************************************/
/*!
    @brief  Constructor to setup a battery bank
    @param    batteryInstance
              A unique id for the battery bank
    @param    name
              A name for the bank. Can be used to populate e.g. SignalK attributes
    @param    shuntResistance
              The resistance of the shunt resistor measured in microOhms
    @param    expectedMaxAmp
              Expected max current in Ampere
              
              
*/
/**************************************************************************/
Battery::begin(unsigned char batteryInstance, String name, double shuntResistance, double expectedMaxAmp, double capacity)
{
  Battery::init(batteryInstance, name, shuntResistance, expectedMaxAmp, capacity);
}



void Battery::init(unsigned char batteryInstance, String name, double shuntResistance, double expectedMaxAmp, double capacity)
{

  /*******************************************************************************************************************
  ** Declare program constants, global variables and instantiate INA class                                          **
  *******************************************************************************************************************/
 
  uint8_t        _devicesFound =      0; ///< Number of INAs found

  _shuntResistance = shuntResistance;
  _devicesFound = _INA.begin(expectedMaxAmp, _shuntResistance);
  if (_devicesFound < 1)
  {
    Serial.println("No INA devices found");
    
  }
  else
  {    
    _INA.setBusConversion(8500);            // Maximum conversion time 8.244ms
    _INA.setShuntConversion(8500);          // Maximum conversion time 8.244ms
    _INA.setAveraging(128);                 // Average each reading n-times
    _INA.setMode(INA_MODE_CONTINUOUS_BOTH); // Bus/shunt measured continuously
  }
}


/**************************************************************************/
/*!
    @brief  Function to return the current of taken out from the battery
    @return current in Ampere.
*/
/**************************************************************************/
double Battery::getCurrent()
{
  return _INA.getBusMicroAmps() / 1000.0;
}

/**************************************************************************/
/*!
    @brief  Function to return the bus voltage( betwen + and - of the battery)
    @return current in Volt.
*/
/**************************************************************************/
double Battery::getVoltage()
{
  return _INA.getBusMilliVolts() / 1000.0;
}

/**************************************************************************/
/*!
    @brief  Function to get the name of the battery bank
    @return The  name
*/
/**************************************************************************/
String Battery::getName()
{
  return _name;
}

/**************************************************************************/
/*!
    @brief  Function to get the instance of the battery bank
    @return The instance
*/
/**************************************************************************/
unsigned char Battery::getInstance()
{
  return _batteryInstance;
}
