/*
 * Client.c
 *
 *  Created on: 10 oct. 2020
 *      Author: micavazzana
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Client.h"
#include "inputs.h"

Client* cli_newParametres(char* name, char* lastName, char* cuit, int idClient) //constructor con parametros
{
    Client *pc = NULL;

    if (name != NULL && lastName != NULL && cuit != NULL && idClient >= 0)
    {
        pc = cli_new();
        if (pc != NULL)
        {
            cli_setName(pc, name);
            cli_setLastName(pc, lastName);
            cli_setCuit(pc, cuit);
            cli_setId(pc,idClient);
        }
    }
    return pc;
}

Client* cli_new(void) //constructor sin parametros
{
    return (Client *)malloc(sizeof(Client));
}

void cli_delete(Client* pc)
{
    if (pc != NULL)
        free(pc);
}

/******************************** SETTERS AND GETTERS ***********************************************/

int cli_setName(Client* this, char* name)
{
    int result = ERROR;
    if (this != NULL && name != NULL && isValidLetters(name, NAME_LEN))
    {
        strncpy(this->name, name, (int)sizeof(this->name));
        result = SUCCESS;
    }
    return result;
}

int cli_getName(Client* this, char* name)
{
    int result = ERROR;
    if (this != NULL && name != NULL)
    {
        strncpy(name, this->name, (int)sizeof(name));
        result = SUCCESS;
    }
    return result;
}

int cli_setLastName(Client* this, char* lastName)
{
    int result = ERROR;
    if (this != NULL && lastName != NULL && isValidLetters(lastName, NAME_LEN))
    {
        strncpy(this->lastName, lastName, (int)sizeof(this->lastName));
        result = SUCCESS;
    }
    return result;
}

int cli_getLastName(Client* this, char* lastName)
{
    int result = ERROR;
    if (this != NULL && lastName != NULL)
    {
        strncpy(lastName, this->lastName, (int)sizeof(lastName));
        result = SUCCESS;
    }
    return result;
}

int cli_setCuit(Client* this, char* cuit)
{
    int result = ERROR;
    if (this != NULL && cuit != NULL && isValidDocumentNumber(cuit, CUIT_LEN))
    {
        strncpy(this->cuit, cuit, (int)sizeof(this->cuit));
        result = SUCCESS;
    }
    return result;
}

int cli_getCuit(Client* this, char* cuit)
{
    int result = ERROR;
    if (this != NULL && cuit != NULL)
    {
        strncpy(cuit, this->cuit, (int)sizeof(cuit));
        result = SUCCESS;
    }
    return result;
}

int cli_setIdTxt(Client* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL && isValidNumber(id, 1000))
    {
        this->idClient = atoi(id);
        result = SUCCESS;
    }
    return result;
}

int cli_getIdTxt(Client* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->idClient);
        result = SUCCESS;
    }
    return result;
}

int cli_setId(Client* this, int id)
{
    int result = ERROR;
    if (this != NULL && id >=0)
    {
        this->idClient = id;
        result = SUCCESS;
    }
    return result;
}

int cli_getId(Client* this, int* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        *id = this->idClient;
        result = SUCCESS;
    }
    return result;
}

/*********************************CLIENT FUNCTIONS*************************************/
/**
 * \brief To indicate that all position in the array are empty
 * \param list Client*[] Pointer to array of pointers of client type
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int cli_initArray(Client* list[], int len) // recibe **list puntero a puntero
{
    int result = ERROR;
    int i;

    if (list != NULL && len > 0)
    {
        for (i = 0; i < len; i++)
        {
            list[i] = NULL;
            //*(list+i)=NULL;
        }
        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Searches for an empty index in the array,
 * 		  this function checks if the pointer is NULL and saves the first index found.
 * \param list Client*[] Pointer to array of pointers of client type
 * \param len int Array length
 * \return int Return value of the first empty index found -
 * 			   or (-1) if Error [Invalid length, NULL pointer or if there isn't more avaible space]
 */
