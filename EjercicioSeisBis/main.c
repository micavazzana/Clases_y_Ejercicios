/**
Realizar un programa que haga la liquidación de sueldos de una fábrica con 40 empleados,
los datos con que se cuentan son: Apellido, legajo, sueldo básico y antigüedad.
Se debe mostrar por pantalla un listado con el siguiente formato
Nombre Sueldo básico Sueldo neto
Xxxxx ####,## ####,##
Para calcular el sueldo neto se debe tener en cuenta :
Realizar un descuento de 12% del sueldo básico por jubilación
Realizar un descuento de 3.5% del sueldo básico por obra social
Realizar una bonificación del 1.5% del sueldo básico por cada 10 años de antigüedad.
Para calcular el sueldo neto debe usar una función.
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
