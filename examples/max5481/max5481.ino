/*****
 * max5481.ino
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
 
#include<MAX5481.h>

#define DPIN 5  // Digital Pin 5 on Arduino


MAX5481 DPOT(DPIN);


void setup()
{

  // This bit of code can be removed and is here only for
  // Demonstration purpouses.
  
  DPOT.setWiper(1000);  // Sets the wiper to 1000
  DPOT.writeWiper();    // Writes the value of the wiper to NVM
  delay(2500);
  DPOT.setWiper(250);   // Sets the wiper to 250
  delay(2500);
  DPOT.readWiper();     // Sets the wiper to the value in NVM
                        // This command should be run in setup to initialize the DPOT
                        // to it's last saved value.

}

void loop()
{


}