int cli_findEmptyIndex(Client* list[], int len)
{
    int result = ERROR;
    int i;

    if (list != NULL && len > 0)
    {
        for (i = 0; i < len; i++)
        {
            if (list[i] == NULL)
            {
                result = i;
                break;
            }
        }
    }
    return result;
}

/**
 * \brief Generates a new id for a new client,
 * \param void
 * \return int Return value of the new id
 */
static int generateNewId(void)
{
    static int id = 0;
    id++;
    return id;
}

/**
 * \brief Requests the user to complete the data asked and adds that data to the array.
 * \param list Client* Pointer to array of clients
 * \param len int Array length
 * \return Return (-1) if Error - Invalid length or NULL pointer or no avaible space
 * 				  (-2) if Error - wrong entry of the fields
 * 				  or client index position where it was charged
 */
int cli_loadAndAddData(Client* list[], int len)
{
    int result = ERROR;
    Client bufferClient;
    int index;
    Client* pC; ///un cliente

    if (list != NULL && len > 0)
    {
        pC = cli_new();
        if (pC != NULL)
        {
            index = cli_findEmptyIndex(list, len);
            if (index != ERROR
                && utn_getName(bufferClient.name, NAME_LEN, "\nIngrese nombre: ", "\nError!", 3) == SUCCESS
                && utn_getName(bufferClient.lastName, NAME_LEN, "\nIngrese apellido: ", "\nError!", 3) == SUCCESS
                && utn_getIdentityDocument(bufferClient.cuit, CUIT_LEN, "\nIngrese cuit: ", "\nError!", 3) == SUCCESS)
            {
                bufferClient.idClient = generateNewId();
                cli_setName(pC, bufferClient.name);
                cli_setLastName(pC, bufferClient.lastName);
                cli_setCuit(pC, bufferClient.cuit);
                cli_setId(pC, bufferClient.idClient);
                list[index] = pC;
                result = index; //SUCCESS;
            }
            else
            {
                result = -2;
                cli_delete(pC);
            }
        }
    }
    return result;
}

/**
 * \brief Requests the user to complete the data asked and adds that data to the array.
 * \param list Client* Pointer to array of clients
 * \param len int Array length
 * \return Return (-1) if Error - Invalid length or NULL pointer or no avaible space
 * 				  (-2) if Error - wrong entry of the fields
 * 				  or client index position where it was charged
 */
int cli_loadAndAddDataConstructorParametres(Client* list[], int len)
{
    int result = ERROR;
    Client bufferClient;
    int index;
    Client* pc;

    if (list != NULL && len > 0)
    {
        index = cli_findEmptyIndex(list, len);
        if (index != ERROR
            && utn_getName(bufferClient.name, NAME_LEN, "\nIngrese nombre: ", "\nError!", 3) == SUCCESS
            && utn_getName(bufferClient.lastName, NAME_LEN, "\nIngrese apellido: ", "\nError!", 3) == SUCCESS
            && utn_getIdentityDocument(bufferClient.cuit, CUIT_LEN, "\nIngrese cuit: ", "\nError!", 3) == SUCCESS)
        {
            bufferClient.idClient = generateNewId();
            pc = cli_newParametres(bufferClient.name, bufferClient.lastName, bufferClient.cuit, bufferClient.idClient);
            if (pc != NULL)
            {
                list[index] = pc;
                result = index; //SUCCESS;
            }
        }
        else
        {
            result = -2;
        }
    }
    return result;
}

/**
 * \brief Searches a Client by Id
 * \param list Client* Pointer to array of clients
 * \param len int Array length
 * \param id int, id searched
 * \return Return client index position or (-1) if [Invalid length or NULL pointer received or client not found]
 */
int cli_findById(Client* list[], int len, int id)
{
    int result = ERROR;
    int i;
    int bufferId;

    if (list != NULL && len > 0 && id > 0)
    {
        for (i = 0; i < len; i++)
        {
            cli_getId(list[i], &bufferId);
            if (list[i] != NULL && bufferId == id)
            {
                result = i;
                break;
            }
        }
    }
    return result;
}

