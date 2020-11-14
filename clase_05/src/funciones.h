/*
 * funciones.h
 *
 *  Created on: 8 sep. 2020
 *      Author: micavazzana
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


int getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int calcularMaximo(int arrayInt[],int tamArray,int* pMaximo);
int calcularMinimo(int arrayInt[],int tamArray,int* pMinimo);
int calcularPromedio(int arrayInt[],int tamArray,float* pPromedio);
int ordenar(int *array, int len);
void imprimirArray(int *array, int len,char *texto);

#endif /* FUNCIONES_H_ */
