#include <stdlib.h>
#include "contestant.h"
#include <string.h>


Contestant* Contestant_new();
Contestant* Contestant_newParametros(int numeroConcursante,int añoNacimiento,char* nombre,char* dni,char* FechaDePresentacion,char* temaPresentacion,int puntajePrimeraRonda);

int contestant_setNumeroConcursante(Contestant* this,int numero)
{
    int returnValue=-1;
    if(this!= NULL && numero>0)
    {
        this->numero=numero;
        returnValue=1;
    }
    return returnValue;
}
int contestant_getNumeroConcursante(Contestant* this,int* numero)
{
    int returnValue=-1;
    if(this!= NULL && numero!=NULL)
    {
        *numero=this->numero;
        returnValue=1;
    }
    return returnValue;

}

int contestant_setAñoNacimiento(Contestant* this,int anio)
{
    int returnValue=-1;
    if(this!= NULL && anio>0)
    {
        this->anio=anio;
        returnValue=1;
    }
    return returnValue;
}
int contestant_getAñoNacimiento(Contestant* this,int* anio)
{
    int returnValue=-1;
    if(this!= NULL && anio!=NULL)
    {
        *anio=this->anio;
        returnValue=1;
    }
    return returnValue;
}

int contestant_setNombre(Contestant* this,char* nombre)
{
    int returnValue=-1;
    if(this!= NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        returnValue=1;
    }
    return returnValue;
}
int contestant_getNombre(Contestant* this,char* nombre)
{
    int returnValue=-1;
    if(this!= NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        returnValue=1;
    }
    return returnValue;
}

int contestant_setDni(Contestant* this,char* dni)
{
    int returnValue=-1;
    if(this!= NULL && dni!=NULL)
    {
        strcpy(this->dni,dni);
        returnValue=1;
    }
    return returnValue;
}
int contestant_getDni(Contestant* this,char* dni)
{
    int returnValue=-1;
    if(this!= NULL && dni!=dni)
    {
        strcpy(dni,this->dni);
        returnValue=1;
    }
    return returnValue;
}

int contestant_setFechaDePresentacion(Contestant* this,char* fechaDePresentacion);
int contestant_getFechaDePresentacion(Contestant* this,char* fechaDePresentacion);

int contestant_setTemaPresentacion(Contestant* this,char* temaPresentacion);
int contestant_getTemaPresentacion(Contestant* this,char* temaPresentacion);

int contestant_setPuntajePrimeraRonda(Contestant* this,int puntajePrimeraRonda);
int contestant_getPuntajePrimeraRonda(Contestant* this,int* puntajePrimeraRonda);