/**
 * \brief Modifys data from clients. Allows the user to decide which field to change.
 * \param list Client* Pointer to array of client
 * \param len int Array length
 * \return Return (-1) Error - if Invalid length or NULL pointer or if can't find a client
 * 				  (-2) Error - if Name could not be changed
 * 				  (-3) Error - if Last name could not be changed
 * 				  (-4) Error - if Cuit could not be changed
 * 				  (0) if Ok
 */
int cli_modify(Client* list[], int len)
{
    int result = ERROR;
    int index;
    Client bufferClient;
    int option;

    if (list != NULL && len > 0)
    {
        if (cli_printList(list, len) == SUCCESS
            && utn_getNumber(&bufferClient.idClient, "\nIngrese el id del cliente que quiere modificar: ", "\nError!", 0, INT_MAX, 5) == SUCCESS
            && cli_findById(list, len, bufferClient.idClient) != ERROR)
        {
            index = cli_findById(list, len, bufferClient.idClient);
            if (list[index] != NULL)
            {
                do
                {
                    if (utn_getNumber(&option,
                                      "\n\nIngrese una opcion: "
                                      "\n1.Modificar Nombre "
                                      "\n2.Modificar Apellido "
                                      "\n3.Modificar Cuit "
                                      "\n4.Volver al menu principal\n",
                                      "Error, elija una opcion valida\n", 1, 4, 3) == SUCCESS)
                    {
                        switch (option)
                        {
                        case 1:
                            if (utn_getName(bufferClient.name, NAME_LEN, "\nIngrese nombre: ", "\nError!", 3) == SUCCESS)
                            {
                                cli_setName(list[index], bufferClient.name);
                                result = SUCCESS;
                            }
                            else
                            {
                                result = -2;
                            }
                            break;
                        case 2:
                            if (utn_getName(bufferClient.lastName, NAME_LEN, "\nIngrese apellido: ", "\nError!", 3) == SUCCESS)
                            {
                                cli_setLastName(list[index], bufferClient.lastName);
                                result = SUCCESS;
                            }
                            else
                            {
                                result = -3;
                            }
                            break;
                        case 3:
                            if (utn_getIdentityDocument(bufferClient.cuit, CUIT_LEN, "\nIngrese cuit: ", "\nError!", 3) == SUCCESS)
                            {
                                cli_setCuit(list[index], bufferClient.cuit);
                                result = SUCCESS;
                            }
                            else
                            {
                                result = -4;
                            }
                            break;
                        } //fin switch
                    }
                    else
                    {
                        printf("Se acabaron sus reintentos, vuelva a ingresar");
                    }
                    if (result < 0)
                    {
                        break;
                    }
                } while (option != 4);
            }
        }
    }
    return result;
}

/**
 * \brief Remove a client searched by Id (put isEmpty Flag in 1)
 * \param list Client* Pointer to array of clients
 * \param len int Array length
 * \param id int, id searched
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a client] - (0) if Ok
 */
int cli_remove(Client* list[], int len, int id)
{
    int result = ERROR;
    int index;

    if (list != NULL && len > 0 && id > 0)
    {
        index = cli_findById(list, len, id);
        if (index != ERROR && list[index] != NULL)
        {
            cli_delete(list[index]); //libero espacio de memoria
            list[index] = NULL; // pongo en null al puntero al array
            result = SUCCESS;
        }
    }
    return result;
}

/**
 * \brief Prints the data of only one client
 * \param list Client
 * \return Return (-1) if Error [flag isEmpty is TRUE] - (0) if Ok
 */
