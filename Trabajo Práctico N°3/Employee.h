/*******************************************************************
*Division:1g
*Alumno:Julio Cesar Urquiza
********************************************************************/
#include "validaciòn.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);//se carga el id en la estructura empleado
int employee_getId(Employee* this,int* id);//me devuelve el id del empleado

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_ListAEmployee(Employee* this,int i);

int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(void* e1, void* e2);
int employee_CompareBySalary(void* e1, void* e2);
int employee_CompareByWorkHour(void* e1, void* e2);

int modificarEmpleados(Employee*);

#endif // employee_H_INCLUDED
