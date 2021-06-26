#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int primerNumero;
    int segundoNumero;
    int flag1=0;
    int flag2=0;
    int flag3=0;

    int resultadoSum;
    int resultadoRes;
    float resultadoDiv;
    int resultadoMul;
    int resultadoFac1;
    int resultadoFac2;

    int retornoDivision;

    int seguir=1;

    do{
        //menu de opciones
        switch(menu(primerNumero,segundoNumero,flag1,flag2))
        {
        case 1://pedir primer numero
            flag1=pedirNumero(&primerNumero,"Ingrese el primer numero:");
            break;
        case 2://pedir segundo numero
            flag2=pedirNumero(&segundoNumero,"Ingrese el segundo numero:");
            break;
        case 3://calcular las operaciones
            flag3=calcularOperaciones(primerNumero,segundoNumero,flag1,flag2,
                                      &resultadoSum,&resultadoRes,&resultadoDiv,
                                      &resultadoMul,&resultadoFac1,&resultadoFac2,&retornoDivision);
            break;
        case 4://mostrar los resultados
            mostrarResultados(flag3,retornoDivision,resultadoSum,resultadoRes,
                              resultadoDiv,resultadoMul,resultadoFac1,resultadoFac2);
            break;
        case 5://salir
            seguir=0;
            break;
        default:
            printf("No es una opcion valida\n");
            break;
        }
    }while(seguir);
    return 0;
}
