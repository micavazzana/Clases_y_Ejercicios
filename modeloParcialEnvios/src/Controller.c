/*
 * controller.c
 *
 *  Created on: 13 nov. 2020
 *      Author: micavazzana
 */
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Controller.h"
#include "Inputs.h"
#include "Envio.h"
#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define NORMAL 0
#define EXPRESS 1
#define SEGUN_DISPO 2

int controller_loadFromText(LinkedList* listaEnvios, char* ruta)
{
	int returnAux = ERROR;
	FILE* pArchivo;

	if(listaEnvios != NULL && ruta != NULL)
	{
		pArchivo = fopen(ruta,"r");
		if(pArchivo != NULL)
		{
			returnAux = parser_EnvioTxt(pArchivo, listaEnvios);
		}
		fclose(pArchivo);
	}
	return returnAux;
}

int controller_printOne(void* pElement)
{
	int returnAux = ERROR;
	Envio* unEnvio;
	Envio buffer;
	char tipoEntrega[25];

	if(pElement != NULL)
	{
		unEnvio = (Envio*)pElement;
		envio_getId(unEnvio,&buffer.idEnvio);
		envio_getNombreProducto(unEnvio,buffer.nombreProducto);
		envio_getIdCamion(unEnvio,&buffer.idCamion);
		envio_getZonaDestinos(unEnvio,buffer.zonaDestinos);
		envio_getKmRecorridos(unEnvio,&buffer.kmRecorridos);
		envio_getTipoEntrega(unEnvio,&buffer.tipoEntrega);
		if(buffer.tipoEntrega == NORMAL)
		{
			sprintf(tipoEntrega,"NORMAL");
		} else if(buffer.tipoEntrega == EXPRESS) {
			sprintf(tipoEntrega,"EXPRESS");
		} else {
			sprintf(tipoEntrega,"SEGUN DISPO");
		}
		printf("%15d %15s %15d %15s %10.1f %25s\n",
				buffer.idEnvio,
				buffer.nombreProducto,
				buffer.idCamion,
				buffer.zonaDestinos,
				buffer.kmRecorridos,
				tipoEntrega);
		returnAux = SUCCESS;
	}
	return returnAux;
}

int controller_printList(LinkedList* listaEnvios)
{
	int returnAux = ERROR;

	if(listaEnvios != NULL)
	{
		printf("\n%15s %15s %15s %15s %10s %25s\n\n","ID ENVIO","NOMBRE","ID CAMION","ZONA","KM","TIPO ENT");
		returnAux = ll_map(listaEnvios,controller_printOne);
	}
	return returnAux;
}

int controller_CalculateOneCost(void* pElement)
{
	int returnAux = ERROR;
	Envio* unEnvio;
	Envio buffer;
	float costo;

	if(pElement != NULL)
	{
		unEnvio = (Envio*)pElement;
		envio_getKmRecorridos(unEnvio,&buffer.kmRecorridos);
		envio_getTipoEntrega(unEnvio,&buffer.tipoEntrega);
		costo = envio_calcularCosto(buffer.kmRecorridos,buffer.tipoEntrega);
		envio_setCostoEnvio(unEnvio,costo);
		returnAux = SUCCESS;
	}
	return returnAux;
}

int controller_printListWithCost(LinkedList* listaEnvios)
{
	int returnAux = ERROR;

	if(listaEnvios != NULL)
	{
		printf("\n%15s %15s %15s %15s %10s %25s %12s\n\n","ID ENVIO","NOMBRE","ID CAMION","ZONA","KM","TIPO ENT","COSTO ENVIO");
		returnAux = ll_map(listaEnvios,controller_printOneWithCost);
	}
	return returnAux;
}

int controller_printOneWithCost(void* pElement)
{
	int returnAux = ERROR;
	Envio* unEnvio;
	Envio buffer;
	char tipoEntrega[25];

	if(pElement != NULL)
	{
		unEnvio = (Envio*)pElement;
		envio_getId(unEnvio,&buffer.idEnvio);
		envio_getNombreProducto(unEnvio,buffer.nombreProducto);
		envio_getIdCamion(unEnvio,&buffer.idCamion);
		envio_getZonaDestinos(unEnvio,buffer.zonaDestinos);
		envio_getKmRecorridos(unEnvio,&buffer.kmRecorridos);
		envio_getTipoEntrega(unEnvio,&buffer.tipoEntrega);
		envio_getCostoEnvio(unEnvio,&buffer.costoEnvio);
		if(buffer.tipoEntrega == NORMAL)
		{
			sprintf(tipoEntrega,"NORMAL");
		} else if(buffer.tipoEntrega == EXPRESS) {
			sprintf(tipoEntrega,"EXPRESS");
		} else {
			sprintf(tipoEntrega,"SEGUN DISPO");
		}
		printf("%15d %15s %15d %15s %10.1f %25s \t$%.2f\n",
				buffer.idEnvio,
				buffer.nombreProducto,
				buffer.idCamion,
				buffer.zonaDestinos,
				buffer.kmRecorridos,
				tipoEntrega,
				buffer.costoEnvio);
		returnAux = SUCCESS;
	}
	return returnAux;
}

