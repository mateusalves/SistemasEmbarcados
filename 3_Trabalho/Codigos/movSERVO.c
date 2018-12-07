#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int in5 = 5;

void servo0graus()
{
	digitalWrite(in5, HIGH);
	delayMicroseconds(600);
	digitalWrite(in5, LOW);
	for (int i=0; i<32;i++) delayMicroseconds(600);
}

void servoPIgraus()
{
	digitalWrite(in5, HIGH);
	delayMicroseconds(600);
	digitalWrite(in5, LOW);
	for (int i=0; i<26;i++) delayMicroseconds(600);
}


void servo90graus()
{
	digitalWrite(in5, HIGH);
	delayMicroseconds(1500);
	digitalWrite(in5, LOW);
	for (int i=0; i<12;i++) delayMicroseconds(1500);
}
void servo180graus()
{
	digitalWrite(in5, HIGH);
	delayMicroseconds(2400);
	digitalWrite(in5, LOW);
	for (int i=0; i<7;i++) delayMicroseconds(2400);
}

int main()
{
	if(wiringPiSetup()==-1)
	{
		puts("Deu ruim no setup");
		return -1;
	}

	pinMode(in5, OUTPUT);

		for( int i=0; i<100;i++) servo180graus();
		delay(500);
		for(int  i=0; i<100;i++) servoPIgraus();
	return 0;
}
