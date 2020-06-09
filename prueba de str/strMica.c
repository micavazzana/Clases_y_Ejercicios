#include "strMica.h"

///funcion strlen///

int strlenMica(char cadena[])
{
    int i;
    int contadorCaracter= 0;

    for(i=0; cadena[i]!= '\0'; i++)
    {
        contadorCaracter++;
    }

    return contadorCaracter;
}

///funcion strcpy///

void strcpyMica(char destino[], char origen[])
{
    int i;

    for(i=0; origen[i]!='\0'; i++)
    {
        destino[i]= origen[i];
    }

    destino[i]= '\0';
}

///funcion strcmp///

int strcmpMica(char cadena1[], char cadena2[])
{
    int i;
    int j;
    int resultado = 0;

    for(i=0; cadena1[i]!='\0'; i++)
    {
        for(j=0; cadena2[j]!='\0'; j++)
        {
            if(cadena1[i] == cadena2[j])
            {
                resultado = resultado + 0;
            }
            else
            {
                if(cadena1[i] < cadena2[j])
                {
                    resultado--;
                }
                if(cadena1[i] > cadena2[j])
                {
                    resultado++;
                }
            }
        }
    }

    return resultado;
}

///funcion strupr///

char struprMica(char cadena[])
{
    int i;
    int contador = 0;

    for(i=0; cadena[i]!='\0'; i++)
    {
        if(cadena[i]>= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i]-32;
        }
        contador++;
    }

    return cadena[contador];
}

///funcion strlwr///

char strlwrMica(char cadena[])
{
    int i;
    int contador = 0;

    for(i=0; cadena[i]!='\0'; i++)
    {
        if(cadena[i]>= 'A' && cadena[i] <= 'Z')
        {
            cadena[i] = cadena[i]+32;
        }
        contador++;
    }

    return cadena[contador];
}

///funcion strcat///

char strcatMica(char cadena1[], char cadena2[])
{
    int i;
    int j;

    for(i=0; cadena1[i]!='\0'; i++)
    {
    }

    for(j=0; cadena2[j]!='\0'; j++)
    {
        cadena1[i]= cadena2[j];
        i++;
    }

    return cadena1[i];
}
