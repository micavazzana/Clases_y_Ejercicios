/*
 ============================================================================
 Name        : modeloParcialEnvios.c
 Author      : Mica Vazzana
 Version     :
 Copyright   : micavazzana
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "LinkedList.h"
#include "Controller.h"
#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

int main(void) {

	int option;
	LinkedList* listaEnvios = ll_newLinkedList();
	int estaCargado = FALSE;

	if(listaEnvios != NULL)
	{
		do
		{
			if(utn_getNumber(&option,
					"\n\nIngrese una opcion: \n"
					"\n1. Cargar los datos desde el archivo data.csv (modo texto)."
					"\n2. Imprimir Envios"
					"\n3. Calcular costos"
					"\n4. Generar archivo de costos para zona"
					"\n5. Imprimir lista de zonas"
					"\n6. SALIR\n\n","\nError! elija una opcion valida",1,6,5)==SUCCESS)
			{
				switch(option)
				{
				case 1://pedir nombre del archivo

					if(estaCargado == FALSE)
					{
						if(controller_loadFromText(listaEnvios,"data.csv") == SUCCESS)//pasar variable
						{
							printf("Cargado con exito");
							estaCargado = TRUE;
						} else {
							printf("ERROR");
						}
					} else {
						printf("Ya esta cargado");
					}
					break;
				case 2:
					if(ll_isEmpty(listaEnvios) == 0)
					{
						controller_printList(listaEnvios);
					} else {
						printf("\nDebe cargar el archivo primero");
					}
					break;
				case 3:
					if(ll_isEmpty(listaEnvios) == 0)
					{
						ll_map(listaEnvios,controller_CalculateOneCost);
						controller_printListWithCost(listaEnvios);
					} else {
						printf("\nDebe cargar el archivo primero");
					}
					break;
				case 4:
					if(ll_isEmpty(listaEnvios) == 0)
					{
						controller_saveFileWithShippingByZone(listaEnvios);
					} else {
						printf("\nDebe cargar el archivo primero");
					}
					break;
				case 5:
					if(ll_isEmpty(listaEnvios) == 0)
					{
						controller_createListOfZones(listaEnvios);
					} else {
						printf("\nDebe cargar el archivo primero");
					}
					break;
				case 6:
					printf("chau chau");
					break;
				}//fin switch
			}//fin if get menu
		}while(option!=6);
	} else {
		printf("no hay memoria para iniciar el programa");
	}
	return EXIT_SUCCESS;
}
