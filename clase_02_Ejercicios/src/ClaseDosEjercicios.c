/*
 ============================================================================
 Name        : ClaseDosEjercicios.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Ejercicio:
 Realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num;
	int i;
	int acum = 0;
	int max;
	int min;
	float promedio;

	for (i = 0; i < 5; i++) {
		printf("Ingrese un numero: ");
		fpurge(stdin);
		scanf("%d", &num);
		acum = acum + num;

		if (num > max || i == 0) {
			max = num;
		}
		if (num < min || i == 0) {
			min = num;
		}
	}
	promedio = (float) acum / i;

	printf("\nPromedio: %.2f",promedio);
	printf("\nMinimo: %d Maximo: %d",min,max);

	return EXIT_SUCCESS;
}
