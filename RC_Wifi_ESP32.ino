/*How to make a wifi controlled car using Nodemcu ESP8266  and NEW Blynk App
  https://www.youtube.com/c/TechieLagan
*/

// Include the library files
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Define the motor pins
#define EN_FR 14
#define IN1_FR 12
#define IN2_FR 13
#define EN_FL 4
#define IN1_FL 2
#define IN2_FL 15

#define EN_BR 25
#define IN1_BR 26
#define IN2_BR 27
#define EN_BL 21
#define IN1_BL 19
#define IN2_BL 18


#define BLYNK_TEMPLATE_ID "TMPL68dE1gw4O"
#define BLYNK_TEMPLATE_NAME "ESP32 Car"
#define BLYNK_AUTH_TOKEN "TDmmBZMgpbnk6G1EFzzYrP6wHjbQ_8Ql"


// Variables for the Blynk widget values
int x = 50;
int y = 50;
int Speed;

// char auth[] = "TDmmBZMgpbnk6G1EFzzYrP6wHjbQ_8Ql"; //Enter your Blynk auth token
char ssid[] = "Dimasrifky"; //Enter your WIFI name
char pass[] = "dinanfamily"; //Enter your WIFI passowrd


void setup() {
  Serial.begin(9600);
  //Set the motor pins as output pins
  pinMode(EN_FR, OUTPUT);
  pinMode(EN_FL, OUTPUT);
  pinMode(EN_BR, OUTPUT);
  pinMode(EN_BL, OUTPUT);

  pinMode(IN1_FR, OUTPUT);
  pinMode(IN2_FR, OUTPUT);
  pinMode(IN1_FL, OUTPUT);
  pinMode(IN2_FL, OUTPUT);
  pinMode(IN1_BR, OUTPUT);
  pinMode(IN2_BR, OUTPUT);
  pinMode(IN1_BL, OUTPUT);
  pinMode(IN2_BL, OUTPUT);

  // Initialize the Blynk library
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
}

// Get the joystick values
BLYNK_WRITE(V0) {
  x = param[0].asInt();
}
// Get the joystick values
BLYNK_WRITE(V1) {
  y = param[0].asInt();
}
//Get the slider values
BLYNK_WRITE(V2) {
  Speed = param.asInt();
}

// Check these values using the IF condition
void smartcar() {
  if (y > 70) {
    carForward();
    Serial.println("carForward");
  } else if (y < 30) {
    carBackward();
    Serial.println("carBackward");
  } else if (x < 30) {
    carLeft();
    Serial.println("carLeft");
  } else if (x > 70) {
    carRight();
    Serial.println("carRight");
  } else if (x < 70 && x > 30 && y < 70 && y > 30) {
    carStop();
    Serial.println("carstop");
  }
}
void loop() {
  Blynk.run();// Run the blynk function
  smartcar();// Call the main function
}

/**************Motor movement functions*****************/
void carForward() {
  analogWrite(EN_FR, Speed);
  analogWrite(EN_FL, Speed);
  analogWrite(EN_BR, Speed);
  analogWrite(EN_BL, Speed);
  
  digitalWrite(IN1_FR, LOW);
  digitalWrite(IN2_FR, HIGH);
  digitalWrite(IN1_FL, LOW);
  digitalWrite(IN2_FL, HIGH);

  digitalWrite(IN1_BR, HIGH);
  digitalWrite(IN2_BR, LOW);
  digitalWrite(IN1_BL, HIGH);
  digitalWrite(IN2_BL, LOW);
}
void carBackward() {
  analogWrite(EN_FR, Speed);
  analogWrite(EN_FL, Speed); 
  analogWrite(EN_BR, Speed);
  analogWrite(EN_BL, Speed);

  digitalWrite(IN1_FR, HIGH);
  digitalWrite(IN2_FR, LOW);
  digitalWrite(IN1_FL, HIGH);
  digitalWrite(IN2_FL, LOW);

  digitalWrite(IN1_BR, LOW);
  digitalWrite(IN2_BR, HIGH);
  digitalWrite(IN1_BL, LOW);
  digitalWrite(IN2_BL, HIGH);
}
void carLeft() {
  analogWrite(EN_FR, Speed);
  analogWrite(EN_FL, Speed);
  analogWrite(EN_BR, Speed);
  analogWrite(EN_BL, Speed);

  digitalWrite(IN1_FR, LOW);
  digitalWrite(IN2_FR, HIGH);
  digitalWrite(IN1_FL, HIGH);
  digitalWrite(IN2_FL, LOW);
  
  digitalWrite(IN1_BR, HIGH);
  digitalWrite(IN2_BR, LOW);
  digitalWrite(IN1_BL, LOW);
  digitalWrite(IN2_BL, HIGH);
}
void carRight() {
  analogWrite(EN_FR, Speed);
  analogWrite(EN_FL, Speed);
  analogWrite(EN_BR, Speed);
  // analogWrite(EN_BL, Speed);

  digitalWrite(IN1_FR, HIGH);
  digitalWrite(IN2_FR, LOW);
  digitalWrite(IN1_FL, LOW);
  digitalWrite(IN2_FL, HIGH);
  
  digitalWrite(IN1_BR, LOW);
  digitalWrite(IN2_BR, HIGH);
  digitalWrite(IN1_BL, HIGH);
  digitalWrite(IN2_BL, LOW);
}
void carStop() {
  digitalWrite(IN1_FR, LOW);
  digitalWrite(IN2_FR, LOW);
  digitalWrite(IN1_FL, LOW);
  digitalWrite(IN2_FL, LOW);
  digitalWrite(IN1_BR, LOW);
  digitalWrite(IN2_BR, LOW);
  digitalWrite(IN1_BL, LOW);
  digitalWrite(IN2_BL, LOW);
}