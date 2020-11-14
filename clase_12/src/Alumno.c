/*
 * Alumno.c
 *
 *  Created on: 1 oct. 2020
 *      Author: micavazzana
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include"Alumno.h"
#include "inputs.h"
#define SUCCESS 0
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0

int alumno_init(Alumno *list, int len)
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

int alumno_findEmptyIndex(Alumno *list, int len)
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

int alumno_add(Alumno *list, int len, int *id)
{
	int result = ERROR;
	Alumno bufferAlumno;
	int index;

	index = alumno_findEmptyIndex(list, len);
	if(list!=NULL && len>0 && index!=ERROR && id!=NULL)
	{
		if(utn_getName(bufferAlumno.nombre, NAME_LEN, "\nIngrese nombre: ","\nError", 3) == SUCCESS	&&
				utn_getNumber(&bufferAlumno.legajo, "\nIngrese legajo: ","\nError", 0, INT_MAX, 3) == SUCCESS)
		{
			bufferAlumno.isEmpty = FALSE;
			bufferAlumno.id = *id;
			list[index] = bufferAlumno;
			(*id)++;
			result = SUCCESS;
		}
	}
	return result;
}

int alumno_findById(Alumno *list, int len, int id)
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

int alumno_modify(Alumno *list, int len, int id)
{
	int result = ERROR;
	int index;
	int option;
	Alumno bufferAlumno;

	index = alumno_findById(list, len, id);
	if(list!=NULL&& len>0 && id>0 && index!=ERROR && list[index].isEmpty == FALSE)
	{
		do {
			if(utn_getNumber(&option, "\n\nIngrese una opcion: "
					"\n1.Modificar Nombre "
					"\n2.Modificar Legajo "
					"\n3.Volver al menu principal\n",
					"Error, elija una opcion valida\n", 1, 3, 3) == SUCCESS)
			{
				switch (option)
				{
				case 1:
					if(utn_getName(bufferAlumno.nombre, NAME_LEN, "\nIngrese nuevo nombre: ","\nError", 3) == SUCCESS)
					{
						strncpy(list[index].nombre, bufferAlumno.nombre,NAME_LEN);
						result = SUCCESS;
					} else {
						result = ERROR;//error distinto en cada caso para saber que cosa es la que falla al modificar
					}
					break;
				case 2:
					if (utn_getNumber(&bufferAlumno.legajo,	"\nIngrese nuevo legajo: ","\nError", 0,INT_MAX, 3) == SUCCESS)
					{
						list[index].legajo = bufferAlumno.legajo;
						result = SUCCESS;
					} else {
						result = ERROR;
					}
					break;
				}
			}
		} while (option != 3);
	}
	return result;
}

int alumno_remove(Alumno *list, int len, int id)
{
	int result = ERROR;
	int index;
	char bufferAnswer[10];

	index = alumno_findById(list, len, id);
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

int alumno_sort(Alumno *list, int len, int order)//ordena up o down y por doble criterio, nombre y legajo
{
	int result = ERROR;
	int i;
	Alumno aux;
	int disorderedState = 1;

	if(list!=NULL && len>0 && (order==0 || order==1))
	{
		while (disorderedState)
		{
			disorderedState = 0;
			for(i=0;i<(len-1);i++)
			{
				if((order == UP && (strncasecmp(list[i].nombre, list[i + 1].nombre,	NAME_LEN) > 0 ||
						(strncasecmp(list[i].nombre,list[i+1].nombre, NAME_LEN) == 0 && list[i].legajo > list[i+1].legajo)))
				|| (order == DOWN && (strncasecmp(list[i].nombre,list[i+1].nombre, NAME_LEN) < 0 ||
						(strncasecmp(list[i].nombre,list[i+1].nombre, NAME_LEN)	== 0 && list[i].legajo < list[i + 1].legajo))))
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

int alumno_printOne(Alumno list)
{
	int result = ERROR;

	if (list.isEmpty == FALSE)
	{
		printf("\n%5d %15s %7d", list.id, list.nombre, list.legajo);
		result = SUCCESS;
	}
	return result;

}

int alumno_printArray(Alumno *list, int len)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0)
	{
		printf("\n%5s %15s %7s\n","ID","NOMBRE","LEGAJO");
		for(i=0;i<len;i++)
		{
			alumno_printOne(list[i]);
		}
		result = SUCCESS;
	}
	return result;
}

int isAnyData(Alumno *list, int len)
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

int hardCodeData(Alumno *list, int *id)
{
	int result=ERROR;
	char nombre[][NAME_LEN]={"Mike","Eleven","Dustin","Will","Max","Lucas","Nancy","Steve","Jonathan","Joyce","Jim"};
	int legajo[]={123,124,125,126,127,128,129,130,131,132,133};
	int i;

	if(list!=NULL && id!=NULL)
	{
		for(i=0;i<11;i++)
		{
			strcpy(list[i].nombre, nombre[i]);
			list[i].legajo = legajo[i];
			list[i].isEmpty = FALSE;
			list[i].id = *id;
			(*id)++;
		}
		result = SUCCESS;
	}
	return result;
}

