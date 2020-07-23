#include <stdio.h>
#include <string.h>
#include "Producto.h"
#define EMPTY 0
#define TAKEN 1


int initArray(sProduct listProducts[], int sizeArray)
{
    int i;
    int Return = -1;

    if(listProducts != NULL && sizeArray >=0)
    {
        for(i=0; i<sizeArray; i++)
        {
            listProducts[i].isEmpty = EMPTY;
        }
        Return = 0;
    }

    return Return;
}

sProduct chargeProduct()
{
    sProduct product;

    if(getString(product.name,"Ingrese un nombre: ","Debe ingresar un nombre: ")==0
            && getString(product.description,"Ingrese una descripcion: ","Debe ingresar solo texto: ")==0
            && getFloat(&product.price,"Ingrese un precio: ","Debe ingresar un precio: ")==0)
    {
        product.isEmpty = TAKEN;
    }

    return product;
}

int findEmpty(sProduct listProducts[], int sizeArray)
{
    int i;
    int Return = -1;

    if(listProducts != NULL && sizeArray >=0)
    {
        for(i=0; i<sizeArray; i++)
        {
            if(listProducts[i].isEmpty == EMPTY)
            {
                Return = i;
                break;
            }
            else
            {
                Return = -2;
            }
        }
    }

    return Return;
}

int chargeListProducts(sProduct listProducts[], int sizeArray, int* id)
{
    int emptySpace;
    int Return = -1;

    if(listProducts != NULL && sizeArray >=0)
    {
        emptySpace = findEmpty(listProducts, sizeArray);
    }

    if(emptySpace >= 0)
    {
        listProducts[emptySpace] = chargeProduct();
        listProducts[emptySpace].id = *id;
        *id = *id + 1;
        Return = 0;
    }
    else
    {
        if(emptySpace == -2)
        {
            printf("Ya no hay lugar!");
        }
        else
        {
            printf("Error");
        }
    }

    return Return;
}

void printProduct(sProduct product)
{
    printf("\nID: %d \nNombre: %s \nDescripcion: %s \nPrecio: %.2f\n",
           product.id,
           product.name,
           product.description,
           product.price);
}

void printListProducts(sProduct listProducts[], int sizeArray)
{
    int i;

    for(i=0; i<sizeArray; i++)
    {
        if(listProducts[i].isEmpty == TAKEN)
        {
            printProduct(listProducts[i]);
        }
    }
}

int discount25Percent(float num, float* result)
{
    float twentyfivePercent;
    int Return = -1 ;

    if(num >0 && result != NULL)
    {
        twentyfivePercent = (25 * num) / 100;
        *result  = num - twentyfivePercent;
        Return = 0;
    }

    return Return;
}

void exercise2(sProduct listProducts[], int sizeArray)
{
    char answer;
    float result;
    int success;
    int i;

    printf("Quiere aplicar un 25 porciento de descuento al precio? [s/n]: ");
    fflush(stdin);
    scanf("%c",&answer);

    //if(getChar(&answer,"Quiere aplicar un 25 porciento de descuento al precio? [s/n]: ","Debe ingresar s o n: ")==0)
    {
        while(answer != 's' && answer != 'n')
        {
            printf("Debe ingresar s o n! ");
            //getChar(&answer,"Ingrese: ","Debe ingresar s o n: ");
            printf("Ingrese: ");
            fflush(stdin);
            scanf("%c",&answer);
        }

        if(answer == 's')
        {
            for(i=0; i<sizeArray; i++)
            {
                success = discount25Percent(listProducts[i].price,&result);
                listProducts[i].price = result;
            }
            if(success == 0)
            {
                printf("Aplicando descuento...\n");
            }
        }

    }

}
