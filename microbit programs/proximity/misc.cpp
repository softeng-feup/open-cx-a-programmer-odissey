#include "misc.h"

#define imageMask 0x01000000

void drawImage(const uint32_t &image, const MicroBit &uBit) {
  for (int i = 0; i < 25; ++i)
    uBit.display.image.setPixelValue(i % 5, i / 5, (bool)(image & (imageMask >> i) * 255);
}
