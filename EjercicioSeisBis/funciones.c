#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

eEmpleado CargarEmpleado()
{
    eEmpleado empleado;
    printf("\nIngrese apellido: ");
    scanf("%s", empleado.apellido);
    printf("\nIngrese legajo: ");
    scanf("%d",&empleado.legajo);
    printf("\nIngrese sueldo: ");
    scanf("%f",&empleado.sueldo);
    printf("\nIngrese antiguedad: ");
    scanf("%d",&empleado.antiguedad);

    return empleado;
}

void CargarListadoEmpleados(eEmpleado arrayEmpleados[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        arrayEmpleados[i] = CargarEmpleado();
    }
}

void MostrarEmpleado(eEmpleado empleado)
{
    float sueldoNeto;
    sueldoNeto = CalcularSueldoNeto(empleado);
    printf("\n%15s %17.2f %15.2f\n",empleado.apellido, empleado.sueldo, sueldoNeto);
}

void MostrarListadoEmpleado(eEmpleado arrayEmpleados[], int tam)
{
    int i;

    printf("\n\t Apellido \tSueldo Basico \tSueldo Neto\n");
    for(i=0; i<tam; i++)
    {
        MostrarEmpleado(arrayEmpleados[i]);
    }
}

float CalcularSueldoNeto(eEmpleado empleado)
{

    float descJubilacion;
    float descObraSocial;
    float bonificacion;
    float sueldoNeto;

    descJubilacion = Porcentaje(empleado.sueldo, 12);
    descObraSocial = Porcentaje(empleado.sueldo, 3.5);
    bonificacion = Porcentaje(empleado.sueldo, 1.5);

    if(empleado.antiguedad >= 10 && empleado.antiguedad <20)
    {
        sueldoNeto = empleado.sueldo - descJubilacion - descObraSocial + bonificacion;
    }
    else if(empleado.antiguedad>=20 && empleado.antiguedad <30)
    {
        sueldoNeto = empleado.sueldo - descJubilacion - descObraSocial + (bonificacion*2);
    }
    else if(empleado.antiguedad>=30 && empleado.antiguedad < 40)
    {
        sueldoNeto = empleado.sueldo - descJubilacion - descObraSocial + (bonificacion*3);
    }
    else if(empleado.antiguedad>=40 && empleado.antiguedad <50)
    {
        sueldoNeto = empleado.sueldo - descJubilacion - descObraSocial + (bonificacion*4);
    }
    else if(empleado.antiguedad>=50)
    {
        sueldoNeto = empleado.sueldo - descJubilacion - descObraSocial + (bonificacion*5);
    }
    else
    {
        sueldoNeto = empleado.sueldo - descJubilacion - descObraSocial;
    }

    return sueldoNeto;
}

float Porcentaje(float sueldo, float porcentaje)
{
    float multiplicar;
    float resultado;

    multiplicar = sueldo * porcentaje;
    resultado = multiplicar/100;

    return resultado;
}
