#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "inputs.h"
#define TAKEN 1
#define EMPTY 0

int printMainMenu(void)
{
    int option;

    printf("\n1. Seleccione 1 para entrar al Ejercicio 1");
    printf("\n2. Seleccione 2 para entrar al Ejercicio 2");
    printf("\n3. Seleccione 3 para Salir\n");

    scanf("%d",&option);

    return option;
}

int calculateHigher(int firstNumber, int secondNumber, int* higher)
{
    int result = 1;

    if(higher != NULL)
    {
        if(firstNumber == secondNumber)
        {
            result = 0;
        }
        else
        {
            if(firstNumber < secondNumber)
            {
                *higher = secondNumber;
            }
            else
            {
                *higher = firstNumber;
            }
        }
    }

    return result;
}

void exOne(void)
{
    int firstResult, secondResult;
    int numOne, numTwo;
    int higher;

    printf("\tEjercicio 1\n Debe ingresar dos numeros para calcular al mayor\n");

    firstResult = getInt(&numOne,"Ingrese el primer numero: ","Error, se espera que ingrese un numero: ");
    secondResult = getInt(&numTwo,"Ingrese el segundo numero: ","Error, se espera que ingrese un numero: ");

    if(firstResult == 0 && secondResult == 0)
    {
        if(calculateHigher(numOne, numTwo, &higher) == 0)
        printf("Son iguales");
        else
        printf("El numero mayor es: %d", higher);
    }
}

int printMenuEx2(void)
{
    int option;

    printf("\n1. Imprimir array");
    printf("\n2. Cargar array");
    printf("\n3. Seleccione 3 para volver\n");

    scanf("%d",&option);

    return option;
}

void exTwo(void)
{
    int option;
    float temp[31];
    int isEmpty[31];

    printf("\tEjercicio 2\n Este ejercicio tiene en cuenta al 3 y 4");

    initArray(temp,31,isEmpty);
    hardcodearTemps(temp,isEmpty);

    do
    {
        option = printMenuEx2();

        switch(option)
        {
            case 1:
                printArray(temp,31,isEmpty);
                break;

            case 2:
                chargeArray(temp,isEmpty);
                break;

            default:
                printf("No es una opcion valida");
                break;
        }


    }while(option != 3);
}

void initArray(float arrayTemp[], int len, int isEmpty[])
{
    int i;

    for(i=0;i<len;i++)
    {
        arrayTemp[i] = 0;
        isEmpty[i] = EMPTY;
    }

}

void hardcodearTemps(float arrayTemp[],int isEmpty[])
{
    int i;
    float array[]= {35.6,32,32.9,34,29,28,30.5,34};

    for(i=0;i<8;i++)
    {
        if(isEmpty[i] == EMPTY)
        {
            arrayTemp[i] = array[i];
            isEmpty[i] = TAKEN;
        }
    }
}

void printArray(float arrayTemp[], int len, int isEmpty[])
{
    int i;

    for(i=0;i<len;i++)
    {
        if(isEmpty[i] == TAKEN)
        {
            printf("\nDia %d Temperatura: %.2f",i+1, arrayTemp[i]);
        }
    }
}

int chargeArray(float arrayTemp[], int isEmpty[])
{
    int result = -1;
    int day;
    //int i;
    float temp;
    int rta;

    rta = getInt(&day,"Elija un dia para cargar una temperatura: ","Error, debe elegir un dia de 1 a 31\n");

    while(day < 1 || day > 31)
    {
        printf("Error, debe elegir un dia de 1 a 31\n");
        rta = getInt(&day,"Elija un día: \n","Error, debe elegir un dia de 1 a 31\n");
    }

    if(rta == 0)
    {
        if(isEmpty[day-1] == EMPTY && getFloat(&temp,"Ingrese una tempertatura: \n","Error, debe ingresar una tempertatura\n")==0)
        {
            arrayTemp[day-1] = temp;
            isEmpty[day-1] = TAKEN;
            result = 0;
        }
        else
        {
            printf("\nYa esta cargado");
        }
    }

    return result;
}

