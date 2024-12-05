
#include <ELECHOUSE_CC1101_SRC_DRV.h>

void setup() {

  Serial.begin(9600);
  if (ELECHOUSE_cc1101.getCC1101()) {  // Check the CC1101 Spi connection.
    Serial.println("Connection OK");
  } else {
    Serial.println("Connection Error");
  }

  ELECHOUSE_cc1101.Init();            // must be set to initialize the cc1101!
  ELECHOUSE_cc1101.setModulation(1);  // set modulation mode. 0 = 2-FSK, 1 = GFSK, 2 = ASK/OOK, 3 = 4-FSK, 4 = MSK.
  ELECHOUSE_cc1101.setRxBW(200);      // Set the Receive Bandwidth in kHz. Value from 58.03 to 812.50. Default is 812.50 kHz.
  ELECHOUSE_cc1101.setDRate(200);     // Set the Data Rate in kBaud. Value from 0.02 to 1621.83. Default is 99.97 kBaud!
  ELECHOUSE_cc1101.SpiWriteReg(CC1101_IOCFG2, 0x0D);  //serial clock.synchronous to the data in synchronous serial mode
  ELECHOUSE_cc1101.SpiStrobe(CC1101_SRX);  //RX mode
}

void loop() {
}
