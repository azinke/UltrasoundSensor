/**
    Powered by Smart Technology Benin
    
    @autor: AMOUSSOU Z. Kenneth
    @date: 27/08/2018
    @version: 1.0
*/
#ifndef H_ULTRASOUND
#define H_ULTRASOUND

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

//#define SOUND_SPEED 340     // Sound speed: ~340m/s
#define CM_CONST 29         // Centimeter

#define ECHO 2
#define TRIG 3

class Ultrasound{
    public:
        // timeout: in microseconds - 10s of timeout set by default
        Ultrasound(uint8_t echo = ECHO, uint8_t trig = TRIG, unsigned long timeout = 10000000UL);
        int read();
        void setTimeout(unsigned long timeout);
    private:
        unsigned int _ping();
        uint8_t _echo;
        uint8_t _trig;
        unsigned int _timeout;
};

#endif
