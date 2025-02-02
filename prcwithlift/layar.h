void setup_oled() {
  u8g2.begin();
  //u8g2.setContrast(50);
}

void setup_lcd(){
  lcd.init();                   
  lcd.init();
  lcd.backlight();
  lcd.setCursor((16 - 10) / 2, 0);
  lcd.print("Clampion !");
  // lcd.setCursor((16 - 16) / 2, 1);
  // lcd.print("Towards the Champion");
}

void tampilkanGambar(const int* gambar){
  u8g2.clearBuffer();
  u8g2.drawBitmap(0, 0, (128/8), 64, gambar); 
 
  u8g2.sendBuffer();                             
  delay(100);
}

void tampilkanTeks(const char* teks, int x, int y, const uint8_t* font) {
  u8g2.clearBuffer();  // Bersihkan layar
  u8g2.setFont(font);  // Pilih font
  u8g2.drawStr(x, y, teks);  // Gambar teks
  u8g2.sendBuffer();  // Tampilkan ke layar
}

void tampilkanTeksTengah(const char* teks, const uint8_t* font) {
  u8g2.setFont(font);
  int textWidth = u8g2.getUTF8Width(teks);
  int x = (128 - textWidth) / 2;
  int y = (64 / 2) + 5; // Posisikan di tengah secara vertikal
  tampilkanTeks(teks, x, y, font);
}