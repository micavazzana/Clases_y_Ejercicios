/*
 ============================================================================
 Name        : clase_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

		int edad;

		if(utn_getNumero(&edad,"Ingrese edad: \n", "ERROR: Reingrese\n", 1, 100, 4) == 0)
		{
			printf("Ingresaste %d", edad);
		}



	return EXIT_SUCCESS;
}

