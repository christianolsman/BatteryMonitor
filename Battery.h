/***************************************************************************************************************/
/*!
*
* @file Battery.h
*
* @brief Header file for Battery class
*
* @mainpage Battery
*
* @section Sensors
*
* Class definition header for the battery class. This class is representing the state of a battery or a battery bank. 
* It is using an INA2** breakout board (e.g. INA226) comunicating over I2C,  together with an excellent INA library https://github.com/SV-Zanshin/INA/wiki. The sensor is measuring the voltage drop over a shunt resistor.
*
* @section license GNU General Public License v3.0
*
* This program is free software : you can redistribute it and/or modify it under the terms of the GNU General
* Public License as published by the Free Software Foundation, either version 3 of the License, or (at your
* option) any later version.This program is distributed in the hope that it will be useful, but WITHOUT ANY
* WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.You should have received a copy of the GNU General Public License
* along with this program(see https://github.com/SV-Zanshin/INA/blob/master/LICENSE).  If not, see
* <http://www.gnu.org/licenses/>.

*/
#ifndef Battery_h
#define Battery_h


#include "Arduino.h"
#include <N2kMessages.h>
#include <INA.h>

class Battery{
  public:
    begin(unsigned char batteryInstance,String name,double shuntResistance, double expectedMaxAmp, double capacity);
    Battery();
    
    unsigned char getInstance();
    String getName();
    double getCurrent();
    double getVoltage();
    double getTemperature();
    double getStateOfCharge();     

  private:
    unsigned char _batteryInstance;
    String _name;
    double _voltage;
    double _current;
    double _expectedMaxAmp;
    double _capacity;
    double _temperature;
    double _stateOfCharge;
    double _shuntResistance;
    INA_Class _INA;   
    void init(unsigned char batteryInstance,String name,double shuntResistance, double expectedMaxAmp, double capacity);
  
  };

#endif
