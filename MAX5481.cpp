/*****
 * MAX5481.cpp
 *
 * Created on: 11-16-2016
 *     Author: Robert F. Chapman <Robert.F.Chapman@gmail.com>
 *             Copyright (c) 2016-2019 Robert F. Chapman
 *  
 *  This file is part of MAX5481 Library for Arduino Micro(s).
 *
 *  This Library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This Library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
 */
 
#include <MAX5481.h>
#include <SPI.h>



MAX5481::MAX5481(uint8_t ss)
{
     pinMode(ss, OUTPUT);
     digitalWrite(ss, HIGH)  // Make sure CE is HIGH at instantiation

     _SS = ss;  // Set Slave Select Pin
}

void MAX5481::setWiper(unsigned int value)
{
 //local constants
 const byte WRITE_WIPER = 0x00; //command to write to the wiper register only

//  const byte COPY_EEPROM_TO_WIPER = 0x30; //command to copy the EEPROM value to the wiper register
 
 //command the new wiper setting (requires sending 3 bytes)
 digitalWrite(_SS, LOW); //set the SS pin low to select the chip
 SPI.transfer(WRITE_WIPER); //Byte 1: the command byte
 SPI.transfer(highByte(value << 6)); //Byte 2: the upper 8 bits of the 10-bit command: (D9.D8.D7.D6.D5.D4.D3.D2)
 SPI.transfer(lowByte(value << 6)); //Byte 3: the lower 2 bits of the 10-bit command, with 6 zeros to the right of them: (D1.D0.x.x.x.x.x.x)
 digitalWrite(_SS, HIGH); //set the SS pin high to "latch the data into the appropriate control register" (see datasheet pg. 14)
 delay(10); //wait a short time for the previous command to get properly set
}

void MAX5481::writeWiper()
{
 const byte WRITE_EEPROM = 0x20; //command to copy the wiper register into the non-volatile memory (EEPROM) of the digital pot
   
   digitalWrite(_SS, LOW); //set the SS pin low to select the chip
   SPI.transfer(WRITE_EEPROM); //Byte 1: the command byte
   digitalWrite(_SS, HIGH); //set the SS pin high to "latch the data into the appropriate control register" (see datasheet pg. 14 & 16)
   delay(13); //wait 13ms (see datasheet pg. 16 under the paragraph titled "Copy Wiper Register to NV Register"--they require a 12ms wait time, so I'll wait 13ms to be sure)
}
   
//copy the value stored in the EEPROM to the wiper register, to command the wiper to go there
void MAX5481::readWiper()
{
 const byte COPY_EEPROM_TO_WIPER = 0x30; //command to copy the EEPROM value to the wiper register
 digitalWrite(_SS, LOW); //set the SS pin low to select the chip
 SPI.transfer(COPY_EEPROM_TO_WIPER); //Byte 1: the command byte
 digitalWrite(_SS, HIGH); //set the SS pin high to "latch the data into the appropriate control register" (see datasheet pg. 14 & 16)
}

