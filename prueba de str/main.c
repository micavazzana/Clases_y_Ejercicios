#include <stdio.h>
#include <string.h>
#include "strMica.h"

int main ()
{
    ///strCMP_MICA///

    char cadena1[50] = "asz";
    char cadena2[50] = "aza";

    printf("\nSTRCMP\n");

    if(strcmpMica(cadena1, cadena2) == 0)
    {
        printf("\nSon iguales");
    }
    else
    {
        printf("\nSon distintos");
        if (strcmpMica(cadena1, cadena2) > 0)
        {
            printf("\n%s es mayor a %s", cadena1, cadena2);
        }
        else
        {
            printf("\n%s es menor a %s", cadena1, cadena2);
        }
    }

    ///strCPY_MICA///

    char origen[50] = "hola mundo";
    char destino[50];
    strcpyMica (destino, origen);

    printf("\n\nSTRCPY\n");
    printf("\n%s", destino);


    ///strUPR_MICA y strLWR_MICA///

    char cadenaAUpr[50] = "mica";
    char cadenaALwr[50] = "MICA";

    struprMica(cadenaAUpr);
    strlwrMica(cadenaALwr);

    printf("\n\nSTRUPR y STRLWR\n");
    printf("\nLa cadena convertida a mayus: %s",cadenaAUpr);
    printf("\nLa cadena convertida a minus: %s",cadenaALwr);

    ///strCAT_MICA///

    char hola[50] = "hola ";
    char mundo[50] = "mundo";

    strcatMica(hola,mundo);

    printf("\n\nSTRCAT\n");
    printf("\n%s\n",hola);

    return 0;

}



