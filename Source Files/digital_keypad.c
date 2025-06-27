#include <xc.h>
#include "digital_keypad.h"

void init_digital_keypad(void)
{
    /* Set Keypad Port as input */
    KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES;
}

unsigned char read_digital_keypad(unsigned char mode)
{
    static char once = 1;
    static int longpressed=1;
    unsigned char key= KEYPAD_PORT &INPUT_LINES;
    static unsigned char pre_key;
    
    if(key!=ALL_RELEASED && once){
        once =0;
        pre_key = key;
        longpressed = 0;
        
        
    }
    else if(key == ALL_RELEASED && !once){
        once =1;
        if(longpressed<15)
            return pre_key;
    }
    else if(!once && longpressed <= 15)
        longpressed++;
    else if(!once && longpressed == 16 && key == SW4){
        longpressed++;
        return LPSW4;
    }
    
    return ALL_RELEASED;
}
//    
//    if (mode == LEVEL_DETECTION)
//    {
//        return KEYPAD_PORT & INPUT_LINES;
//    }
//    else
//    {
//        if (((KEYPAD_PORT & INPUT_LINES) != ALL_RELEASED) && once)
//        {
//            once = 0;
//            
//            return KEYPAD_PORT & INPUT_LINES;
//        }
//        else if ((KEYPAD_PORT & INPUT_LINES) == ALL_RELEASED)
//        {
//            once = 1;
//        }
//    }
//    
//    return ALL_RELEASED;

