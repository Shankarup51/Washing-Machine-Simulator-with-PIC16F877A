
#include"main.h"
extern unsigned char reset_flag; //reset flag can be used in this file
extern unsigned char operational_mode;
//array of strings
char *washing_program[] = {"Daily", "Heavy", "Dedicates", "Whites", "Stain Wash", "Ecocottons", "woolens", "Bedsheet", "Rinse+Dry", "Dry Wash",
    "Wash Only", "Aqua store"};
char *water_level[] = {"Auto", "Low", "Medium", "High", "Max"};
unsigned char level = 0;
unsigned char program_no = 0;
unsigned char sec, min;
unsigned int total_time,wash_time,rinse_time,spin_time,time;

void power_on_screen(void) {

    for (unsigned char i = 0; i < 16; i++) {
        clcd_putch(BLOCK, LINE1(i));
        __delay_us(500);
    }

    clcd_print("Powering on", LINE2(3));
    clcd_print("Washing Machine", LINE3(1));

    for (unsigned char i = 0; i < 16; i++) {
        clcd_putch(BLOCK, LINE4(i));
        __delay_us(500);
    }

    __delay_us(5000);
}

void washing_program_display(unsigned char key) {
    if (reset_flag == RESET_WASH_PROGRAM_SCREEN) {
        clear_screen();
        reset_flag = RESET_NOTHING;
    }

    if (key == SW4) {
        clear_screen();
        program_no++;
        if (program_no == 12) {
            program_no = 0;
        }
    }

    clcd_print("Washing Program", LINE1(0));
    clcd_putch('*', LINE2(0));

    clcd_print(washing_program[program_no], LINE2(1));
    if (program_no == 10) {
        clcd_print(washing_program[program_no + 1], LINE3(1));
        clcd_print(washing_program[0], LINE4(1));
    } else if (program_no == 11) {
        clcd_print(washing_program[0], LINE3(1));
        clcd_print(washing_program[1], LINE4(1));
    } else {
        clcd_print(washing_program[program_no + 1], LINE3(1));
        clcd_print(washing_program[program_no + 2], LINE4(1));
    }



}

void clear_screen(void) {
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_us(500);
}

void water_level_screen(unsigned char key) {
    if (reset_flag == RESET_WATER_LEVEL_SCREEN) {
        clear_screen();
        reset_flag = RESET_NOTHING;
    }

    if (key == SW4) {
        clear_screen();
        level++;
        if (level >= 5) {
            level = 0;
        }

    }

    clcd_print("Water level", LINE1(0));
    clcd_putch('*', LINE2(0));

    clcd_print(water_level[level], LINE2(1));
    clcd_print(water_level[(level + 1) % 5], LINE3(1));
    clcd_print(water_level[(level + 2) % 5], LINE4(1));
}

void run_program(unsigned char key) {
    
    door_status_check();
    
    if (reset_flag == RESET_START_SCREEN) {
        clear_screen();
        clcd_print("Prog:", LINE1(0));
        clcd_print(washing_program[program_no], LINE1(6));
        clcd_print("Time:", LINE2(0));
        //mm : ss 01 : 30
        clcd_putch(min/10+'0',LINE2(6));
        clcd_putch(min%10+'0',LINE2(7));
        
        clcd_putch(':',LINE2(8));
        clcd_putch(sec/10+'0',LINE2(9));
        clcd_putch(sec%10+'0',LINE2(10));
        reset_flag= RESET_NOTHING;
        
        __delay_ms(2000);
        
        clear_screen();
        clcd_print("Function:",LINE1(0));
        clcd_print("Time",LINE2(0));
        clcd_print("5:START 6:PAUSE",LINE3(0));
        
        total_time=time=min*60+sec;
        wash_time= (int)total_time*0.46;
        rinse_time= (int)total_time*0.12;
        spin_time= (int)total_time*0.42;
        TMR2ON =1;
        FAN=ON;
         
    }
    
    if(key == SW6){
        TMR2ON = 0;
        FAN = OFF;
        operational_mode=PAUSE; 
    }
    
    if(program_no<=7){
        if(total_time>=(time-wash_time)){
            clcd_print("wash",LINE1(10));
        }
        else if(total_time >= (time-wash_time-spin_time)){
            clcd_print("Rinse",LINE1(10));
        }
        else{
            clcd_print("Spin",LINE1(10));
        }
    }
    else if(program_no ==8){
        if(total_time>=(time-(0.40 *time))){
             clcd_print("Rinse",LINE1(10));
        }
        else{
            clcd_print("Spin",LINE1(10));
        }
    }
    else if(program_no==9){
        clcd_print("Spin",LINE1(10));
    }
    else {
        clcd_print("wash",LINE1(10));
    }
    
    clcd_putch(min/10+'0',LINE2(6));
    clcd_putch(min%10+'0',LINE2(7));
    clcd_putch(':',LINE2(8));
    clcd_putch(sec/10+'0',LINE2(9));
    clcd_putch(sec%10+'0',LINE2(10));
    
    if(min==0 && sec==0){
        BUZZER=ON;
        FAN=OFF;
        clear_screen();
        clcd_print("Prgm Completed",LINE1(0));
        clcd_print("Remove Cloths",LINE2(0));
        __delay_ms(2000);
        BUZZER =OFF;
        operational_mode = WASHING_PROGRAM_SCREEN;
        reset_flag = RESET_WASH_PROGRAM_SCREEN;
        clear_screen();
    }
}


