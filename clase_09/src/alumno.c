#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "alumno.h"
#define ERROR -1
#define EXITO 0
#define TRUE 1
#define FALSE 0

int alumno_alta(Alumno* listaAlumnos,int len,int* id)
{
	int retorno= ERROR;
	Alumno auxiliar;
	int indice;

	indice = alumno_findEmpty(listaAlumnos,len);
	if(listaAlumnos!=NULL && len>0 && indice != ERROR && id!=NULL)
	{
		if(utn_getName(auxiliar.nombre,NOMBRE_LEN,"\nIngrese nombre: ","\nError", 3)==EXITO &&
			utn_getNumber(&auxiliar.legajo, "\nIngrese legajo: ","\nError",0,999999,3)==EXITO)
		{
			auxiliar.isEmpty = FALSE;
			auxiliar.id = *id;
			listaAlumnos[indice] = auxiliar; //si fuera un unico alumno y no un listado deberia de hacer *pAlumno = auxiliar;
			(*id)++;
			retorno = EXITO;
		}
	}
	return retorno;
}

int alumno_imprimirUnSoloAlumno(Alumno* listaAlumnos, int len, int indice)
{
	int retorno = ERROR;

	if (listaAlumnos != NULL && len > 0 && listaAlumnos[indice].isEmpty == FALSE)
	{
		printf("\n%s %d", listaAlumnos[indice].nombre, listaAlumnos[indice].legajo);
		retorno = EXITO;
	}
	return retorno;
}

int alumno_imprimirArray(Alumno* listaAlumnos,int len)
{
    int retorno = ERROR;
    int i;

    if(listaAlumnos!=NULL && len>0)
    {
    	printf("\n%5s %15s %15s\n","ID","NOMBRE","LEGAJO");
        for(i=0;i<len;i++)
        {
        	if(listaAlumnos[i].isEmpty == FALSE)
            {

        		printf ("\n%5d %15s %15d",listaAlumnos[i].id,listaAlumnos[i].nombre,listaAlumnos[i].legajo);
            }
        }
        retorno = EXITO;
    }
    return retorno;
}

int alumno_initArray(Alumno* listaAlumnos,int len)
{
	int retorno = ERROR;
	int i;

	if(listaAlumnos!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			listaAlumnos[i].isEmpty = TRUE;
		}
		retorno = EXITO;
	}
	return retorno;
}

int alumno_findEmpty(Alumno* listaAlumnos,int len)
{
	int retorno = ERROR;
	int i;

	if(listaAlumnos!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(listaAlumnos[i].isEmpty)//true
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int alumno_modificar(Alumno* listaAlumnos,int len,int id)
{
	int retorno= ERROR;
	Alumno auxiliar;
	int opcion;
	int indice;

	indice = alumno_buscarPorId(listaAlumnos,len,id);
	if(listaAlumnos!=NULL && len>0 && id >0 && listaAlumnos[indice].isEmpty == FALSE)
	{
		do {
			utn_getNumber(&opcion, "\n\nIngrese una opcion: "
								"\n1.Modificar nombre"
								"\n2.Modificar legajo"
								"\n3.VOLVER AL MENU PRINCIPAL\n", "Error, elija una opcion valida\n", 0, 3, 3);
			switch (opcion)
			{
			case 1:
				if(utn_getName(auxiliar.nombre,NOMBRE_LEN,"Ingrese nombre: ","Error", 3)==EXITO)
				{
					strncpy(listaAlumnos[indice].nombre,auxiliar.nombre,NOMBRE_LEN);
					retorno=EXITO;
				}
				break;
			case 2:
				if(utn_getNumber(&auxiliar.legajo, "Ingrese legajo: ","Error",0,999999,3)==EXITO)
				{
					listaAlumnos[indice].legajo = auxiliar.legajo;
					retorno=EXITO;
				}
				break;
			}
		}while(opcion!=3);
	}
	return retorno;
}

int alumno_baja(Alumno* listaAlumnos,int len,int id)
{
	int retorno = ERROR;
	int indice;

	indice = alumno_buscarPorId(listaAlumnos,len,id);
	if(listaAlumnos!=NULL && len>0 && indice >=0 && listaAlumnos[indice].isEmpty == FALSE)
	{
		listaAlumnos[indice].isEmpty = TRUE;
		retorno=0;
	}
	return retorno;
}

int alumno_ordenarArray(Alumno* listaAlumnos,int len)
{
	int retorno = ERROR;
	int i;
	Alumno aux;
	int estadoDesordenado=1;

	if(listaAlumnos != NULL && len > 0)
	{
		while(estadoDesordenado)//mientras este desordenado
		{
			estadoDesordenado = 0;
			for(i = 0; i < (len - 1); i++)
			{
				if(strncmp(listaAlumnos[i].nombre, listaAlumnos[i + 1].nombre,NOMBRE_LEN)>0)//aca establezco por que criterio quiero ordenar
				{
					aux = listaAlumnos[i];
					listaAlumnos[i] = listaAlumnos[i + 1];
					listaAlumnos[i + 1] = aux;
					estadoDesordenado = 1;
				}
			}
		}
		retorno = EXITO;
	}
	return retorno;
}

int alumno_buscarPorId(Alumno* listaAlumnos, int len,int id)
{
	int retorno = ERROR;
	int i;

	if (listaAlumnos != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (listaAlumnos[i].isEmpty == FALSE && listaAlumnos[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
