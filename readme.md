# Ultrasound Sensor HC-SR04

This ultrasound sensor is commonly found in many robotic projects. Cheap, it 
could be found quite easily on the market. This library as many others is 
willing to help you deal with it.

## How does it work?

This popular ultrasonic distance sensor provides stable and accurate distance 
measurements from 2cm to 450cm. It has a focus of `less than 15 degrees` and an 
`accuracy of about 2mm`.

This sensor uses ultrasonic sound to measure distance just like bats and 
dolphins do. Ultrasonic sound has such a high pitch that humans cannot hear it. 

This particular sensor sends out an ultrasonic sound that has a frequency of 
about 40 kHz. The sensor has `two main parts`: *a transducer* that creates an 
ultrasonic sound and another that listens for its echo. 
To use this sensor to measure distance, a microcontroller must measure the 
amount of time it takes for the ultrasonic sound to travel back and forth.

## Pinout

| HC-SR04 | Arduino |
|:-------:|:-------:|
Vcc | Vcc
Trig | Arduino digital pin
Echo | Arduino digital pin
Gnd | Gnd

## Usage

It is possible to use the default pinout (`echo: 2`, `trig: 3`) on the library 
by instanciating the sensor with no addtional arguments.

```C++
    Ultrasound mySensor;
```

However, you could define the specific pin you want to use. Checkout the code 
below for an example.

```C++
    uint8_t echoPin = 12;
    uint8_t rigPin = 13;
    Ultrasound mySensor(echoPin, trigPin);
```

It is possible to set the time frame in which we expect to get an `echo` back 
to the sensor. This avoid waiting too long without response. So the timeout can 
be set with this library as follow:

```C++
    unsigned long timeout = 20000000UL; // 20ms
    mySensor.setTimeout(timeout);
```

To read the distance measured by the sensor, use the `read()` method.

```C++
    unsigned int measure = mySensor.read();
```

