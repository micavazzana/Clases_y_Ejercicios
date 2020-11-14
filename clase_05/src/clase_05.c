/*
 ============================================================================
 Name        : Test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Pedir 5 numeros


 - OP1 - Calcular Maximo
 - OP2 - Calcular Promedio
 - OP3 - Calcular Minimo
 -
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 5

int main(void) {

	int variableInt;
	char aMensaje[200];
	int arrayInt[TAM];
	int flagCargaCorrecta = 0;
	int maximo;
	int minimo;
	float promedio;

	for(int i=0; i < TAM ; i++)
	{
		sprintf(aMensaje,"Ingrese un numero %d\n",i+1);
		if(getInt(aMensaje,"Fuera de rango [0-1000]\n",&variableInt,5,1000,0) != 0)
		{
			printf("GAME OVER");
			flagCargaCorrecta = -1;
			break;
		}
		else
		{
			arrayInt[i] = variableInt;
		}
	}
	if(flagCargaCorrecta == 0)
	{
		printf("\nEN EL ORDEN INGRESADO:\n");
		imprimirArray(arrayInt, TAM,"Numero ingresado: ");
		printf("\n\nORDENADO:\n");
		ordenar(arrayInt, TAM);
		imprimirArray(arrayInt, TAM,"Numero ingresado: ");

		if(calcularMaximo(arrayInt,TAM,&maximo) == 0)
		{
		    printf("\n\nEl maximo es: %d",maximo);
		}
		if(calcularMinimo(arrayInt,TAM,&minimo) == 0)
		{
		    printf("\nEl minimo es: %d",minimo);
		}
		if(calcularPromedio(arrayInt,TAM,&promedio)==0)
		{
		    printf("\nEl promedio es: %.2f",promedio);
		}
	}
	return 0;
}

;
