/*
  Configuration
*/

// Pins - important: use the "alternative pinout" for PlatformIO!
// See also: https://raw.githubusercontent.com/SpenceKonde/ATTinyCore/master/avr/extras/Pinout_x4.jpg
#define STATUSLED_PIN 2
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
  decoded.voltage = parseFloat(((bytes[0] & 0xFF) << 8) | (bytes[1] & 0xFF)) / 1000.00
  return decoded;
}
-------------------------------------- */