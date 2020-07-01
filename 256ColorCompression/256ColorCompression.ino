
#include <avr/pgmspace.h>
// I would like to use some thing like std:vector libary to use dynamic arrays. But because we always will have small SRAM the amount of arrays.

#define highWord(W) ((W) >> 16)
#define midWord(W)  ((W) >> 8)
#define lowWord(w)  ((w) & 0xff)

char ImageName[] = "Name"; // Put your frame name here.



const uint32_t Image[256] PROGMEM  = { // This array is for the image in 24-bit HEX format.Replace these with your own image. 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 0x000000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 0x000000, 
0x000000, 0x000000, 0xff0000, 0xff0000, 0xff0000, 0xe0ddff, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xe0ddff, 0xff0000, 0x000000, 0x000000, 
0x000000, 0x000000, 0x000000, 0xe0ddff, 0xe0ddff, 0xe0ddff, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xe0ddff, 0xe0ddff, 0xe0ddff, 0xff0000, 0xff0000, 0x000000, 
0x000000, 0x000000, 0xff0000, 0xff0000, 0xe0ddff, 0xe0ddff, 0x2121ff, 0x2121ff, 0xff0000, 0xff0000, 0xe0ddff, 0xe0ddff, 0x2121ff, 0x2121ff, 0x000000, 0x000000, 
0x000000, 0x000000, 0xff0000, 0x2121ff, 0x2121ff, 0xe0ddff, 0xe0ddff, 0xff0000, 0xff0000, 0x2121ff, 0x2121ff, 0xe0ddff, 0xe0ddff, 0xff0000, 0xff0000, 0xff0000, 
0x000000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xe0ddff, 0xe0ddff, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xe0ddff, 0xe0ddff, 0xff0000, 0xff0000, 0x000000, 
0x000000, 0x000000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0x000000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 
0x000000, 0x000000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 
0x000000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 
0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0xff0000, 0xff0000, 0x000000, 0xff0000, 0xff0000, 
0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 
0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000
};

uint8_t color0[256] = {0}; // This holds the found color places. only 8 bit. smaller than 24 bit for the color information.


uint16_t ImPix = (sizeof(Image) / sizeof(Image[0])); // How many pixels in image.

