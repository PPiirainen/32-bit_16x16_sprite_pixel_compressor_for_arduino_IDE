

#include <avr/pgmspace.h>
#include "FastLED.h"
#include <pixeltypes.h>
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define Num_LEDs 256
#define DATA_PIN 9
#include "A.h" //  these .h files contains the compressed images. 
#include "B.h"
#include "ect.h"

CRGB leds [Num_LEDs];

void LedON( uint8_t NumOfColors, uint16_t NumOfDiffCol[], uint32_t Colrs[], uint8_t *Pointers[])
{

  for (uint8_t i = 0; i < NumOfColors; i++) // Go trough every color
  {
    for (uint16_t j = 0; j < NumOfDiffCol[i] ; j++) // Go trough every color place
    {
      uint8_t x =  pgm_read_dword(Pointers[i] + j);  //  Go trough every color place in color array.
      leds[x] = pgm_read_dword_far(&Colrs[i]);  // Write the color information to the leds
    }
  }
  FastLED.show();
}

void setup() {
  // Set the Leds information using the Fastled libary.
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, Num_LEDs).setCorrection(TypicalLEDStrip); // Ledtype
  FastLED.setBrightness(10); // overall brightness.
  }


void loop() {
  for (uint8_t Ntimes = 0; Ntimes < 8; Ntimes++) // How many times to repeat,
  {
     LedON(AColrsNum, ANumOfDiffCol, AColrs, Apointers); // the function to show image A. Copypasted from the compressor output. 
    delay(400);
  
    LedON(BColrsNum, BNumOfDiffCol, BColrs, Bpointers); // the function to show image B. Copypasted from the compressor output. 
    delay(400);
   }
  
   LedON(ectColrsNum, ectNumOfDiffCol, ectColrs, ectpointers);  // the function to show image ect. Copypasted from the compressor output. 
   delay(400);
 
}
