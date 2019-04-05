#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getInt (int *pNum, char* msg, char* msgE);
int utn_getFloat (float *pNum, char* msg, char* msgE);
int utn_sumNum (float numA, float numB, char* resultMsg);
int utn_restNum (float numA, float numB, char* resultMsg);
int utn_divideNum (float numA, float numB, char* resultMsg, char* msgE);
int utn_multiplyNum (float numA, float numB, char* resultMsg);
int utn_factorial (float numA);
int utn_calculateAll(float numA, float numB);
int utn_showValues(float numA, float numB);

#endif // UTN_H_INCLUDED
