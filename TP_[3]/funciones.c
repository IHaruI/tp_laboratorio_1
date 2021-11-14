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

/// @fn int controlarOpcion(LinkedList*)
/// @brief Verifica si hay empleados cargados.
/// @param listaEmpleados LinkedList*
/// @return 0 si esta ok.

int controlarOpcion(LinkedList* listaEmpleados)
{
    int retorno = 1;
    int len;

    len = ll_len(listaEmpleados);

    if(len > 0)
    {
    	retorno = 0;
    }
    return retorno;
}

/// @fn int listaDeEmpleados(LinkedList*, int)
/// @brief Lista de empleados.
/// @param pArrayListEmployee LinkedList*
/// @param indice int
/// @return 0 si esta ok.

int listaDeEmpleados(LinkedList* pArrayListEmployee, int indice)
{
    Employee* auxEmployee;
    int id;
    char nombre[51];
    int horasTrabajadas;
    int salario;

    auxEmployee = ll_get(pArrayListEmployee, indice);
    employee_getId(auxEmployee, &id);
    employee_getNombre(auxEmployee, nombre);
    employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
    employee_getSueldo(auxEmployee, &salario);

    printf("%d\t%15s\t\t\t%d\t\t%d\n", id, nombre, horasTrabajadas, salario);

    return 0;
}

/// @fn int modificarEmpleado(LinkedList*)
/// @brief Modifica a un empleado mediante el ID.
/// @param pArrayListEmployee LinkedList*
/// @return 0 si esta ok.

int modificarEmpleado(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int bandera = -1;
    int opcion;
    int indice;
    char nombre[51];
    int horasTrabajadas;
    int salario;

    indice = buscarId("\n\nIngrese el ID del empleado: ", "\nError, ingrese uno de los ID mostrados: ", pArrayListEmployee);
    if(indice == -1)
    {
        printf("\nError.\n");
    }
    else
    {
        do
        {
            if(bandera == 0)
            {
            	printf("\n____________________________________\n");
                printf("\nSe ha completado la modificacion.\n");
                printf("____________________________________");
                printf("\n\n-----------------------------------------------------------------");
                printf("\nId\t\tNombre\t\tHoras trabajadas\tSueldo\n");
                listaDeEmpleados(pArrayListEmployee, indice);
                printf("-----------------------------------------------------------------\n");
            }

            mostrarMenuDeModificacion();
            opcion = getInt(opcion, "\nIngrese la opcion que desee: ", "\nError, ingrese unas de las opciones dadas: ", 1, 4);
            pEmployee = ll_get(pArrayListEmployee, indice);

            switch(opcion)
            {
				case 1:
					printf("\n--------------------------------------");
					getOnlyString(nombre, "\nIngrese su nombre: ", "\nError, reingrese su nombre: ");
					printf("--------------------------------------");
					employee_setNombre(pEmployee, nombre);
					bandera = 0;
				break;

				case 2:
					printf("\n-------------------------------------------");
					horasTrabajadas = getInt(horasTrabajadas, "\nIngrese horas: ", "\nError, reingrese la hora: ", 0, 500);
					printf("-------------------------------------------");
					employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
					bandera = 0;
				break;

				case 3:
					printf("\n-------------------------------------------");
					salario = getInt(salario, "\nIngrese su salario: ", "\nError, reingrese su salario: ", 0, 1000000);
					printf("-------------------------------------------");
					employee_setSueldo(pEmployee, salario);
					bandera = 0;
				break;
            }
        }while(opcion != 4);
    }
    return bandera;
}

/// @fn int buscarId(char[], char[], LinkedList*)
/// @brief Busca el ID buscado.
/// @param mensaje char
/// @param mensajeError char
/// @param pArrayListEmployee Linkedist*
/// @return El indice.

int buscarId(char mensaje[], char mensajeError [], LinkedList* pArrayListEmployee)
{
    int indice;
    int id;

    printf("%s", mensaje);
    scanf("%d", &id);

    indice = findEmployeeById(id, pArrayListEmployee);

     while(indice == -1)
    {
    	printf("\n---------------------------------------------");
        printf("%s", mensajeError);
        scanf("%d", &id);
        indice = findEmployeeById(id, pArrayListEmployee);
    }
    return indice;
}

