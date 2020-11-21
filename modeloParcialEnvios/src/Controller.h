/*
 * controller.h
 *
 *  Created on: 13 nov. 2020
 *      Author: micavazzana
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Envio.h"
#include "LinkedList.h"
#include "Parser.h"

int controller_loadFromText(LinkedList* listaEnvios, char* ruta);
int controller_printOne(void* shipping);
int controller_printList(LinkedList* listaEnvios);
int controller_CalculateOneCost(void* pElement);
int controller_printListWithCost(LinkedList* listaEnvios);
int controller_printOneWithCost(void* pElement);
int controller_saveFileWithShippingByZone(LinkedList* listaEnvios);
int controller_saveToText(LinkedList* listaEnvios, char* ruta);

int controller_createListOfZones(LinkedList* listaEnvios);
LinkedList* zona_generateList(LinkedList* listaEnvios);
int controller_printOneZone(void* pElement);
int controller_printListZone(LinkedList* listaEnvios);

#endif /* CONTROLLER_H_ */


/***********  NOTAS  PARA MI *************/
// texto   / fprintf y fscanf
// binario/ fwrite y fread
