/*
 * File:   Convertidor01.c
 * Author: rmanr
 *
 * Created on 26 de agosto de 2021, 01:19 PM
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
    TRISB = 0;
    ANSELB = 0;
    
    ADCON0 = 0b00000001;
    ADCON1 = 0b00000000;       
    ADCON2 = 0b10010000;
}

int convierte (void){
    int Resultado;
    
    ADCON0bits.GO = 1;
        
    while(ADCON0bits.GO);
    
    Resultado = ADRESL + ADRESH*256;
    
    return Resultado;
}

void main(void) {
    //Llamado de la funcion con los bits necesarios
    configura();
   
    __delay_ms(1);
            
    while (1){
        
        LATB = convierte()/4; //Los 8 bits menos significativos y hacemos corrimiento de los 10 bits dividiendo en 4
        
        LATAbits.LA0 ^= 1;  //Con cada ejecución ese pin cambia de 0 a 1 y de 1 a 0
        __delay_ms(50);    //Función de retardo en milisegundos
    }   
   
    return;
}
