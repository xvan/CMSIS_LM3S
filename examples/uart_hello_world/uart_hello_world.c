/* UART.c */

#include "lm3s/lm3s_cmsis.h"

//*****************************************************************************
//
// UART0 string printer  
//
//*****************************************************************************


void print_uart0(const char *s) {
 while(*s != '\0') { /* Loop until end of string */
 UART0->DR = (unsigned int)(*s); /* Transmit char */
 s++; /* Next char */
 }
}


//*****************************************************************************
//
// Simple Hello World 
//
//*****************************************************************************
int
main(void)
{
    print_uart0("Hellow World?\n");

    //
    // Loop forever.
    //
    
    while(1)
    {
    }
}


