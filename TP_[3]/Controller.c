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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if (pFile != NULL)
        {
			retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
		}
        fclose(pFile);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
        	retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        }
        fclose(pFile);
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{
    Employee* pEmployee = employee_new();
    int retorno = -1;
    char nombre[51];
    int horasTrabajadas = 0;
    int salario = 0;

    printf("\n--------------------------------------");
    getOnlyString(nombre, "\nIngrese su nombre: ", "\nError, reingrese su nombre: ");
    printf("--------------------------------------");
    horasTrabajadas = getInt(horasTrabajadas, "\nIngrese horas: ", "\nError, reingrese la hora: ", 0, 500);
    printf("--------------------------------------");
    salario = getInt(salario, "\nIngrese su salario: ", "\nError, reingrese su salario: ", 0, 1000000);
    printf("--------------------------------------");

    employee_setId(pEmployee, id);
    employee_setNombre(pEmployee, nombre);
    employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
    employee_setSueldo(pEmployee, salario);

    if(pEmployee != NULL)
    {
    	retorno = ll_add(pArrayListEmployee, pEmployee);
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int opcion;

    do
    {
    	mostrarOpciones();
    	opcion = getInt(opcion, "\nIngrese la opcion que desee: ", "\nError, ingrese una de las opciones dadas: ", 1, 2);

		if (opcion == 1)
		{
			retorno = controller_ListEmployee(pArrayListEmployee);
			retorno = modificarEmpleado(pArrayListEmployee);

			if (retorno == -1 || retorno == 0)
			{
				break;
			}
		}
     }while(opcion != 2);

     return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int opcion = 0;
	int retorno = -1;

	do
	{
		mostrarOpciones();
		opcion = getInt(opcion, "\nIngrese la opcion que desee: ", "\nError, ingrese una de las opciones dadas: ", 1, 2);

		if(opcion == 1)
		{
			retorno = controller_ListEmployee(pArrayListEmployee);
			retorno = eliminarEmpleado(pArrayListEmployee);
			break;
		}
	}while(opcion != 2);


    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len;

    printf("\n-----------------------------------------------------------------");
    printf("\nId\t\tNombre\t\tHoras trabajadas\tSueldo\n");
    len = ll_len(pArrayListEmployee);

    for(int i = 0; i < len; i++)
    {
    	listaDeEmpleados(pArrayListEmployee, i);
    }

    printf("\nId\t\tNombre\t\tHoras trabajadas\tSueldo\n");
    printf("-----------------------------------------------------------------");

    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    LinkedList* cloneList;

    cloneList = ll_clone(pArrayListEmployee);

    retorno = ordenarEmpleados(cloneList);

    ll_deleteLinkedList(cloneList);

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen (path, "w");
            if(pFile != NULL)
            {
            	retorno = parser_SaveDataEmployeeFromText(pFile, pArrayListEmployee);
            }
        fclose(pFile);
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen (path, "wb");
            if(pFile != NULL)
            {
                retorno = parser_SaveDataEmployeeBinary(pFile, pArrayListEmployee);
            }
        fclose(pFile);
    }
    return retorno;
}
