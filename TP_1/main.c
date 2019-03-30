#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int A;
    int B;
    int result;

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
                A=utn_getInt(&A,"Ingresar 1er operando: ","Error. ");
                break;
            case 2:
                B=utn_getInt(&B,"Ingresar 2edo operando: ","Error. ");
                break;
            case 3:
                result=utn_sumNum(A,B);
                break;
            case 4:
                result=utn_restNum(A,B);
                break;
            case 5:
                result=utn_divideNum(A,B);
                break;
            case 6:
                result=utn_multiplyNum(A,B);
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    printf("Eligio la opcion: %d\nEl resultado es: %.2f",opcion,(float)result);

    return 0;
}
