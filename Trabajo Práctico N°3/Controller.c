/*******************************************************************
*Division:1g
*Alumno:Julio Cesar Urquiza
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


int controller_loadFromText(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(pArrayListEmployee!=NULL)
    {
        pFile=fopen("data.csv","r");
        if(pFile == NULL)
        {
            printf("El archivo no existe\n");
            exit(EXIT_FAILURE);
        }
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        printf("\nDatos Cargados con exito\n");
        fclose(pFile);
        retorno=1;
    }
    return retorno;
}


int controller_loadFromBinary(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(pArrayListEmployee!=NULL)
    {
        pFile=fopen("data.bin","rb");
        if(pFile == NULL)
        {
            printf("El archivo no existe\n");
            exit(EXIT_FAILURE);
        }
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        printf("\nDatos Cargados con exito\n");
        fclose(pFile);
        retorno=1;
    }
    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int  id;
    char nombre[51];
    int  horasTrabajadas;
    int  sueldo;

    int opcion;
    Employee* aux;
    if(pArrayListEmployee!=NULL)
    {
        do{
        //pedir los datos al usuario
        id=1+ll_len(pArrayListEmployee);
        pedirTextoConNumeros(nombre,"ingrese nombre: ","ERROR,");
        pedirNumeroSinLimite(&horasTrabajadas,"ingrese cantidad de horas trabajadas: ","ERROR,");
        pedirNumeroSinLimite(&sueldo,"ingrese sueldo: ","ERROR,");

        aux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);//junto los datos y creo al empleado
        if(aux!=NULL )
        {
            pedirNumero(&opcion,"desea cargar el empleado a la lista?(1.SI o 2.NO): ","ERROR, ",2,1);
            if(opcion==1)
            {
                ll_add(pArrayListEmployee,aux);//agrego el empleado al linkedlist
            }
        }
        else
        {
            printf("hubo un error vuelva a ingresar los datos\n");
        }

        pedirNumero(&opcion,"¿desea ingresar otro empleados?(1.SI o 2.NO): ","ERROR, ",2,1);
        }while(opcion!=2);
    }
    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno=-1;
    Employee* aux=NULL;
    int index;
    if(pArrayListEmployee!=NULL)
    {
        if(ll_len(pArrayListEmployee)>0)
        {
            do{
                pedirNumeroSinLimite(&index,"ingrese el id del empleado al que deasea editar: ","ERROR,");
                aux=(Employee*)ll_get(pArrayListEmployee,index-1);
                if(aux!=NULL)
                {
                    system("cls");
                    printf("%6s %6s %20s %10s %10s\n","index","id","nombre","sueldo","horasTrabajadas");
                    employee_ListAEmployee(aux,index-1);
                    modificarEmpleados(aux);
                    retorno=1;
                }
                else
                {
                    printf("este empleado no existe todavia\n");
                }
            pedirNumero(&opcion,"¿desea continuar ingresando empleados?(1 para SI o 2 para NO): ","ERROR, ",2,1);
            }while(opcion!=2);
        }
        else
        {
            printf("No hay empleados que modificar\n");
        }
    }
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno=-1;
    Employee* aux=NULL;
    int index;
    if(pArrayListEmployee!=NULL)
    {
        if(ll_len(pArrayListEmployee)>0)
        {
            do{
                pedirNumeroSinLimite(&index,"ingrese el index del empleado al que deasea eliminar: ","ERROR,");
                aux=(Employee*)ll_get(pArrayListEmployee,index-1);
                if(aux!=NULL)
                {
                    ll_remove(pArrayListEmployee,index-1);
                    retorno=1;
                }
                else
                {
                    printf("Este empleado no existe todavia\n");
                }
            pedirNumero(&opcion,"¿desea continuar ingresando empleados?(1 para SI o 2 para NO): ","ERROR, ",2,1);
            }while(opcion!=2);
        }
        else
        {
            printf("No hay empleados para eliminar\n");
        }
    }
    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* aux;
    int len;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        printf("Cantidad de elementos: %d\n",len);//cuenta los elementos de mi linkedlist
        if(len>0)
        {
            printf("%6s %6s %20s %20s %10s\n","index","id","nombre","horas Trabajadas","sueldo");
            for(int i=0;i<len;i++)
            {
                aux=(Employee*)ll_get(pArrayListEmployee,i);
                if(aux!=NULL)
                {
                    employee_ListAEmployee(aux,i);
                }
            }
        }
        retorno=1;
    }
    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int opcion;
    int orden;
    if(pArrayListEmployee!=NULL)
    {
        printf("como desea ordenarlos:\n");
        printf("De que manera los desea ordenar:(0.ascendente) (1.descendente)");
        pedirNumero(&orden,"ingrese una opcion: ","ERROR, ",1,0);
        printf("1.Por el id\n2.Por el nombre\n3.Por el sueldo\n4.Por la cantidad de horas trabajadas\n5.No los quiero ordenar\n");
        pedirNumero(&opcion,"ingrese una opcion: ","ERROR, ",5,1);

        switch(opcion)
        {
            case 1:
                ll_sort(pArrayListEmployee,*employee_CompareById,orden);
                break;
            case 2:
                ll_sort(pArrayListEmployee,employee_CompareByName,orden);
                break;
            case 3:
                ll_sort(pArrayListEmployee,employee_CompareBySalary,orden);
                break;
            case 4:
                ll_sort(pArrayListEmployee,employee_CompareByWorkHour,orden);
                break;
            case 5:
                break;
        }
        retorno=1;
    }

     return retorno;
}


int controller_saveAsText(LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int i;
    Employee* aux;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[51];
    int opcion;
    int len;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        printf("Cantidad de elementos: %d\n",len);//cuenta los elementos de mi linkedlist
        pedirNumero(&opcion,"Esta seguro que quiere guardar la lista de empleado?(1 para SI o 2 para NO): ","ERROR, ",2,1);
        if(opcion==1)
        {
            pFile=fopen("data.csv","w");
            if(pFile == NULL)
            {
                printf("El archivo no existe\n");
                exit(EXIT_FAILURE);
            }
            for(i=0;i<len;i++)
            {
                aux=ll_get(pArrayListEmployee,i);
                employee_getId(aux,&id);
                employee_getNombre(aux,nombre);
                employee_getSueldo(aux,&sueldo);
                employee_getHorasTrabajadas(aux,&horasTrabajadas);
                fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
            }
            fclose(pFile);
        }
    }
    return 1;
}


int controller_saveAsBinary(LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int i;
    Employee* aux;
    int opcion;
    int len;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        printf("Cantidad de elementos: %d\n",len);//cuenta los elementos de mi linkedlist
        pedirNumero(&opcion,"Esta seguro que quiere guardar la lista de empleado?(1 para SI o 2 para NO): ","ERROR, ",2,1);
        if(opcion==1)
        {
            pFile=fopen("data.bin","wb");
            if(pFile == NULL)
            {
                printf("El archivo no existe\n");
                exit(EXIT_FAILURE);
            }
            for(i=0;i<len;i++)
            {
                aux=ll_get(pArrayListEmployee,i);
                fwrite(aux,sizeof(Employee),1,pFile);
            }
            fclose(pFile);
        }
    }
    return 1;
}

