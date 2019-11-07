#include <stdio.h>
#include "FileManager.h"
#include "MicroBit.h"

MicroBit uBit;  // Microbit API
FileManager files(uBit);
int uBitID = 0;  // Unique microbit ID
#define checkMark 0b0000000001000101010001000
#define xMark 0b1000101010001000101010001

void onButtonA(MicroBitEvent) { drawImage(checkMark); }

void onButtonB(MicroBitEvent) { drawImage(xMark); }

void drawImage(const uint32_t &image) {
  uint32_t mask = 0x01000000;
  for (int i = 0; i < 25; ++i) {
    uBit.display.image.setPixelValue(i % 5, i / 5, (bool)(image & mask) * 255);
    mask >>= 1;
  }
}

int main() {
  // Initialise the micro:bit runtime.
  uBit.init();
  uBit.serial.send("\nRuntime initialized\n");

  uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_EVT_ANY, onButtonA);
  uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_EVT_ANY, onButtonB);

  while (true) {
    uBit.sleep(100);
  };

  release_fiber();
}
