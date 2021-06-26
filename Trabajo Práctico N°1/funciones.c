#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "Aritmèticas.h"

int menu(int primerNumero,int segundoNumero,int flag1,int flag2)
{
    int opcion;
    system("cls");
    printf("CALCULADORA\n");
    printf("1.Ingresar 1er operando ");
    if (flag1)
    {
        printf("(A=%d)\n",primerNumero);
    }
    else
    {
        printf("(A=x)\n");
    }
    printf("2.Ingresar 2do operando ");
    if (flag2)
    {
        printf("(B=%d)\n",segundoNumero);
    }
    else
    {
        printf("(B=y)\n");
    }
    printf("3.Calcular todas las operaciones\n");
    printf("4.Informar resultados\n");
    printf("5.Salir\n");
    pedirNumero(&opcion,"Elija una opcion: ");
    return opcion;
}

int pedirNumero(int* variable,char* mensaje)
{
    int retorno;
    retorno=0;
    if(variable!=NULL && mensaje!=NULL)
    {
        int bufferInt;
        printf("%s",mensaje);
        scanf("%d",&bufferInt);
        *variable=bufferInt;
        retorno=1;
    }
    return retorno;
}

int calcularOperaciones(int primerNumero,int segundoNumero,int flag1,int flag2,
                        int* resultadoSum,int* resultadoRest,float* resultadoDiv,
                        int* resultadoMult,int* resultadoFac1,int* resultadoFac2,
                        int* retornoDivision)
{
    int retorno=0;
    if (flag1 && flag2 &&
        resultadoSum!=NULL && resultadoRest!=NULL && resultadoDiv!=NULL &&
        resultadoMult!=NULL && resultadoFac1!=NULL && resultadoFac2!=NULL)
    {
        if(sumar(primerNumero,segundoNumero,resultadoSum))
        {
            if(restar(primerNumero,segundoNumero,resultadoRest))
            {
                if(multiplicar(primerNumero,segundoNumero,resultadoMult))
                {
                            retorno=1;
                }
            }
        }
        *resultadoFac1=calcularFactorial(primerNumero);
        *resultadoFac2=calcularFactorial(segundoNumero);
        *retornoDivision=dividir(primerNumero,segundoNumero,resultadoDiv);
        if(retorno)
        {
            printf("operaciones calculadas\n");
        }
        else
        {
            printf("Hubo un error al hacer las operaciones\n");
        }
    }
    else
    {
        printf("falta ingresar numeros\n");
    }
    system("pause");
    return retorno;
}

void mostrarResultados(  int flag3,int retornoDivision,
                        int resultadoSum,int resultadoRest,float resultadoDiv,
                        int resultadoMult,int resultadoFac1,int resultadoFac2)
{
    if (flag3)
    {
        printf("\nMostrando resultados");
        printf("\na.El resultado de A + B es :%d",resultadoSum);
        printf("\nb.El resultado de A - B es :%d",resultadoRest);
        if(retornoDivision==1)
        {
            printf("\nc.El resultado de A / B es :%.2f",resultadoDiv);
        }
        else
        {
            printf("\nc.No es posible dividir por cero");
        }
        printf("\nd.El resultado de A * B es: %d",resultadoMult);
        if(resultadoFac1==-1)
        {
            printf("\ne.No se puede sacar el factorial de A devido a que es negativo");
        }
        else
        {
            printf("\ne.El factorial de A es %d",resultadoFac1);
        }

        if(resultadoFac2==-1)
        {
            printf("\ne.No se puede sacar el factorial de B devido a que es negativo\n");
        }
        else
        {
            printf("\ne.El factorial de B es %d\n",resultadoFac2);
        }
    }
    else
    {
        printf("Primeros deves calcular las operaciones para poder mostrar los resultados\n");
    }
    system("pause");
}
