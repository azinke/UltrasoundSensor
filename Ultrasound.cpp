/**
    Powered by Smart Technology Benin
    
    @autor: AMOUSSOU Z. Kenneth
    @date: 27/08/2018
    @version: 1.0
*/
#include "Ultrasound.h"

Ultrasound::Ultrasound(uint8_t echo, uint8_t trig, unsigned long timeout){
    _echo = echo;
    _trig = trig;
    _timeout = timeout;
    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);
    digitalWrite(_trig, LOW); // Initialization
}

/**
    function: _ping
    @summary: trigger an echo from the ultrasound sensor
    @parameter: none
    @return: none
*/
unsigned int Ultrasound::_ping(){
    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);
    
    return pulseIn(_echo, HIGH, _timeout);
}

/**
    function: read
    @summary: read a response of the back wave to the sensor
    @parameter: none
    @return:
        float: the distance measured
*/
int Ultrasound::read(){
    unsigned int _buffer = 0;
    _buffer = _ping();
    if(_buffer == 0) return -1;
    else{ return _buffer/(2 * CM_CONST); }
}

/**
    function: setTimeout
    @summary: set the timeout
    @parameter:
        timeout: number of microseconds to wait for
    @return:none
*/
void Ultrasound::setTimeout(unsigned long timeout){
    _timeout = timeout;
}
