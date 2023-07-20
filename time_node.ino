#include <ESP8266WiFi.h>
const char* ssid="NETGEAR";
const char* password="sri@54321";
WiFiServer server(80);
int led1 = 13;

int enB = D1;
int led2 = 16;
int led3 = 5;
int in3 = D4;
int in4 = D5;
int an=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
int enA = D0;
int enB = D1;
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(in4, OUTPUT);

Serial.print("Connecting to.");
Serial.println(ssid);

WiFi.mode(WIFI_STA);
WiFi.begin(ssid,password);
while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print("..");}
Serial.println("Nodemcu(esp8266) is connected to the ssid");
Serial.println(WiFi.localIP());
 server.begin();
 delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
 // check for incoming client connections
  WiFiClient client;
  client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        // read the data and print it to the serial monitor
        //Serial.write(client.read());
        byte by = client.read();
        Serial.println(char(by));
        char resul = char(by);
        if(resul=='a')
        {
          digitalWrite(led1,HIGH);
          delay(1000);
          digitalWrite(led1,LOW);
          
        }
        if(resul=='b')
        {
          digitalWrite(led2,HIGH);
          delay(1000);
          digitalWrite(led2,LOW);
          
        }
        if(resul=='c')
        {
          digitalWrite(led3,HIGH);
          delay(1000);
          digitalWrite(led3,LOW);
          
        }
      }
    }
    // close the connection
    client.stop();
  }
}
