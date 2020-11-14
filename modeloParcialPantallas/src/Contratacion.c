/*
 * Contrataciones.c
 *
 *  Created on: 1 oct. 2020
 *      Author: micavazzana
 */
#include "inputs.h"
#include "Contratacion.h"
#define UP 1
#define DOWN 0

static int generateNewId(void);

int con_init(Contratacion *list, int len)
{
	int result = ERROR;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		result = SUCCESS;
	}
	return result;
}

int con_findEmptyIndex(Contratacion *list, int len)
{
	int result = ERROR;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty)
			{
				result = i;
				break;
			}
		}
	}
	return result;
}

int con_add(Contratacion *list, int len, Pantalla *listPantalla, int lenPantalla)
{
	int result = ERROR;
	Contratacion bufferContratacion;
	int bufferIdPantalla;
	int index;

	index = con_findEmptyIndex(list, len);
	if (list != NULL && len > 0&& listPantalla != NULL && lenPantalla > 0 && index != ERROR)
	{
		if (pan_printArray(listPantalla, lenPantalla) == SUCCESS &&
			utn_getNumber(&bufferIdPantalla,"\nIngrese el id de la pantalla donde realizara la contratacion: ","\nError", 0, INT_MAX, 3) == SUCCESS &&
			pan_findById(listPantalla, lenPantalla,bufferIdPantalla)!=ERROR &&
			utn_getIdCard(bufferContratacion.cuitCliente, CUIT_LEN, "\nIngrese cuit: ","\nError", 3) == SUCCESS &&
			utn_getIdCard(bufferContratacion.nombreArchivo, NOMBRE_LEN, "\nIngrese nombre de archivo: ","\nError", 3) == SUCCESS &&
			utn_getNumber(&bufferContratacion.dias,"Ingrese la cantidad de dias: ","\nError",0,365,3)== SUCCESS)
		{
			bufferContratacion.isEmpty = FALSE;
			bufferContratacion.idContratacion = generateNewId();
			bufferContratacion.idPantalla = bufferIdPantalla;
			list[index] = bufferContratacion;
			result = SUCCESS;
		}
	}
	return result;
}

int con_modify(Contratacion *list, int len, Pantalla *listPantalla,	int lenPantalla)
{
	int result = ERROR;
	int index;
	Contratacion bufferContratacion;
	int bufferId;

	if (list != NULL && len > 0 && listPantalla != NULL && lenPantalla > 0)
	{
		if (utn_getIdCard(bufferContratacion.cuitCliente, CUIT_LEN, "\nIndique el CUIT del cliente para conocer sus contrataciones: ", "\nError", 3) == SUCCESS
				&& con_comprobarCuitExiste(list, len,bufferContratacion.cuitCliente) == SUCCESS
				&& con_imprimirContratacionPorCuit(list, len, listPantalla,lenPantalla, bufferContratacion.cuitCliente) == SUCCESS
				&& utn_getNumber(&bufferId,	"\nIngrese el id de la contratacion a modificar", "\nError", 0, INT_MAX, 3) == SUCCESS
				&& con_findById(list, len, bufferId) != ERROR
				&& utn_getNumber(&bufferContratacion.dias, "\nIngrese nueva cantidad de dias: ", "\nError", 0, 365, 3) == SUCCESS)
		{
			index = con_findById(list, len, bufferId);
			list[index].dias = bufferContratacion.dias;
			result = SUCCESS;
		}
	}
	return result;
}

int con_findById(Contratacion *list, int len, int id)
{
	int result = ERROR;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == FALSE && list[i].idContratacion == id)
			{
				result = i;
				break;
			}
		}
	}
	return result;
}

int con_comprobarCuitExiste(Contratacion *list, int len, char *cuitRecibido)
{
	int retorno = ERROR;
	int i;

	if (list != NULL && cuitRecibido != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty==FALSE && strncmp(list[i].cuitCliente, cuitRecibido, CUIT_LEN) == 0)
			{
				retorno = SUCCESS;
				break;
			}
		}
	}
	return retorno;
}


