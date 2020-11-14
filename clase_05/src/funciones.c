/*
 * funciones.c
 *
 *  Created on: 8 sep. 2020
 *      Author: micavazzana
 */
#include <stdio.h>
#include <stdlib.h>

int calcularPromedio(int *arrayInt,int tamArray,float *pPromedio)
{
    int retorno = -1;
    int acumulador=0;
    float bufferPromedio;
    int i;

    if(arrayInt != NULL && pPromedio != NULL && tamArray > 0)
    {
        for(i=0;i<tamArray;i++)
        {
            acumulador = acumulador + arrayInt[i];
        }
        bufferPromedio= (float)acumulador /tamArray ;
        *pPromedio = bufferPromedio;
        retorno = 0;
    }

    return retorno;
}

int calcularMinimo(int *arrayInt,int tamArray,int *pMinimo)
{
    int retorno = -1;
    int bufferMin;
    int i;

    if(arrayInt != NULL && pMinimo != NULL && tamArray > 0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(arrayInt[i]<bufferMin || i == 0)
            {
                bufferMin = arrayInt[i];
            }
        }
        *pMinimo = bufferMin;
        retorno = 0;
    }

    return retorno;
}

int calcularMaximo(int *arrayInt,int tamArray,int *pMaximo)
{
    int retorno = -1;
    int bufferMax;
    int i;

    if(arrayInt != NULL && pMaximo != NULL && tamArray > 0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(arrayInt[i]>bufferMax || i == 0)
            {
                bufferMax = arrayInt[i];
            }
        }
        *pMaximo = bufferMax;
        retorno = 0;
    }

    return retorno;
}

int getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	int bufferInt;

	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL &&  reintentos >= 0 &&	maximo >= minimo)
	{
		while(reintentos >0)
		{
			printf("%s",mensaje);
			fpurge(stdin);
			scanf("%d",&bufferInt);

			if(bufferInt < minimo || bufferInt > maximo)
			{
				printf("%s",mensajeError);
				reintentos--;
			}
			else
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
		}
	}
	return retorno;
}


int ordenar(int *array, int len)
{
	int retorno = -1;
	int i;
	int aux;
	int estadoDesordenado=1;

	if(array != NULL && len > 0)
	{
		while(estadoDesordenado)//mientras este desordenado
		{
			estadoDesordenado = 0;
			for(i = 0; i < (len - 1); i++)
			{
				if(array[i] > array[i + 1])
				{
					aux = array[i];
					array[i] = array[i + 1];
					array[i + 1] = aux;
					estadoDesordenado = 1;
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

void imprimirArray(int *array, int len,char *texto)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("\n%s%d",texto,array[i]);
	}
}
