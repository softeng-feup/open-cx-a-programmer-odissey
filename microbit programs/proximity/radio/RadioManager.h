#pragma once
#include "MicroBit.h"

namespace RadioManager {
void init(int transmitPower);
void proximityHandler(MicroBitEvent);
float distanceEstimate(int rssi, int env);

}  // namespace RadioManager
