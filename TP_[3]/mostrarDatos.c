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

/// @fn void mostrarMenu()
/// @brief Muestra el menu.

void mostrarMenu()
{
	printf("\n------------------------------ Menu de Opciones ------------------------------\n");
    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir.\n");
    printf("\n------------------------------------------------------------------------------\n");
}

/// @fn void mostrarOpciones()
/// @brief Muesta lista de empleados o si desea regresar.

void mostrarOpciones()
{
	printf("\n----------- Opciones -----------\n");
	printf("\n1. Ver la lista de empleados.\n");
	printf("2. Regresar.\n");
	printf("\n--------------------------------\n");
}

/// @fn void mostrarMenuDeModificacion()
/// @brief Muesta las opciones de modificacion.

void mostrarMenuDeModificacion()
{
	printf("\n----------- Opciones -----------\n");
    printf("\n1. Modificar Nombre.\n");
    printf("2. Modificar Horas de Trabajo.\n");
    printf("3. Modificar Sueldo.\n");
    printf("4. Regresar.\n");
    printf("\n--------------------------------\n");
}

/// @fn void mostrarMenuEliminado()
/// @brief Muestra si desea eliminar al empleado o no.

void mostrarMenuEliminado()
{
	printf("\n----------- Menu de Eliminacion -----------\n");
	printf("\n¿Seguro que quiere eliminarlo/a?\n");
	printf("1. Eliminar.\n");
	printf("2. Cancelar.\n");
	printf("\n-------------------------------------------\n");
}

/// @fn void mostrarMenuDeOrdenamiento()
/// @brief Muestra opciones de ordenamiento.

void mostrarMenuDeOrdenamiento()
{
	printf("\n----------- Menu de Ordenamiento -----------\n");
	printf("\n1. Ordenar los empleados por Id.\n");
	printf("2. Ordenar los empleados por Nombre.\n");
	printf("3. Salir.\n");
	printf("\n--------------------------------------------\n");
}
