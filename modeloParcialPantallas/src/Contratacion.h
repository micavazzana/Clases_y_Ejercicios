/*
 * Contrataciones.h
 *
 *  Created on: 1 oct. 2020
 *      Author: micavazzana
 */
#ifndef CONTRATACIONES_H_
#define CONTRATACIONES_H_
#define NOMBRE_LEN 50
#define CUIT_LEN 20
#include "Pantalla.h"

typedef struct
{
    char cuitCliente[CUIT_LEN];
    char nombreArchivo[NOMBRE_LEN];
    int isEmpty;
    int idContratacion;
    int idPantalla;
    int dias;

} Contratacion;

int con_comprobarCuitExiste(Contratacion *list, int len, char *cuitRecibido);
int con_imprimirContratacionPorCuit(Contratacion *list, int len, Pantalla* listPantalla, int lenPantalla,char* cuitRecibido);
int consultaFacturacion(Contratacion* listContratacion, int lenContratacion, Pantalla* listPantalla, int lenPantalla);
int con_informar(Contratacion *listContratacion, int lenContratacion, Pantalla *listPantalla, int lenPantalla);

/**
 * \brief To indicate that all position in the array are empty,
 * 		  this function put the flag (isEmpty) in TRUE in all position of the array
 * \param list Contratacion* Pointer to array of cons
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int con_init(Contratacion* list, int len);

/**
 * \brief Searches for an empty index in the array,
 * 		  this function checks if the flag(isEmpty) is TRUE and saves the first index found.
 * \param list Contratacion* Pointer to array of cons
 * \param len int Array length
 * \return int Return value of the first empty index found -
 * 			   or (-1) if Error [Invalid length, NULL pointer or if there isn't more avaible space]
 */
int con_findEmptyIndex(Contratacion* list, int len);

/**
 *
 */
int con_add(Contratacion *list, int len, Pantalla* listPantalla, int lenPantalla);

/**
 * \brief Searches an Contratacion by Id
 * \param list Contratacion* Pointer to array of cons
 * \param len int Array length
 * \param id int, id searched
 * \return Return con index position or (-1) if [Invalid length or NULL pointer received or con not found]
 */
int con_findById(Contratacion* list, int len,int id);

/**
 * \brief Lets the user to decide what field to change of an existing con
 * 			(also choosed by the user, searched by id)
 * \param list con* Pointer to array of cons
 * \param len int Array length
 * \param int id, id searched
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a con] - (0) if Ok
 */
int con_modify(Contratacion *list, int len,Pantalla* listPantalla,int lenPantalla);

/**
 * \brief Remove an con searched by Id (put isEmpty Flag in 1)
 * \param list Contratacion* Pointer to array of cons
 * \param len int Array length
 * \param id int, id searched
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a con] - (0) if Ok
 */
int con_remove(Contratacion *list, int len, Pantalla *listPantalla,	int lenPantalla);

/**
 * \brief Sort the elements in the array of cons, the argument order indicate UP or DOWN order
 * \param list Contratacion* Pointer to array of cons
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int con_sort(Contratacion* list, int len, int order);

/**
 * \brief Prints the data of only one con
 * \param list Contratacion* Pointer to array of cons
 * \return Return (-1) if Error [flag isEmpty is TRUE] - (0) if Ok
 */
int con_printOne(Contratacion list,Pantalla listPantalla);

/**
 * \brief Print the content of cons array
 * \param list Contratacion* Pointer to array of cons
 * \param length int  Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int con_printArray(Contratacion* list, int len, Pantalla* listPantalla,int lenPantalla);

/**
 * \brief Checks if there is any data in the array
 * 			this function checks the flag (isEmpty). If it is false, there is data.
 * \param list Contratacion* Pointer to array of cons
 * \param len int Array length
 * \return int Returns TRUE(1) if there is data, if not, returns FALSE(0)
 */
int con_isAnyData(Contratacion* list, int len);

/**
 * \brief Forces data into the array of cons
 * \param list Contratacion* Pointer to array of cons
 * \param id int* Pointer to the id to be asigned
 * \return Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int con_hardCodeData(Contratacion* list);

#endif /* CONTRATACIONES_H_ */
