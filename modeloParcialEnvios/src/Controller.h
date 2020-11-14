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

int controller_loadTexto(LinkedList* pArray, char* ruta);
int controller_printOne(void* shipping);
int controller_printList(LinkedList* pArray);



#endif /* CONTROLLER_H_ */
