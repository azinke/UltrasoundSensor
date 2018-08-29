/**
    Powered by SmartTech Benin
    
    ---------------------------
       HC-SR04      Arduino   
    ---------------------------
        Vcc          Vcc (5V)
        Trig            12
        Echo            13
        Gnd            GND
    ---------------------------    
*/
#include <Ultrasound.h>
Ultrasound UX(12, 13);

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print("Distance: ");
  Serial.print(UX.read());
  Serial.println(" cm");
  delay(500);
}
