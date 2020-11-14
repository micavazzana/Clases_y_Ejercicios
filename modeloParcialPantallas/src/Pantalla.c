/*
 * Pantalla.c
 *
 *  Created on: 1 oct. 2020
 *      Author: micavazzana
 */
#include "inputs.h"
#include "Pantalla.h"
#define UP 1
#define DOWN 0

static int generateNewId(void);

int pan_init(Pantalla *list, int len)
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

int pan_findEmptyIndex(Pantalla *list, int len)
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

int pan_add(Pantalla *list, int len)
{
	int result = ERROR;
	Pantalla bufferPantalla;
	int index;

	if(list!=NULL && len>0)
	{
		index = pan_findEmptyIndex(list, len);
		if(index!=ERROR &&
				utn_getName(bufferPantalla.nombre, NOMBRE_LEN, "\nIngrese nombre: ","\nError", 3) == SUCCESS	&&
				utn_getAlphanumeric(bufferPantalla.direccion, DIRE_LEN, "\nIngrese direccion: ","\nError", 3) == SUCCESS &&
				utn_getFloatNumber(&bufferPantalla.precio, "\nIngrese precio: ","\nError", 0, FLT_MAX, 3) == SUCCESS &&
				utn_getNumber(&bufferPantalla.tipo, "\nIngrese tipo [1 LCD/ 2 LED]: ","\nError",1,2,3) == SUCCESS)
		{
			bufferPantalla.isEmpty = FALSE;
			bufferPantalla.idPantalla = generateNewId();
			list[index] = bufferPantalla;
			result = SUCCESS;
		}
	}
	return result;
}

int pan_findById(Pantalla *list, int len, int id)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0 && id>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].idPantalla == id)
			{
				result = i;
				break;
			}
		}
	}
	return result;
}

int pan_modify(Pantalla *list, int len, int id)
{
	int result = ERROR;
	int index;
	int option;
	Pantalla bufferPantalla;

	index = pan_findById(list, len, id);
	if(list!=NULL&& len>0 && id>0 && index!=ERROR && list[index].isEmpty == FALSE)
	{
		do {
			if(utn_getNumber(&option, "\n\nIngrese una opcion: "
					"\n1.Modificar Nombre "
					"\n2.Modificar Direccion "
					"\n3.Modificar Precio "
					"\n4.Modificar Tipo "
					"\n5.Volver al menu principal\n",
					"Error, elija una opcion valida\n", 1, 5, 3) == SUCCESS)
			{
				switch (option)
				{
				case 1:
					if(utn_getName(bufferPantalla.nombre, NOMBRE_LEN, "\nIngrese nuevo nombre: ","\nError", 3) == SUCCESS)
					{
						strncpy(list[index].nombre, bufferPantalla.nombre,NOMBRE_LEN);
						result = SUCCESS;
					} else {
						result = ERROR;//podria poner un error distinto en cada caso
					}
					break;
				case 2:
					if (utn_getAlphanumeric(bufferPantalla.direccion,DIRE_LEN,"\nIngrese nueva direccion: ","\nError", 3) == SUCCESS)
					{
						strncpy(list[index].direccion,bufferPantalla.direccion,DIRE_LEN);
						result = SUCCESS;
					} else {
						result = ERROR;
					}
					break;
				case 3:
					if(utn_getFloatNumber(&bufferPantalla.precio, "\nIngrese nuevo precio: ","\nError", 0, FLT_MAX, 3) == SUCCESS)
					{
						list[index].precio = bufferPantalla.precio;
						result = SUCCESS;
					} else {
						result = ERROR;
					}
					break;
				case 4:
					if (utn_getNumber(&bufferPantalla.tipo,"\nIngrese tipo [1 LCD/ 2 LED]: ","\nError",1,2,3) == SUCCESS)
					{
						list[index].tipo = bufferPantalla.tipo;
						result = SUCCESS;
					} else {
						result = ERROR;
					}
					break;
				}
			}
		} while (option != 5);
	}
	return result;
}

int pan_remove(Pantalla *list, int len, int id)
{
	int result = ERROR;
	int index;
	char bufferAnswer[10];

	index = pan_findById(list, len, id);
	if(list!=NULL && len>0 && id>0 && index!=ERROR && list[index].isEmpty == FALSE)
	{
		if(utn_getName(bufferAnswer, 10,"\nSeguro que desea eliminar? Debe ingresar 'Si' para proseguir con la baja ","\nError.", 3) == SUCCESS
				&& strncasecmp(bufferAnswer, "si", 10) == 0)
		{
			list[index].isEmpty = TRUE;
			result = SUCCESS;
		}
	}
	return result;
}

int pan_sort(Pantalla *list, int len, int order)//ordena up o down y por doble criterio, nombre y legajo
{
	int result = ERROR;
	/*int i;
	Pantalla aux;
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
	}*/
	return result;
}

int pan_printOne(Pantalla list)
{
	int result = ERROR;
	char tipo[8];

	if(list.isEmpty == FALSE)
	{
		if(list.tipo == TIPO_LED)
		{
			sprintf(tipo,"LED");
		}
		else if(list.tipo == TIPO_LCD)
		{
			sprintf(tipo,"LCD");
		}
		printf("\n%5d %15s %15s %10.2f %10s", list.idPantalla, list.nombre, list.direccion,list.precio,tipo);
		result = SUCCESS;
	}
	return result;
}

int pan_printArray(Pantalla *list, int len)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0)
	{
		printf("\n%5s %15s %15s %10s %10s","ID","NOMBRE","DIRECCION","PRECIO","TIPO");
		for(i=0;i<len;i++)
		{
			pan_printOne(list[i]);
		}
		result = SUCCESS;
	}
	return result;
}

int pan_isAnyData(Pantalla *list, int len)
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

int pan_hardCodeData(Pantalla* list)
{
	int result=ERROR;
	int tipo[]= {1,1,2,2};
    char nombre[][50]= {"PantallaUno","PantallaDos","PantallaTres","PantallaCuatro"};
    char direccion[][20]= {"Alsina 222","Suipacha 435","Belgrano 856","Mitre 700"};
    float precio[]= {105.5, 250, 250,100};
	int i;

	if(list!=NULL)
	{
		for(i=0;i<4;i++)
		{
		 	list[i].tipo = tipo[i];
            strncpy(list[i].nombre,nombre[i],NOMBRE_LEN);
            strncpy(list[i].direccion,direccion[i],DIRE_LEN);
            list[i].precio = precio[i];
            list[i].idPantalla = generateNewId();
            list[i].isEmpty = FALSE;
		}
		result = SUCCESS;
	}
	return result;
}

static int generateNewId(void)
{
	static int id = 0;
	id++;
	return id;
}

