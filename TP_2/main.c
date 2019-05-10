#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_strings.h"
#define LEN_EMPLOYEE 1000
#define TRIES 3

///ESTE PROGRAMA FUE COMPILADO EN WINDOWS. AUTOR BRAIAN BALDINO.
int main()
{
    Employee Empleado[LEN_EMPLOYEE];
    employee_menu(Empleado,LEN_EMPLOYEE,"\n1)Alta\n2)Modificacion\n3)Baja\n"
             "4)Informar\n5)Salir\n",5,TRIES);
    return 0;
}
