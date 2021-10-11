/*
 * File:   pwm01.c
 * Author: rmanr
 *
 * Created on 20 de septiembre de 2021, 12:51 PM
 */

#include <xc.h>

#pragma config FOSC = INTOSCIO //Se selecciona oscilador interno
#pragma config WDTEN = OFF     //Se deshabilita el perro guardían
#pragma config MCLRE = ON      //Se habilita el pin 1 como reset externo
#pragma config LVP = OFF       //Se deshabilita la programación por bajo voltaje 
#pragma config ICPRT = OFF     //Se deshabilita el pin para programación y depuración   

#define _XTAL_FREQ 1000000 //Constante que indica la frecuencia a la que opera el microcontrolador

//Prototipos de funciones

void configura (void){
    TRISA = 0;      //Registro para definir los pines del puerto A como salidas (todos como 0)
    ANSELA = 0b00000001;     //Registro para definir los pines del puerto A como digitales (todos como 0)
    TRISC = 0;
    ANSELC = 0;
    ADCON0 = 0b00000001;
    ADCON1 = 0b00000000;       
    ADCON2 = 0b00010000;
    
    /*
     INTCON=0b10000000;
     RCONbits.IPEN=1;
     PIE1bits.RCIE = 1;
     */
    CCP1CON = 0x0F;
    T2CON = 0x07;
    PR2 = 155;  
}

void convierte (void){
    //int Resultado;
    
    ADCON0bits.GO = 1;
    CCPR1L = ADRESH;
    
    if (ADRESL > 127)
        CCP1CONbits.DC1B1 = 1;
    else
        CCP1CONbits.DC1B1 = 0;
    
    ADRESL = ADRESL * 2;
    
    if (ADRESL > 127)
        CCP1CONbits.DC1B0 = 1;
    else
        CCP1CONbits.DC1B0 = 0;
    
    //while(ADCON0bits.GO);
    
    //Resultado = ADRESL + ADRESH*256;
    
    //return Resultado;
}

void main(void) {
    //Llamado de la funcion con los bits necesarios
    configura();
    __delay_ms(1);
            
    while (1){
        convierte();
        //LATB = convierte()/4; //Los 8 bits menos significativos y hacemos corrimiento de los 10 bits dividiendo en 4
        //LATAbits.LA0 ^= 1;  //Con cada ejecución ese pin cambia de 0 a 1 y de 1 a 0
        __delay_ms(50);    //Función de retardo en milisegundos
    }   
   
    return;
}
