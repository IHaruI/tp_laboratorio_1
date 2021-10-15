/*
 ============================================================================
 Name        : TP_[2]
 Author      : Galimany Patricio 1F
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "employeeLibrary.h"
#define TAM 1000


int main(void) {
	setbuf(stdout, NULL);

	    eEmpleados lista[TAM];
	    int id = 1;  //ID para el primer empleado cargado.
	    char salir = 'n';  //Salir del programa.

	    initEmployees(lista, TAM);

	    do
	    {
	        switch(menu())
	        {
	            case 1:
	            	if(altaEmpleado(lista, TAM, id))
	            	{
	            		id++;
	            	}
	            	break;

	            case 2:
	            	bajaEmpleado(lista,TAM);
	                break;

	            case 3:
	                modificarEmpleado(lista,TAM);
	                break;

	            case 4:
	                informar(lista,TAM);
	                break;

	            case 5:
	                printf("\n¿Esta seguro que desea salir? (S/N): ");
	                fflush(stdin);
	                salir = getchar();
	                break;

	            default:
	                printf("Error. Opcion invalida\n");
	                fflush(stdin);

	        }
	    }while(salir == 'n');
	return EXIT_SUCCESS;
}
