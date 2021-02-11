/*
  Configuration
*/

// Interval between measures (in seconds)
#define SLEEPTIME 300

// Time to wait after startup until sensor calibration (in milliseconds)
#define CALIBRATION_DELAY 60000L

// Number of calibration measures
// (only small delay between measures, so even for high values calibration does not take long)
#define CALIBRATION_CYCLES 50

// How much the measured value must deviate from calibrated value to be detected
// as state "true"
// e.g. 0.05 = 5% -> measured value must be at least 5% less than calibrated value
#define MIN_DEVIATION 0.01

// Pins - important: use the "alternative pinout" for PlatformIO!
// See also: https://raw.githubusercontent.com/SpenceKonde/ATTinyCore/master/avr/extras/Pinout_x4.jpg
// Be careful: In the wiring diagram from https://ct.de/y7yx MISO and MOSI pins are mistakenly swapped!
#define IRLED_PIN 3
#define IRDIODE_PIN 8
#define IRSENS_PIN A3
//#define STATUSLED_PIN 2
#define DIO0_PIN 0
#define NSS_PIN 1

// device configuration from The Things Network
// ACTIVATION METHOD: ABP, msb left
unsigned char NwkSkey[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
unsigned char AppSkey[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
unsigned char DevAddr[4] = { 0x00, 0x00, 0x00, 0x00 };

/* --------- TTN Payload decoder ---------
function Decoder(bytes, port) {
  var decoded = {};
  decoded.state = Boolean(bytes[0]);
  decoded.voltage = parseFloat(((bytes[1] & 0xFF) << 8) | (bytes[2] & 0xFF)) / 1000.00
  return decoded;
}
-------------------------------------- */