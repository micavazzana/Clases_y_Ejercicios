/*
 * nac.h
 *
 *  Created on: 29 sep. 2020
 *      Author: micavazzana
 */

#ifndef NAC_H_
#define NAC_H_
#define NOMBRE_LEN 50

typedef struct{

	char nombre[NOMBRE_LEN];
	int isEmpty;
	int id;
}Nacionalidad;

int nac_alta(Nacionalidad* lista,int len,int* id);
int nac_imprimirUnaNac(Nacionalidad lista);
int nac_imprimirArray(Nacionalidad* lista,int len);
int nac_initArray(Nacionalidad* lista,int len);
int nac_findEmptyIndex(Nacionalidad* lista,int len);
int nac_modificar(Nacionalidad* lista,int len,int id);
int nac_baja(Nacionalidad* lista,int len,int id);
int nac_ordenarArray(Nacionalidad* lista,int len,int orden);
int nac_buscarPorId(Nacionalidad* lista, int len,int id);

#endif /* NAC_H_ */
