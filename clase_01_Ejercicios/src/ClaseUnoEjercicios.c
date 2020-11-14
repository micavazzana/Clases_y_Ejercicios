/*
 ============================================================================
 Name        : ClaseUnoEjercicios.c

	Agregar al programa adjunto la funcionalidad resaltada con un (*)

    - Limpie la pantalla
    - Solicite dos valores numéricos al usuario distintos de cero *
    - Asigne a las variables numero1 y numero2 los valores obtenidos
    - Realice la resta de dichas variables
    - Muestre el resultado por pantalla
    - Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor *
    - Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *


    - Solicite al usuario 10 números
    - Calcule cuántos son negativos y cuantos son positivos
    - Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

	int a;
	int b;
	int resultado;

	printf("\nIngrese numeros distintos a 0\n");
	printf("\nIngrese 1 numero: ");
	fpurge(stdin);
	scanf("%d", &a);
	while (a == 0) {
		printf("\nError, debe ser distinto a 0: ");
		fpurge(stdin);
		scanf("%d", &a);

	}
	printf("\nIngrese 2 numero: ");
	fpurge(stdin);
	scanf("%d", &b);
	while (b == 0) {
		printf("\nIError, debe ser distinto a 0: ");
		fpurge(stdin);
		scanf("%d", &b);

	}
	resultado = a - b;

	printf("______________________________________\n");
	printf("\nEl resultado es: %d \n", resultado);
	if (resultado > 0) {
		printf("\nResultado positivo \n");
	} else {
		printf("\nResultado negativo \n");
	}
	printf("______________________________________\n\n\n\n");

	int num;
	int i;
	int positivos = 0;
	int negativos = 0;
	for (i = 0; i < 10; i++) {
		printf("\nIngrese numero: ");
		fpurge(stdin);
		scanf("%d", &num);
		if (num >= 0) {
			positivos++;
		} else {
			negativos++;
		}
	}
	printf("______________________________________\n");
	printf("\nCantidad de positivos: %d \n", positivos);
	printf("\nCantidad de negativos: %d \n", negativos);
	printf("______________________________________\n\n\n\n");

	return 0;
}
