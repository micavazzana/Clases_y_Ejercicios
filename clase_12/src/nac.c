/*
 * Nacionalidad.c
 *
 *  Created on: 1 oct. 2020
 *      Author: micavazzana
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include"nac.h"
#include "inputs.h"
#define SUCCESS 0
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0

int nac_init(Nacionalidad *list, int len)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
		}
		result = SUCCESS;
	}
	return result;
}

int nac_findEmptyIndex(Nacionalidad *list, int len)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty)
			{
				result = i;
				break;
			}
		}
	}
	return result;
}

int nac_add(Nacionalidad *list, int len, int *id)
{
	int result = ERROR;
	Nacionalidad bufferNacionalidad;
	int index;

	index = nac_findEmptyIndex(list, len);
	if(list!=NULL && len>0 && index!=ERROR && id!=NULL)
	{
		if(utn_getName(bufferNacionalidad.pais, PAISLEN, "\nIngrese pais: ","\nError", 3) == SUCCESS)
		{
			bufferNacionalidad.isEmpty = FALSE;
			bufferNacionalidad.id = *id;
			list[index] = bufferNacionalidad;
			(*id)++;
			result = SUCCESS;
		}
	}
	return result;
}

int nac_findById(Nacionalidad *list, int len, int id)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				result = i;
				break;
			}
		}
	}
	return result;
}

int nac_modify(Nacionalidad *list, int len, int id)
{
	int result = ERROR;
	int index;
	Nacionalidad bufferNacionalidad;

	index = nac_findById(list, len, id);
	if(list!=NULL&& len>0 && id>0 && index!=ERROR && list[index].isEmpty == FALSE)
	{
		if(utn_getName(bufferNacionalidad.pais, PAISLEN, "\nIngrese nuevo pais: ","\nError", 3) == SUCCESS)
		{
			strncpy(list[index].pais, bufferNacionalidad.pais,PAISLEN);
			result = SUCCESS;
		}
	}
	return result;
}

int nac_remove(Nacionalidad *list, int len, int id)
{
	int result = ERROR;
	int index;
	char bufferAnswer[10];

	index = nac_findById(list, len, id);
	if (list!=NULL && len>0 && id>0 && index!=ERROR && list[index].isEmpty == FALSE)
	{
		if (utn_getName(bufferAnswer, 10,"\nSeguro que desea eliminar? Debe ingresar 'Si' para proseguir con la baja ","\nError,ingrese una respuesta valida.", 3) == SUCCESS
				&& strncasecmp(bufferAnswer, "si", 10) == 0)
		{
			list[index].isEmpty = TRUE;
			result = SUCCESS;
		}
	}
	return result;
}

int nac_sort(Nacionalidad *list, int len, int order)//ordena up o down
{
	int result = ERROR;
	int i;
	Nacionalidad aux;
	int disorderedState = 1;

	if(list!=NULL && len>0 && (order==0 || order==1))
	{
		while (disorderedState)
		{
			disorderedState = 0;
			for(i=0;i<(len-1);i++)
			{
				if((order == UP && (strncasecmp(list[i].pais,list[i+1].pais,PAISLEN) > 0)) ||
						(order == DOWN &&  (strncasecmp(list[i].pais,list[i+1].pais,PAISLEN) < 0)))
				{
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
					disorderedState = 1;
				}
			}
		}
		result = SUCCESS;
	}
	return result;
}

int nac_printOne(Nacionalidad list)
{
	int result = ERROR;

	if (list.isEmpty == FALSE)
	{
		printf("\n%5d %15s", list.id, list.pais);
		result = SUCCESS;
	}
	return result;
}

int nac_printArray(Nacionalidad *list, int len)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0)
	{
		printf("\n%5s %15s\n","ID","PAIS");
		for(i=0;i<len;i++)
		{
			nac_printOne(list[i]);
		}
		result = SUCCESS;
	}
	return result;
}

int isAnyData(Nacionalidad *list, int len)
{
	int i;
	int result = FALSE;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE) //if there is data
			{
				result = TRUE;
				break;
			}
		}
	}
	return result;
}

int hardCodeData(Nacionalidad *list, int *id)
{
	int result=ERROR;
	char pais[][PAISLEN]={"Arg","Arg","Arg","Chile","Uruguay","Peru","Uruguay","Uruguay","Arg","Arg","Colombia"};
	int i;

	if(list!=NULL && id!=NULL)
	{
		for(i=0;i<11;i++)
		{
			strcpy(list[i].pais, pais[i]);
			list[i].isEmpty = FALSE;
			list[i].id = *id;
			(*id)++;
		}
		result = SUCCESS;
	}
	return result;
}

