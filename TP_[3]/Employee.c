#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"
#include "mostrarDatos.h"
#include "parser.h"
#include "utn.h"

/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief Crea empleados con parametros.
/// @param idStr char*
/// @param nombreStr char*
/// @param horasTrabajadasStr char*
/// @param salario char*
/// @return Empleado creado.

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* salario)
{
    Employee* pEmployee = employee_new();

    if(pEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && salario != NULL)
    {
        employee_setId(pEmployee, atoi(idStr));
        employee_setNombre(pEmployee, nombreStr);
        employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr));
        employee_setSueldo(pEmployee, atoi(salario));
    }
    return pEmployee;
}

/// @fn Employee employee_new*()
/// @brief Constructor de empleados.
/// @return Empleados creados.

Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee = (Employee*) calloc(sizeof(Employee), 1);

    return pEmployee;
}

/// @fn int employee_setId(Employee*, int)
/// @brief Coloca un ID en un empleado.
/// @param this
/// @param id
/// @return 1 si esta ok.

int employee_setId(Employee* this, int id)
{
    int retorno;

    if(this != NULL)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}

/// @fn int employee_setNombre(Employee*, char*)
/// @brief Establece un nombre al empleado.
/// @param this Employee*
/// @param nombre char*
/// @return 1 si esta ok.

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief Establece las horas trabajdas de un empleado.
/// @param this Employee*
/// @param horasTrabajadas int
/// @return 1 si esta ok.

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

/// @fn int employee_setSueldo(Employee*, int)
/// @brief Establece el salario de un empleado.
/// @param this Employee*
/// @param sueldo int
/// @return 1 si esta ok.

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }
    return retorno;
}

/// @fn int employee_getId(Employee*, int*)
/// @brief Obtiene el ID de un empleado.
/// @param this Employee*
/// @param id int*
/// @return 1 si esta ok.

int employee_getId(Employee* this, int* id)
{
    int retorno;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

/// @fn int employee_getNombre(Employee*, char*)
/// @brief Obtiene un nombre de un empleado.
/// @param this Employee*
/// @param nombre char*
/// @return 1 si esta ok.

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}

/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief Obtiene la hora trabaja de un empleado.
/// @param this Employee*
/// @param horasTrabajadas int*
/// @return 1 si esta ok.

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

/// @fn int employee_getSueldo(Employee*, int*)
/// @brief Obtiene un salario de un empleado.
/// @param this Employee*
/// @param sueldo int*
/// @return 1 si esta ok.

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}

/// @fn void employee_delete(Employee*)
/// @brief Elimina a un empleado.
/// @param this Employee*

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

/// @fn int employee_compareId(void*, void*)
/// @brief Compara IDs de dos empleados.
/// @param e1 void*
/// @param e2 void*
/// @return 1 si el primer ID es mayor que el segundo, si no lo es retornara -1.

int employee_compareId(void* e1, void* e2)
{
    Employee* pEmployee1 = (Employee*) e1;
    Employee* pEmployee2 = (Employee*) e2;
    int id1;
    int id2;
    int retorno = 0;

    if(pEmployee1 != NULL && pEmployee2 != NULL)
    {
		employee_getId(pEmployee1, &id1);
		employee_getId(pEmployee2, &id2);

		if(id1 > id2)
		{
			retorno = 1;
		}
		else if(id1 < id2)
		{
			retorno = -1;
		}
    }
    return retorno;
}

/// @fn int employee_CompareName(void*, void*)
/// @brief Compara los nombres de los empleados.
/// @param e1 void*
/// @param e2 void*
/// @return El valor de strcmp.

int employee_CompareName(void* e1, void* e2)
{
    Employee* pEmployee1 = (Employee*) e1;
    Employee* pEmployee2 = (Employee*) e2;
    char nombre1[51];
    char nombre2[51];
    int retorno;

    if(pEmployee1 != NULL && pEmployee2 != NULL)
    {
        employee_getNombre(pEmployee1, nombre1);
        employee_getNombre(pEmployee2, nombre2);
        retorno = strcmp(nombre1, nombre2);
    }
    return retorno;
}

int employee_CompareHoursWorked(void* e1, void* e2)
{
    Employee* pEmployee1 = (Employee*) e1;
    Employee* pEmployee2 = (Employee*) e2;
    int horas1;
    int horas2;
    int retorno = 0;

    if(pEmployee1 != NULL && pEmployee2 != NULL)
    {
    	employee_getHorasTrabajadas(pEmployee1, &horas1);
    	employee_getHorasTrabajadas(pEmployee2, &horas2);

    	if(horas1 > horas2)
    	{
    		retorno = 1;
    	}
    	else if(horas1 < horas2)
    	{
    		retorno = -1;
    	}
    }
    return retorno;
}

int employee_CompareSalary(void* e1, void* e2)
{
    Employee* pEmployee1 = (Employee*) e1;
    Employee* pEmployee2 = (Employee*) e2;
    int salario1;
    int salario2;
    int retorno = 0;

    if(pEmployee1 != NULL && pEmployee2 != NULL)
    {
    	employee_getSueldo(pEmployee1, &salario1);
    	employee_getSueldo(pEmployee2, &salario2);

    	if(salario1 > salario2)
    	{
    		retorno = 1;
    	}
    	else if(salario1 < salario2)
    	{
    		retorno = -1;
    	}
    }
    return retorno;
}
