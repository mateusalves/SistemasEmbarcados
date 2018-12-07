#include "gpio_sysfs.h"
#include <unistd.h>

int main()
{
        int in1=4, in2=14, in3=17, in4=18;

setGPIO_Out(in1);
setGPIO_Out(in2);
setGPIO_Out(in3);
setGPIO_Out(in4);

while(1)
{ 
GPIO_Write(in1,1);
GPIO_Write(in2,0);
GPIO_Write(in3,0);
GPIO_Write(in4,1);
usleep(10*1000);

GPIO_Write(in1,0);
GPIO_Write(in2,1);
GPIO_Write(in3,0);
GPIO_Write(in4,1);
usleep(10*1000);

GPIO_Write(in1,0);
GPIO_Write(in2,1);
GPIO_Write(in3,1);
GPIO_Write(in4,0);
usleep(10*1000);

GPIO_Write(in1,1);
GPIO_Write(in2,0);
GPIO_Write(in3,1);
GPIO_Write(in4,0);
usleep(10*1000);
}
}

