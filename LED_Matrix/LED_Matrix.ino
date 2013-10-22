#include "Tlc5940.h"
int matrixWidth = 16;
int matrixHeight = 5;
int led[16][5] = {
	{0 , 16, 32, 48, 64},
	{1 , 17, 33, 49, 65},
	{2 , 18, 34, 50, 66},
	{3 , 19, 35, 51, 67},
	{4 , 20, 36, 52, 68},
	{5 , 21, 37, 53, 69},
	{6 , 22, 38, 54, 70},
	{7 , 23, 39, 55, 71},
	{8 , 24, 40, 56, 72},
	{9 , 25, 41, 57, 73},
	{10, 26, 42, 58, 74},
	{11, 27, 43, 59, 75},
	{12, 28, 44, 60, 76},
	{13, 29, 45, 61, 77},
	{14, 30, 46, 62, 78},
	{15, 31, 47, 63, 79}
};

int letter_A[5][5] = {
	{0,4095,4095,4095,0},
	{4095,0,0,0,4095},
	{4095,4095,4095,4095,4095},
	{4095,0,0,0,4095},
	{4095,0,0,0,4095}
};

int letter_B[5][5] = {
	{4095,4095,4095,4095,0},
	{4095,0,0,0,4095},
	{4095,4095,4095,4095,0},
	{4095,0,0,0,4095},
	{4095,4095,4095,4095,0}
};

void setup()
{
  /* Call Tlc.init() to setup the tlc.
     You can optionally pass an initial PWM value (0 - 4095) for all channels.*/
  Tlc.init();
  Tlc.clear();
  Serial.begin(9600);
}

/* This loop will create a Knight Rider-like effect if you have LEDs plugged
   into all the TLC outputs.  NUM_TLCS is defined in "tlc_config.h" in the
   library folder.  After editing tlc_config.h for your setup, delete the
   Tlc5940.o file to save the changes. */

void loop()
{
/*
  int direction = 1;
  for (int channel = 0; channel < NUM_TLCS * 16; channel += direction) {
       Tlc.clear();

    if (channel == 0) {
      direction = 1;
    } 
	else {
		Tlc.set(channel - 1, 1000);
    }
    Tlc.set(channel, 4095);
    if (channel != NUM_TLCS * 16 - 1) {
		Tlc.set(channel + 1, 1000);
    } else {
		direction = -1;
    }

    Tlc.update();
    delay(75);
  }*/
  
	for (int j = 0; j < 4; j++) { //for each column in the LED MATRIX
		for (int k = 0; k < 4; k++) { // for each LED in the column
			Tlc.set(led[k][j], letter_B[j][k]);
			Tlc.update();
			delay(1000);
		}
	}
}





