/*
 * Copyright (c) 2014, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== empty.c ========
 */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>



/* BIOS Header files */
#include <ti/sysbios/BIOS.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
// #include <ti/drivers/I2C.h>
// #include <ti/drivers/SDSPI.h>#include <stdlib.h>
// #include <ti/drivers/SPI.h>
// #include <ti/drivers/UART.h>
// #include <ti/drivers/Watchdog.h>

/* Board Header file */
#include "Board.h"
#include <string.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>

#include <stdbool.h>

#define LCD_RS 4
#define LCD_RW 5
#define LCD_E 6
#define LCD_DB0 11
#define LCD_DB1 12
#define LCD_DB2 13
#define LCD_DB3 14
#define LCD_DB4 7
#define LCD_DB5 8
#define LCD_DB6 9
#define LCD_DB7 10

volatile char buff1[17];
volatile char buff2[17];

void LCD_send(unsigned char RS, unsigned char data);
/*
 *  ======== heartBeatFxn ========
 *  Toggle the Board_LED0. The Task_sleep is determined by arg0 which
 *  is configured for the heartBeat Task instance.
 */
Void heartBeatFxn(UArg arg0, UArg arg1)
{
	int i = 0;
    while (1) {
        Task_sleep(100);
        GPIO_toggle(Board_LED0);

        int minutes = i/(1000*60);
        buff1[15] = i%10 + '0';
        buff1[14] = '.';
        buff1[13] = (i%(60*1000))%10 + '0';
        buff1[12] = (i%(60*1000)/10)%10 + '0';

        //minutes
        buff1[11] = minutes%10 + '0';
        buff1[10] = (minutes/10)%10 + '0';

        i++;
    }
}

void LCD_init()
{
	//function set (8 bit mode)
	LCD_send(0, 0x38);
	//Turn LCD on
	LCD_send(0, 0x0C);
	//Clear display
	LCD_send(0, 0x01);
	//Task_sleep(2);

	//Entry set mode
	LCD_send(0, 0x06);

	//cursor display shift
	LCD_send(0, 0x14);

	//Set DDRAM
	LCD_send(0, 0x80);

	LCD_send(1, 'H');
	LCD_send(1, 'I');
}

void LCD_send(unsigned char RS, unsigned char data)
{
	//code
	//code
	//code
	volatile int i = 0;
	GPIO_write(LCD_E, 0);
	GPIO_write(LCD_RW, 0);
	GPIO_write(LCD_RS, RS);
	GPIO_write(LCD_E, 1);
	GPIO_write(LCD_DB0, data & 0x1 ? 1 : 0);
	GPIO_write(LCD_DB1, data & 0x2 ? 1 : 0);
	GPIO_write(LCD_DB2, data & 0x4 ? 1 : 0);
	GPIO_write(LCD_DB3, data & 0x8 ? 1 : 0);
	GPIO_write(LCD_DB4, data & 0x10 ? 1 : 0);
	GPIO_write(LCD_DB5, data & 0x20 ? 1 : 0);
	GPIO_write(LCD_DB6, data & 0x40 ? 1 : 0);
	GPIO_write(LCD_DB7, data & 0x80 ? 1 : 0);
	for(i=0;i<2000;i++);
	GPIO_write(LCD_E, 0);




}

void clear_screen()
{
LCD_send(0, 0x01);
}

void send_line(char arr[])
{
int i = 0;
for(i=0; i<16 || arr[i] != 0; i++)
{
LCD_send(1,arr[i]);
}
}

void LCD_print(UArg food)
{

//Clear Screen
//clear_screen();

//set DDRAM address (line 1 0x00)
LCD_send(0,0x80);
//send line
send_line(buff1);

//set DDRAM address (line 2= 0x40)
LCD_send(0, 0xC0);
//send line
send_line(buff2);

}

void sample_screen()
{

char arr1[17] = "    Fuck you,   ";
char arr2[17] = "    Jeramie     ";

strcpy(buff1,arr1);
strcpy(buff2,arr2);
//LCD_print();


}




/*
 *  ======== main ========
 */


int main(void)
{
    /* Call board init functions. */
    Board_initGeneral();
    Board_initGPIO();
    // Board_initI2C();
    // Board_initSDSPI();
    // Board_initSPI();
    // Board_initUART();
    // Board_initWatchdog();

    Clock_Params clockParams;
    Clock_Handle myClock;
    Error_Block eb;
    Task_Handle task0;

    Task_Params taskParams;
    Task_Params_init(&taskParams);

    int j;
    for(j=0; j<17; j++) {
    	buff1[j] = ' ';
    	buff2[j] = ' ';
    }
    Error_init(&eb);
    Clock_Params_init(&clockParams);
    clockParams.period = 100;
    clockParams.startFlag = TRUE;
    myClock = Clock_create(LCD_print, 10, &clockParams, &eb);
    if(myClock == 0)
    {
    	System_abort("Fuckin clock");
    }

    LCD_init();

    task0 = Task_create(heartBeatFxn, &taskParams, &eb);
   // sample_screen();F
    /* Turn on user LED */
    GPIO_write(Board_LED0, Board_LED_ON);



    System_printf("Starting the example\nSystem provider is set to SysMin. "
                  "Halt the target to view any SysMin contents in ROV.\n");

    //GPIO_write(4,1);
    /* SysMin will only print to the console when you call flush or exit */
    System_flush();

    /* Start BIOS */
    BIOS_start();

    return (0);
}
