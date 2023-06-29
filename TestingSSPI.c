/*
 * File:   TestingSSPI.c
 * Author: ank12
 *
 * Created on 3 de junio de 2023, 04:49 PM
 */

// CONFIG
#pragma config FOSC = HS       // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF   

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#define _XTAL_FREQ 20000000
//Defini Los pines para la transmision de datos al LCD
#define RS RD2
#define EN RD3

#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7
#define LED1 PORTDbits.RD1

#define Write_Sram 0x02

#include <xc.h>
#include "SSPI.h"
#include "lcd.h"
#include <stdio.h>
int lectura;
char data[];



void Sram_write(char dato, int address)
{
        
    
   
      PORTCbits.RC0 = 0;//Activo el exclavo CC
     __delay_us(10);
      SSPBUF = 0x02;//Instruccion de escritura
      
      __delay_us(10);   
        SSPBUF = (address>>8) & 0xFF;//Parte alta de la direccion  
      __delay_us(10);        
       SSPBUF =  address & 0xFF;//Parte baja  de la direccion   
       __delay_us(10); 
       SSPBUF = dato;//Dato
       __delay_us(10);
       PORTCbits.RC0 = 1;//Activo el exclavo CC
    
    
}

void Sram_read()
{
    
    ;
    
}


void main(void) {
    int data = 0;
    TRISCbits.TRISC0 = 0;//Pin CC de seleccion exclavo como salida
    PORTCbits.RC0 = 1;//Disable el exclavo CC
     TRISD = 0x00;  
     LED1 = 1;
    Sspi_Init();
    SSpi_Clock_Source(Sspi_Fosc_4);
    Sspi_work_Cpol_Cpha(clock_low_rising_edge);
    Lcd_Init(); 
      Lcd_Clear();
       Lcd_Set_Cursor(1, 1);
       sprintf(data, "Bienvenidoa");
        
        Lcd_Clear();
        for(int i = 0; i<=100; i++)
        {
            Sram_write(data, i); 
            data += 1;
        }
       
    
       
          
   
               
    
 while(1)
 {      
     
       
      
           
      /*
    
     Lcd_Set_Cursor(1, 1);
    sprintf(data, "Int A %d",lectura);
    Lcd_Write_String(data);
      __delay_ms(50);
       */       
    
     
 }
   
    return;
}
