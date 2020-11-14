/*
 ============================================================================
 Name        : ejercicioClaseUno.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Pedir 5 numeros al usuario y calcular promedio

int main(void) {

	int num;
	int resultadoScan;
	float promedio;
	int acumulador = 0;
	int i;

	for (i = 0; i < 5; i++) {
		printf("\nIngrese un numero: ");
		fpurge(stdin);
		resultadoScan = scanf("%d", &num);
		while (resultadoScan == 0) {
			printf("\nError, Ingrese un numero: ");
			fpurge(stdin);
			resultadoScan = scanf("%d", &num);
		}
		acumulador = acumulador + num;
	}
	promedio = (float) acumulador / i;
	printf("\nPromedio de todos los numeros: %.2f", promedio);

	return EXIT_SUCCESS;
}
