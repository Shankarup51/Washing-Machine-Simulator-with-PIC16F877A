#include <xc.h>
#include "timers.h"

void init_timer2(void)
{
    //timer2 control register
    
   
    
    
    // turn on the timer2
    TMR2ON = 0;
    
    
   
    // enable timer2 interrupt
    TMR2IE = 1;
    
    
   
    
    //no of ticks in PR2
    PR2 = 250;
    
    
}