int controller_saveFileWithShippingByZone(LinkedList* listaEnvios)
{
	int returnAux = ERROR;
	LinkedList* nuevaLista;
	char zona[ZONE_LEN];

	if(listaEnvios != NULL)
	{
		ll_map(listaEnvios,controller_CalculateOneCost);
		nuevaLista = ll_clone(listaEnvios);
		if(nuevaLista != NULL &&
				utn_getName(zona,ZONE_LEN,"\nIngrese la zona con la cual va generar archivo: ","\nError",5)==SUCCESS)
		{
			ll_filter2(nuevaLista,envio_compararZona,zona);
			strncat(zona,".csv",ZONE_LEN);
			controller_saveToText(nuevaLista,zona);
		}
		returnAux = SUCCESS;
	}
	return returnAux;
}

int controller_saveToText(LinkedList* listaEnvios, char* ruta)
{
	int returnAux = ERROR;
	FILE* pArchivo;
	Envio* envio;
	Envio buffer;

	if(listaEnvios != NULL && ruta != NULL)
	{
		pArchivo = fopen(ruta,"w");
		if(pArchivo != NULL)
		{
			fprintf(pArchivo,"ID ENVIO,NOMBRE,ID CAMION,ZONA,KM,TIPO ENT,COSTO ENVIO\n");
			for(int i = 0; i< ll_len(listaEnvios);i++)
			{
				envio = (Envio*)ll_get(listaEnvios,i);
				if(envio != NULL
						&& envio_getId(envio,&buffer.idEnvio) == SUCCESS
						&& envio_getNombreProducto(envio,buffer.nombreProducto) == SUCCESS
						&& envio_getIdCamion(envio,&buffer.idCamion) == SUCCESS
						&& envio_getZonaDestinos(envio,buffer.zonaDestinos) == SUCCESS
						&& envio_getKmRecorridos(envio,&buffer.kmRecorridos) == SUCCESS
						&& envio_getTipoEntrega(envio,&buffer.tipoEntrega) == SUCCESS
						&& envio_getCostoEnvio(envio,&buffer.costoEnvio) == SUCCESS)
				{
					fprintf(pArchivo,"%d,%s,%d,%s,%f,%d,%f\n",buffer.idEnvio,buffer.nombreProducto,buffer.idCamion,buffer.zonaDestinos,buffer.kmRecorridos,buffer.tipoEntrega,buffer.costoEnvio);
				}
			}
			returnAux = 0;
		}
		fclose(pArchivo);
	}
	return returnAux;
}

int controller_createListOfZones(LinkedList* listaEnvios)
{
	int result = ERROR;
	LinkedList* listaZonas;

	if(listaEnvios != NULL)
	{
		listaZonas = zona_generateList(listaEnvios);
		controller_printListZone(listaZonas);
		result = SUCCESS;

	}
	return result;
}

static int zoneIsInList(LinkedList* listZona, char* zona)
{
	int result = FALSE;
	int i;
	char bufferZona[ZONE_LEN];
	Zona* pZona;

	for (i = 0; i < ll_len(listZona); i++)
	{
		pZona = ll_get(listZona,i);
		zona_getZonaDestinos(pZona,bufferZona);
		if (strncmp(bufferZona,zona,ZONE_LEN)==0)
		{
			result = TRUE;
			break;
		}
	}
	return result;
}

LinkedList* zona_generateList(LinkedList* listaEnvios)
{
	LinkedList* listaZonas = NULL;
    Envio* pElement;
    Zona* pElementZona;
    int i;
    char bufferZonaEnvios[ZONE_LEN];

    if(listaEnvios != NULL)
    {
    	listaZonas = ll_newLinkedList();
    	if(listaZonas != NULL)
    	{
    		for(i=0;i<ll_len(listaEnvios);i++)
    		{
    			pElement = (Envio*) ll_get(listaEnvios,i);
    			envio_getZonaDestinos(pElement,bufferZonaEnvios);
				if(zoneIsInList(listaZonas,bufferZonaEnvios)==FALSE)
				{
					pElementZona = zona_new();
					if(pElementZona != NULL)
					{
						zona_setZonaDestinos(pElementZona,bufferZonaEnvios);
						ll_add(listaZonas,pElementZona);
					} else {
						ll_deleteLinkedList(listaZonas);
						listaZonas = NULL;
						break;
					}
				}
			}
		}
	}
    return listaZonas;
}

int controller_printOneZone(void* pElement)
{
	int returnAux = ERROR;
	Zona* unaZona;
	char bufferZona[51];

	if(pElement != NULL)
	{
		unaZona = (Zona*)pElement;
		zona_getZonaDestinos(unaZona,bufferZona);
		bufferZona[0] = bufferZona[0]-32;
		printf("\n %s",bufferZona);
		returnAux = SUCCESS;
	}
	return returnAux;
}

int controller_printListZone(LinkedList* listaZonas)
{
	int returnAux = ERROR;

	if(listaZonas != NULL)
	{
		printf("\n%s\n","ZONAS: ");
		returnAux = ll_map(listaZonas,controller_printOneZone);
	}
	return returnAux;
}
