#include<reg52.h>       
                            
sbit LED_1 = P0^1;
sbit LED_2 = P0^2;

void Delay(void);           

void main (void)
{
    while(1)                
    {
        LED1=0;  
	LED2=0;
        Delay();
        LED1=1; 
	LED2=1;
        Delay();
    }
}

void Delay(void)
{
    int j;
    int i;
    for(i=0;i<100;i++)
    {
        for(j=0;j<1000;j++)
        {
        }
    }
}