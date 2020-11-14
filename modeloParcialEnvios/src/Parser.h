/*
 * Parser.h
 *
 *  Created on: 14 nov. 2020
 *      Author: micavazzana
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int parser_EnvioTxt(FILE* pFile , LinkedList* pArray);
int parser_EnvioBinario(FILE* pFile , LinkedList* pArray);

#endif /* PARSER_H_ */
