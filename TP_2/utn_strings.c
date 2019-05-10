#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_strings.h"

///ESTE PROGRAMA FUE COMPILADO EN WINDOWS. AUTOR BRAIAN BALDINO.
/** \brief  Asks user to enter something.
* \param    pointerString Pointer to string array
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \return   return 0.
**/
int getString(char* pointerString, char* msg, char*msgE)
{
    char bufferStr[20];
    printf(msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pointerString!=NULL)
    {
        strncpy(pointerString,bufferStr,sizeof(bufferStr));
    }
    return 0;
}

/** \brief  Asks user to enter a number(integer).
* \param    pointerNumber Pointer to integer
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \return   return 0.
**/
int getInt (int *pointerNumber, char* msg, char* msgE)

{
    int number;
    int ret=-1;
    printf(msg);
    if(scanf("%d",&number)==1)
    {
        (*pointerNumber)=number;
        ret=0;
    }
    else
    {
        printf(msgE);
        fflush(stdin);
        //fpurge(stdin);
    }
    return ret;
}

/** \brief  Asks user to enter a number(float).
* \param    pointerNumber Pointer to integer
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \return   return 0.
**/
int getFloat (float *pointerNumber, char* msg, char* msgE)

{
    float number;
    int ret=-1;
    printf(msg);
    if(scanf("%f",&number)==1)
    {
        (*pointerNumber)=number;
        ret=0;
    }
    else
    {
        printf(msgE);
    }
    return ret;
}

/** \brief  Asks user to enter a number(integer)
*           withing a range.
* \param    pointerNumber Pointer to integer
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \param    minimo Minimum number to be entered.
* \param    maximo Maximum number to be entered.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
**/
int getIntInRange(  int *pointerNumber,
                    char *msg,
                    char *msgE,
                    int minimo,
                    int maximo,
                    int tries)
{
    int retorno = -1;
    char bufferStr[20];
    int bufferInt;
    do
    {

        if((pointerNumber != NULL)&&(!getStringNumeros(bufferStr,msg,msgE,tries)))
        {
            bufferInt=atoi(bufferStr);
            if(bufferInt>=minimo&&bufferInt<=maximo)
            {
                retorno = 0;
                *pointerNumber = bufferInt;
            }
            else
            {
                printf("El numero esta fuera del rango!\n");
                tries--;
            }
        }
        else
        {
            printf("No es un numero valido!\n");
            tries--;
        }
    } while(retorno==-1&&tries>0);
    return retorno;
}

/** \brief  Asks user to enter text
*           validating that the text contains
*           no numbers or special characters.
* \param    pointerString Pointer to string array
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
**/
int getStringLetras (char* pointerString, char* msg, char* msgE,int tries)
{
    char bufferStr[51];
    int ret=-1;
    while(ret==-1 && tries>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pointerString!=NULL)
            &&(isLetter(bufferStr)))
        {
            strncpy(pointerString,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf(msgE);
            tries--;
        }
    }
    return ret;
}

/** \brief  Asks user to enter text(number)
*           validating that the string is a number.
* \param    pointerString Pointer to string array
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
**/
int getStringNumeros (char* pointerString, char* msg, char* msgE,int tries)
{
    char bufferStr[20];
    int retorno=-1;
    while(retorno==-1 && tries>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pointerString!=NULL)
           &&(isNumber(bufferStr)))
        {
            strncpy(pointerString,bufferStr,sizeof(bufferStr));
            retorno=0;
        }
        else
        {
            printf(msgE);
            retorno=-1;
        }
    }
    return retorno;
}

/** \brief  Asks user to enter text(float number)
*           validating that the string is a float number.
* \param    pointerString Pointer to string array
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
**/
int getStringNumerosFloat (char* pointerString, char* msg, char* msgE,int tries)
{
    char bufferStr[20];
    int retorno=-1;
    while(retorno==-1 && tries>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pointerString!=NULL)
           &&(isNumberFloat(bufferStr)))
        {
            strncpy(pointerString,bufferStr,sizeof(bufferStr));
            retorno=0;
        }
        else
        {
            printf(msgE);
            retorno=-1;
        }
    }
    return retorno;
}

