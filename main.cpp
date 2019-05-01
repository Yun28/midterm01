#include "mbed.h"
#include "uLCD_4DGL.h"
#include <stdlib.h>

BusIn DIN(D3,D4,D5,D6,D7);
uLCD_4DGL uLCD(D1, D0, D14);


int main(void)
{
  int sum = 0;
  int i, a;
  char buffer[5];


  while (true)
  {
	a = 0;
	for (i = 3; i>=0; i--) a += DIN[i]*pow(2,i);
	uLCD.locate(0,4);
  	//uLCD.printf("0b%d\n",a);
	if (a != 0)
	{
		uLCD.locate(0,0);
		sum += a;
		itoa(sum,buffer,2);
  		uLCD.printf("0b%s\n",buffer);
		wait(1);
	}
  }
}
