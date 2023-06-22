/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */
#define Sspi_Fosc_4  0x00
#define Sspi_Fosc_16 0x01
#define Sspi_Fosc_64 0x02
#define Sspi_timer2_output_2 0x03
#define Sspi_slave_mode_SCK_SS_Enable 0x04
#define Sspi_slave_mode_SCK_SS_Disable 0x05


#define clock_low_rising_edge 0x00
#define clock_high_falling_edge 0x01
#define clock_low_falling_edfe 0x02
#define clock_high_rising_edge 0x03




/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H
#include <xc.h> // include processor files - each processor file is guarded. 




void Sspi_Init(){
    
    SSPEN = 1;
    TRISCbits.TRISC3 = 0;//Pin RC3 donde esta la señal SCK como salida
    TRISCbits.TRISC4 = 1;//Pin SDI del SPI como entrada
    TRISCbits.TRISC5 = 0;//Pin SDO del SPI como salida
  
    
    
}

void SSpi_Clock_Source(int value)

{
    if(value==0)
    {
        
    SSPM3 = 0;
    SSPM2 = 0;
    SSPM1 = 0;
    SSPM0 = 0;  
    }
    
    else if(value==1)
    {
        
    SSPM3 = 0;
    SSPM2 = 0;
    SSPM1 = 0;
    SSPM0 = 1;  
    }
    
    else if(value==2)
    {
        
    SSPM3 = 0;
    SSPM2 = 0;
    SSPM1 = 1;
    SSPM0 = 0;  
    }
    
    else if(value==3)
    {
        
    SSPM3 = 0;
    SSPM2 = 0;
    SSPM1 = 1;
    SSPM0 = 1;  
    }
    
    else if(value==4)
    {
        
    SSPM3 = 0;
    SSPM2 = 1;
    SSPM1 = 0;
    SSPM0 = 0;  
    }
    
    else if(value==5)
    {
        
    SSPM3 = 0;
    SSPM2 = 1;
    SSPM1 = 0;
    SSPM0 = 1;  
    }
    
    
}

void Sspi_work_Cpol_Cpha(int mode)
{
    SMP = 0;
    if(mode==0)
    {
       CKP = 0;
       CKE = 0;
        
    }
       if(mode==1)
    {
       CKP = 1;
       CKE = 0;
        
    }
       if(mode==2)
    {
       CKP = 0;
       CKE = 1;
        
    }
       if(mode==3)
    {
       CKP = 1;
       CKE = 1;
        
    }
    
    
}





#endif	/* XC_HEADER_TEMPLATE_H */

