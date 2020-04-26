int CargarNum(char msje[])
{
    int num;

    printf("%s", msje);
    scanf("%d",&num);

    return num;
}

void CargarListadoNum(int arrayNum[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        arrayNum[i] = CargarNum("\nIngrese un numero: ");
    }
}

void MostrarListadoNum(int arrayNum[], int tam)
{
    int i;

    for(i=0;i<tam;
    i++)
    {
        printf("\nNumero ingresado: %d\n", arrayNum[i]);
    }
}

int BuscarMayor(int arrayNum[], int tam)
{
    int max;
    int i;

    for(i=0;i<tam;i++)
    {
        if(max < arrayNum[i] || i == 0)
        {
            max = arrayNum[i];
        }
    }

    return max;
}

int BuscarMenor(int arrayNum[], int tam)
{
    int min;
    int i;

    for(i=0;i<tam;i++)
    {
        if(min > arrayNum[i] || i == 0)
        {
            min = arrayNum[i];
        }
    }

    return min;
}

void OrdenarAsc(int arrayNum[], int tam)
{
    int i;
    int j;
    int auxNum;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(arrayNum[i] > arrayNum[j])
            {
                auxNum = arrayNum[i];
                arrayNum[i]= arrayNum[j];
                arrayNum[j] = auxNum;
            }
        }
    }
}

void OrdenarDesc(int arrayNum[], int tam)
{
    int i;
    int j;
    int auxNum;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(arrayNum[i] < arrayNum[j])
            {
                auxNum = arrayNum[i];
                arrayNum[i]= arrayNum[j];
                arrayNum[j] = auxNum;
            }
        }
    }
}

int Sumar(int arrayNum[], int tam)
{
    int i;
    int suma = 0;

    for(i=0;i<tam;i++)
    {
        suma = arrayNum[i] + suma;
    }

    return suma;
}

float Promedio(int arrayNum[], int tam)
{
    int i;
    float suma = 0;
    float promedio;

    for(i=0;i<tam;i++)
    {
        suma = arrayNum[i] + suma;
    }
    promedio = suma/i;

    return promedio;
}

int BuscarPosicion(int arrayNum[], int tam)
{
    int i;
    int num;
    int posicion;

    num = CargarNum("\nDe que numero quiere saber la posicion?: ");

    for(i=0;i<tam;i++)
    {
        if(num == arrayNum[i])
        {
            posicion = i;
        }
    }

    return posicion;
}

int BuscarNum(int arrayNum[], int tam)
{
    int i;
    int num;
    int conteo = 0;

    num = CargarNum("\nQue numero quiere saber cuantas veces fue ingresado?: ");

    for(i=0;i<tam;i++)
    {
        if(num == arrayNum[i])
        {
           conteo++;
        }
    }

    return conteo;
}

