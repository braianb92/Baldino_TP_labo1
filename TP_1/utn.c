#include <stdio.h>

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
*\param resultMsg Mensaje relacionado al resultado de la funcion
*\return 0
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
*\param resultMsg Mensaje relacionado al resultado de la funcion
*\return 0
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
*\param resultMsg Mensaje relacionado al resultado de la funcion
*\param msgE Mensaje que avisa que la division por 0 no es posible.
*\return 0
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
*\param resultMsg Mensaje relacionado al resultado de la funcion
*\return 0
*/
int utn_multiplyNum (int numA, int numB, char* resultMsg)
{
    int result;

    result=numA*numB;
    printf("%s%.2f\n",resultMsg,(float)result);

    return 0;
}

/**
*\brief Funcion que multiplica dos valores
*\param numA operando
*\return resultado
*/
int utn_factorial (int numA)
{
    int result;

    if(numA==1)
    {
        return 1;
    }
    result=numA* utn_factorial(numA - 1);
    return (result);
}

/**
*\brief Funcion que calcula suma, resta, division, multiplicacion y factorial
*\param numA Primer operando
*\param numB Segundo operando
*\return 0
*/
int utn_calculateAll(int numA, int numB)
{
    utn_sumNum(numA, numB, "El resultado de A+B es: ");
    utn_restNum(numA, numB,"El resultado de A-B es: ");
    utn_divideNum(numA, numB, "El resultado de A/B es: ","No se permite la division por 0");
    utn_multiplyNum(numA, numB, "El resultado de A*B es: ");
    utn_factorial(numA);
    utn_factorial(numB);

    return 0;
}
