#include <Wire.h>
// #include <RTClib.h>
#include <DmxMaster.h>

// RTC_DS1307 rtc;

// https://github.com/PaulStoffregen/Time

int toggle, dmxChannel;
// int hour, minute, number, digit;

const byte numMap[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  Serial.begin(9600);
  DmxMaster.maxChannel(24);

  // if (!rtc.begin()) {
  //   Serial.println("Couldn't find RTC");
  //   Serial.flush();
  //   while (1) delay(10);
  // }

  // if (! rtc.isrunning()) {
  //   Serial.println("RTC is NOT running, let's set the time!");
  //   // When time needs to be set on a new device, or after a power loss, the
  //   // following line sets the RTC to the date & time this sketch was compiled
  //   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //   // This line sets the RTC with an explicit date & time, for example to set
  //   // January 21, 2014 at 3am you would call:
  //   // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  // }
}

void loop() {
  // DateTime now = rtc.now();
  // int hour = now.hour();
  // int minute = now.minute();

  // Send DMX commands for each segment
  // for (int digit = 0; digit < 4; digit++) {
  //
  //   if (digit == 0) {
  //     number = hour / 10
  //   } else if (digit == 1) {
  //     number = hour % 10
  //   } else if (digit == 2) {
  //     number = minute / 10
  //   } else {
  //     number = minute % 10
  //   }
  //
  //   for (int segment = 0; segment < 7; segment++) {
  //     int dmxChannel = digit * 7 + segment + 1;  // DMX channels start from 1
  //     DmxMaster.write(dmxChannel, numMap[number][segment]);
  //   }
  // }

  for (int segment = 0; segment < 7; segment++) {
    DmxMaster.write(segment + 1, numMap[toggle][segment] == 1 ? 50 : 0);
  }
  Serial.println(toggle);
  toggle++;
  delay(1000);
  
  if (toggle > 9) {
    toggle = 0;
  }
}
