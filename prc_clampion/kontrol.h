// Bagian kontrol belum stabil, masih banyak revisi (menyesuaikan robot)

void kontRol() {

  //====================== (Default) =========================
  leftX = (Ps3.data.analog.stick.lx);   // Analog kiri untuk belok
  rightY = (Ps3.data.analog.stick.ry);  // Analog kanan untuk maju/mundur
  leftY = (Ps3.data.analog.stick.ly);
  rightX = (Ps3.data.analog.stick.rx);

  //====================== (Invers) =========================
  // rightY = (Ps3.data.analog.stick.lx);
  // leftX  = (Ps3.data.analog.stick.ry);
  // rightX = (Ps3.data.analog.stick.ly);
  // leftY  = (Ps3.data.analog.stick.rx);

  //==================     ANALOG kiri untuk segalanya(Default)    ==================

  //   if ((leftY < -50) && (leftX >= -64) && (leftX <= 64)) {
  //     digitalWrite(ena, 50);
  //     digitalWrite(motor1a, HIGH);
  //     digitalWrite(motor1b, LOW);
  //     digitalWrite(enb, 50);
  //     digitalWrite(motor2a, HIGH);
  //     digitalWrite(motor2b, LOW);
  //     Serial.println("nging"); Serial.print(leftY); Serial.print(leftX);
  //   }

  //   if ((leftY > 50) && (leftX >= -64) && (leftX <= 64)) {
  //     digitalWrite(ena, 50);
  //     digitalWrite(motor1a, LOW);
  //     digitalWrite(motor1b, HIGH);
  //     digitalWrite(enb, 50);
  //     digitalWrite(motor2a, LOW);
  //     digitalWrite(motor2b, HIGH);
  //     Serial.println("ngung"); Serial.print(leftY); Serial.print(leftX);

  //   }

  //   if ((leftX > 50) && (leftY >= -64) && (leftY <= 64)) {
  //     digitalWrite(ena, 50);
  //     digitalWrite(motor1a, HIGH);
  //     digitalWrite(motor1b, LOW);
  //     digitalWrite(enb, 50);
  //     digitalWrite(motor2a, HIGH);
  //     digitalWrite(motor2b, LOW);
  //     Serial.println("ngong"); Serial.print(leftY); Serial.print(leftX);

  //   }

  //   if ((leftX < -50) && (leftY >= -64) && (leftY <= 64)) {
  //     digitalWrite(ena, 50);
  //     digitalWrite(motor1a, HIGH);
  //     digitalWrite(motor1b, LOW);
  //     digitalWrite(enb, 50);
  //     digitalWrite(motor2a, HIGH);
  //     digitalWrite(motor2b, LOW);
  //     Serial.println("ngeng"); Serial.print(leftY); Serial.print(leftX);

  //   }

  //==================== Analog kiri berbelok, kanan maju/mundur(Modded) ==========================//

  // Variabel kecepatan motor
  int speedLeft = 0;
  int speedRight = 0;

  // -----------------  Analog Yumna -----------------
  if (rightY > 10) {  // Maju
    speedLeft -= map(rightY, -128, 0, 255, 0);
    speedRight -= map(rightY, -128, 0, 255, 0);
  } else if (rightY < -10) {  // Mundur
    speedLeft += map(rightY, 0, 127, 0, 255);
    speedRight += map(rightY, 0, 127, 0, 255);
  }

  // ----------------- Analog Syimal -----------------
  if (leftX > 10) {  // Belok Kanan
    speedLeft += map(leftX, 0, 127, 0, 255);
    speedRight -= map(leftX, 0, 127, 0, 255);
  } else if (leftX < -10) {  // Belok Kiri
    speedLeft -= map(leftX, -128, 0, 255, 0);
    speedRight += map(leftX, -128, 0, 255, 0);
  }

  // ----------------- Kecepatan Motor beh -----------------
  speedLeft = constrain(speedLeft, -255, 255);
  speedRight = constrain(speedRight, -255, 255);

  // Motor syimall
  if (speedLeft > 0) {
    analogWrite(ena, speedLeft);
    digitalWrite(motor1a, HIGH);
    digitalWrite(motor1b, LOW);
  } else if (speedLeft < 0) {
    analogWrite(ena, -speedLeft);
    digitalWrite(motor1a, LOW);
    digitalWrite(motor1b, HIGH);
  } else {
    analogWrite(ena, 0);
  }

  // Motor yumna
  if (speedRight > 0) {
    analogWrite(enb, speedRight);
    digitalWrite(motor2a, HIGH);
    digitalWrite(motor2b, LOW);
  } else if (speedRight < 0) {
    analogWrite(enb, -speedRight);
    digitalWrite(motor2a, LOW);
    digitalWrite(motor2b, HIGH);
  } else {
    analogWrite(enb, 0);
  }

  // Debug
  Serial.print(" LeftX: ");
  Serial.print(leftX);
  Serial.print(" RightY: ");
  Serial.println(rightY);
  Serial.print(" SpeedLeft: ");
  Serial.print(speedLeft);
  Serial.print(" SpeedRight: ");
  Serial.println(speedRight);


  //    else if ((rightY < -50) && (rightX >= -64) && (rightX <= 64)) {
  //      servoPosition = 0; // Gerakkan servo ke 90 derajat
  //      myServo.write(servoPosition);
  //      Serial.println("BERGERAK 0 DERAJAT");
  //    }
  //
  //    else if ((rightY > 50) && (rightX >= -64) && (rightX <= 64)) {
  //      servoPosition = 90; // Gerakkan servo ke 90 derajat
  //      myServo.write(servoPosition);
  //      Serial.println("BERGERAK 90 DERAJAT");
  //    }
  //
  //    else if ((rightX > 50) && (rightY >= -64) && (rightY <= 64)) {
  //      servoPosition = 180; // Gerakkan servo ke 90 derajat
  //      myServo.write(servoPosition);
  //      Serial.println("BERGERAK 180 DERAJAT");
  //    }
  //
  //    else if ((rightX < -50) && (rightY >= -64) && (rightY <= 64)) {
  //      servoPosition = 90; // Gerakkan servo ke 90 derajat
  //      myServo.write(servoPosition);
  //      Serial.println("BERGERAK 90 DERAJAT");
  //    }
  //======================== BATAS ANALOG =================================

  //=========================== UTILITY =================================
  // Cek jika tombol CROSS ditekan
  if (Ps3.data.button.cross) {
    digitalWrite(ena, 0);
    digitalWrite(motor1a, LOW);
    digitalWrite(motor1b, LOW);
    digitalWrite(enb, 0);
    digitalWrite(motor2a, LOW);
    digitalWrite(motor2b, LOW);
    Serial.println("PING");
  }

  // Cek jika tombol CIRCLE ditekan
  if (Ps3.data.button.circle) {
    digitalWrite(ena, 50);
    digitalWrite(motor1a, HIGH);
    digitalWrite(motor1b, LOW);
    digitalWrite(enb, 50);
    digitalWrite(motor2a, HIGH);
    digitalWrite(motor2b, LOW);
    Serial.println("BULET");
  }

  // Cek jika tombol TRIANGLE ditekan
  if (Ps3.data.button.triangle) {
    digitalWrite(ena, 50);
    digitalWrite(motor1a, LOW);
    digitalWrite(motor1b, HIGH);
    digitalWrite(enb, 50);
    digitalWrite(motor2a, LOW);
    digitalWrite(motor2b, HIGH);
    Serial.println("Segitiga");
  }

  // Cek jika tombol SQUARE ditekan
  if (Ps3.data.button.square) {
    digitalWrite(ena, 50);
    digitalWrite(motor1a, LOW);
    digitalWrite(motor1b, HIGH);
    digitalWrite(enb, 50);
    digitalWrite(motor2a, LOW);
    digitalWrite(motor2b, HIGH);
    Serial.println("Kotak");
  }

  // ------------------ Gripper Naik/Turun -------------------
  if (Ps3.event.button_down.r2) {
    // Mengangkat gripper dengan pengecekan batas maksimum
    if (posisiServo1 < 180) {
      posisiServo1 += STEP;                        // Tambah 5 derajat (naik)
      if (posisiServo1 > 180) posisiServo1 = 180;  // Pastikan tidak lebih dari 180
      servo1.write(posisiServo1);                  // Gerakkan servo sesuai posisi
      Serial.println("Gripper Naik (R2)");
      delay(50);  // Delay kecil agar gerakan lebih halus
    }
  }

  if (Ps3.event.button_down.l2) {
    // Menurunkan gripper dengan pengecekan batas minimum
    if (posisiServo1 > 0) {
      posisiServo1 -= STEP;                    // Kurangi 5 derajat (turun)
      if (posisiServo1 < 0) posisiServo1 = 0;  // Pastikan tidak kurang dari 0
      servo1.write(posisiServo1);              // Gerakkan servo sesuai posisi
      Serial.println("Gripper Turun (L2)");
      delay(50);  // Delay kecil agar gerakan lebih halus
    }
  }
  // // SERVO
  // if (Ps3.event.button_down.r2) {
  //   // Bergerak maju dengan pengecekan batas maksimum
  //   if (posisiServo1 < 180) {
  //     posisiServo1 += STEP;                        // Tambah 5 derajat
  //     if (posisiServo1 > 180) posisiServo1 = 180;  // Pastikan tidak lebih dari 180
  //     servo1.write(posisiServo1);
  //     Serial.println("R2");
  //     delay(50);  // Delay kecil agar gerakan lebih halus
  //   }
  // }

  // if (Ps3.event.button_down.r1) {
  //   // Bergerak mundur dengan pengecekan batas minimum
  //   if (posisiServo1 > 0) {
  //     posisiServo1 -= STEP;                    // Kurang 5 derajat
  //     if (posisiServo1 < 0) posisiServo1 = 0;  // Pastikan tidak kurang dari 0
  //     servo1.write(posisiServo1);
  //     Serial.println("R1");
  //     delay(50);  // Delay kecil agar gerakan lebih halus
  //   }
  // }

  if (Ps3.event.button_down.r1) {
    // Bergerak maju dengan pengecekan batas maksimum
    if (posisiServo2 < 180) {
      posisiServo2 += STEP;                        // Tambah 5 derajat
      if (posisiServo2 > 180) posisiServo2 = 180;  // Pastikan tidak lebih dari 180
      servo2.write(posisiServo2);
      Serial.println("R1");
      delay(50);
    }
  }

  if (Ps3.event.button_down.l1) {
    // Bergerak mundur dengan pengecekan batas minimum
    if (posisiServo2 > 0) {
      posisiServo2 -= STEP;                    // Kurang 5 derajat
      if (posisiServo2 < 0) posisiServo2 = 0;  // Pastikan tidak kurang dari 0
      servo2.write(posisiServo2);
      Serial.println("L1");
      delay(50);
    }
  }

  if (Ps3.event.button_down.up) {
    // Bergerak maju dengan pengecekan batas maksimum
    if (posisiServo3 < 180) {
      posisiServo3 += STEP;                        // Tambah 5 derajat
      if (posisiServo3 > 180) posisiServo3 = 180;  // Pastikan tidak lebih dari 180
      servo2.write(posisiServo3);
      Serial.println("UP");
      delay(50);  // Delay kecil agar gerakan lebih halus
    }
  }

  if (Ps3.event.button_down.down) {
    // Bergerak mundur dengan pengecekan batas minimum
    if (posisiServo3 > 0) {
      posisiServo3 -= STEP;                    // Kurang 5 derajat
      if (posisiServo3 < 0) posisiServo3 = 0;  // Pastikan tidak kurang dari 0
      servo2.write(posisiServo3);
      Serial.println("DOWN");
      delay(50);  // Delay kecil agar gerakan lebih halus
    }
  }



  // else {
  //   digitalWrite(ena, 0);
  //   digitalWrite(motor1a, LOW);
  //   digitalWrite(motor1b, LOW);
  //   digitalWrite(enb, 0);
  //   digitalWrite(motor2a, LOW);
  //   digitalWrite(motor2b, LOW);
  //   Serial.println("BERHENTIII");
  // }
}
