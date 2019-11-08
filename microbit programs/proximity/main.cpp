#include "misc.h"

#define checkMark 0b0000000001000101010001000
#define xMark 0b1000101010001000101010001

MicroBit uBit;

bool friend_seen = false;
bool broadcast = true;

const char group_name[] = "tiger";

void onButtonA(MicroBitEvent) { uBit.radio.datagram.send("1"); }

void onButtonB(MicroBitEvent) { uBit.radio.datagram.send("2"); }

void onButtonAB(MicroBitEvent) {
  broadcast ^= true;
  uBit.display.print("!");
}

void onData(MicroBitEvent) {
  ManagedString s = uBit.radio.datagram.recv();
  int rssi = uBit.radio.getRSSI();

  if (s == "1") drawImage(xMark, uBit);

  if (s == "2") drawImage(checkMark, uBit);

  if (s == group_name && rssi < 60) friend_seen = true;
}

int main() {
  uBit.init();

  uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_EVT_ANY, onButtonA);
  uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_EVT_ANY, onButtonB);
  uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_EVT_ANY, onButtonAB);

  uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM,
                         onData);

  uBit.radio.enable();

  while (true) {
    if (friend_seen) {
      drawImage(checkMark, uBit);
      friend_seen = false;
      uBit.sleep(1000);
    } else
      drawImage(xMark, uBit);

    if (broadcast) uBit.radio.datagram.send(group_name);

    uBit.sleep(1000);
  }
}
