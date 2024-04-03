#include <SoilHygrometer.h>

//SoilHygrometer hygrometer(A0);

const int hygrometer = A0;
int value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("SOIL HUMIDITY CODE IS RUNNING!");

  // pinMode(6, OUTPUT);
}
 
void loop() {
  // digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  value = analogRead(hygrometer);
  value = constrain(value,400,1023);
  value = map(value,400,1023,100,0);


  Serial.println("CURRENT HUMIDITY IS: ");
  Serial.println(value);

  // add a conditional statement to toggle pump on & off. 

  // digitalWrite(6, LOW);
  // delay(300);
  // put your main code here,  to run repeatedly:
  //  hygrometer.print("Soil hygrometer value: ", 0, 100);  

  delay(1000);
}
