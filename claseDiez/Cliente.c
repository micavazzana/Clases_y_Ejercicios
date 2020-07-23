#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#define OCUPADO 1
#define VACIO 0

/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimir(Cliente* pElemento)
{
    int retorno=-1;

    if(pElemento != NULL && pElemento->isEmpty == OCUPADO)
    {
        printf("\n%d %s %s %.2f",pElemento->id,pElemento->nombre,pElemento->dni,pElemento->altura);
        retorno = 0;
    }

    return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirArray(Cliente* array,int limite)
{
    int respuesta = -1;
    int i;

    if(array != NULL && limite >0)
    {
        for(i=0; i<limite; i++)
        {
            cli_imprimir(&array[i]);
        }
        respuesta = 0;
    }

    return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_inicializarArray(Cliente* array,int limite)
{
    int respuesta = -1;
    int i;

    if(array != NULL && limite >0)
    {
        for(i=0; i<limite; i++)
        {
            array[i].isEmpty = VACIO;
        }
        respuesta = 0;
    }

    return respuesta;
}

/**
 * \brief Da de alta un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaArray(Cliente* array,int limite, int indice, int* id)
{
    int respuesta = -1;
    Cliente auxCliente;

    if(array != NULL && limite > 0 && indice >= 0 && indice < limite && id != NULL && array[indice].isEmpty == VACIO)
    {
        if( getString(auxCliente.nombre,"Ingrese el nombre: ","Error, debe ingresar solo texto: ") == 0 &&
                getDni(auxCliente.dni,"Ingrese el DNI: ","Error, debe ingresar un numero de DNI valido: ") == 0 &&
                getFloat(&auxCliente.altura,"Ingrese la altura: ","Error, debe ingresar una altura valida: ")==0)
        {
            respuesta = 0;
            auxCliente.id = *id;
            auxCliente.isEmpty = OCUPADO;
            array[indice] = auxCliente;
            (*id)++;
        }
    }

    return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_modificarArray(Cliente* array,int limite, int indice)
{
    int respuesta = -1;
    Cliente auxCliente;

    if(array != NULL && limite > 0 && indice >= 0 && indice < limite && array[indice].isEmpty == OCUPADO)
    {
        if( getString(auxCliente.nombre,"Ingrese el nombre: ","Error, debe ingresar solo texto: ") == 0 &&
                getDni(auxCliente.dni,"Ingrese el DNI: ","Error, debe ingresar un numero de DNI valido: ") == 0 &&
                getFloat(&auxCliente.altura,"Ingrese la altura: ","Error, debe ingresar una altura valida: ")==0)
        {
            respuesta = 0;
            auxCliente.id = array[indice].id;
            auxCliente.isEmpty = OCUPADO;
            array[indice] = auxCliente;
        }
    }

    return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_bajaArray(Cliente* array,int limite, int indice)
{
    int respuesta = -1;

    if(array != NULL && limite > 0 && indice >= 0 && indice < limite && array[indice].isEmpty == OCUPADO)
    {
        array[indice].isEmpty = VACIO;
        respuesta = 0;
    }

    return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
///REVISAR EL RETORNO - estaria devolciendo la posicion donde esta ese id.
int cli_buscarId(Cliente array[], int limite, int valorBuscado)
{
    int retorno=-1;
    int i;

    if(array != NULL && limite>0 && valorBuscado >= 0)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(array[i].id == valorBuscado)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cli_getEmptyIndex(Cliente* array,int limite)
{
    int retorno=-1;
    int i;

    if(array != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            if(array[i].isEmpty == VACIO)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR) ///ESTO NO ESTA; DEVUELVE SIEMPRE -1
 *
 */
int cli_ordenarPorNombre(Cliente* array,int limite)
{
    int respuesta = -1;
    int flagSwap;
    int i;
    Cliente auxCliente;

    if(array != NULL && limite > 0)
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<limite-1; i++)
            {
                if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
                {
                    flagSwap = 1;
                    auxCliente = array[i];
                    array[i] = array[i+1];
                    array[i+1] = auxCliente;
                }
            }
            limite--;

        }
        while(flagSwap);
    }

    return respuesta; ///REVISAR RETORNO
}


/**
 * \brief Ordenar el array de clientes por nombre y altura
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR) ///ESTO NO ESTA; DEVUELVE SIEMPRE -1
 *
 */
int cli_ordenarPorNombreAltura(Cliente* array,int limite)
{
    int respuesta = -1;
    int flagSwap;
    int i;
    Cliente auxCliente;
    int auxiliarCmp;

    if(array != NULL && limite > 0)
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<limite-1; i++)
            {
                auxiliarCmp = strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN);

                if(auxiliarCmp > 0 || (auxiliarCmp == 0 && array[i].altura < array[i+1].altura))
                {
                    flagSwap = 1;
                    auxCliente = array[i];
                    array[i] = array[i+1];
                    array[i+1] = auxCliente;
                }
            }
            limite--;
        }
        while(flagSwap);
    }
    return respuesta; ///REVISAR RETORNO
}
