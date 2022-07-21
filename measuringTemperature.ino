#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN 4    // 온습도센서를 4번에 연결
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial mySerial(2,3);   // 블루투스 모듈 txd는 2번에, rxd는 3번에 연결


void setup() {
  mySerial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();  // 온도

  mySerial.print(temp);   // 온도값 출력
  delay(1000);
}
