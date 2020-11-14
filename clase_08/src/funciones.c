#include <stdio.h>
#include <stdlib.h>

int imprimirArray(int* arrayNumeros,int len)
{
	int retorno=-1;
	int i;

	if(arrayNumeros!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			printf("%d ",arrayNumeros[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int contadorDeNumeros(int* arrayNumeros,int len,int numeroAContar,int* pCantidadQueHay)
{
    int retorno=-1;
	int i;
	int contador=0;

	if(arrayNumeros!=NULL && len>0 && pCantidadQueHay!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(arrayNumeros[i]==numeroAContar)
			{
			    contador++;
			}
		}
		retorno = 0;
		*pCantidadQueHay = contador;
	}
	return retorno;
}

int contadorDeCaracteres(char* cadenaCaracteres,char caracterAContar,int* pCantidadQueHay)
{
    int retorno=-1;
	int i;
	int contador=0;

	if(cadenaCaracteres!=NULL && pCantidadQueHay!=NULL)
	{
		for(i=0;cadenaCaracteres[i] != '\0';i++)
		{
			if(cadenaCaracteres[i] == caracterAContar)
			{
			    contador++;
			}
		}
		retorno = 0;
		*pCantidadQueHay = contador;
	}
	return retorno;
}

int validarCaracteresAlfabeticos(char* cadenaCaracteres)
{
    int retorno=0;
	int i;

	if(cadenaCaracteres!=NULL)
	{
		for(i=0;cadenaCaracteres[i] != '\0';i++)
		{
			if((cadenaCaracteres[i] < 'a' || cadenaCaracteres [i] > 'z') && (cadenaCaracteres[i] < 'A' || cadenaCaracteres[i] > 'Z'))
			{
			    retorno=-1;
			    break;
			}
		}
	}
	return retorno;
}

int getString(char* string, int len)
{
    int retorno = -1;
    char aux[4096];

    if(string != NULL && len > 0)
    {
        fpurge(stdin);
        fgets(aux,sizeof(aux),stdin);
        aux[strnlen(aux,sizeof(aux))-1]='\0';

        if(strnlen(aux,sizeof(aux)) <= len)
        {
            strncpy(string,aux,len);
            retorno = 0;
        }
    }
    return retorno;
}

int getNombre(char* nombre, int len, char* mensaje)
{
    int retorno = -1;
    char aux[4096];

    if(nombre != NULL && mensaje != NULL && len > 0)
    {
            printf("%s",mensaje);
            if(getString(aux,sizeof(aux))==0 &&
               validarCaracteresAlfabeticos(aux)==0 &&
               strnlen(aux,sizeof(aux))<len)
            {
                retorno = 0;
                strncpy(nombre,aux,len);
            }
    }
    return retorno;
}
