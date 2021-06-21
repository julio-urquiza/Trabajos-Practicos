/*******************************************************************
*Division:1g
*Alumno:Julio Cesar Urquiza
********************************************************************/
#include <stdlib.h>
#include "Employee.h"
#include <string.h>


Employee* employee_new()
{
    Employee* empleado=NULL;

    empleado = (Employee*) malloc(sizeof(Employee));

    return empleado;

}

Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Employee* empleadoRetorno=NULL;
    Employee* aux;

    aux = employee_new();
    if(aux!=NULL)
    {
        if(employee_setId(aux,id)&&
           employee_setNombre(aux,nombre)&&
           employee_setHorasTrabajadas(aux,horasTrabajadas)&&
           employee_setSueldo(aux,sueldo))
        {
            empleadoRetorno=aux;
        }
    }
    return empleadoRetorno;
}

int employee_setId(Employee* this,int id)
{
    int returnValue=-1;
    if(this!= NULL && id>0)
    {
        this->id=id;
        returnValue=1;
    }

    return returnValue;
}

int employee_getId(Employee* this,int* id)
{
    int returnValue=-1;
    if(this!= NULL && id!=NULL)
    {
        *id=this->id;
        returnValue=1;
    }
    return returnValue;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int returnValue=-1;
    if(this!= NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        returnValue=1;
    }
    return returnValue;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int returnValue=-1;
    if(this!= NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        returnValue=1;
    }
    return returnValue;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int returnValue=-1;
    if(this!= NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        returnValue=1;
    }
    return returnValue;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int returnValue=-1;
    if(this!= NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        returnValue=1;
    }
    return returnValue;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int returnValue=-1;
    if(this!= NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        returnValue=1;
    }
    return returnValue;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int returnValue=-1;
    if(this!= NULL && sueldo>0)
    {
        *sueldo=this->sueldo;
        returnValue=1;
    }
    return returnValue;
}

int employee_ListAEmployee(Employee* this,int i)
{
    int retorno=0;
    int  id;
    char nombre[51];
    int  horasTrabajadas;
    int  sueldo;

    if(this!=NULL)
    {
        employee_getId(this,&id);
        employee_getNombre(this,nombre);
        employee_getHorasTrabajadas(this,&horasTrabajadas);
        employee_getSueldo(this,&sueldo);
        printf("%6d) %6d %20s %20d %10d\n",i+1,id,nombre,horasTrabajadas,sueldo);
        retorno=1;
    }
    return retorno;
}

int employee_CompareByName(void* e1, void* e2)
{
    Employee* aux1;
    Employee* aux2;
    aux1=(Employee*)e1;
    aux2=(Employee*)e2;
    int retorno=0;
    if (strcmp(aux1->nombre,aux2->nombre)>0)
    {
        retorno=1;
    }
    else
    {
        if (strcmp(aux1->nombre,aux2->nombre)<0)
        {
            retorno=-1;
        }
    }
    return retorno;
}

int employee_CompareById(void* e1, void* e2)
{
    Employee* aux1;
    Employee* aux2;
    aux1=(Employee*)e1;
    aux2=(Employee*)e2;
    int retorno=0;
    if (aux1->id>aux2->id)
    {
        retorno=1;
    }
    else
    {
        if (aux1->id<aux2->id)
        {
            retorno=-1;
        }
    }
    return retorno;
}

int employee_CompareBySalary(void* e1, void* e2)
{
    Employee* aux1;
    Employee* aux2;
    aux1=(Employee*)e1;
    aux2=(Employee*)e2;
    int retorno=0;
    if (aux1->sueldo>aux2->sueldo)
    {
        retorno=1;
    }
    else
    {
        if (aux1->sueldo<aux2->sueldo)
        {
            retorno=-1;
        }
    }
    return retorno;
}

int employee_CompareByWorkHour(void* e1, void* e2)
{
    int retorno=0;
    Employee* aux1;
    Employee* aux2;
    aux1=(Employee*)e1;
    aux2=(Employee*)e2;
    if (aux1->horasTrabajadas>aux2->horasTrabajadas)
    {
        retorno=1;
    }
    else
    {
        if (aux1->horasTrabajadas<aux2->horasTrabajadas)
        {
            retorno=-1;
        }
    }
    return retorno;
}

int modificarEmpleados(Employee* this)
{
    int retorno=-1;
    int opcion;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[51];
    if(this!=NULL)
    {
        printf("que desea modificar:\n");
        printf("1.Id\n2.Nombre\n3.Sueldo\n4.Horas Trabajadas\n");
        pedirNumero(&opcion,"Ingrese una opcion: ","ERROR",4,1);
        retorno=1;
        switch(opcion)
        {
        case 1:
            pedirNumeroSinLimite(&id,"ingrese id: ","ERROR");
            employee_setId(this,id);
            break;
        case 2:
            pedirTexto(nombre,"ingrese nombre: ","ERROR");
            employee_setNombre(this,nombre);
            break;
        case 3:
            pedirNumeroSinLimite(&sueldo,"ingrese sueldo: ","ERROR");
            employee_setSueldo(this,sueldo);
            break;
        case 4:
            pedirNumeroSinLimite(&horasTrabajadas,"ingrese horas trabajadas: ","ERROR");
            employee_setHorasTrabajadas(this,horasTrabajadas);
            break;
        }
    }
    return retorno;
}







