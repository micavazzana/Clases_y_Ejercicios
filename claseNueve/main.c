/******************************************************************************
-Ejercicio 1.
Definir un nuevo tipo de dato que represente un producto.
El producto tiene un nombre una descripci�n y un precio.
Hacer un programa que le pida al usuario los datos del producto
y los cargue en una variable del tipo Producto definida en la funci�n main.
Imprimir los campos de la variable producto para chequear que est�n cargadas correctamente.

-Ejercicio 2.
Tomar el programa del ejercicio anterior y agregarle lo siguiente:
 1) Una vez que el usuario ingreso los datos, preguntarle si quiere aplicar un
 descuento del 25% al precio del producto. Si acepta, calcular el nuevo precio.
 2) Hacer una funci�n que reciba la variable producto definida y que imprima sus valores.
 NOTA: Puede pasarse la variable producto por referencia o por valor.
 *ESTE EJERCICIO ESTA MODIFICADO A APLICAR EL DESCUENTO A TODO EL ARRAY Y NO SOLO UN PRODUCTO

-Ejercicio 3.
Utilizando la biblioteca "Producto.h" de los ejercicios anteriores,
definir un array de 100 productos. Realizar una funci�n que inicialice el array indicando que
los items no est�n cargados con informacion valida.

-Ejercicio 4.
Tomar el "Ejercicio 3" y realizar una funci�n que reciba el array, un indice, y le permita
al usuario cargar los datos en el item de la posici�n especificada por el indice.
*ESTE EJERCICIO ESTA MODIFICADO A QUE BUSQUE UN LUGAR LIBRE EN EL ARRAY Y CARGUE ESE ESPACIO / Se pide en el punto siguiente

- Ejercicio 5.
Tomar el "Ejercicio 4" y agregar a la biblioteca producto una funci�n que devuelva el indice
de un item vac�o (sin cargar) o -1 en caso de error o de que no haya m�s lugar.
Esta funci�n debe recibir el array y su longitud:

    int prod_getEmptyIndex(Producto lista[], int len);

-Ejercicio 6.
Tomar la biblioteca producto del "Ejercicio 5"  y realizar un programa con un menu de dos opciones:
    a) Cargar un producto
    b) Imprimir lista productos
Se deber� utilizar la funci�n que devuelve una posici�n vac�a para indicar en que posici�n
del array se guardaran los datos ingresados.//ESTO NO ESTA HECHO

-Ejercicio 7.
Agregar al tipo de dato el campo ID que represente un identificador �nico.
Modificar el c�digo del ejercicio anterior para que �l ID se genere de manera autom�tica.
Se deber� cargar �l ID al cargar un nuevo producto.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"
#define TAMPROD 100

int main()
{

    sProduct listProducts[TAMPROD];
    char option;
    int idProd = 1;

    if(initArray(listProducts,TAMPROD)==0)
    {
        do
        {
            printf("\na) Cargar un producto");
            printf("\nb) Imprimir la lista de productos");
            printf("\nc) Aplicar descuento");
            printf("\nd) Salir\n");
            fflush(stdin);
            scanf("%c",&option);

            switch(option)
            {
            case 'a':
                chargeListProducts(listProducts,TAMPROD,&idProd);
                system("pause");
                system("cls");
                break;
            case 'b':
                printListProducts(listProducts,TAMPROD);
                system("pause");
                system("cls");
                break;
            case 'c':
                exercise2(listProducts,TAMPROD);
                system("pause");
                system("cls");
                break;
            case 'd':
                printf("Hasta luego!");
                break;
            default:
                printf("No es una opcion valida!");
                break;
            }
        }
        while(option != 'd');
    }

    return 0;
}

