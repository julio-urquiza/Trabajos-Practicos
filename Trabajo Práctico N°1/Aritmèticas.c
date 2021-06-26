/*******************************************************************
*Programa:Trabajo Practico Nº1
*Division:1F
*Fecha:12/09/2020
*Autor:Julio Cesar Urquiza
*
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Aritmèticas.h"

int sumar(int numero1,int numero2,int* resultado)
{
    int retono=0;
    if(resultado!=NULL)
    {
        *resultado=numero1+numero2;
        retono=1;
    }
    return retono;
}

int restar(int numero1,int numero2,int* resultado)
{
    int retono=0;
    if(resultado!=NULL)
    {
        *resultado=numero1-numero2;
        retono=1;
    }
    return retono;
}

int multiplicar(int numero1,int numero2,int* resultado)
{
    int retono=0;
    if(resultado!=NULL)
    {
        *resultado=numero1*numero2;
        retono=1;
    }
    return retono;
}

float dividir(int numero1,int numero2,float* resultado)
{
    int retono=0;
    float aux;
    if (numero2!=0 && resultado!=NULL)
    {
        aux=(float)numero1/numero2;
        retono=1;
    }
    *resultado=aux;
    return retono;
}

int calcularFactorial(int numero)
{
    int resultado=-1;
    if(numero>=0)
    {
        if (numero == 0)
        {
            resultado=1;
        }
        else
        {
            resultado = numero*calcularFactorial(numero-1);
        }
    }
    return resultado;
}
