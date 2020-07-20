/******************
Ejercicios Clase 7

Ej 1:
 * Escribir la función calcularMayor(),
 * la misma debe recibir dos números enteros y devolver por referencia, el numero mayor.
 * Deberá retornar un 1 sí encontró un mayor, o un 0 si ambos números son iguales.

Ej 2:
 * crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
 * Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia
 * del mes. Hacer un programa con un menu de dos opciones, 1.imprimir array y 2.cargar array
 * Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 * Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 * y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
 * Ambas opciones deben volver al menu ppal.
 *
 * Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h

Ej 3:
 * Definir una funcion validarFloat() que reciba un array de chars en donde los
 * caracteres representan un numero decimal. La funcion debera devolver en su valor de retorno
 * si la cadena recibida contiene o no un valor numerico en formato texto.
 *
Ej 4:
 * Completar la funcion getFloat() para que devuelva un numero float ingresado por el usuario


******************/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int option;

    do

    {
        option = printMainMenu();

        switch(option)
        {
            case 1:
                exOne();
                break;

            case 2:
                exTwo();
                break;

            case 3:
                printf("Hasta luego!");
                break;

            default:
                printf("No es una opcion valida");
                break;
        }

    }while(option != 3);

    return 0;
}