int con_remove(Contratacion *list, int len, Pantalla *listPantalla,	int lenPantalla)
{
	int result = ERROR;
	int index;
	Contratacion bufferContratacion;
	int bufferId;
	char bufferAnswer[10];

	if (list != NULL && len > 0 && listPantalla != NULL && lenPantalla > 0)
	{
		if (utn_getIdCard(bufferContratacion.cuitCliente, CUIT_LEN, "\nIndique el CUIT del cliente para conocer sus contrataciones: ", "\nError", 3) == SUCCESS
				&& con_comprobarCuitExiste(list, len,bufferContratacion.cuitCliente) == SUCCESS
				&& con_imprimirContratacionPorCuit(list, len, listPantalla,lenPantalla, bufferContratacion.cuitCliente) == SUCCESS
				&& utn_getNumber(&bufferId,	"\nIngrese el id de la contratacion a dar de baja", "\nError", 0, INT_MAX, 3) == SUCCESS
				&& con_findById(list, len, bufferId) != ERROR
				&& utn_getName(bufferAnswer, 10,"\nSeguro que desea eliminar? Debe ingresar 'Si' para proseguir con la baja ","\nError,ingrese una respuesta valida.", 3) == SUCCESS
				&& strncasecmp(bufferAnswer, "si", 10) == 0)
        {
			index = con_findById(list, len, bufferId);
			list[index].isEmpty = TRUE;
			result = SUCCESS;
		}
	}
	return result;
}

int con_printOne(Contratacion list, Pantalla listPantalla)
{
	int result = ERROR;

	if (list.isEmpty == FALSE && listPantalla.isEmpty == FALSE)
	{
		printf("\n%5d %15s %15s %8d %5d %18s %14.2f",
				list.idContratacion,
				list.cuitCliente,
				list.nombreArchivo,
				list.dias,
				list.idPantalla,
				listPantalla.nombre,
				listPantalla.precio);
		result = SUCCESS;
	}
	return result;
}

int con_printArray(Contratacion *listContratacion, int lenContratacion, Pantalla *listPantalla, int lenPantalla)
{
	int result = ERROR;
	int i;
	int indicePantalla;

	if (listContratacion != NULL && lenContratacion > 0 && listPantalla != NULL	&& lenPantalla > 0)
	{
		printf("\n%5s %15s %15s %8s %5s %15s %15s", "ID CON", "CUIT", "NOMBRE ARCHIVO", "DIAS", "ID PAN", "NOMBRE PAN","PRECIO");
		for (i = 0; i < lenContratacion; i++)
		{
			if (listContratacion[i].isEmpty == FALSE)
			{
				indicePantalla = pan_findById(listPantalla, lenPantalla, listContratacion[i].idPantalla);
				con_printOne(listContratacion[i], listPantalla[indicePantalla]);
			}
		}
		result = SUCCESS;
	}
	return result;
}

int con_imprimirContratacionPorCuit(Contratacion *listContratacion,int lenContratacion, Pantalla *listPantalla, int lenPantalla,char* cuitRecibido)
{
	int result = ERROR;
	int i;
	int indicePantalla;

	if (listContratacion != NULL && lenContratacion > 0 && listPantalla != NULL && lenPantalla > 0 && cuitRecibido != NULL)
	{
		printf("\n%5s %15s %15s %8s %5s %15s %15s", "ID CON", "CUIT", "NOMBRE ARCHIVO", "DIAS", "ID PAN", "NOMBRE PAN","PRECIO");
		for (i = 0; i < lenContratacion; i++)
		{
			if (listContratacion[i].isEmpty == FALSE && strncmp(listContratacion[i].cuitCliente, cuitRecibido, CUIT_LEN) == 0)
			{
				indicePantalla = pan_findById(listPantalla, lenPantalla,listContratacion[i].idPantalla);
				con_printOne(listContratacion[i], listPantalla[indicePantalla]);
			}
		}
		result = SUCCESS;
	}
	return result;
}

int con_isAnyData(Contratacion *list, int len)
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

