#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float A;
    float B;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!) (B!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                utn_getFloat(&A,"Ingrese 1er operando: ","Error ");
                printf("A=%.2f\n",A);
                break;
            case 2:
                utn_getFloat(&B,"Ingrese 2do operando: ","Error ");
                utn_showValues(A,B);
                break;
            case 3:
                utn_sumNum(A,B,"El resultado de A+B es: ");
                utn_showValues(A,B);
                break;
            case 4:
                utn_restNum(A,B,"El resultado de A-B es:  ");
                utn_showValues(A,B);
                break;
            case 5:
                utn_divideNum(A,B,"El resultado de A/B es:  ","No se permite la division por 0");
                utn_showValues(A,B);
                break;
            case 6:
                utn_multiplyNum(A,B,"El resultado de A*B es:  ");
                utn_showValues(A,B);
                break;
            case 7:
                utn_factorial(A);
                utn_factorial(B);
                utn_showValues(A,B);
                printf("El resultado de A! es: %.d\nEl resultado de B! es: %d\n",utn_factorial(A),utn_factorial(B));
                break;
            case 8:
                utn_calculateAll(A,B);
                utn_showValues(A,B);
                printf("El resultado de A! es: %d\nEl resultado de B! es: %d\n",utn_factorial(A),utn_factorial(B));
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
