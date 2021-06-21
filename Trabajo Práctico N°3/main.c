/*******************************************************************
*Division:1g
*Alumno:Julio Cesar Urquiza
*DNI:42833671
*Trabajo Practico N°3
********************************************************************/
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>

void opciones(void);

int main()
{
    LinkedList* miLista=ll_newLinkedList();//asigno espacio para la linkedlist
    int flag=0;
    int seguir=1;
    do{

        opciones();
        switch(opcionSwitch("Ingrese una de las opciones: ","ERROR,",1,10))
        {

        case 1://1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
            system("cls");
            if(flag==0){
                flag=controller_loadFromText(miLista);
            }
            else{
                printf("Ya se cargaron lo datos una vez\n");
            }
            break;
        case 2://2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
            system("cls");
            if(flag==0){
                flag=controller_loadFromBinary(miLista);
            }
            else{
                printf("Ya se cargaron lo datos una vez\n");
            }
            break;
        case 3://3. Alta de empleado
            system("cls");
            if(flag==1){
                controller_addEmployee(miLista);
            }
            else{
                printf("Todavia no cargaste los datos\n");
            }
            break;
        case 4://4. Modificar datos de empleado
            system("cls");
            controller_ListEmployee(miLista);
            controller_editEmployee(miLista);
            break;
        case 5://5. Baja de empleado
            system("cls");
            controller_ListEmployee(miLista);
            controller_removeEmployee(miLista);
            break;
        case 6://6. Listar empleados
            system("cls");
            controller_ListEmployee(miLista);
            break;
        case 7://7. Ordenar empleados
            system("cls");
            controller_sortEmployee(miLista);
            break;
        case 8://8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
            system("cls");
            if(flag==1){
                controller_saveAsText(miLista);
            }
            else{
                printf("Todavia no cargaste los datos\n");
            }
            break;
        case 9://9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
            system("cls");
            if(flag==1){
                controller_saveAsBinary(miLista);
            }
            else{
                printf("Todavia no cargaste los datos\n");
            }
            break;
        case 10://10. Salir
            system("cls");
            printf("\nGracias por su tiempo, Adios\n");
            ll_deleteLinkedList(miLista);
            seguir=0;
            break;
        }
        system("pause");
    }while(seguir);
    return 0;
}

void opciones(void)
{
    system("cls");
    printf("Trabajo Practico Numero 3\n\n");
    printf("Que desea hacer?\n");
    printf("1.Cargar los datos de los empleados (modo texto)\n");
    printf("2.Cargar los datos de los empleados (modo binario)\n");
    printf("3.Alta de empleado\n");
    printf("4.Modificar datos de empleado\n");
    printf("5.Baja de empleado\n");
    printf("6.Listar empleados\n");
    printf("7.Ordenar empleados\n");
    printf("8.Guardar los datos de los empleados (modo texto)\n");
    printf("9.Guardar los datos de los empleados (modo binario)\n");
    printf("10.Salir\n\n");
}
