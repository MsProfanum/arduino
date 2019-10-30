#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 20, 4);
DHT dht(DHTPIN, DHTTYPE);

void setup() { 
  lcd.init();
  dht.begin();
  lcd.backlight();
  lcd.print("Temp:  Humidity:");
}

void loop() {
  delay(500);
  lcd.setCursor(0, 1);
  float h = dht.readHumidity();
  float f = dht.readTemperature();

  if (isnan(h) || isnan(f)) {
    lcd.print("ERROR");
    return;
  }

  lcd.print(f);
  lcd.print("C");
  lcd.setCursor(7,1);
  lcd.print(h);
  lcd.print("%");  
}
