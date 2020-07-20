#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

int getInt(int* integer, char* message, char* errorMessage)
{
    int result = -1;
    char auxNum[5000];

    if(integer != NULL && message != NULL && errorMessage != NULL)
    {
        printf("%s",message);
        fflush(stdin);
        fgets(auxNum,5000,stdin);
        auxNum[strlen(auxNum)-1]='\0';

        while(validationInt(auxNum)== -1)
        {
           printf("%s",errorMessage);
           fflush(stdin);
           fgets(auxNum,5000,stdin);
           auxNum[strlen(auxNum)-1]='\0';
        }

        *integer = atoi(auxNum);
        result = 0;
    }

    return result;
}


int validationInt(char num[])
{
    int result = 0;
    int i = 0;

    if(num[0] == '-' || num[0] == '+')
    {
        i = 1;
    }

    for( ; num[i]!= '\0'; i++)
    {

        if(num[i] < '0' || num[i] > '9')
        {
            result = -1;
            break;
        }
    }

    return result;
}

int getFloat(float* decimal, char* message, char* errorMessage)
{
    int result = -1;
    char auxNum[5000];

    if(decimal != NULL && message != NULL && errorMessage != NULL)
    {
        printf("%s",message);
        fflush(stdin);
        fgets(auxNum,5000,stdin);
        auxNum[strlen(auxNum)-1]='\0';

        while(validationFloat(auxNum)== -1)
        {
           printf("%s",errorMessage);
           fflush(stdin);
           fgets(auxNum,5000,stdin);
           auxNum[strlen(auxNum)-1]='\0';
        }

        *decimal = atof(auxNum);
        result = 0;
    }

    return result;

}

int validationFloat(char num[])
{
    int result = 0;
    int i = 0;
    int counterPoints = 0;

    if(num[0] == '-' || num[0] == '+')
    {
        i = 1;
    }

    for( ; num[i]!= '\0'; i++)
    {
        if(num[i] < '0' || num[i] > '9')
        {
            if(num[i] == '.')
            {
                counterPoints++;
                if(counterPoints>1)
                {
                    result = -1;
                    break;
                }
            }
            else
            {
                result = -1;
                break;
            }
        }
    }

    if(num[strlen(num)-1] == '.')
    {
        result = -1;
    }

    return result;
}

int getString(char* str, char* message, char* errorMessage)
{
    int result = -1;

    if(str != NULL && message != NULL && errorMessage != NULL)
    {
        printf("%s",message);
        fflush(stdin);
        fgets(str,5000,stdin);
        str[strlen(str)-1]='\0';

        while(validationOnlyLetter(str)== -1)
        {
           printf("%s",errorMessage);
           fflush(stdin);
           fgets(str,5000,stdin);
           str[strlen(str)-1]='\0';
        }

        result = 0;
    }

    return result;
}

int validationOnlyLetter(char str[])
{
    int i ;
    int result = 0;

    for(i=0; str[i]!= '\0'; i++)
    {
        if((str[i] < 'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
           result = -1;
           break;
        }
    }

    return result;
}
