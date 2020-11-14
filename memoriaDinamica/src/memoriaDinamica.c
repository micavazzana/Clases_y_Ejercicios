/*
 ============================================================================
 Name        : memoriaDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* PUNTEROS
    int* punteroInt = NULL;

    int auxInt = 10;

    punteroInt = &auxInt;

    printf("\nDireccion de punteroInt: %p",&punteroInt);
    printf("\nDireccion de auxInt: %p",&auxInt);
    printf("\nContenido de punteroInt: %p",punteroInt);

    printf("\nContenido de auxInt: %d",auxInt);
    printf("\nContenido de auxInt a traves de punteroInt: %i",*punteroInt);

    */

    ////Declaro una variable y reservo memoria para esa variable
    int* pEdad;

    pEdad = (int*) malloc (sizeof(int));
    if(pEdad!=NULL)//Uso la varible, por ejemplo asignando un valor
    *pEdad=44;

    ////Aca declaro un array de edades, reservando memoria para un array de tamaño 100
    int* pArrayEdad;
    int sizeArrayEdad = 100;

    pArrayEdad = (int*) malloc (sizeof(int)*sizeArrayEdad);
    if(pArrayEdad!=NULL)//Uso el array, por ejemplo asignando cero en todas sus posiciones
    {
        for(int i=0;i<sizeArrayEdad;i++)
        {
            *(pArrayEdad+i) = 0; /// es lo mismo que hacerlo como: pArrayEdad[i]=0;
        }
    }

    ///Declaro un auxiliar para reasignar espacio con realloc
    //realloc recibe el array que estoy queriendo recalcular, y el nuevo tamaño a reservar

    int* pArrayEdadAux;

    pArrayEdadAux = (int*) realloc (pArrayEdad, sizeof(int)*sizeArrayEdad);
    if(pArrayEdadAux!=NULL)//me fijo si realloc encontro esa cantidad de memoria, solo entonces lo asigno a la variable
    {
        pArrayEdad = pArrayEdadAux;
        pArrayEdadAux = NULL; //para no dejar ese puntero apuntando a la misma dir de memoria lo apunto a otra cosa
    }

    ////Para liberar la memoria hago FREE

    free(pArrayEdad);

    return 0;
}

//ejemplo de funcion que crea un array de int y lo inicializa, recibe el tamaño del array que voy a querer declarar y el valor con el que inizializo
//devuelve el array al que le asigno espacio en memoria
int* crearArrayInt(int cantidad, int valorDeInit)
{
    int* pArray;

    if(cantidad>0)
    {
        pArray = (int*)malloc(sizeof(int)*cantidad);
        if(pArray != NULL)
        {
            for(int i=0;i<cantidad;i++)
            {
                pArray[i]=valorDeInit;
            }
        }
    }
    return pArray;
}

////ejemplo de funcion que hace un resize del array que recibe y ademas recibe la nueva cantidad que se declarara
//retorna el array con el nuevo tamaño
int* resizeArrayInt(int* pArray, int cantidad)
{
    int* pArrayAux;

    if(pArray != NULL && cantidad>0)
    {
       pArrayAux = (int*) realloc (pArray, sizeof(int)*cantidad);
    }
    return pArrayAux;
}

