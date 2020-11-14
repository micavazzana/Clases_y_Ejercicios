/*
 * controller.c
 *
 *  Created on: 13 nov. 2020
 *      Author: micavazzana
 */
#include <stdlib.h>
#include <stdio.h>
#include "Controller.h"
#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define NORMAL 0
#define EXPRESS 1
#define SEGUN_DISPO 2

// texto   / fprintf y fscanf
// binario/ fwrite y fread

int controller_loadTexto(LinkedList* pArray, char* ruta)
{
	int returnAux = ERROR;
	FILE* pArchivo;
	char header[500];
	char idEnvio[500];
	char nombreProducto[500];
	char idCamion[500];
	char zonaDestinos[500];
	char kmRecorridos[500];
	char tipoEntrega[500];
	float costoEnvio;
	Envio* pElement;

	if(pArray != NULL && ruta != NULL)
	{
		pArchivo = fopen(ruta,"r");
		if(pArchivo != NULL)
		{
			//empieza parser
			fscanf(pArchivo,"%[^\n]",header);
			do
			{
				if(fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idEnvio,nombreProducto,idCamion,zonaDestinos,kmRecorridos,tipoEntrega)==6)
				{
					costoEnvio = calcularCostoEnvio(atof(kmRecorridos), atoi(tipoEntrega));
					if(costoEnvio!= ERROR)
					{
						pElement = envio_newParametros(idEnvio, nombreProducto, idCamion, zonaDestinos, kmRecorridos, tipoEntrega, costoEnvio);
						returnAux = ll_add(pArray,pElement);
					}
				} else {
					returnAux = -2;
					break;
				}
			}while(!feof(pArchivo));
			//fin parser
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

int controller_printList(LinkedList* pArray)
{
	int returnAux = ERROR;

	if(pArray != NULL)
	{
		printf("\n%15s %15s %15s %15s %10s %25s %12s\n\n","ID ENVIO","NOMBRE","ID CAMION","ZONA","KM","TIPO ENT","COSTO ENVIO");
		returnAux = ll_map(pArray,controller_printOne);
	}
	return returnAux;
}



//funcion que calcule por cada envio el costo //1 solo p Element
//ll_get
//calcularcosto
//int ll_set(LinkedList* this, int index,void* pElement)
//ll_map (paso funcion)





//punto 4

int controller_nose(LinkedList* pArray)
{
	int returnAux = ERROR;

	if(pArray != NULL)
	{
	/*
	 1 - utn_getName()//ingrese zona
	{
		llclone

		llfilter // por zona compara
	}
	fopen()"w"/escribo en archivo con nombre zona ingreasa// controller guardar
	*/
	}
	return returnAux;
}








//"entidad zonas" //punto 5
/**
 * \brief Checks if alredy exists a rubro in the list
 * \param listRubro Rubro* Pointer to array of rubros
 * \param lenRubro int Array rubros length
 * \param rubro int rubro to check if exists
 * \return Return (-1) if Error [flag isEmpty is TRUE] - (0) if Ok
 *//*
static int rubroIsInList(Rubro* listRubro, int lenRubro, int rubro)
{
    int result = FALSE;
    int i;

    for (i = 0; i < lenRubro; i++)
    {
        if (listRubro[i].isEmpty == FALSE && listRubro[i].rubro == rubro)
        {
            result = TRUE; //alredy exists
            break;
        }
    }
    return result;
}
*/
/**
 * \brief Generates a list of rubro
 * \param listPublication Publication* Pointer to array of publications
 * \param lenPublication int Array publications length
 * \param listRubro Rubro* Pointer to array of rubros
 * \param lenRubro int Array rubros length
 * \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *//*
int zona_generateList(Publication* listPublication[], int lenPublication,Rubro *listRubro, int lenRubro)
{
    int result = ERROR;
    int i;
    int indexRubro = 0;
    int bufferRubro;

    if (listRubro != NULL && lenRubro > 0 && listPublication != NULL && lenPublication > 0 && rubro_init(listRubro, lenRubro) == SUCCESS)
    {
        for (i = 0; i < lenPublication; i++)
        {
            publi_getRubro(listPublication[i],&bufferRubro);
            if (listPublication[i] != NULL && rubroIsInList(listRubro, lenRubro, bufferRubro) == FALSE)
            {
                listRubro[indexRubro].rubro = listPublication[i]->rubro;
                listRubro[indexRubro].isEmpty = FALSE;
                indexRubro++;
            }
        }
        result = SUCCESS;
    }
    return result;
}*/
