/*
 * nac.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ezemanzano
 */

#ifndef NAC_H_
#define NAC_H_

#define LONG 50
#define TRUE 1
#define FALSE 0

typedef struct
{
	char pais[LONG];
	char nombre [LONG];
	int isEmpty;
	int id;
} Nac;

int nac_init(Nac * pArrayNacs, int limite);

int nac_alta (Nac * pArrayNacs, int limite);
int nac_baja (Nac * pArrayNacs, int limite);
int nac_modificar (Nac * pArrayNacs, int limite);

int nac_imprimir (Nac * pArrayNacs , int limite);

int nac_buscarLibre (Nac * pArrayNacs, int limite);
int nac_buscarLibreRef (Nac * pArrayNacs, int limite, int * pIndice);
int nac_buscarIndicePorId (Nac * pArrayNacs, int limite, int idBuscar,int * pIndice);
int nac_ordenarPorNombre (Nac * pArrays, int limite , int orden);

#endif /* NAC_H_ */
