#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int A;
    int B;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                utn_getInt(&A,"Ingrese 1er operando: ","Error ");
                break;
            case 2:
                utn_getInt(&B,"Ingrese 2do operando: ","Error ");
                break;
            case 3:
                utn_sumNum(A,B,"La suma es: ");
                break;
            case 4:
                utn_restNum(A,B,"La resta es: ");
                break;
            case 5:
                utn_divideNum(A,B,"La division es: ","No se permite la division por 0");
                break;
            case 6:
                utn_multiplyNum(A,B,"La multiplicacion es: ");
                break;
            case 7:
                utn_factorial(A);
                printf("El factorial de: %d! = %1d\n",A,utn_factorial(A));
                break;
            case 8:
                utn_calculateAll(A,B);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
