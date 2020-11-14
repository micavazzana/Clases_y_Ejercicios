/*
 ============================================================================
 Name        : clase08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 1) Se tiene el siguiente array de variables del tipo int
int numeros[12]={3,7,4,5,2,3,7,1,7,3,2,7};
Hacer una funcion que reciba el array y su tamaño, y lo imprima.
Escribir un programa para probar la funcion.

2) Hacer una funcion que reciba el array del punto 1 y su tamaño,
y cuente cuantas veces aparece el numero 7.
Al terminar de contar, la funcion deberá imprimir por pantalla el valor contado.
Escribir un programa para probar la funcion.

3) Modificar la funcion del punto 2 para que NO imprima el valor contado,
sino que lo devuelva por referencia (recibiendo la direccion de memoria de una
variable donde escribirá el valor contado). Escribir un programa para probar la funcion.

4) Dada la siguiente cadena de caracteres:
char nombre[8]={'p','e','p','e','1','2','3','\0'};
Hacer una funcion que reciba el array y su tamaño, y cuente cuantas veces aparece
la letra 'e'.Al terminar de contar, la funcion deberá imprimir por pantalla el valor contado.
Escribir un programa para probar la funcion.
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define LEN 12
#define NUM_A_BUSCAR 7
#define CHAR_A_BUSCAR 'e'

int main(void) {

	int numeros[LEN]={3,7,4,5,2,3,7,1,7,3,2,7};
	char nombre[]={'p','e','p','e','1','2','3','\0'};
	int cantidadDeNumero;
	int cantidadDeChar;
	char name[51];

	imprimirArray(numeros,LEN);
    if(contadorDeNumeros(numeros,LEN,NUM_A_BUSCAR,&cantidadDeNumero)==0)
    {
        printf("\nHay %d %d",cantidadDeNumero,NUM_A_BUSCAR);
    }
    if(contadorDeCaracteres(nombre,CHAR_A_BUSCAR,&cantidadDeChar)==0)
    {
        printf("\nHay %d %c",cantidadDeChar,CHAR_A_BUSCAR);
    }

    if(getNombre(name, 51, "\nIngrese su nombre: ")==0)
	{
		printf("\nSon solo letras");
	} else {
		printf("\nHay mas que solo letras");
	}
	return 0;
}