void setup() {
  
    delay(1000);
    Serial.begin(9600);
   while (!Serial)
   {
     // wait for //Serial port to connect. Needed for native USB port only. Rest of the code does not execute unless serial opened. 
   }

  // Calculatin how many different colors there are. 
  uint8_t res = 0;
   for (uint16_t i = 0; i < ImPix; i++) // 
  {
    uint8_t j = 0;
    for (j = 0; j < i; j++)
    {
      if (pgm_read_dword_far(&Image[i]) == pgm_read_dword_far(&Image[j])) {
        break;
      }
    }
    // If not seen earlier,then calcultate it
    if (i == j) {
      res++;
    }
  }
 
  // Calculate  and print different colors.   

  uint64_t Colors[res] = {0};//Array size of found number of colors.

  uint8_t index = 0;
  for (uint16_t i = 0; i < ImPix; i++) // n.
  {
    uint8_t j = 0;
    for (j = 1 ; j < i; j++)

      if (pgm_read_dword_far(&Image[i]) == pgm_read_dword_far(&Image[j])) {
        break;
      }
    // If not seen earlier,then calcultate it
    if (i == j) {
      Colors[index] = pgm_read_dword_far(&Image[i]);
      index++;
    }
   }
  Serial.println(F("#pragma once")); Serial.println(F(" "));
  Serial.print(F("extern const uint32_t ")); Serial.print(ImageName); Serial.print(F("Colrs[")); Serial.print(res); Serial.print(F("] PROGMEM = {"));
  uint8_t loWord, mdWord, hiWord;
  for (uint8_t i = 0; i < res; i++) // This mess is needed because Serial.print(value,HEX) omits the leading zeroes. This is the easiest way to include them into print.
  {
    loWord = lowWord(Colors[i]);
    mdWord = midWord(Colors[i]);
    hiWord = highWord(Colors[i]);
    Serial.print(F("0X"));
    char hiWordString[24] = {0};              // first 8 bits
    sprintf(hiWordString, "%02X", hiWord);
    Serial.print(hiWordString);

    char mdWordString[32] = {0};              // second 8 bits
    sprintf(mdWordString, "%02X", mdWord);
    Serial.print(mdWordString);

    char lowWordString[32] = {0};            // last 8 bits
    sprintf(lowWordString, "%02X", loWord);
    Serial.print(lowWordString);
    if (i < res - 1) // we dont need F(",") for the last place.
    {
      Serial.print(F(","));
    }
  }
  Serial.println(F("};"));

 
 for (uint8_t i = 0; i < res; i++) // Calculatin number of different colors.
      {
    uint8_t ColorPlace = 0;   
   
    for (uint16_t j = 0; j < ImPix; j++)  
    {
     
        if (pgm_read_dword_far(&Image[j]) == Colors[i])
        {
          color0[ColorPlace] = j;
          ColorPlace++;
        }
    }
   
     // This prints the colors arrays.
     Serial.print(F("extern const uint8_t "));  Serial.print(ImageName); 
  Serial.print(F("c"));Serial.print(i); Serial.print(F("[")); Serial.print(ColorPlace); Serial.print(F("] PROGMEM = {"));
  
  for (uint8_t n = 0; n < ColorPlace; n++)
  {
    Serial.print(color0[n]); 
    if (n < ColorPlace - 1) // we dont need F(",") for the last place.
    {
      Serial.print(F(","));
    }
  }
   Serial.println(F("};"));
  }
  Serial.println(F(" ")); 
 
 Serial.print(F("extern const uint8_t *")); Serial.print(ImageName); Serial.print(F("pointers[] = {")); 
 for (uint8_t i = 0; i < res; i++)
 {

 // These prints the array sizes. This way is more flexible if needed for bigger images in the future.
 
Serial.print(ImageName);Serial.print(F("c"));Serial.print(i);
 if (i < res- 1) // we dont need F(",") for the last place.
    {
      Serial.print(F(", "));
    } 

 }
Serial.print(F("};"));


 Serial.println(F(" "));
Serial.print(F("extern const uint8_t ")); Serial.print(ImageName); Serial.print(F("ColrsNum = (sizeof("));Serial.print(ImageName);Serial.print(F("Colrs) / sizeof("));Serial.print(ImageName); Serial.print(F("Colrs[0]));"));
Serial.println(F(" "));

for (uint8_t i = 0; i < res; i++){
Serial.print(F("extern uint8_t ")); Serial.print(ImageName); Serial.print(F("col"));Serial.print(i);Serial.print(F(" = ( sizeof(")); Serial.print(ImageName); Serial.print(F("c"));Serial.print(i);Serial.print(F(") / sizeof(")); Serial.print(ImageName); Serial.print(F("c"));Serial.print(i);Serial.println(F("[0]));")); // montako paikkaa varilla0. tata kaytetaan varin paikalleen laittemissessa.

  }

  Serial.println(F(" "));


Serial.println(F(" "));
Serial.print(F("extern uint16_t ")); Serial.print(ImageName);Serial.print(F("NumOfDiffCol["));Serial.print(res);Serial.print(F("] = {")); 
for (uint8_t i = 0; i < res; i++)
{
Serial.print(ImageName); Serial.print(F("col"));Serial.print(i);
 if (i < res- 1) // we dont need F(",") for the last place.
    {
      Serial.print(F(", "));
    } 
}
 Serial.println(F("};"));
//This prints the function to use in the code.  
Serial.print(F("LedON(")); Serial.print(ImageName); Serial.print(F("ColrsNum, ")); Serial.print(ImageName); Serial.print(F("NumOfDiffCol, ")); Serial.print(ImageName); Serial.print(F("Colrs, ")); Serial.print(ImageName); Serial.println(F("pointers);"));

}

void loop() {
  //Chill. Prints the .h file once. 
}
