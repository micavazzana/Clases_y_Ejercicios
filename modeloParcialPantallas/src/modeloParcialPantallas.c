/*
 ============================================================================
 Name        : modeloParcialPantallas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Contratacion.h"
#include "inputs.h"
#define QTY_PANTALLA 100
#define QTY_CONTRATACION 1000

int main(void) {

	int option;
	Pantalla listPantalla[QTY_PANTALLA];
	Contratacion listContratacion[QTY_CONTRATACION];
	int bufferIdPantalla;

	if(pan_init(listPantalla,QTY_PANTALLA)==SUCCESS && con_init(listContratacion,QTY_CONTRATACION)==SUCCESS)
	{
		pan_hardCodeData(listPantalla);
		con_hardCodeData(listContratacion);
		do
		{
			if(utn_getNumber(&option, "\n\nIngrese una opcion: "
					"\n1.Cargar una pantalla"
					"\n2.Modificar una pantalla"
					"\n3.Eliminar una pantalla"
					"\n4.Contratar una publicidad"
					"\n5.Modificar condiciones de publicacion"
					"\n6.Cancelar Contratacion"
					"\n7.Consulta Facturacion"
					"\n8.Imprimir contratacion"
					"\n9.Imprimir pantalla"
					"\n10.Informar"
					"\n11.Salir\n",
					"Error, elija una opcion valida\n", 1, 11, 3) == SUCCESS)
			{
				switch(option)
				{
				case 1://Cargar una pantalla
					if(pan_add(listPantalla, QTY_PANTALLA) == SUCCESS)
					{
						printf("\nCarga realizada con exito\n");
					} else {
						printf("\nYa no hay lugar!\n");
					}
					break;
				case 2://Modificar una pantalla
					if(pan_isAnyData(listPantalla,QTY_PANTALLA)==TRUE)
					{
						pan_printArray(listPantalla, QTY_PANTALLA);
						if(utn_getNumber(&bufferIdPantalla,"\n\nIngrese el id de la pantalla que quiere modificar: ","\nError",0,INT_MAX,3)==SUCCESS &&
								pan_modify(listPantalla, QTY_PANTALLA,bufferIdPantalla) == SUCCESS)
						{
							printf("\nModificacion realizada con exito\n");
						} else {
							printf("\nNo se puedo realizar la modificacion o no existen cargas con ese id\n");
						}
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 3://Eliminar una pantalla
					if(pan_isAnyData(listPantalla,QTY_PANTALLA)==TRUE)
					{
						pan_printArray(listPantalla, QTY_PANTALLA);
						if(utn_getNumber(&bufferIdPantalla,"\n\nIngrese el id de la pantalla que quiere eliminar: ","\nError",0,INT_MAX,3)==SUCCESS &&
								pan_remove(listPantalla, QTY_PANTALLA,bufferIdPantalla) == SUCCESS)
						{
							printf("\nBaja realizada con exito\n");
						} else {
							printf("\nNo se puedo realizar la baja o no existen cargas con ese id\n");
						}
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 4://Contratar una publicidad
					if(pan_isAnyData(listPantalla,QTY_PANTALLA)==TRUE)
					{
						if(con_add(listContratacion,QTY_CONTRATACION,listPantalla,QTY_PANTALLA)==SUCCESS)
						{
							printf("\nCarga realizada con exito\n");
						} else {
							printf("\nNo se puedo realizar la carga. No hay lugar, o no existe el id de pantalla ingresado\n");
						}
					} else {
						printf("\nNo hay pantallas donde realizar la contratacion");
					}
					break;
				case 5://Modificar condiciones de publicacion
					if(pan_isAnyData(listPantalla,QTY_PANTALLA)==TRUE && con_isAnyData(listContratacion,QTY_CONTRATACION)==TRUE)
					{
						if(con_modify(listContratacion,QTY_CONTRATACION,listPantalla,QTY_PANTALLA)==SUCCESS)
						{
							printf("\nModificacion realizada con exito\n");
						} else {
							printf("\nNo se puedo realizar la modificacion\n");
						}
					} else {
						printf("\nNo hay contataciones cargadas");
					}
					break;
				case 6://Cancelar Contratacion
					if(pan_isAnyData(listPantalla,QTY_PANTALLA)==TRUE &&  con_isAnyData(listContratacion,QTY_CONTRATACION)==TRUE)
					{
						if(con_remove(listContratacion,QTY_CONTRATACION,listPantalla,QTY_PANTALLA)==SUCCESS)
						{
							printf("\nBaja realizada con exito\n");
						} else {
							printf("\nNo se puedo realizar la baja\n");
						}
					} else {
						printf("\nNo hay contataciones cargadas");
					}
					break;
				case 7://Consulta Facturacion
					if(pan_isAnyData(listPantalla,QTY_PANTALLA)==TRUE && con_isAnyData(listContratacion,QTY_CONTRATACION)==TRUE)
					{
						consultaFacturacion(listContratacion,QTY_CONTRATACION,listPantalla,QTY_PANTALLA);
					} else {
						printf("\n\nNo hay contataciones cargadas");
					}
					break;
				case 8:
					if(pan_isAnyData(listPantalla,QTY_PANTALLA)==TRUE && con_isAnyData(listContratacion,QTY_CONTRATACION)==TRUE)
					{
						con_printArray(listContratacion,QTY_CONTRATACION,listPantalla,QTY_PANTALLA);
					} else {
						printf("\nNo hay contataciones cargadas");
					}
					break;
				case 9:
					if(pan_isAnyData(listPantalla,QTY_PANTALLA)==TRUE)
					{
						pan_printArray(listPantalla,QTY_PANTALLA);
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 10://Informar
					if(pan_isAnyData(listPantalla,QTY_PANTALLA)==TRUE && con_isAnyData(listContratacion,QTY_CONTRATACION)==TRUE)
					{
						con_informar(listContratacion,QTY_CONTRATACION,listPantalla,QTY_PANTALLA);
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 11:
					printf("\nChau chau adios!\n");
					break;
				}
			}
		}while(option!=11);
	} else {
		printf("\nERROR!! No se pudo iniciar el programa\n");
	}
	return EXIT_SUCCESS;
}
