#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getIntRange (int* pNum, int max, int min,char* msg,char* msgE,int tries);
float utn_getFloatRange (float* pNum, int max, int min,char* msg,char* msgE,int tries);
int utn_getInt (int *pNum, char* msg, char* msgE);
float utn_getFloat (float *pNum, char* msg, char* msgE);
int utn_sumNum (int numA, int numB, char* resultMsg);
int utn_restNum (int numA, int numB, char* resultMsg);
int utn_divideNum (int numA, int numB, char* resultMsg, char* msgE);
int utn_multiplyNum (int numA, int numB, char* resultMsg);
long utn_factorial (int numA);
int utn_calculateAll(int numA, int numB);

#endif // UTN_H_INCLUDED
