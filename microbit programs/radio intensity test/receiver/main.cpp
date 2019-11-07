#include "MicroBit.h"

MicroBit uBit;

int radioIntensity = 999;

void onData(MicroBitEvent) {
  ManagedString s = uBit.radio.datagram.recv();
  radioIntensity = uBit.radio.getRSSI();
}

int main() {
  // Initialise the micro:bit runtime.
  uBit.init();

  uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM,
                         onData);

  uBit.radio.enable();

  while (true) {
    uBit.display.scroll(ManagedString(radioIntensity));
    uBit.sleep(100);
  }
  release_fiber();
}
