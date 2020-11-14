/*
 * Pantalla.h
 *
 *  Created on: 1 oct. 2020
 *      Author: micavazzana
 */
#ifndef PANTALLA_H_
#define PANTALLA_H_
#define NOMBRE_LEN 50
#define DIRE_LEN 20
#define TIPO_LED 2
#define TIPO_LCD 1
#define SUCCESS 0
#define ERROR -1
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>

typedef struct
{
    int tipo;
    char nombre[NOMBRE_LEN];
    char direccion[DIRE_LEN];
    float precio;
    int isEmpty;
    int idPantalla;

} Pantalla;

/**
 * \brief To indicate that all position in the array are empty,
 * 		  this function put the flag (isEmpty) in TRUE in all position of the array
 * \param list Pantalla* Pointer to array of pans
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int pan_init(Pantalla* list, int len);

/**
 * \brief Searches for an empty index in the array,
 * 		  this function checks if the flag(isEmpty) is TRUE and saves the first index found.
 * \param list Pantalla* Pointer to array of pans
 * \param len int Array length
 * \return int Return value of the first empty index found -
 * 			   or (-1) if Error [Invalid length, NULL pointer or if there isn't more avaible space]
 */
int pan_findEmptyIndex(Pantalla* list, int len);

/**
 *
 */
int pan_add(Pantalla* list,int len);

/**
 * \brief Searches an Pantalla by Id
 * \param list Pantalla* Pointer to array of pans
 * \param len int Array length
 * \param id int, id searched
 * \return Return pan index position or (-1) if [Invalid length or NULL pointer received or pan not found]
 */
int pan_findById(Pantalla* list, int len,int id);

/**
 * \brief Lets the user to decide what field to change of an existing pan
 * 			(also choosed by the user, searched by id)
 * \param list pan* Pointer to array of pans
 * \param len int Array length
 * \param int id, id searched
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a pan] - (0) if Ok
 */
int pan_modify(Pantalla* list, int len, int id);

/**
 * \brief Remove an pan searched by Id (put isEmpty Flag in 1)
 * \param list Pantalla* Pointer to array of pans
 * \param len int Array length
 * \param id int, id searched
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a pan] - (0) if Ok
 */
int pan_remove(Pantalla* list, int len, int id);

/**
 * \brief Sort the elements in the array of pans, the argument order indicate UP or DOWN order
 * \param list Pantalla* Pointer to array of pans
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int pan_sort(Pantalla* list, int len, int order);

/**
 * \brief Prints the data of only one pan
 * \param list Pantalla* Pointer to array of pans
 * \return Return (-1) if Error [flag isEmpty is TRUE] - (0) if Ok
 */
int pan_printOne(Pantalla list);

/**
 * \brief Print the content of pans array
 * \param list Pantalla* Pointer to array of pans
 * \param length int  Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int pan_printArray(Pantalla* list, int len);

/**
 * \brief Checks if there is any data in the array
 * 			this function checks the flag (isEmpty). If it is false, there is data.
 * \param list Pantalla* Pointer to array of pans
 * \param len int Array length
 * \return int Returns TRUE(1) if there is data, if not, returns FALSE(0)
 */
int pan_isAnyData(Pantalla* list, int len);

/**
 * \brief Forces data into the array of pans
 * \param list Pantalla* Pointer to array of pans
 * \param id int* Pointer to the id to be asigned
 * \return Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int pan_hardCodeData(Pantalla* list);

#endif /* PANTALLA_H_ */
