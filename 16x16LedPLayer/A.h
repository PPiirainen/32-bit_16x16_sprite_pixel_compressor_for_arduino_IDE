// This is the image information for image 01. 

#pragma once
 
extern const uint32_t AColrs[5] PROGMEM = {0X000000,0XFF6600,0XFF0033,0XFFFFCC,0X000033};
extern const uint8_t Ac0[131] PROGMEM = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,40,41,42,43,44,45,46,47,48,49,50,51,52,53,62,63,64,74,75,76,77,78,79,80,81,82,83,84,85,86,87,89,90,107,108,109,110,111,112,113,114,142,143,144,160,169,175,176,181,182,183,190,191,192,193,194,200,201,202,203,206,207,208,209,210,211,212,213,214,215,217,218,220,221,222,223,224,225,229,230,234,235,236,237,238,239,240,241,242,243,247,248,253,254,255};
extern const uint8_t Ac1[51]  PROGMEM= {36,37,38,39,59,60,61,67,92,93,99,106,115,116,117,118,119,120,123,124,125,131,132,133,134,135,136,137,138,139,140,141,145,146,147,151,153,155,157,166,174,226,227,228,232,233,244,245,249,250,251};
extern const uint8_t Ac2[66] PROGMEM = {54,55,56,57,58,65,66,68,71,88,91,94,95,96,97,98,100,101,102,103,104,105,121,122,126,127,128,129,130,148,149,150,152,154,156,158,159,161,162,163,164,165,167,168,170,171,177,180,184,185,186,187,188,189,195,196,197,198,199,204,205,216,219,231,246,252};
extern const uint8_t Ac3[4] PROGMEM = {69,70,72,73};
extern const uint8_t Ac4[4]PROGMEM = {172,173,178,179};
extern const uint8_t Ac5[0] PROGMEM = {};
extern const uint8_t Ac6[0] PROGMEM = {};
extern const uint8_t Ac7[0] PROGMEM = {};
 
extern const uint8_t *Apointers[] = {Ac0, Ac1, Ac2, Ac3, Ac4, Ac5, Ac6, Ac7}; 
extern const uint8_t AColrsNum = (sizeof(AColrs) / sizeof(AColrs[0])); 
extern uint8_t Acol0 = ( sizeof(Ac0) / sizeof(Ac0[0]));
extern uint8_t Acol1 = (sizeof(Ac1) / sizeof(Ac1[0]));
extern uint8_t Acol2 = (sizeof(Ac2) / sizeof(Ac2[0]));
extern uint8_t Acol3 = (sizeof(Ac3) / sizeof(Ac3[0]));
extern uint8_t Acol4 = (sizeof(Ac4) / sizeof(Ac4[0]));
extern uint8_t Acol5 = (sizeof(Ac5) / sizeof(Ac5[0]));
extern uint8_t Acol6 = (sizeof(Ac6) / sizeof(Ac6[0]));
extern uint8_t Acol7 = (sizeof(Ac7) / sizeof(Ac7[0]));
 
extern uint16_t ANumOfDiffCol[8] = {Acol0, Acol1, Acol2, Acol3, Acol4, Acol5, Acol6, Acol7};
