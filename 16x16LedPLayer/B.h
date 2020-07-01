#pragma once
 
extern const uint32_t BColrs[4] PROGMEM = {0X000000,0XCCCCCC,0X0066CC,0XFF0000};
extern const uint8_t Bc0[137] PROGMEM = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,27,28,29,30,31,32,33,34,40,41,42,43,44,45,46,47,48,49,50,51,52,53,62,63,64,76,77,78,79,80,81,82,83,85,87,95,96,104,106,108,109,110,111,112,113,114,115,116,127,128,129,130,138,139,141,142,143,144,145,148,158,159,160,175,176,177,180,189,190,191,192,193,202,203,205,206,207,208,209,210,211,212,213,214,217,218,219,222,223,224,225,230,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};
extern const uint8_t Bc1[74]  PROGMEM= {24,25,26,35,36,37,38,39,54,55,56,57,58,59,60,61,65,66,67,68,69,70,71,72,73,74,75,92,93,94,97,98,99,123,124,125,126,133,134,135,136,137,149,150,151,152,153,154,157,181,182,183,187,188,194,195,196,197,198,199,200,201,215,216,220,221,226,227,228,229,231,232,233,234};
extern const uint8_t Bc2[29] PROGMEM = {84,86,88,89,90,91,100,101,102,103,105,107,117,118,119,120,121,122,131,132,155,156,164,165,166,167,184,185,186};
extern const uint8_t Bc3[16] PROGMEM = {140,146,147,161,162,163,168,169,170,171,172,173,174,178,179,204};
extern const uint8_t Bc4[0]PROGMEM = {};
extern const uint8_t Bc5[0] PROGMEM = {};
extern const uint8_t Bc6[0] PROGMEM = {};
extern const uint8_t Bc7[0] PROGMEM = {};
 
extern const uint8_t *Bpointers[] = {Bc0, Bc1, Bc2, Bc3, Bc4, Bc5, Bc6, Bc7}; 
extern const uint8_t BColrsNum = (sizeof(BColrs) / sizeof(BColrs[0])); 
extern uint8_t Bcol0 = ( sizeof(Bc0) / sizeof(Bc0[0]));
extern uint8_t Bcol1 = (sizeof(Bc1) / sizeof(Bc1[0]));
extern uint8_t Bcol2 = (sizeof(Bc2) / sizeof(Bc2[0]));
extern uint8_t Bcol3 = (sizeof(Bc3) / sizeof(Bc3[0]));
extern uint8_t Bcol4 = (sizeof(Bc4) / sizeof(Bc4[0]));
extern uint8_t Bcol5 = (sizeof(Bc5) / sizeof(Bc5[0]));
extern uint8_t Bcol6 = (sizeof(Bc6) / sizeof(Bc6[0]));
extern uint8_t Bcol7 = (sizeof(Bc7) / sizeof(Bc7[0]));
 
extern uint16_t BNumOfDiffCol[8] = {Bcol0, Bcol1, Bcol2, Bcol3, Bcol4, Bcol5, Bcol6, Bcol7};