int cli_printOne(Client* pClient)
{
    int result = ERROR;
    Client buffer;

    if (pClient != NULL)
    {
        cli_getName(pClient, buffer.name);
        cli_getLastName(pClient, buffer.lastName);
        cli_getCuit(pClient, buffer.cuit);
        cli_getId(pClient, &buffer.idClient);
        printf("\n%10d %15s %15s %35s\n",
               buffer.idClient,
               buffer.name,
               buffer.lastName,
               buffer.cuit);
        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Print the content of clients array
 * \param list Client* Pointer to array of clients
 * \param length int  Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int cli_printList(Client* list[], int len)
{
    int result = ERROR;
    int i;

    if (list != NULL && len > 0)
    {
        printf("%10s %15s %15s %35s\n", "ID CLIENTE", "NOMBRE", "APELLIDO", "CUIT");
        for (i = 0; i < len; i++)
        {
            cli_printOne(list[i]);
        }
        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Checks if there is any data in the array
 * 			this function checks the flag (isEmpty). If it is false, there is data.
 * \param list Client* Pointer to array of clients
 * \param len int Array length
 * \return int Returns TRUE(1) if there is data, if not, returns FALSE(0)
 */
int cli_isAnyData(Client* list[], int len)
{
    int i;
    int result = FALSE;

    if (list != NULL && len > 0)
    {
        for (i = 0; i < len; i++)
        {
            if (list[i] != NULL) //if there is data
            {
                result = TRUE;
                break;
            }
        }
    }
    return result;
}

/**
 * \brief Forces data into the array of clients
 * \param list Client* Pointer to array of clients
 * \return Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int cli_hardCodeData(Client* list[])
{
    int result = ERROR;
    char name[][NAME_LEN] = {"Mike", "Eleven", "Dustin", "Will", "Max", "Lucas", "Nancy", "Steve", "Jonathan", "Joyce", "Jim"};
    char lastName[][NAME_LEN] = {"Whealer", "Hooper", "Henderson", "Byers", "Mayfield", "Sinclair", "Whealer", "Harrington", "Byers", "Byers", "Hooper"};
    char cuit[][CUIT_LEN] = {"27-582364-6", "27-588564-7", "20-582377-7", "27-582378-5", "20-545363-0", "30-582784-0", "27-548278-6", "20-587884-0", "27-581234-6", "27-142364-5", "20-582124-4"};
    int idClient;
    int i;
    Client* pc;

    if (list != NULL)
    {
        for (i = 0; i < 11; i++)
        {
            idClient = generateNewId();
            pc = cli_newParametres(name[i], lastName[i], cuit[i], idClient);
            if (pc != NULL)
            {
                list[i] = pc;
            }
        }
        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Sort the elements in the array of clients, the argument order indicate UP or DOWN order
 * \param list Client* Pointer to array of clients
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int cli_sort(Client* list[], int len, int order)
{
    int result = ERROR;
    int i;
    Client* aux;
    int disorderedState = 1;
    char bufferLastName[NAME_LEN];
    char bufferLastNamePlusOne[NAME_LEN];
    char bufferName[NAME_LEN];
    char bufferNamePlusOne[NAME_LEN];

    if (list != NULL && len > 0 && (order == 0 || order == 1))
    {
        while (disorderedState)
        {
            disorderedState = 0;
            for (i = 0; i < (len - 1); i++)
            {
                cli_getLastName(list[i],bufferLastName);
                cli_getLastName(list[i+1],bufferLastNamePlusOne);
                cli_getName(list[i],bufferName);
                cli_getName(list[i+1],bufferNamePlusOne);
                if ((order == UP && (strncasecmp(bufferLastName, bufferLastNamePlusOne, NAME_LEN) > 0 ||
                                     (strncasecmp(bufferLastName, bufferLastNamePlusOne, NAME_LEN) == 0 && strncasecmp(bufferName, bufferNamePlusOne, NAME_LEN) > 0))) ||
                    (order == DOWN && (strncasecmp(bufferLastName, bufferLastNamePlusOne, NAME_LEN) < 0 ||
                                       (strncasecmp(bufferLastName, bufferLastNamePlusOne, NAME_LEN) == 0 && strncasecmp(bufferName, bufferNamePlusOne, NAME_LEN) < 0))))
                {
                    aux = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = aux;
                    disorderedState = 1;
                }
            }
        }
        result = SUCCESS;
    }
    return result;
}