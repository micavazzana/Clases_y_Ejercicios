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
