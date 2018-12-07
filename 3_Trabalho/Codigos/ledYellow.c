#include <wiringPi.h>
#include <stdio.h>

const int LED_YELLOW = 26;

int main()
{
	wiringPiSetup();

	pinMode(LED_YELLOW, OUTPUT);




}
