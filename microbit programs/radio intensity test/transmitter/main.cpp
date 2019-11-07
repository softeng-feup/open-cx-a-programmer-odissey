#include "MicroBit.h"

MicroBit uBit;

int radioIntensity = 999;

int main() {
  // Initialise the micro:bit runtime.
  uBit.init();

  uBit.radio.enable();

  while (true) {
    uBit.display.scroll(ManagedString("Sending radio packets"));
    uBit.radio.datagram.send("2");
    uBit.sleep(500);
  }
  release_fiber();
}
