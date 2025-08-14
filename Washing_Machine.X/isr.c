#include <xc.h>

extern unsigned char sec,min;
unsigned int count ;
void __interrupt() isr(void)
{
    if(TMR2IF)
    {
        if( ++count == 20000) // 250 , 200ns 8 bit timer for 1 sec
        {
            if(sec != 0)
            {
                sec--;
            }
            else if(sec == 0 && min != 0)
            {
                min--;
                sec = 60;
            }
            count = 0;
            
            PORTD = ~PORTD;
        }
        
        TMR2IF = 0; // clear interrupt flag 
        
    }
    
    
}

