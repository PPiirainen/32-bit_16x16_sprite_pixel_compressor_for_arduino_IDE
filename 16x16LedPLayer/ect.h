// This is the image information for image ect. 
#pragma once
 
extern const uint32_t ectColrs[5] PROGMEM = {0X000000,0XFF6600,0XFF0033,0XFFFFCC,0X000033};
extern const uint8_t ectc0[131] PROGMEM = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,40,41,42,43,44,45,46,47,48,49,50,51,52,53,62,63,64,74,75,76,77,78,79,80,81,82,83,84,85,86,87,89,90,107,108,109,110,111,112,113,114,142,143,144,160,169,175,176,181,182,183,190,191,192,193,194,200,201,202,203,206,207,208,209,210,211,212,213,214,215,217,218,220,221,222,223,224,225,229,230,234,235,236,237,238,239,240,241,242,243,247,248,253,254,255};
extern const uint8_t ectc1[51]  PROGMEM= {36,37,38,39,59,60,61,67,92,93,99,106,115,116,117,118,119,120,123,124,125,131,132,133,134,135,136,137,138,139,140,141,145,146,147,151,153,155,157,166,174,226,227,228,232,233,244,245,249,250,251};
extern const uint8_t ectc2[66] PROGMEM = {54,55,56,57,58,65,66,68,71,88,91,94,95,96,97,98,100,101,102,103,104,105,121,122,126,127,128,129,130,148,149,150,152,154,156,158,159,161,162,163,164,165,167,168,170,171,177,180,184,185,186,187,188,189,195,196,197,198,199,204,205,216,219,231,246,252};
extern const uint8_t ectc3[4] PROGMEM = {69,70,72,73};
extern const uint8_t ectc4[4]PROGMEM = {172,173,178,179};
extern const uint8_t ectc5[0] PROGMEM = {};
extern const uint8_t ectc6[0] PROGMEM = {};
extern const uint8_t ectc7[0] PROGMEM = {};
 
extern const uint8_t *ectpointers[] = {ectc0, ectc1, ectc2, ectc3, ectc4, ectc5, ectc6, ectc7}; 
extern const uint8_t ectColrsNum = (sizeof(ectColrs) / sizeof(ectColrs[0])); 
extern uint8_t ectcol0 = ( sizeof(ectc0) / sizeof(ectc0[0]));
extern uint8_t ectcol1 = (sizeof(ectc1) / sizeof(ectc1[0]));
extern uint8_t ectcol2 = (sizeof(ectc2) / sizeof(ectc2[0]));
extern uint8_t ectcol3 = (sizeof(ectc3) / sizeof(ectc3[0]));
extern uint8_t ectcol4 = (sizeof(ectc4) / sizeof(ectc4[0]));
extern uint8_t ectcol5 = (sizeof(ectc5) / sizeof(ectc5[0]));
extern uint8_t ectcol6 = (sizeof(ectc6) / sizeof(ectc6[0]));
extern uint8_t ectcol7 = (sizeof(ectc7) / sizeof(ectc7[0]));
 
extern uint16_t ectNumOfDiffCol[8] = {ectcol0, ectcol1, ectcol2, ectcol3, ectcol4, ectcol5, ectcol6, ectcol7};
