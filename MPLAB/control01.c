/*
 * File:   control01.c
 * Author: rmanr
 *
 * Created on 4 de octubre de 2021, 12:15 PM
 */

#include <xc.h>

#pragma config FOSC = INTOSCIO //Se selecciona oscilador interno
#pragma config WDTEN = OFF     //Se deshabilita el perro guardían
#pragma config MCLRE = ON      //Se habilita el pin 1 como reset externo
#pragma config LVP = OFF       //Se deshabilita la programación por bajo voltaje 
#pragma config ICPRT = OFF     //Se deshabilita el pin para programación y depuración   

#define _XTAL_FREQ 4000000 //Constante que indica la frecuencia a la que opera el microcontrolador

//Prototipos de funciones

char bandera = 0;
int valor = 0;

void __interrupt(high_priority) LAP (void){
    char Letra;
    
    Letra = RCREG1;
    
    if (Letra == 65){
        LATAbits.LA0 ^= 1;
    }else if(Letra == 66){
        LATAbits.LA1 ^= 1;
    }else if (Letra ==67){
        
        if (bandera == 0){
            valor += 50;
            CCPR1L = valor;
            
            if (valor > 149){
                bandera = 1;
                
            }else{
                valor -= 30;
                CCPR1L = valor;
                
                if (valor < 30){
                    bandera = 0;
                }
            }
        }
    }
    
    //PIR1bits.RCIF = 0;
}


void Configuracion (void){
    TRISA = 0;      //Registro para definir los pines del puerto A como salidas (todos como 0)
    ANSELA = 0b00000001;     //Registro para definir los pines del puerto A como digitales (todos como 0)
    TRISC = 0xC0; //b?11000000?
    ANSELC = 0;
    /*
    ADCON0 = 0b00000001;
    ADCON1 = 0b00000000;       
    ADCON2 = 0b00010000;
    */
    INTCON=0b00000000;
    RCONbits.IPEN=1;
    PIE1bits.RCIE = 1;
    
    OSCCON=0x53; // 4MHz
     
    SPBRG1 = 25;
    TXSTA1 = 0x24;
    SPBRGH1 = 0x00;
    RCSTA1 = 0x90;
     
     
    CCP1CON = 0x0F;
    T2CON = 0x07;
    PR2 = 155;
    CCPR1L = 0; 
     
}




void main(void) {
    char Letra;
    //Llamado de la funcion con los bits necesarios
    Configuracion();
    __delay_ms(10);
            
    while (1){
        
        if (PIR1bits.RCIF){
            Letra = RCREG1;

            if (Letra == 65){
                LATAbits.LA0 ^= 1;
            }else if(Letra == 66){
                LATAbits.LA1 ^= 1;
            }
            
        }
        
        LATAbits.LA7 ^= 1;
        __delay_ms(500);    //Función de retardo en milisegundos
    }   
   
    return;
}