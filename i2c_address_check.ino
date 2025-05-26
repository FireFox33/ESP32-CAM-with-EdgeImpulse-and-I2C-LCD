#include <Wire.h>

#define I2C_SDA 14
#define I2C_SCL 15

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("I2C Scanner for ESP32-CAM");
  
  Wire.begin(I2C_SDA, I2C_SCL);

  byte error, address;
  int nDevices = 0;

  Serial.println("Scanning for I2C devices...");

  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  ✅");
      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0)
    Serial.println("❌ No I2C devices found\n");
  else
    Serial.println("✅ Done\n");
}

void loop() {
  // nothing to do in loop
}
