/*
 * funciones.h
 *
 *  Created on: 17 sep. 2020
 *      Author: micavazzana
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int imprimirArray(int* arrayNumeros,int len);
int contadorDeNumeros(int* arrayNumeros,int len,int numero,int* pCantidadQueHay);
int contadorDeCaracteres(char* cadenaCaracteres,char caracterAContar,int* pCantidadQueHay);
int validarCaracteresAlfabeticos(char* cadenaCaracteres);
int getString(char* string, int len);
int getNombre(char* nombre, int len, char* mensaje);

#endif /* FUNCIONES_H_ */
