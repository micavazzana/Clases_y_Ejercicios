#include <stdio.h>
#include <string.h>

char hacerPrimerasLetrasMayus(char cadena[]);

int main()
{
    char nombre[50];
    char apellido[50];
    char nombreCompleto[50];

    printf("Ingrese su nombre: ");
    fgets(nombre,50,stdin);
    nombre[strlen(nombre)-1] = '\0';
    printf("Ingrese su apellido: ");
    fgets(apellido,50,stdin);
    apellido[strlen(apellido)-1] = '\0';

    strlwr(nombre);
    strlwr(apellido);

    strcpy(nombreCompleto,apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    hacerPrimerasLetrasMayus(nombreCompleto);

    printf("%s",nombreCompleto);

    return 0;
}

char hacerPrimerasLetrasMayus(char cadena[])
{
    int i;
    int contador = 0;

    for(i=0; cadena[i]!='\0'; i++)
    {
        if(i == 0)
        {
            cadena[i] = cadena[i]-32;
        }
        contador++;
    }

    for(i=0;i<contador;i++)
    {
       if(cadena[i] == ' ')
        {
            cadena[i+1] = cadena[i+1]-32;
        }
    }

    return cadena[contador];
}


