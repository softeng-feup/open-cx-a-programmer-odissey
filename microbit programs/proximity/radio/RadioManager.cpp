#include "RadioManager.h"
#include <string>
#include "Globals.h"
#include "misc.h"

#define UBITSERIALDEBUG
#define MeterRSSI 63

const char group_name2[] = "tiger";

void RadioManager::proximityHandler(MicroBitEvent) {
  ManagedString s = uBit.radio.datagram.recv();
  int rssi = uBit.radio.getRSSI();

#ifdef UBITSERIALDEBUG
  uBit.serial.send("Data: ");
  uBit.serial.send(s);
  uBit.serial.send("  ");
  uBit.serial.send("Distance: ");
  uBit.serial.send((int)RadioManager::distanceEstimate(rssi, 2));
  uBit.serial.send("\n");
#endif

  if (s == "1") drawImage(xMark, uBit);

  if (s == "2") drawImage(checkMark, uBit);

  if (s == group_name2 && rssi < 60) friend_seen = true;
}

void RadioManager::init(int transmitPower) {
  uBit.radio.enable();
  uBit.radio.setGroup(radioGroup);
  uBit.radio.setTransmitPower(transmitPower);
}

float RadioManager::distanceEstimate(int rssi, int env) {
  return pow((int)10, (float)((float)(MeterRSSI - rssi) / (10 * env)));
}
