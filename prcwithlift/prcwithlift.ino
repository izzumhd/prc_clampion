#include <Ps3Controller.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>
#include <variabel.h>
#include <layar.h>
#include <kontrol.h>
#include <eksekusi.h>

void setup() {
  Serial.begin(115200);
  setup_sedoyo();
}

void loop() {
  loop_sedoyo();
}
