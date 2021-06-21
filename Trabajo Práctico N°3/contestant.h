#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int numeroConcursante;
    int añoNacimiento;
    char[51] nombre;
    char [9] dni;
    char [10] fechaDePresentacion;
    char[31] temaPresentacion;
    int puntajePrimeraRonda;

}Contestant;


Contestant* Contestant_new();
Contestant* Contestant_newParametros(int numeroConcursante,int añoNacimiento,char* nombre,char* dni,char* FechaDePresentacion,char* temaPresentacion,int puntajePrimeraRonda);

int contestant_setNumeroConcursante(Contestant* this,int numero);
int contestant_getNumeroConcursante(Contestant* this,int numero);

int contestant_setAñoNacimiento(Contestant* this,int anio);
int contestant_getAñoNacimiento(Contestant* this,int anio);

int contestant_setNombre(Contestant* this,char* nombre);
int contestant_getNombre(Contestant* this,char* nombre);

int contestant_setDni(Contestant* this,char* dni);
int contestant_getDni(Contestant* this,char* dni);

int contestant_setFechaDePresentacion(Contestant* this,char* fechaDePresentacion);
int contestant_getFechaDePresentacion(Contestant* this,char* fechaDePresentacion);

int contestant_setTemaPresentacion(Contestant* this,char* temaPresentacion);
int contestant_getTemaPresentacion(Contestant* this,char* temaPresentacion);

int contestant_setPuntajePrimeraRonda(Contestant* this,int puntajePrimeraRonda);
int contestant_getPuntajePrimeraRonda(Contestant* this,int puntajePrimeraRonda);

