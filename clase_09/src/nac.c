/*
 * nac.c
 *
 *  Created on: 29 sep. 2020
 *      Author: micavazzana
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "nac.h"
#define ERROR -1
#define EXITO 0
#define TRUE 1
#define FALSE 0

int nac_alta(Nacionalidad* lista,int len,int* id)
{
	int retorno= ERROR;
	Nacionalidad auxiliar;
	int indice;

	indice = nac_findEmptyIndex(lista,len);
	if(lista!=NULL && len>0 && indice != ERROR && id!=NULL)
	{
		if(utn_getName(auxiliar.nombre,NOMBRE_LEN,"\nIngrese nombre: ","\nError", 3)==EXITO)
		{
			auxiliar.isEmpty = FALSE;
			auxiliar.id = *id;
			lista[indice] = auxiliar;
			(*id)++;
			retorno = EXITO;
		}
	}
	return retorno;
}

int nac_imprimirUnaNac(Nacionalidad lista)
{
	int retorno=ERROR;

	if(lista.isEmpty == FALSE)
	{
		printf ("\n%5d %15s",lista.id,lista.nombre);
		retorno=EXITO;
	}
	return retorno;
}

int nac_imprimirArray(Nacionalidad* lista,int len)
{
    int retorno = ERROR;
    int i;

    if(lista!=NULL && len>0)
    {
    	printf("\n%5s %15s\n","ID","NOMBRE");
        for(i=0;i<len;i++)
        {
        	nac_imprimirUnaNac(lista[i]);
        }
        retorno = EXITO;
    }
    return retorno;
}

int nac_initArray(Nacionalidad* lista,int len)
{
	int retorno = ERROR;
	int i;

	if(lista!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			lista[i].isEmpty = TRUE;
		}
		retorno = EXITO;
	}
	return retorno;
}

int nac_findEmptyIndex(Nacionalidad* lista,int len)
{
	int retorno = ERROR;
	int i;

	if(lista!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(lista[i].isEmpty)//true
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int nac_modificar(Nacionalidad* lista,int len,int id)
{
	int retorno= ERROR;
	Nacionalidad auxiliar;
	int indice;

	indice = nac_buscarPorId(lista,len,id);
	if(lista!=NULL && len>0 && id >0 && lista[indice].isEmpty == FALSE)
	{
		if(utn_getName(auxiliar.nombre,NOMBRE_LEN,"Ingrese nombre: ","Error", 3)==EXITO)
		{
			strncpy(lista[indice].nombre,auxiliar.nombre,NOMBRE_LEN);
			retorno=EXITO;
		}
	}
	return retorno;
}

int nac_baja(Nacionalidad* lista,int len,int id)
{
	int retorno = ERROR;
	int indice;

	indice = nac_buscarPorId(lista,len,id);
	if(lista!=NULL && len>0 && indice >=0 && lista[indice].isEmpty == FALSE)
	{
		lista[indice].isEmpty = TRUE;
		retorno=EXITO;
	}
	return retorno;
}

int nac_ordenarArray(Nacionalidad* lista,int len,int orden)
{
	int retorno = ERROR;
	int i;
	Nacionalidad aux;
	int estadoDesordenado=1;

	if(lista != NULL && len > 0 && (orden == 1 || orden == 0))
	{
		while(estadoDesordenado)
		{
			estadoDesordenado = 0;
			for(i = 0; i < (len - 1); i++)
			{
				if( (orden == 1 && strncasecmp(lista[i].nombre, lista[i + 1].nombre,NOMBRE_LEN)>0) ||
					(orden == 0 && strncasecmp(lista[i].nombre, lista[i + 1].nombre,NOMBRE_LEN)<0))
				{
					aux = lista[i];
					lista[i] = lista[i + 1];
					lista[i + 1] = aux;
					estadoDesordenado = 1;
				}
			}
		}
		retorno = EXITO;
	}
	return retorno;
}

int nac_buscarPorId(Nacionalidad* lista, int len,int id)
{
	int retorno = ERROR;
	int i;

	if (lista != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (lista[i].isEmpty == FALSE && lista[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