/** \brief  Asks user to enter text (alphanumeric)
*           validating that the text contains
*           only numbers or letters or '-'.
* \param    pointerString Pointer to string array
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
**/
int getStringAlphanumeric (char* pointerString, char* msg, char* msgE,int tries)
{
    char bufferStr[250];
    int ret=-1;
    while(ret==-1 && tries>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pointerString!=NULL)
           &&(isAlphanumeric(bufferStr)))
        {
            strncpy(pointerString,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf(msgE);
            tries--;
        }
    }
    return ret;
}

/** \brief  Asks user to enter a valid
*           phone number. One '-' is allowed.
* \param    pointerString Pointer to string array
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
**/
int getTelephone (char* pointerString, char* msg, char* msgE,int tries)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && tries>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pointerString!=NULL)
           &&(isTelephone(bufferStr)))
        {
            strncpy(pointerString,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf(msgE);
            tries--;
        }
    }
    return ret;
}

/** \brief  Asks user to enter a valid DNI.
* \param    pointerString Pointer to string array
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
**/
int getDni (char* pointerString, char* msg, char* msgE,int tries)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && tries>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pointerString!=NULL)
           &&(isDni(bufferStr)))
        {
            strncpy(pointerString,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf(msgE);
            tries--;
        }
    }
    return ret;
}

/** \brief  Asks user to enter a valid CUIT.
* \param    pointerString Pointer to string array
* \param    msg Message to be shown to the user.
* \param    msgE Error message to be shown to the user.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
**/
int getCuit (char* pointerString, char* msg, char* msgE,int tries)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && tries>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pointerString!=NULL)
           &&(isCuit(bufferStr)))
        {
            strncpy(pointerString,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf(msgE);
            tries--;
        }
    }
    return ret;
}

/** \brief  Validates if sting contains only numbers (integer).
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isNumber (char* pointerString)
{
    int i=0;
    while(pointerString[i]!='\0')
    {
        if(pointerString[i]<'0' || pointerString[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
/** \brief  Validates if sting contains only numbers (float).
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isNumberFloat (char* pointerString)
{
    int i=0;
    int contadorPuntos=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]<'0' || pointerString[i]>'9')
           &&(pointerString[i]!='.'))
        {
            return 0;
        }
        if(pointerString[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>1)
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

/** \brief  Validates if sting contains only letters.
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isLetter (char* pointerString)
{
    int i=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]!=' ')&&(pointerString[i]<'a'||pointerString[i]>'z')
           &&(pointerString[i]<'A'||pointerString[i]>'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief  Validates if sting contains only letters,
*           numbers, spaces or a dot.
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isAlphanumeric (char* pointerString)
{
    int i=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]!=' ')&&(pointerString[i]!='.')
           &&(pointerString[i]<'a'||pointerString[i]>'z')
           &&(pointerString[i]<'A'||pointerString[i]>'Z')
           &&(pointerString[i]<'0' || pointerString[i]>'9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief  Validates if sting contains only numbers,
*           spaces or a dash(only one).
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isTelephone (char* pointerString)
{
    int i=0;
    int contadorGuion=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]!=' ')
           &&(pointerString[i]!='-')
           &&(pointerString[i]<'0' || pointerString[i]>'9'))
        {
            return 0;
        }
        if(pointerString[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return 1;
        }
    return 0;
}

/** \brief  Validates if sting contains only numbers
*           and if its lengh is 7 as minimun accepted
*           or 8 as maximum accepted for a DNI.
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isDni (char* pointerString)
{
    int i=0;
    while(pointerString[i]!='\0')
    {
        if(!isNumber(pointerString))
        {
            return 0;
        }
        if(strlen(pointerString)<7 || strlen(pointerString)>8)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief  Validates if sting contains only numbers,
*           and two dashes in fixed position.
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isCuit (char* pointerString)
{
    int ret=0;
    int i=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]!='-')
           &&(pointerString[i]<'0' || pointerString[i]>'9'))
        {
            return 0;
        }
        else if((pointerString[2]=='-')
                &&(pointerString[10]=='-' || pointerString[11]=='-'))
        {
            ret=1;
        }
        i++;
    }
    return ret;
}
