# MAX5481

Arduino Library for the Maxim MAX5481-5484 Digital Potentiometer

This library implements functions to control the MAX5481 digital Potentiometer(s) using SPI

See the Maxim Integrated datasheet for details [MAX5481](https://datasheets.maximintegrated.com/en/ds/MAX5481-MAX5484.pdf)

___

Class and Methods

---

## Constructor
### MAX5481(int SSPIN)
##### Description
Instantiation of the Digital Potentiometer sets the Slave Select Pin. The Slave select is pulled high
##### Syntax
`MAX5481 myDpot(SSPIN);`
##### Parameters
SSPIN: A required parameter, number of the Slave Select Pin
##### Return
None
##### Example
```C++
// Instantiation of MAX5481 Digital Potentiometer
MAX5481 myDpot(11);
```

## Methods
### setWiper(int value)
##### Description
Sets the wiper to the given value
##### Syntax
`setWiper(value);`
##### Parameters
value: a value between 0-1024
##### Return
None
##### Example
```C++
// Sets the Digital Potentiometer wiper to a given value
setWiper(wiper_value);
```

### writeWiper(int value)
##### Description
Writes the current value of the wiper to NVM (Non-Volitle Memory)
##### Syntax
`writeWiper();`
##### Parameters
None
##### Return
None
##### Example
```C++
// Sets the Digital Potentiometer wiper to a given value
writeWiper();
```

### readWiper(int value)
##### Description
Moves the value in NVM into the wiper
##### Syntax
`readWiper();`
##### Parameters
None
##### Return
None
##### Example
```C++
// Moves the value in NMV into the wiper
readWiper();
```

### Attibutions
This library was inspired by previous works done by Gabriel Staples and Others.

[http://forum.arduino.cc/index.php?topic=242376.0](http://forum.arduino.cc/index.php?topic=242376.0)

[http://www.electricrcaircraftguy.com/2016/11/MAX5481-DigitalPotentiometer.html](http://www.electricrcaircraftguy.com/2016/11/MAX5481-DigitalPotentiometer.html)

___

If you like and use this library please consider making a small donation using [PayPal](https://www.paypal.me/robertfchapman/5USD)
