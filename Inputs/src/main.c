/*
 ============================================================================
 Name        : Inputs.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#define CHAR_LEN 51

int main(void) {

	int numero;
	float numeroFloat;
	char nombre[CHAR_LEN];
	char alphanumerico[CHAR_LEN];


	if (utn_getNumber(&numero,"\nIngrese un numero entre 0 y 20: ","\nError!",0,20,3)==0 &&
		utn_getFloatNumber(&numeroFloat,"\nIngrese un numero flotante entre 0 y 20: ","\nError!",0.0,20.0,3)==0 &&
		utn_getName(nombre,CHAR_LEN,"\nIngrese un nombre (solo letras): ","\nError!",3)==0 &&
		utn_getAlphanumeric(alphanumerico,CHAR_LEN,"\nIngrese un alphanumerico (solo letras o numeros): ","\nError!",3)==0)
	{
		printf("\n\nRESULTADOS:\n\nNumero: %d \nNumero Flotante: %.2f \nNombre: %s \nAlphanumerico: %s",numero,numeroFloat,nombre,alphanumerico);
	} else {
		printf("Algo esta mal codeado amigue");
	}

	return EXIT_SUCCESS;
}

