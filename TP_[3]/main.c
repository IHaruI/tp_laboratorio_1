/*
 ============================================================================
 Name        : TP_[3]
 Author      : Galimany Patricio 1F.
 Version     :
 Copyright   :
 Description : Nomina de Empleados.
 ============================================================================
 */

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

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
	int option;                         //Opcion elegida del menu.
	int verificar = 0;					//Da paso a las opciones sabiendo si se cargo los datos.
	int id = 1000;						//Inicializacion de os empleados.
	int loaded = 0;						//Verifica que archivos de cargaron.
	int retorno = 0;

    LinkedList* listaEmpleados = NULL;  //Lista de empleados.

    listaEmpleados = ll_newLinkedList();

    do{
    	mostrarMenu();
    	option = getInt(option, "\nIngrese una de las opciones: ", "\nError, Ingrese una de las opciones dadas: ", 0, 10);
		verificar = controlarOpcion(listaEmpleados);

        switch(option)
        {
            case 1:
            	if (loaded == 0)
            	{
            		id = controller_loadFromText("data.csv", listaEmpleados);
            		printf("\n_______________________________________\n");
            		verificarRetorno("\nSe ha cargado correctamente.\n", "\nError en la carga.\n", retorno);
            		printf("_______________________________________\n");
            		loaded = 1;
            	}
                else
                {
                	printf("\n_______________________________________\n");
                    printf("\nYa se ha cargado un archivo.\n");
                    printf("_______________________________________\n");
                }
                break;

            case 2:
                if(loaded == 0)
                {
                    id = controller_loadFromBinary("data.bin", listaEmpleados);
                    printf("\n_______________________________________\n");
                    verificarRetorno("\nSe ha cargado correctamente.\n", "\nError en la carga.\n", retorno);
                    printf("_______________________________________\n");
                    loaded = 1;
                }
                else
                {
                	printf("\n_______________________________________\n");
                	printf("\nYa se ha cargado un archivo.\n");
                	printf("_______________________________________\n");
                }
            	break;

            case 3:
                if(verificar == 0)
                {
                    id = createId(id);
                    retorno = controller_addEmployee(listaEmpleados, id);
                    printf("\n\n_______________________________________\n");
                    verificarRetorno("\nSe ha completado el alta correctamente.\n", "\nError en la carga.\n", retorno);
                    printf("_______________________________________\n");
                }
                else
                {
                	printf("\n______________________________________________________________\n");
                    printf("\nError, cargar primero archivos para ingresar a esta opcion.\n");
                    printf("______________________________________________________________\n");
                }
            	break;

            case 4:
                if(verificar == 0)
                {
                	retorno = controller_editEmployee(listaEmpleados);
                	printf("\n_______________________________________\n");
                	verificarRetorno("\nSe ha editado correctamente.\n", "\nError en la edicion.\n", retorno);
                	printf("_______________________________________\n");
                }
                else
                {
                	printf("\n______________________________________________________________\n");
                	printf("\nError, cargar primero archivos para ingresar a esta opcion.\n");
                	printf("______________________________________________________________\n");
                }
            	break;

            case 5:
            	if(verificar == 0)
            	{
            		retorno = controller_removeEmployee(listaEmpleados);
            		printf("\n_______________________________________\n");
            		verificarRetorno("\nSe ha eliminado con exito.\n", "\nError en la eliminacion.\n", retorno);
            		printf("_______________________________________\n");
            	}
            	else
            	{
            		printf("\n______________________________________________________________\n");
            		printf("\nError, cargar primero archivos para ingresar a esta opcion.\n");
            		printf("______________________________________________________________\n");
            	}
            	break;

            case 6:
            	if(verificar == 0)
            	{
            		retorno = controller_ListEmployee(listaEmpleados);
            		printf("\n_______________________________________\n");
            		verificarRetorno("\nSe ha mostrado la lista correctamente.\n", "\nError mostrar la lista.\n", retorno);
            		printf("_______________________________________\n");
            	}
            	else
            	{
            		printf("\n______________________________________________________________\n");
            		printf("\nError, cargar primero archivos para ingresar a esta opcion.\n");
            		printf("______________________________________________________________\n");
            	}
            	break;

            case 7:
            	if(verificar == 0)
            	{
            		retorno = controller_sortEmployee(listaEmpleados);
            		printf("\n_______________________________________\n");
            		verificarRetorno("\nSe ha mostrado la lista correctamente.\n", "\nError en ordenar la lista.\n", retorno);
            		printf("_______________________________________\n");
            	}
            	else
            	{
            		printf("\n______________________________________________________________\n");
            		printf("\nError, cargar primero archivos para ingresar a esta opcion.\n");
            		printf("______________________________________________________________\n");
            	}
            	break;

            case 8:
            	if(verificar == 0)
            	{
            		retorno = controller_saveAsText("data.csv", listaEmpleados);
            		printf("\n_______________________________________\n");
            		verificarRetorno("\nSe ha guardado la lista correctamente.\n", "\nError en el guardado de la lista.\n", retorno);
            		printf("_______________________________________\n");
            	}
            	else
            	{
            		printf("\n______________________________________________________________\n");
            		printf("\nError, cargar primero archivos para ingresar a esta opcion.\n");
            		printf("______________________________________________________________\n");
            	}
            	break;

            case 9:
            	if(verificar == 0)
            	{
            		retorno = controller_saveAsBinary("data.bin", listaEmpleados);
            		printf("\n_______________________________________\n");
            		verificarRetorno("\nSe ha guardado la lista correctamente.\n", "\nError en el guardado de la lista.\n", retorno);
            		printf("_______________________________________\n");
            	}
            	else
            	{
            		printf("\n______________________________________________________________\n");
            		printf("\nError, cargar primero archivos para ingresar a esta opcion.\n");
            		printf("______________________________________________________________\n");
            	}
            	break;

            default:
            	printf("\n_______________________________________\n");
                printf("\nError. Opcion invalida.\n");
                printf("_______________________________________\n");
                fflush(stdin);
        }
    }while(option != 10);
    return 0;
}
