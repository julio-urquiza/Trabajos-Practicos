/*******************************************************************
*Division:1g
*Alumno:Julio Cesar Urquiza
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r;
    char nombre[51];
    int id;
    int sueldo;
    int horasTrabajadas;
    Employee* aux;

    if(pArrayListEmployee!=NULL && pFile!=NULL)
    {
        do{
            r = fscanf(pFile,"%d,%[^,],%d,%d\n",&id,nombre,&horasTrabajadas,&sueldo);
            if(r==4)
            {
                aux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
                ll_add(pArrayListEmployee,aux);
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
    }

    return 1;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r;
    Employee dato;
    Employee* aux;

    if(pArrayListEmployee!=NULL && pFile!=NULL)
    {
        do{
            r=fread(&dato,sizeof(Employee),1,pFile);
            if(r==1)
            {
                aux=employee_newParametros(dato.id,dato.nombre,dato.horasTrabajadas,dato.sueldo);
                ll_add(pArrayListEmployee,aux);
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
    }
    return 1;

}
