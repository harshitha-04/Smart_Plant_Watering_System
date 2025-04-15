#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Irrigation");
  lcd.setCursor(0, 1);
  lcd.print("System is on");
  lcd.print("");
  delay(3000);
  lcd.clear();
}
 
void loop() {
  int moistureValue = analogRead(A0);
  int flowSensorValue = analogRead(A1); // Assuming water flow sensor is connected to A1
  
  Serial.print("Moisture: ");
  Serial.println(moistureValue);
  
  if (moistureValue > 950) {
    digitalWrite(2, LOW);
    lcd.setCursor(0, 0);
    lcd.print("WaterPump ON ");
    lcd.setCursor(0,0);
    Serial.print("Flow Sensor: ");
    Serial.println(flowSensorValue);
  } else {
    digitalWrite(2, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("WaterPump OFF");
  }

  if (moistureValue < 300) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture: high"); // Clear enough space for the value
  } else if (moistureValue > 300 && moistureValue < 950) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture: mid"); // Clear enough space for the value
  } else if (moistureValue > 950) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture: low"); // Clear enough space for the value
    delay(3000); // Delay to display "Moisture: LOW" message
    lcd.clear(); // Clear the screen
    lcd.setCursor(0, 0); // Set cursor to beginning of the first line
    lcd.print("Flow: "); // Print "Flow: " message
    lcd.print(flowSensorValue);
    lcd.print("mL/s"); // Display water flow sensor value
    delay(1000); // Adjust delay as needed
  }
}
