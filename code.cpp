// C++ code
//

#include "LiquidCrystal.h"
//#include <HttpClient.h>


LiquidCrystal lcd(10,9,7,6,5,4);

int moisture = 0;
int lightValue = 0;
int temp = 0;
int celsius = 0;
int fahrenheit = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  moisture = analogRead(A0);
  temp = analogRead(A1);
  lightValue = analogRead(A2);
  Serial.println(moisture);
  
  
  float voltage = temp * 4.68;
 voltage /= 1024.0;
 
 // now print out the temperature

 float temperatureC = (voltage - 0.5) * 100;
 Serial.print("Light: ");
Serial.println(lightValue);

lcd.setCursor(0, 0);
lcd.print("Temp:");
lcd.print(temperatureC);


lcd.setCursor(0, 1);
lcd.print("Light: ");
lcd.print(lightValue);
lcd.print("  ");

lcd.setCursor(11, 0);
lcd.print("Moisture:");
lcd.setCursor(11, 1);
lcd.print(moisture);

 
  
  
  if (moisture < 150 || temperatureC > 50) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(2, LOW);
    send_message();
  }
  if (moisture >= 150 && moisture < 400) {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  if (moisture >= 400 && moisture < 700) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  if (moisture >= 700 && moisture < 1000) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }

  temp;
  delay(10); // Delay a little bit to improve simulation performance
}


void send_message(){
  //const String account_sid = "account sid";
  //const String auth_token = "authentication token";
  //const String twilio_number = "sender no.";
  //const String destination_number = "receiver no.";
  //String message_body = "Moisture level is low or temperature is high. Please check your plants.";

  //HttpClient client;
  //client.begin("https://api.twilio.com", 443, "/2010-04-01/Accounts/" + account_sid + "/Messages.json");
  //client.addHeader("Content-Type", "application/x-www-form-urlencoded");
  //client.setAuthorization(account_sid.c_str(), auth_token.c_str());

  //String postData = "From=" + twilio_number + "&To=" + destination_number + "&Body=" + message_body;
  //client.POST(postData);

  //int statusCode = client.responseStatusCode();
  //String response = client.responseBody();
  //Serial.print("Response status code: ");
  //Serial.println(statusCode);
  //Serial.print("Response body: ");
  //Serial.println(response);
  
  
  digitalWrite(3, HIGH);

  
}