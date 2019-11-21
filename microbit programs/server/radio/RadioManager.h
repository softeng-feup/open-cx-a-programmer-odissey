#pragma once
#include "MicroBit.h"

namespace RadioManager {
void init(int transmitPower);
void proximityHandler(MicroBitEvent);
void sendVote(const char *vote);
void receiveVotes(MicroBitEvent);
}  // namespace RadioManager
