// Test code for Adafruit GPS modules using MTK3329/MTK3339 driver
//
// This code shows how to listen to the GPS module in an interrupt
// which allows the program to have more 'freedom' - just parse
// when a new NMEA sentence is available! Then access data when
// desired.
//
// Tested and works great with the Adafruit Ultimate GPS module
// using MTK33x9 chipset
//    ------> http://www.adafruit.com/products/746
// Pick one up today at the Adafruit electronics shop
// and help support open source hardware & software! -ada

#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
#include <autoDelay.h>
#include "globals.h"

// Connect the GPS Power pin to 5V
// Connect the GPS Ground pin to ground
// Connect the GPS TX (transmit) pin to Digital 8
// Connect the GPS RX (receive) pin to Digital 7

// you can change the pin numbers to match your wiring:
SoftwareSerial mySerial(8, 7);
Adafruit_GPS GPS(&mySerial);



// Set GPSECHO to 'false' to turn off echoing the GPS data to the Serial console
// Set to 'true' if you want to debug and listen to the raw GPS sentences
#define GPSECHO false

autoDelay autodelayGPS;                 /// sets up delay for GPS printouts

long GPSdelay = 2000;

autoDelay autodelayAtmosphere;           // Sets up delay for Atmospheric Readings


long AtmosDelay = 10000;

autoDelay autodelayLoRa;                  // Sets up Delay for LoRa transmissions

long LoRaDelay = 5000;



void setup() {


  Serial.begin(115200);                   // connect at 115200 so we can read the GPS fast enough and echo without dropping chars
  delay (1000);                                           // also spit it out

  GPSsetup();                                 // GPS Setup Scripts


}








uint32_t timer = millis();


void loop()  {                  // run over and over again


  GPSread_andParse();                // Checks for incoming GPS messages, can directly print messages, or parse them using GPS library for later recall (prefered)



  if (autodelayGPS.delayScript(GPSdelay)) {                      // approximately every 2 seconds or so, print out the current stats


    GPSserialMainPrint() ;                               //Serial Print Data
  }
}
