/* 
 * File:   washing_machhine_header.h
 * Author: 91805
 *
 * Created on June 25, 2025, 1:38 PM
 */

#ifndef WASHING_MACHHINE_HEADER_H
#define	WASHING_MACHHINE_HEADER_H

void power_on_screen(void);
void clear_screen(void);
void washing_program_display(unsigned char key);
void water_level_screen(unsigned char key);
void set_time(void);
void run_program(unsigned char key);
void door_status_check(void);

#endif	/* WASHING_MACHHINE_HEADER_H */

