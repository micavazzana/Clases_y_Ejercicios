/**
Realizar un programa que haga la liquidaci�n de sueldos de una f�brica con 40 empleados,
los datos con que se cuentan son: Apellido, legajo, sueldo b�sico y antig�edad.
Se debe mostrar por pantalla un listado con el siguiente formato
Nombre Sueldo b�sico Sueldo neto
Xxxxx ####,## ####,##
Para calcular el sueldo neto se debe tener en cuenta :
Realizar un descuento de 12% del sueldo b�sico por jubilaci�n
Realizar un descuento de 3.5% del sueldo b�sico por obra social
Realizar una bonificaci�n del 1.5% del sueldo b�sico por cada 10 a�os de antig�edad.
Para calcular el sueldo neto debe usar una funci�n.
**/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define T 2

int main()
{
    eEmpleado listadoEmpleados[T]; ///= {{"Perez",123,5000,10},{"Gonzalez",124,3000,5},{"Garcia",125,10000.5,20}};

    CargarListadoEmpleados(listadoEmpleados, T);
    MostrarListadoEmpleado(listadoEmpleados, T);

    return 0;
}
