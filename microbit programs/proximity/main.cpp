#include "ButtonManager.h"
#include "Globals.h"
#include "RadioManager.h"
#include "misc.h"

MicroBit uBit;
enum states uBitState = ST_PROXIMITY;
uint8_t radioGroup = 0;

bool friend_seen = false;
const char group_name[] = "tiger";

int main() {
  // Initialize uBit framework and stack
  uBit.init();

  // Initialize button and randio listeners
  ButtonManager::listenAllButtons(ButtonManager::proximityHandler);
  uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM,
                         RadioManager::proximityHandler);
  // Initialize Radio framework
  RadioManager::init(7);

  while (true) {
    switch (uBitState) {
      case ST_GROUP: {
        uBit.display.printChar('0' + radioGroup);
        break;
      }
      case ST_PROXIMITY: {
        if (friend_seen) {
          drawImage(checkMark, uBit);
          friend_seen = false;
        } else
          drawImage(xMark, uBit);

        uBit.radio.datagram.send(group_name);
        break;
      }

      default:
        break;
    }
    uBit.sleep(1000);
  }
}
