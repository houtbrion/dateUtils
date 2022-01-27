#include <NTPClient.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xF0, 0x0D };

#include "dateUtils.h"

EthernetUDP ntpUDP;

#define OFFSET 32400 //(9*60*60) UTCとJSTの差分

NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", OFFSET, 60000);

void setup(){
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("setup start.");

  Ethernet.begin(mac);
  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();
  unsigned long unixTime=timeClient.getEpochTime();

  date_t date;
  Serial.println(unixTime);
  unixTimeToDate(unixTime, &date);
  Serial.println(dateToUnixTime(&date));
  Serial.println();

  Serial.println(dateString(unixTime));
  Serial.println(dateString(unixTime,FORMAT_DATE));
  Serial.println(dateString(unixTime,FORMAT_WDAY));
  Serial.println(dateString(unixTime,FORMAT_TIME));
  Serial.println();

  delay(1000);
}