int con_hardCodeData(Contratacion *list)
{
	int result=ERROR;
    char cuitCliente[][CUIT_LEN]= {"1234","2222","2525","1234","2222","2525"};
    char nombreArchivo[][NOMBRE_LEN]= {"Archivo1.mov","Archivo2.mov","Archivo3.mov","Archivo4.mov","Archivo5.mov","Archivo6.mov"};
    int idPantalla[]= {4,4,1,2,2,3};
    int dias[]= {5,2,10,3,7,6};
	int i;

	if(list!=NULL)
	{
		for(i=0;i<6;i++)
		{
	        strncpy(list[i].cuitCliente,cuitCliente[i],CUIT_LEN);
            strncpy(list[i].nombreArchivo,nombreArchivo[i],NOMBRE_LEN);
            list[i].idPantalla = idPantalla[i];
            list[i].dias = dias[i];
            list[i].idContratacion = generateNewId();
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

int consultaFacturacion(Contratacion *listContratacion, int lenContratacion, Pantalla *listPantalla, int lenPantalla)
{
	int result = ERROR;
	Contratacion bufferContratacion;
	int i;
	int indicePantalla;
	float facturacion[1000];

	if (listContratacion != NULL && lenContratacion > 0 && listPantalla != NULL && lenPantalla > 0)
	{
		if (utn_getIdCard(bufferContratacion.cuitCliente, CUIT_LEN, "\nIndique el CUIT del cliente para conocer su facturacion: ", "\nError", 3) == SUCCESS
				&& con_comprobarCuitExiste(listContratacion, lenContratacion, bufferContratacion.cuitCliente) == SUCCESS)
		{
			for (i = 0; i < lenContratacion; i++)
			{
				if (listContratacion[i].isEmpty == FALSE && strncmp(listContratacion[i].cuitCliente, bufferContratacion.cuitCliente, CUIT_LEN) == 0)
				{
					indicePantalla = pan_findById(listPantalla, lenPantalla, listContratacion[i].idPantalla);
					facturacion[i] = listPantalla[indicePantalla].precio * listContratacion[i].dias;
					printf("\n%5s %14s %15s %8s %5s %15s %15s\n", "ID CON", "CUIT", "NOMBRE ARCHIVO", "DIAS", "ID PAN", "NOMBRE PAN", "PRECIO");
					con_printOne(listContratacion[i], listPantalla[indicePantalla]);
					printf("\n\nTotal: %.2f\n", facturacion[i]);
				}
			}
			result = SUCCESS;
		}
	}
	return result;
}

int con_informar(Contratacion *listContratacion, int lenContratacion, Pantalla *listPantalla, int lenPantalla)
{
	int result = ERROR;
	int opcion;

	if (listContratacion != NULL && lenContratacion > 0 && listPantalla != NULL && lenPantalla > 0)
	{
		do
		{
			if(utn_getNumber(&opcion, "\n\nIngrese una opcion: "
				"\n1.Lista de cada cliente con cantidad de contrataciones e importe a pagar por cada una"
				"\n2.Cliente con importe mas alto a facturar"
				"\n3.Volver al menu principal\n",
				"Error, elija una opcion valida\n", 1, 3, 3) == SUCCESS)
			{
				switch(opcion)
				{
					case 1:
						//
						break;
					case 2:
						//
						break;
				}
			}
		}while(opcion!=3);
		result=SUCCESS;
	}
	return result;
}


int generarListaClientes(Contratacion* listContratacion,int lenContratacion, char* listaClientes)
{
	int result=ERROR;
	int i;
	int indexCuit=0;

	if (listContratacion != NULL && lenContratacion > 0 && listaClientes != NULL)
	{
		for(i=0;i<lenContratacion;i++)
		{
			if(con_comprobarCuitExiste(listContratacion[i],lenContratacion,listaClientes[i])==ERROR)
			{
				strncpy(listaClientes[indexCuit],listContratacion[i].cuitCliente,CUIT_LEN);
				indexCuit++;
			}
		}
		result=SUCCESS;
	}
	return result;
}

/*
void generarInforme(Contratacion* listContratacion,int lenContratacion)
{
	char listaClientes[1000][CUIT_LEN];
	generarListaClientes(listContratacion,lenContratacion,listaClientes);
	int i;

	for(i=0;i<1000;i++)
	{
	    cantidad = calcularCantContratacionesDeUnCliente(listaContrat,len,listaClientes[i].cuit)
	    printf("%s    %d\n",listaClientes[i].cuit,cantidad);

	    for(j....) // iteramos la lista de contrataciones
	    {
	       SI la contratacion es del cliente (comparo el cuit)
	       if(compara cuit)
	       {
	          precio = calcularImporteAPagar(...,listaContratacion[j].idContratacion)
		  printf("contratacion %d  precio:%f",idContratacion,precio)
	       }
	    }
}

*/