void set_time(void) {
    switch (program_no) {
        case 0: //DAILY
        {
            switch (level) {

                case 1:
                    sec = 33;
                    break;
                case 0:

                case 2:
                    min = 0;
                    sec = 41;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 45;
                    break;
            }
        }
            break;
        case 1: //HEAVY
        {
            switch (level) {

                case 1:
                    sec = 43;
                    break;
                case 2:
                case 0:
                    min = 0;
                    sec = 50;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 57;
                    break;


            }
        }
            break;
        case 2: //dedicates
        {
            switch (level) {

                case 1:
                case 2:
                case 0:
                    min = 0;
                    sec = 26;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 31;
                    break;


            }
        }
            break;
        case 3: //white
        {
            switch (level) {

                case 1:
                case 2:
                case 0:
                case 3:
                case 4:
                    min = 1;
                    sec = 16;
                    break;


            }
        }
            break;
        case 4: //stain wash
        {
            switch (level) {

                case 1:
                case 2:
                case 0:
                case 3:
                case 4:
                    min = 1;
                    sec = 36;
                    break;


            }
        }
            break;
        case 5://ecocottons
        {
            switch (level) {

                case 1:
                case 2:
                case 0:
                    min = 0;
                    sec = 3;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 36;
                    break;
            }
        }
            break;
        case 6: //woolens
        {
            switch (level) {

                case 1:
                case 2:
                case 0:
                case 3:
                case 4:
                    min = 0;
                    sec = 29;
                    break;


            }
        }
            break;
        case 7: //bedsheet
        {
            switch (level) {

                case 1:
                    min = 0;
                    sec = 46;
                    break;
                case 2:
                case 0:
                    min = 0;
                    sec = 53;
                    break;
                case 3:
                case 4:
                    min = 1;
                    sec = 0;
                    break;


            }
        }
            break;
        case 8: //Rinse + Dry
        {
            switch (level) {

                case 1:
                    min = 0;
                    sec = 18;
                    break;
                case 2:
                case 0:
                case 3:
                case 4:
                    min = 0;
                    sec = 20;
                    break;


            }
        }
            break;
        case 9: //dry only
        {
            switch (level) {

                case 1:
                case 2:
                case 0:
                case 3:
                case 4:
                    min = 0;
                    sec = 6;
                    break;


            }
        }
            break;
        case 10: //wash only
        {
            switch (level) {

                case 1:
                    min = 0;
                    sec = 16;
                    break;
                case 2:
                case 0:
                    min = 0;
                    sec = 21;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 26;
                    break;


            }
        }
            break;
        case 11://aquastore
        {
            switch (level) {

                case 1:
                case 2:
                case 0:

                case 3:
                case 4:
                    min = 0;
                    sec = 50;
                    break;


            }
        }
            break;

    }
}

void door_status_check(void){
    if( RB0==0 ){//door is open
        FAN = OFF;
        TMR2ON=OFF;
        BUZZER = ON;
        clear_screen();
        clcd_print("Door is open",LINE1(0));
        clcd_print("Pls close door",LINE2(0));
        //wait until door is closed ,until switch is released
    
    
    while(RB0==0)
    {
        ;//WAIT UNTIL DOOR IS OPENED
    }    
    FAN=ON;
    TMR2ON = 1;
    BUZZER=OFF;
    clear_screen();
    clcd_print("Function:",LINE1(0));
    clcd_print("Time",LINE2(0));
    clcd_print("5:START 6:PAUSE",LINE3(0));
    }
}