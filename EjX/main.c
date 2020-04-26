/**
EJERCICIO X
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define T 5


int main()
{
    int listadoNum[T];
    int mayor;
    int menor;
    int suma;
    float promedio;
    int posicion;
    int cantVecesIngresado;

    CargarListadoNum(listadoNum, T);

    OrdenarAsc(listadoNum, T);
    printf("\nLos numeros se muestran en orden ascendente: \n");
    MostrarListadoNum(listadoNum, T);

    OrdenarDesc(listadoNum, T);
    printf("\nLos numeros se muestran en orden descendente: \n");
    MostrarListadoNum(listadoNum, T);

    mayor = BuscarMayor(listadoNum, T);
    printf("\nEl mayor es: %d\n", mayor);
    menor = BuscarMenor(listadoNum, T);
    printf("\nEl menor es: %d\n", menor);

    suma = Sumar(listadoNum, T);
    printf("\nLa suma de los numeros es: %d\n", suma);
    promedio = Promedio(listadoNum, T);
    printf("\nEl promedio de los numeros es: %.2f\n", promedio);

    posicion = BuscarPosicion(listadoNum, T);
    printf("\nEl numero esta en la posicion: %d\n", posicion);

    cantVecesIngresado = BuscarNum(listadoNum, T);
    if(cantVecesIngresado == 0)
    {
        printf("\nEl numero no se encontro.");
    }else
    {
    printf("\nEl numero fue ingresado %d veces\n", cantVecesIngresado);
    }
    return 0;
}
