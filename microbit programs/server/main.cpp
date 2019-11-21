#include "ButtonManager.h"
#include "Globals.h"
#include "RadioManager.h"
#include "misc.h"

MicroBit uBit;
enum states uBitState = ST_PROXIMITY;
uint8_t radioGroup = 0;

unsigned int friend_seen = 0;
const char group_name[] = "tiger";

int main() {
  // Initialize uBit framework and stack
  uBit.init();

  // Initialize button and randio listeners
  // ButtonManager::listenAllButtons(ButtonManager::proximityHandler);
  uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM,
                         RadioManager::receiveVotes);
  // Initialize Radio framework
  RadioManager::init(7);

  while (true) {
    uBit.display.scroll("Receiving votes");
    uBit.sleep(1000);
  }
}
