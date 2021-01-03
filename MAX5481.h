/*****
 * MAX5481.h
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

#ifndef MAX5481_H_
#define MAX5481_H_

#ifdef __cplusplus

#define MAX5481_MAJOR 0
#define MAX5481_MINOR 2
#define MAX5481_PATCH 0

#include <Arduino.h>


class MAX5481
{
    public:
        MAX5481(uint8_t ss);
    
        void setWiper(unsigned int value);
        void readWiper();
        void writeWiper();
private:
        unsigned int _SS;

};


#endif
#endif

