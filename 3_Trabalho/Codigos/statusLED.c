#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

const int LED_RED = 30;
const int LED_GREEN = 6;

int main(int argc, char **argv) //1 libera e 0 nega
{
	wiringPiSetup();

	pinMode(LED_RED, OUTPUT);
	pinMode(LED_GREEN, OUTPUT);

	int status;

	status = atoi(argv[1]);

	if (status)
	{
		digitalWrite(LED_GREEN, HIGH);
		delay(3000); //3 segundos
		digitalWrite(LED_GREEN, LOW);
	}
	else
	{
		digitalWrite(LED_RED, HIGH);
		delay(3000); //3 segundos
		digitalWrite(LED_RED, LOW);
	}

	return 0;
}
