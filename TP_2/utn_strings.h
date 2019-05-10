#ifndef UTN_STRINGS_H_INCLUDED
#define UTN_STRINGS_H_INCLUDED

///ESTE PROGRAMA FUE COMPILADO EN WINDOWS. AUTOR BRAIAN BALDINO.
int getString(char* pointerString, char* msg, char*msgE);
int getInt (int *pointerNumber, char* msg, char* msgE);
int getFloat (float *pointerNumber, char* msg, char* msgE);
int getIntInRange (int *pointerNumber,char *msg,char *msgE,int minimo,int maximo,int tries);
int getStringLetras (char* pointerString, char* msg, char* msgE,int tries);
int getStringNumeros (char* pointerString, char* msg, char* msgE,int tries);
int getStringNumerosFloat (char* pointerString, char* msg, char* msgE,int tries);
int getStringAlphanumeric (char* pointerString, char* msg, char* msgE,int tries);
int getTelephone (char* pointerString, char* msg, char* msgE,int tries);
int getDni (char* pointerString, char* msg, char* msgE,int tries);
int getCuit (char* pointerString, char* msg, char* msgE,int tries);

int isNumber (char* pointerString);
int isNumberFloat (char* pointerString);
int isLetter (char* pointerString);
int isAlphanumeric (char* pointerString);
int isTelephone (char* pointerString);
int isDni (char* pointerString);
int isCuit (char* pointerString);

#endif // UTN_STRINGS_H_INCLUDED
