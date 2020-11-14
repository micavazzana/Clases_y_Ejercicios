/*
 ============================================================================
 Name        : clase_12.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Alumno.h"
#include "nac.h"
#include "inputs.h"
#define QTY_EMPLOYEE 1000
#define SUCCESS 0
#define ERROR -1
#define TRUE 1
#define FALSE 0

int main(void) {

	int option;
	Alumno listAlumnos[QTY_EMPLOYEE];
	int id = 1;
	int bufferId;
	int bufferOrden;

	if(alumno_init(listAlumnos,QTY_EMPLOYEE)==SUCCESS)
	{
		hardCodeData(listAlumnos,&id);
		do
		{
			if(utn_getNumber(&option,"\n\nIngrese una opcion: "
					"\n1.Alta "
					"\n2.Modificacion "
					"\n3.Baja "
					"\n4.Ordenar"
					"\n5.Informar"
					"\n6.SALIR\n",
					"Error, elija una opcion valida\n", 1, 6, 3)==SUCCESS)
			{
				switch(option)
				{
				case 1://cargar
					if(alumno_add(listAlumnos, QTY_EMPLOYEE,&id) == SUCCESS)
					{
						printf("\nCarga realizada con exito\n");
					} else {
						printf("\nYa no hay lugar!\n");
					}
					break;
				case 2://modificar
					if(isAnyData(listAlumnos,QTY_EMPLOYEE)==TRUE)//chequea que haya datos cargados
					{
						alumno_printArray(listAlumnos, QTY_EMPLOYEE);
						if(utn_getNumber(&bufferId,"\n\nIngrese el id del alumno que quiere modificar: ","\nError",0,INT_MAX,3)==SUCCESS &&
								alumno_modify(listAlumnos, QTY_EMPLOYEE,bufferId) == SUCCESS)
						{
							printf("\nModificacion realizada con exito\n");
						} else {
							printf("\nNo se puedo realizar la modificacion o no existen cargas con ese id\n");
						}
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 3://eliminar
					if(isAnyData(listAlumnos,QTY_EMPLOYEE)==TRUE)//chequea que haya datos cargados
					{
						alumno_printArray(listAlumnos, QTY_EMPLOYEE);
						if(utn_getNumber(&bufferId,"\n\nIngrese el id del alumno que quiere eliminar: ","\nError",0,INT_MAX,3)==SUCCESS &&
								alumno_remove(listAlumnos, QTY_EMPLOYEE,bufferId) == SUCCESS)
						{
							printf("\nBaja realizada con exito\n");
						} else {
							printf("\nNo se puedo realizar la baja o no existen cargas con ese id\n");
						}
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 4://ordenar
					if(isAnyData(listAlumnos,QTY_EMPLOYEE)==TRUE)//chequea que haya datos cargados
					{
						if(utn_getNumber(&bufferOrden,"\nIngrese en que orden quiere ver la lista [1-UP/0-DOWN]: ","\nError, debe ingresar o 0 o 1",0,1,3)==SUCCESS &&
								alumno_sort(listAlumnos,QTY_EMPLOYEE,bufferOrden)==SUCCESS)
						{
							printf("\nOrdenado, prosiga");
						}
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 5://imprimir
					if(isAnyData(listAlumnos,QTY_EMPLOYEE)==TRUE)//chequea que haya datos cargados
					{
						alumno_printArray(listAlumnos,QTY_EMPLOYEE);
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 6:
					printf("\nChau chau adios!\n");
					break;
				}
			}
		}while(option!=6);
	} else {
		printf("\nERROR!! No se pudo iniciar el programa\n");
	}
	return EXIT_SUCCESS;
}
