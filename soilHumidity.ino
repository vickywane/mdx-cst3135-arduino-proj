#include <SoilHygrometer.h>

int humidityValue;
int toggleControllerValue;

const int hygrometer = A0;
const int PUMP_PIN = 8;
const int LIGHT_LED_ALERT_PIN = 9;
const int BUZZER_PIN = 4;

void setup() {
  // set BAUD rate
  Serial.begin(9600);

  // set power pins
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(LIGHT_LED_ALERT_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("SproutCare Arduino Automated Water System Project!");
}

void loop() {
  delay(1500);

  // READ SOIL HUMIDITY FROM HYGROMETER
  humidityValue = analogRead(hygrometer);
  humidityValue = constrain(humidityValue, 400, 1023);
  humidityValue = map(humidityValue, 400, 1023, 100, 0);

  // notes: higher humidity value means more water in the system... lower value means less water. 
  if (humidityValue <= 65) {
    Serial.println((String)"-> Soil humidity is low at "+humidityValue+' '+". Adding water!");
    Serial.println();

    // turn on LED_ALERT and WATERING PUMP
    digitalWrite(LIGHT_LED_ALERT_PIN, HIGH);
    digitalWrite(PUMP_PIN, HIGH); 
    digitalWrite(BUZZER_PIN, HIGH); 
  } else {
    Serial.println((String)"-> Soil humidity is adequate for plant at "+humidityValue+' '+".");

    // turn off LED_ALERT, WATERING PUMP & BUZZER
    digitalWrite(LIGHT_LED_ALERT_PIN, LOW);
    digitalWrite(PUMP_PIN, LOW);  
    digitalWrite(BUZZER_PIN, LOW);    
  }

  delay(1500);
}
