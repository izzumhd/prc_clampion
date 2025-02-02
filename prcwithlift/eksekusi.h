void onConnect() {
  Serial.println("Connected.");
}

void setup_sedoyo(){
  Ps3.attach(kontRol);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("90:34:fc:d9:59:11");
  
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
  Serial.println("Ready.");

  servo1.attach(19);
  servo2.attach(18);
  servo3.attach(17);
  setup_oled();
}

void loop_sedoyo(){
  if (!Ps3.isConnected()) {
    unsigned long millisSaiki = millis();

    if (millisSaiki - millisAwal >= selangg) {
      millisAwal = millisSaiki; 
      Serial.println("rung nyambung bos");
      tampilkanTeksTengah("rung nyambung bos", u8g2_font_10x20_tf);
    }
    return;
  }
  
  else {
    oled_tampilan();
  }

  //lcd.scrollDisplayLeft();

  // Update PS3 controller
  // Ps3.update();
}
