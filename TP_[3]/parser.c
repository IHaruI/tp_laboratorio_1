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

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int El id del ultimo empleado.
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    char id[51];
    char nombre[51];
    char horasTrabajadas[51];
    char salario[51];
    int idAuxiliar;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, salario);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, salario);
        pEmployee = employee_newParametros(id, nombre, horasTrabajadas, salario);
        ll_add(pArrayListEmployee, pEmployee);
        employee_getId(pEmployee, &idAuxiliar);
    }
    return idAuxiliar;
}

/** \brief Parsea los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int El id del ultimo empleado.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int i = 0;
    int idAuxiliar;

    while(!feof(pFile))
    {
        pEmployee = employee_new();

            if(fread(pEmployee, sizeof(Employee), 1, pFile) == 1)
            {
                ll_add(pArrayListEmployee, pEmployee);
            }

        pEmployee = ll_get(pArrayListEmployee, i);
        employee_getId(pEmployee, &idAuxiliar);
        i++;
    }
    return idAuxiliar;
}

/// @fn int parser_SaveDataEmployeeFromText(FILE*, LinkedList*)
/// @brief Escribe los datos en modo texto en el archivo data.csv.
/// @param pFile FILE*
/// @param pArrayListEmployee LinkedList*
/// @return 0 si esta ok.

int parser_SaveDataEmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;
    int len;
    int i;
    int retorno = 1;

    len = ll_len(pArrayListEmployee);

    fprintf(pFile, "id, nombre, horasTrabajadas, sueldo\n");

    for(i = 0; i < len; i++)
    {
        pEmployee = ll_get(pArrayListEmployee, i);
        employee_getId(pEmployee, &id);
        employee_getNombre(pEmployee, nombre);
        employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
        employee_getSueldo(pEmployee, &sueldo);
        fprintf(pFile, "%d, %s, %d, %d\n",id, nombre, horasTrabajadas, sueldo);
        retorno = 0;
    }
    return retorno;
}

/// @fn int parser_SaveDataEmployeeBinary(FILE*, LinkedList*)
/// @brief Escribe los datos en modo binario en el archivo data.bin.
/// @param pFile FILE*
/// @param pArrayListEmployee LinkedList*
/// @return 0 si esta ok.

int parser_SaveDataEmployeeBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int retorno = 1;
	int len;

	len = ll_len(pArrayListEmployee);

	for(int i = 0; i < len; i++)
	{
		pEmployee = ll_get(pArrayListEmployee, i);
		fwrite(pEmployee, sizeof(Employee), 1, pFile);
		retorno = 0;
	}
	return retorno;
}
