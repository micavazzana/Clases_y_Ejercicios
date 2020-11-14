/*
 * utn.c
 *
 *  Created on: 3 sep. 2020
 *      Author: micavazzana
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferNum;

	printf("%s\n", mensaje);
	scanf("%d", &bufferNum);
	while ((bufferNum < minimo || bufferNum > maximo) && reintentos > 0) {
		reintentos--;
		printf("%s\n", mensajeError);
		scanf("%d", &bufferNum);
	}
	if (reintentos == 0) {
		printf("No hay mas reintentos");
	} else {
		*pResultado = bufferNum;
		retorno = 0;
	}

	return retorno;
}