/// @fn int findEmployeeById(int, LinkedList*)
/// @brief Encuentra al empleado por el ID
/// @param id int
/// @param pArrayListEmployee LinkedList*
/// @return La posicion del indice del empleado o -1 si la lngitud no es valida o el puntero no encontro a un empleado.

int findEmployeeById(int id, LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    int retorno = -1;
    int auxId;
    int len;

    len = ll_len(pArrayListEmployee);

    for(int i = 0; i < len; i++)
    {
    	auxiliar = ll_get(pArrayListEmployee, i);
        employee_getId(auxiliar, &auxId);

            if(auxId == id)
            {
                auxId = id;
                retorno = i;
                break;
            }
    }
    return retorno;
}

/// @fn int eliminarEmpleado(LinkedList*)
/// @brief Elimina a un empleado por ID.
/// @param pArrayListEmployee LinkedList*
/// @return 0 si esta ok.

int eliminarEmpleado(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int opcion;
	int retorno = -1;
	int indice;

	indice = buscarId("\n\nIngrese el ID del empleado para eliminar: ", "\nError, ingrese uno de los ID mostrados: ", pArrayListEmployee);

	do
	{
		printf("\n-----------------------------------------------------------------");
		printf("\nId\t\tNombre\t\tHoras trabajadas\tSueldo\n");
		listaDeEmpleados(pArrayListEmployee, indice);
		printf("-----------------------------------------------------------------\n");
		mostrarMenuEliminado();
		opcion = getInt(opcion, "\nIngrese la opcion que desee: ", "\nError, ingrese unas de las opciones dadas: ", 1, 2);

		if(opcion == 1)
		{
			pEmployee = ll_get(pArrayListEmployee, indice);
			employee_delete(pEmployee);
			retorno = ll_remove(pArrayListEmployee, indice);
			break;
		}
	}while(opcion != 2);

	return retorno;
}

/// @fn int ordenarEmpleados(LinkedList*)
/// @brief Ordena a los empleados.
/// @param cloneList LinkedList*
/// @return 0 si esta ok.

int ordenarEmpleados(LinkedList* cloneList)
{
    int retorno = -1;
    int opcion;
    int order;

    do
    {
    	mostrarMenuDeOrdenamiento();
    	opcion = getInt(opcion, "\nIngrese la opcion que desee: ", "\nError, ingrese unas de las opciones dadas.: ", 1, 5);

		switch(opcion)
		{
			case 1:
				printf("\n-------------------------------------------------------");
				order = getInt(order, "\nIngrese 0 para ordenar de forma descendente (X-1): \nIngrese 1 para ordenar de forma ascendente (1-X): ", "\nError, ingrese unas de las opciones dadas: ", 0, 1);
				printf("\nOrdenando. . .\n");
				retorno = ll_sort(cloneList, employee_compareId, order);
				controller_ListEmployee(cloneList);
			break;

			case 2:
				printf("\n-------------------------------------------------------");
				order = getInt(order, "\nIngrese 0 para ordenar de forma descendente (Z-A): \nIngrese 1 para ordenar de forma ascendente (A-Z): ", "\nError, ingrese unas de las opciones dadas: ", 0, 1);
				printf("\nOrdenando. . .\n");
				retorno = ll_sort(cloneList, employee_CompareName, order);
				controller_ListEmployee(cloneList);
			break;

			case 3:
				printf("\n-------------------------------------------------------");
				order = getInt(order, "\nIngrese 0 para ordenar de forma descendente (X-1): \nIngrese 1 para ordenar de forma ascendente (1-X): ", "\nError, ingrese unas de las opciones dadas: ", 0, 1);
				printf("\nOrdenando. . .\n");
				retorno = ll_sort(cloneList, employee_CompareHoursWorked, order);
				controller_ListEmployee(cloneList);
				break;

			case 4:
				printf("\n-------------------------------------------------------");
				order = getInt(order, "\nIngrese 0 para ordenar de forma descendente (X-1): \nIngrese 1 para ordenar de forma ascendente (1-X): ", "\nError, ingrese unas de las opciones dadas: ", 0, 1);
				printf("\nOrdenando. . .\n");
				retorno = ll_sort(cloneList, employee_CompareSalary, order);
				controller_ListEmployee(cloneList);
				break;
		}
    }while(opcion != 5);

    return retorno;
}
