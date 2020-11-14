/*
 ============================================================================
 Name        : clase_09.c //10 y 11
 Author      : 
 Version     : version gdb: https://onlinegdb.com/BJPFGUbIP
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "inputs.h"
#define TAM 5
#define TRUE 1
#define FALSE 0

int main(void) {

	int opcion;
	Alumno listaAlumnos[TAM];
	int hayDatosCargados = FALSE;
	int auxiliarId;
	int id = 1;

	if (alumno_initArray(listaAlumnos, TAM) == 0) {

		do {
			utn_getNumber(&opcion, "\n\nIngrese una opcion: "
					"\n1.Alta alumno"
					"\n2.Modificacion Alumno"
					"\n3.Baja Alumno"
					"\n4.Ordenar Alumnos"
					"\n5.Mostrar Alumnos"
					"\n6.SALIR\n", "Error, elija una opcion valida\n", 1, 6, 3);
			switch (opcion)
			{
			case 1:
				printf("CARGA DE DATOS:\n\n");
				if(alumno_alta(listaAlumnos, TAM,&id) == 0)
				{
					printf("\nCarga realizada con exito\n");
					hayDatosCargados = TRUE;
				} else {
					printf("\nYa no hay lugar!\n");
				}
				break;
			case 2:
				if(hayDatosCargados)
				{
					printf("\nMODIFICACION DE DATOS: \n");
					alumno_imprimirArray(listaAlumnos, TAM);
					if (utn_getNumber(&auxiliarId,"\nIngrese el id del alumno que quiere modificar: ","\nError",0,TAM,3)==0 &&
							alumno_modificar(listaAlumnos, TAM,auxiliarId) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					} else {
						printf("\nNo se puedo realizar la modificacion. No existen cargas con ese id\n");
					}
				} else {
					printf("\nDebe cargar datos primero");
				}
				break;
			case 3:
				if(hayDatosCargados)
				{
					printf("\nELIMINACION DE DATOS: \n");
					alumno_imprimirArray(listaAlumnos, TAM);
					if (utn_getNumber(&auxiliarId,"\nIngrese el id del alumno que quiere eliminar: ","\nError",0,TAM,3)==0 &&
					alumno_baja(listaAlumnos, TAM,auxiliarId) == 0)
					{
						printf("\nBaja realizada con exito\n");
					} else {
						printf("\nNo se puedo realizar la baja. No existen cargas con ese id\n");
					}
				} else {
					printf("\nDebe cargar datos primero");
				}
				break;
			case 4:
				if(hayDatosCargados)
				{
					printf("\nOrdenando...");
					if (alumno_ordenarArray(listaAlumnos, TAM) == 0)
					{
						printf("\nOrdenado,prosiga!\n");
					} else {
						printf("\nNo se puedo ordenar\n");
					}
				} else {
					printf("\nDebe cargar datos primero");
				}
				break;
			case 5:
				if(hayDatosCargados)
				{
					printf("\nLISTADO DE DATOS: \n");
					alumno_imprimirArray(listaAlumnos, TAM);
				} else {
					printf("\nDebe cargar datos primero");
				}
				break;
			case 6:
				printf("\nChau chau adios\n");
				break;
			}
		} while (opcion != 6);
	}
	return EXIT_SUCCESS;
}
