
#include <stdio.h>
#include <sstream>
#include "FileManager.h"
#include "MicroBit.h"

MicroBit uBit;  // Microbit API
FileManager files(uBit);
int uBitID = 0;  // Unique microbit ID

void receiveID(MicroBitEvent) {
  ManagedString s = uBit.radio.datagram.recv();
  if (s.length() >= 5 && (s.substring(0, 3) == "KEY")) {
    uBit.display.scroll(s);
    uBit.serial.send("Received ID\n");
    uBit.serial.send(s);
    uBit.serial.send("\n");
    files.write("ID", s.substring(4, s.length() - 4));
  }
}

int main() {
  // Initialise the micro:bit runtime.
  uBit.init();
  uBit.serial.send("\nRuntime initialized\n");  // serial is limited to 21
                                                // characters at a time

  // Initialize radio
  uBit.radio.enable();
  uBit.serial.send("Radio initialized\n");

  // Attempt to read device ID from flash memory
  if (files.read("ID", uBitID) == -1) {
    uBit.serial.send("ID not found\n");
    uBit.serial.send("Waiting for ID\n");

    uBit.radio.setGroup(10);  // Group 10 for ID retrieval

    /**
     * If ID is not found on the device start listening for the ID over radio
     * messagebus.listen starts a different thread
     */
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM,
                           receiveID);

    // Stop main thread from exiting until ID is read
    while (files.read("ID", uBitID) == -1)
      uBit.display.scroll("Waiting for ID");

    // Stop listening for ID once ID is read
    uBit.messageBus.ignore(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM,
                           receiveID);
  }

  // If main exits, there may still be other fibers running or registered event
  // handlers etc. Simply release this fiber, which will mean we enter the
  // scheduler. Worse case, we then sit in the idle task forever, in a power
  // efficient sleep.
  release_fiber();
}
