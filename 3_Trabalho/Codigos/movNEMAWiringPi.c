#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

int  in1 = 7;
int  in2 = 15;
int  in3 = 0;
int  in4 = 1;

//const int calPasso = 18;
const int calPasso = 25;
const int del = 5;

int passo = 0;

int  b1 = 11;
int  b2 = 12;



int movimenta(int passos, int direcao){

	if (direcao == 1 )
	{
		for (int i=0; i<passos; i++)
		{
			switch(passo)
			{
			case 4:
			case 0:
          		  digitalWrite(in1, HIGH);
               	          digitalWrite(in2, LOW);
                          digitalWrite(in3, LOW);
                          digitalWrite(in4, HIGH);
                          delay(del);
		          passo = 1;
			  break;
		        case 1:
 			  digitalWrite(in1, LOW);
                  	  digitalWrite(in2, HIGH);
                  	  digitalWrite(in3, LOW);
                          digitalWrite(in4, HIGH);
                	  delay(del);
			  passo = 2;
	 		  break;
			case 2:
			  digitalWrite(in1, LOW);
                  	  digitalWrite(in2, HIGH);
                  	  digitalWrite(in3, HIGH);
                          digitalWrite(in4, LOW);
                	  delay(del);
			  passo = 3;
		          break;
		        case 3:
                          digitalWrite(in1, HIGH);
                  	  digitalWrite(in2, LOW);
                  	  digitalWrite(in3, HIGH);
                          digitalWrite(in4, LOW);
                	  delay(del);
			  passo = 4;
			  break;
			}
		}
	}
	else if (direcao == 2)
	{
		for (int i=0; i<passos; i++)
		{
			switch(passo)
			{
			case 0:
			case 1:
          		  digitalWrite(in1, HIGH);
               	          digitalWrite(in2, LOW);
                          digitalWrite(in3, HIGH);
                          digitalWrite(in4, LOW);
                          delay(del);
		          passo = 4;
			  break;
			case 2:
			  digitalWrite(in1, HIGH);
                  	  digitalWrite(in2, LOW);
                  	  digitalWrite(in3, LOW);
                          digitalWrite(in4, HIGH);
                	  delay(del);
			  passo = 1;
		          break;
		        case 3:
                          digitalWrite(in1, LOW);
                  	  digitalWrite(in2, HIGH);
                  	  digitalWrite(in3, LOW);
                          digitalWrite(in4, HIGH);
                 	  delay(del);
			  passo = 2;
			  break;
		        case 4:
 			  digitalWrite(in1, LOW);
                  	  digitalWrite(in2, HIGH);
                  	  digitalWrite(in3, HIGH);
                          digitalWrite(in4, LOW);
                	  delay(del);
			  passo = 3;
	 		  break;
			}
		}

	}
         return passo;
}


int main(int argc, char **argv)
{

 	if(wiringPiSetup()==-1)
	{	puts("Deu ruim no setup");
		return -1;
	}

        pinMode(in1, OUTPUT);
        pinMode(in2, OUTPUT);
        pinMode(in3, OUTPUT);
        pinMode(in4, OUTPUT);
        pinMode(b1, INPUT);
        pinMode(b2, INPUT);

	int counter = atoi(argv[1]);

	 while(counter!=0)
        {
		 passo  = movimenta(calPasso,1);
	   	 counter--;
        }

}




