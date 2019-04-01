#include <stdio.h>

/**
*\brief Solicita un numero entero validado dentro de un rango.
*\param *pNum Puntero de numero pedido al usuario.
*\param max Maximo del rango
*\param min Minimo del rango
*\param msg Mensaje que pide el ingreso del entero
*\param msgE Mensaje que se muestra si el dato ingresado no es valido
*\param tries Numero de intentos para verificar la validacion
*\return 0 si esta bien, -1 si esta mal
*/
int utn_getIntRange (int* pNum, int max, int min,char* msg,char* msgE, int tries)
{
    int number;
    int ret=-1;

    while(tries>0)
    {
        printf("%s",msg);
        if(scanf("%d",&number)==1)
        {
            if(number<max && number>min)
            {
                *pNum=number;
                ret=0;
                break;
            }
            tries--;
            printf("%s",msgE);
        }
        fflush(stdin);
        //fpurge(stdin);
    }
    return ret;
}

/**
*\brief Solicita un numero flotante validado dentro de un rango.
*\param *pNum Puntero de numero pedido al usuario.
*\param max Maximo del rango
*\param min Minimo del rango
*\param msg Mensaje que pide el ingreso del flotante
*\param msgE Mensaje que se muestra si el dato ingresado no es valido
*\param tries Numero de intentos para verificar la validacion
*\return 0 si esta bien, -1 si esta mal
*/
float utn_getFloatMaxMin (float* pNum, int max, int min,char* msg,char* msgE,int tries)
{
    float number;
    int ret=-1;

    while(tries>0)
    {
        printf("%s",msg);
        if(scanf("%f",&number)==1)
        {
            if(number<max && number>min)
            {
                *pNum=number;
                ret=0;
                break;
            }
            tries--;
            printf("%s",msgE);
        }
        //fpurge(stdin);
        fflush(stdin);
    }
    return ret;
}

/**
*\brief Solicita al usuario un numero entero
*\param *pNum Puntero de numero pedido al usuario
*\param msg Mensaje que pide el ingreso del entero
*\param msgE Mensaje que se muestra si el dato ingresado no es valido
*\return 0 si esta bien, -1 si esta mal
*/
int utn_getInt (int *pNum, char* msg, char* msgE)
{
    int number;
    int ret=-1;

    do
    {
        printf("%s",msg);
        if(scanf("%d",&number)==1)
        {
            (*pNum)=number;
            ret=0;
        }
        else
        {
            printf("%s",msgE);
        }
        fflush(stdin);
        //fpurge(stdin);

    }while(ret==-1);
    return ret;
}

/**
*\brief Solicita al usuario un numero flotante
*\param *pNum Puntero de numero pedido al usuario
*\param msg Mensaje que pide el ingreso del flotante
*\param msgE Mensaje que se muestra si el dato ingresado no es valido
*\return 0 si esta bien, -1 si esta mal
*/
float utn_getFloat (float *pNum, char* msg, char* msgE)
{
    float number;
    int ret=-1;

    do
    {
        printf("%s",msg);
        if(scanf("%f",&number)==1)
        {
            (*pNum)=number;
            ret=0;
        }
        else
        {
            printf("%s",msgE);
        }
        fflush(stdin);
        //fpurge(stdin);

    }while(ret==-1);
    return ret;
}

/**
*\brief Funcion que suma dos valores
*\param numA Primer valor a sumar
*\param numB Segundo valor a sumar
*\return El resultado de la sumatoria
*/
int utn_sumNum (int numA, int numB, char* resultMsg)
{
    int result;

    result=numA+numB;
    printf("%s%.2f\n",resultMsg,(float)result);

    return 0;
}

/**
*\brief Funcion que resta dos valores
*\param numA Primer valor a restar
*\param numB Segundo valor a restar
*\return El resultado de la resta
*/
int utn_restNum (int numA, int numB, char* resultMsg)
{
    int result;

    result=numA-numB;
    printf("%s%.2f\n",resultMsg,(float)result);

    return 0;
}

/**
*\brief Funcion que divide dos valores
*\param numA Dividendo
*\param numB Divisor
*\return El resultado de la division
*/
int utn_divideNum (int numA, int numB,char* resultMsg, char* msgE)
{
    int result;

    if(numA!=0 && numB!=0)
    {
        result=numA/numB;
        printf("%s%.2f\n",resultMsg,(float)result);
    }
    else if(numA==0)
    {
        result=0;
        printf("%s%.2f\n",resultMsg,(float)result);
    }
    else
    {
        printf("%s\n",msgE);

    }
    return 0;
}

/**
*\brief Funcion que multiplica dos valores
*\param numA Primer valor a multiplicar
*\param numB Segundo valor a multiplicar
*\return El resultado de la multiplicacion
*/
int utn_multiplyNum (int numA, int numB, char* resultMsg)
{
    int result;

    result=numA*numB;
    printf("%s%.2f\n",resultMsg,(float)result);

    return 0;
}

int utn_calculateAll(int numA, int numB, char* msgE)
{
    utn_sumNum(numA, numB, "");
    utn_restNum(numA, numB,"");
    utn_divideNum(numA, numB, "","");
    utn_multiplyNum(numA, numB, "");

    return 0;
}
