/*
 * Nacionalidad.h
 *
 *  Created on: 1 oct. 2020
 *      Author: micavazzana
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define PAISLEN 51

typedef struct
{
	int id;
	char pais[PAISLEN];
	int isEmpty;

} Nacionalidad;

/**
 * \brief To indicate that all position in the array are empty,
 * 		  this function put the flag (isEmpty) in TRUE in all position of the array
 * \param list Nacionalidad* Pointer to array of nacionalidades
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int nac_init(Nacionalidad* list, int len);

/**
 * \brief Searches for an empty index in the array,
 * 		  this function checks if the flag(isEmpty) is TRUE and saves the first index found.
 * \param list Nacionalidad* Pointer to array of nacs
 * \param len int Array length
 * \return int Return value of the first empty index found -
 * 			   or (-1) if Error [Invalid length, NULL pointer or if there isn't more avaible space]
 */
int nac_findEmptyIndex(Nacionalidad* list, int len);

/**
 *
 */
int nac_add(Nacionalidad* listaNacionalidads,int len,int* id);

/**
 * \brief Searches an Nacionalidad by Id
 * \param list Nacionalidad* Pointer to array of nacs
 * \param len int Array length
 * \param id int, id searched
 * \return Return nac index position or (-1) if [Invalid length or NULL pointer received or nac not found]
 */
int nac_findById(Nacionalidad* list, int len,int id);

/**
 * \brief Lets the user to decide what field to change of an existing nac
 * 			(also choosed by the user, searched by id)
 * \param list nac* Pointer to array of nacs
 * \param len int Array length
 * \param int id, id searched
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a nac] - (0) if Ok
 */
int nac_modify(Nacionalidad* list, int len, int id);

/**
 * \brief Remove an nac searched by Id (put isEmpty Flag in 1)
 * \param list Nacionalidad* Pointer to array of nacs
 * \param len int Array length
 * \param id int, id searched
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a nac] - (0) if Ok
 */
int nac_remove(Nacionalidad* list, int len, int id);

/**
 * \brief Sort the elements in the array of nacs, the argument order indicate UP or DOWN order
 * \param list Nacionalidad* Pointer to array of nacs
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int nac_sort(Nacionalidad* list, int len, int order);

/**
 * \brief Prints the data of only one nac
 * \param list Nacionalidad* Pointer to array of nacs
 * \return Return (-1) if Error [flag isEmpty is TRUE] - (0) if Ok
 */
int nac_printOne(Nacionalidad list);

/**
 * \brief Print the content of nacs array
 * \param list Nacionalidad* Pointer to array of nacs
 * \param length int  Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int nac_printArray(Nacionalidad* list, int len);

/**
 * \brief Checks if there is any data in the array
 * 			this function checks the flag (isEmpty). If it is false, there is data.
 * \param list Nacionalidad* Pointer to array of nacs
 * \param len int Array length
 * \return int Returns TRUE(1) if there is data, if not, returns FALSE(0)
 */
int isAnyData(Nacionalidad* list, int len);

/**
 * \brief Forces data into the array of nacs
 * \param list Nacionalidad* Pointer to array of nacs
 * \param id int* Pointer to the id to be asigned
 * \return Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int hardCodeData(Nacionalidad* list,int* id);

#endif /* ALUMNO_H_ */
