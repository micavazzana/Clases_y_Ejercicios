/*
 * alumno.h
 *
 *  Created on: 22 sep. 2020
 *      Author: micavazzana
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define NOMBRE_LEN 50

typedef struct{

	char nombre[NOMBRE_LEN];
	int legajo;
	int isEmpty;
	int id;
}Alumno;

int alumno_alta(Alumno* listaAlumnos,int len,int* id);
int alumno_imprimirArray(Alumno* listaAlumnos,int len);
int alumno_initArray(Alumno* listaAlumnos,int len);
int alumno_findEmpty(Alumno* listaAlumnos,int len);
int alumno_modificar(Alumno* listaAlumnos,int len,int id);
int alumno_baja(Alumno* listaAlumnos,int len,int id);
int alumno_ordenarArray(Alumno* listaAlumnos,int len);
int alumno_buscarPorId(Alumno* listaAlumnos, int len,int id);
int alumno_imprimirUnSoloAlumno(Alumno* listaAlumnos, int len, int indice);

#endif /* ALUMNO_H_ */
