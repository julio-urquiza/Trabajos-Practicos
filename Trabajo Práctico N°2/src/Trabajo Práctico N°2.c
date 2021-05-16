/*******************************************************************
*Programa:Trabajo Practico Nº2
*
*Objetivo:

1. Enunciado
Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
Datos:
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.
Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees” que
facilitará el manejo de la lista de empleados y su modificación. En la sección siguiente se
detallan las funciones que esta biblioteca debe tener.

*Division:1F
*Fecha:15/05/2021
*Autor:Julio Cesar Urquiza
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"


#define TAM 1000

int menu(void);

int main()
{
	setbuf(stdout,NULL);
    int seguir=1;
    Employee empleados[TAM];
    /*
    Employee empleados[TAM]=
    {
        {200,"julio","urquiza",15000,23,0},
        {201,"coco","ramirez",12000,56,0},
        {202,"milo","perez",13000,23,0},
        {203,"matias","tomson",17000,56,0},
        {204,"ernesto","simpsons",20000,23,0},
        {205,"juan","davila",16000,56,0},
        {206,"ivan","estevez",11000,23,0},
        {207,"lola","messi",12000,56,0}
    };
     */

    initEmployees(empleados,TAM);

    do{
        switch(menu())
        {
        case 1:
            //altas
            system("cls");
            darDeAltaEmpleado(empleados,TAM);
            break;
        case 2:
            //modificaciones
            system("cls");
            modificarEmpleado(empleados,TAM);
            break;
        case 3:
            //bajas
            system("cls");
            darDeBajaEmpleado(empleados,TAM);
            break;
        case 4:
            //informar
            system("cls");
            informar(empleados,TAM);
            break;
        case 5:
            //salir
            system("cls");
            printf("Esta saliendo del programa\n");
            seguir=0;
            break;

        }

    }while(seguir);
    return 0;
}

