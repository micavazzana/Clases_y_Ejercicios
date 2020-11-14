/*
 * Alumno.h
 *
 *  Created on: 1 oct. 2020
 *      Author: micavazzana
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define NAME_LEN 51

typedef struct
{
	int id;
	char nombre[NAME_LEN];
	int legajo;
	int isEmpty;

} Alumno;

/**
 * \brief To indicate that all position in the array are empty,
 * 		  this function put the flag (isEmpty) in TRUE in all position of the array
 * \param list Alumno* Pointer to array of alumnos
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int alumno_init(Alumno* list, int len);

/**
 * \brief Searches for an empty index in the array,
 * 		  this function checks if the flag(isEmpty) is TRUE and saves the first index found.
 * \param list Alumno* Pointer to array of alumnos
 * \param len int Array length
 * \return int Return value of the first empty index found -
 * 			   or (-1) if Error [Invalid length, NULL pointer or if there isn't more avaible space]
 */
int alumno_findEmptyIndex(Alumno* list, int len);

/**
 *
 */
int alumno_add(Alumno* list,int len,int* id);

/**
 * \brief Searches an Alumno by Id
 * \param list Alumno* Pointer to array of alumnos
 * \param len int Array length
 * \param id int, id searched
 * \return Return alumno index position or (-1) if [Invalid length or NULL pointer received or alumno not found]
 */
int alumno_findById(Alumno* list, int len,int id);

/**
 * \brief Lets the user to decide what field to change of an existing alumno
 * 			(also choosed by the user, searched by id)
 * \param list alumno* Pointer to array of alumnos
 * \param len int Array length
 * \param int id, id searched
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a alumno] - (0) if Ok
 */
int alumno_modify(Alumno* list, int len, int id);

/**
 * \brief Remove an alumno searched by Id (put isEmpty Flag in 1)
 * \param list Alumno* Pointer to array of alumnos
 * \param len int Array length
 * \param id int, id searched
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a alumno] - (0) if Ok
 */
int alumno_remove(Alumno* list, int len, int id);

/**
 * \brief Sort the elements in the array of alumnos, the argument order indicate UP or DOWN order
 * \param list Alumno* Pointer to array of alumnos
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int alumno_sort(Alumno* list, int len, int order);

/**
 * \brief Prints the data of only one alumno
 * \param list Alumno* Pointer to array of alumnos
 * \return Return (-1) if Error [flag isEmpty is TRUE] - (0) if Ok
 */
int alumno_printOne(Alumno list);

/**
 * \brief Print the content of alumnos array
 * \param list Alumno* Pointer to array of alumnos
 * \param length int  Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int alumno_printArray(Alumno* list, int len);

/**
 * \brief Checks if there is any data in the array
 * 			this function checks the flag (isEmpty). If it is false, there is data.
 * \param list Alumno* Pointer to array of alumnos
 * \param len int Array length
 * \return int Returns TRUE(1) if there is data, if not, returns FALSE(0)
 */
int isAnyData(Alumno* list, int len);

/**
 * \brief Forces data into the array of alumnos
 * \param list Alumno* Pointer to array of alumnos
 * \param id int* Pointer to the id to be asigned
 * \return Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int hardCodeData(Alumno* list,int* id);

#endif /* ALUMNO_H_ */
