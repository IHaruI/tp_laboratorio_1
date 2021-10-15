#include "employeeLibrary.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/// @fn void initEmployees(eEmpleados[], int)
/// @brief Indica que las posiciones estan vacias (pone en verdadero todas las posiciones).
/// @param empleados Lista de empleados * Puntero a la matriz de empleados
/// @param tam Cantidad maxima de empleados.

void initEmployees(eEmpleados empleados[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        empleados[i].isEmpty = 1;
    }
}

/// @fn int menu()
/// @brief Muestra el menu principal de opciones.
/// @return La opcion tomada.

int menu()
{
    int opcion;
    system("cls");
    printf("\n----- Menu de Opciones -----\n");
    printf("1. Alta de empleado.\n");
    printf("2. Baja de empleado.\n");
    printf("3. Modificar de empleado.\n");
    printf("4. Informar\n");
    printf("5. Salir.\n\n");
    printf("Ingrese unas de las opciones: ");
    scanf("%d", &opcion);

    return opcion;
}

/// @fn int altaEmpleado(eEmpleados[], int, int)
/// @brief Se pide los datos del nuevo empleado, se guarda en una validacion temporal y si la validacion esta todo ok lo guardo en la lista de empleado.
/// @param empleado Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.
/// @param id Se asigna a cada empleado registrado.
/// @return	Retorna todo Ok.

int altaEmpleado(eEmpleados empleado[],int tam, int id)
{
    int retorno;
    int indice;
    char name[51];
    char lastname[51];
    float salary;
    int sector;

    retorno = 0;

    system("cls");
    printf("\n----- Alta de Empleados -----\n\n");

    indice = buscarIndiceLibre(empleado, tam);

    if(indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas Empleados\n");
    }
    else
    {
    	printf("Ingrese su nombre: ");
    	fflush(stdin);
    	gets(name);

    	printf("Ingrese su apellido: ");
    	fflush(stdin);
    	gets(lastname);

        printf("Ingrese su salario: ");
        scanf("%f", &salary);

        printf("Ingrese su sector: ");
        scanf("%d", &sector);

        empleado[indice] = addEmployees(id, name, lastname, salary, sector);
        retorno = 1;
    }
    return retorno;
}

/// @fn int buscarIndiceLibre(eEmpleados[], int)
/// @brief Se busca un indice vacio.
/// @param empleados Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.
/// @return Indice.

int buscarIndiceLibre(eEmpleados empleados[], int tam)
{
    int indice;

    indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(empleados[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/// @fn eEmpleados addEmployees(int, char[], char[], float, int)
/// @brief Agregar en una lista existente de empleados los valores recibidos como parámetros en la primera posición vacía.
/// @param id Se asigna a cada empleado registrado.
/// @param name Nombre del empleado.
/// @param lastname Apellido del empleado.
/// @param salary Salario del empleado.
/// @param sector Sector del empleado.
/// @return Nuevo empleado.

eEmpleados addEmployees(int id, char name[], char lastname[], float salary, int sector)
{
    eEmpleados nuevoEmpleado;
    nuevoEmpleado.id = id;
    strcpy(nuevoEmpleado.name, name);
    strcpy(nuevoEmpleado.lastName, lastname);
    nuevoEmpleado.salary = salary;
    nuevoEmpleado.sector = sector;
    nuevoEmpleado.isEmpty = 0;

    return nuevoEmpleado;
}

/// @fn int bajaEmpleado(eEmpleados[], int)
/// @brief Baja de empleado por id.
/// @param empleado Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.
/// @return todo Ok.

int bajaEmpleado(eEmpleados empleado[], int tam)
{
    int retorno;
    int indice;
    int id;
    char confirmar;

    retorno = 0;

    if(buscarEmpleado(empleado,tam))
    {
        system("cls");
        printf("\n----- Baja de Empleados -----\n\n");

        printf("Ingrese ID del empleado: ");
        scanf("%d", &id);

        indice = findEmployeeById(id, empleado, tam);

        if(indice == -1 )
        {
            printf("\nNo tenemos registrado ese ID\n");
        }
        else
        {
            printf("\n ID        1-Nombre      2-Apellido    3-Salario     4-Sector \n\n");

            mostrarEmpleado(empleado[indice]);

            printf("\n¿Seguro que quiere eliminarlo/a? (S/N): ");
            fflush(stdin);
            scanf("%c", &confirmar);

            if(confirmar == 's')
            {
                empleado[indice].isEmpty = 1;
                printf("\n\nSe ha eliminado al empleado/a con exito.\n");
                retorno = 1;
            }
            else
            {
                printf("\n\nSe ha cancelado la baja\n");
            }
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("No hay ningun empleado cargado...\n");
        printf("Ingrese un empleado.\n");
        system("pause");
    }
    return retorno;
}

/// @fn int buscarEmpleado(eEmpleados[], int)
/// @brief Recorre empleado[] si este tiene datos.
/// @param empleado Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.
/// @return Retorna 1 si hay datos cargados y 0 si esta vacio.

int buscarEmpleado(eEmpleados empleado[], int tam)
{
    int retorno = 0;

    for(int i = 0 ; i < tam ; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
        	retorno = 1;
        }
    }
    return retorno;
}

/// @fn int findEmployeeById(int, eEmpleados[], int)
/// @brief Busca empleado por id.
/// @param id Puesto por el usuario.
/// @param empleado Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.
/// @return indice (empleado).

int findEmployeeById(int id, eEmpleados empleado[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(empleado[i].isEmpty == 0 && empleado[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/// @fn void mostrarEmpleado(eEmpleados)
/// @brief Se muestra los datos del empleado.
/// @param xPersona

void mostrarEmpleado(eEmpleados xPersona)
{
    printf(" %2d      %10s     %10s      %6.2f        %2d \n\n",
    		xPersona.id,
			xPersona.name,
			xPersona.lastName,
			xPersona.salary,
			xPersona.sector
          );
}

/// @fn int modificarEmpleado(eEmpleados[], int)
/// @brief Modifica empleado por id.
/// @param empleado Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.
/// @return Todo Ok.

int modificarEmpleado(eEmpleados empleado[], int tam)
{
    int retorno;
    int indice;
    char salir;
    char name[51];
    char lastName[51];
    float salario;
    int Sector;

    retorno = 0;
    salir = 'n';

    if(buscarEmpleado(empleado,tam))
    {

        system("cls");
        printf("----- Modificacion de Empleado -----\n\n");

        printf("Ingrese ID del empleado: ");
        scanf("%d", &indice);

        indice = findEmployeeById(indice,empleado,tam);

        if( indice == -1 )
        {
            printf("\nNo hay registro de ese ID.\n");
        }
        else
        {
            printf("\n ID        1,Nombre      2-Apellido    3-Salario     4-Sector \n\n");

            mostrarEmpleado(empleado[indice]);

            do
            {
                switch(modificarDatos())
                {
                	case 1:
                		printf("Ingrese nuevo nombre: ");
                		fflush(stdin);
                		fgets(name, 51, stdin);
                		cambio(name);
                		strcpy(empleado[indice].name, name);
                		printf("\nNombre actualizado.\n");
                		retorno = 1;
                		salir = getchar();
                		break;

                	case 2:
                		printf("Ingrese nuevo apellido: ");
                		fflush(stdin);
                		fgets(lastName, 51, stdin);
                		cambio(lastName);
                		strcpy(empleado[indice].lastName, lastName);
                		printf("\nApellido actualizado.\n");
                		retorno = 1;
                		salir = getchar();
                		break;

                	case 3:
                		printf("Ingrese nuevo salario: ");
                    	scanf("%f", &salario);
                    	empleado[indice].salary = salario;
                    	printf("\nSalario del empleado actualizado.\n");
                    	retorno = 1;
                    	salir = getchar();
                    	break;

                	case 4:
                		printf("Ingrese nuevo sector: ");
                		scanf("%d", &Sector);
                		empleado[indice].sector = Sector;
                		printf("\nSector del empleado actualizado.\n");
                		retorno = 1;
                		salir = getchar();
                		break;

                	case 5:
                		salir = getchar();
                		break;

                	default:
                		printf("Error. Opcion invalida\n");
                }
            }
            while(salir == 'n');
        }
    }
    else
    {
        system("cls");
        printf("No se ha encontrado ningun empleado cargado . . .\n");
        printf("Por favor, ingrese un empleado.\n");
        system("pause");
    }
    return retorno;
}

/// @fn int modificarDatos()
/// @brief Modifica datos del empleado.
/// @return opcion elegida.

int modificarDatos()
{
    int opcion;
    printf("\n----- ¿Que desea Modificar ? -----\n\n");
    printf("1. Nombre.\n");
    printf("2. Apellido.\n");
    printf("3. Salario.\n");
    printf("4. Sector.\n");
    printf("5. Salir.\n\n");
    printf("Ingrese unas de las opciones: ");
    scanf("%d", &opcion);
    return opcion;
}

/// @fn void cambio(char[])
/// @brief Cambia el \n del fgets a \0.
/// @param palabra

void cambio(char palabra[51])
{
	for(int i = 0; i < 51; i++)
	{
		if(palabra[i] == '\n')
		{
			palabra[i] = '\0';
		}
	}
}

/// @fn void informar(eEmpleados[], int)
/// @brief Lamadas a opciones.
/// @param empleados Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.

void informar(eEmpleados empleados[], int tam)
{
    char salir;

    salir = 'n';

    if(buscarEmpleado(empleados,tam))
    {
        system("cls");
        printf("\n----- Informes -----\n\n");
        do
        {
            switch(menuInformes())
            {
            	case 1:
            		printEmployees(empleados,tam);
            		break;

            	case 2:
            		sortEmployees(empleados,tam);
            		break;

            	case 3:
            		totalPromedio(empleados,tam);
            		break;

            	case 4:
            		empleadosSalarioPromedio(empleados,tam);
            		break;

            	case 5:
            		salir = getchar();
            		break;

            	default:
            		printf("\nError. Opcion invalida\n");
            }
        }
        while(salir == 'n');
    }
    else
    {
        system("cls");
        printf("No hay ningun empleado cargado . . .\n");
        printf("Por favor, ingrese un empleado.\n");
        system("pause");
    }
}

/// @fn int menuInformes()
/// @brief Menu de informes.
/// @return opcion elegida.

int menuInformes()
{
    int opcion;

    printf("-------------------------------------------------------------------\n");
    printf("1. Listado de empleados.\n");
    printf("2. Listado de los empleados ordeandos alfabéticamente por Apellido y Sector.\n");
    printf("3. Total y promedio de los salarios.\n");
    printf("4. Cuantos empleados superan el salario promedio.\n");
    printf("5. Salir.\n\n");
    printf("Ingrese unas de las opciones: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

/// @fn void printEmployees(eEmpleados[], int)
/// @brief Se muestra todos los empleados cargados.
/// @param empleado Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.

void printEmployees(eEmpleados empleado[], int tam)
{
    int bandera;

    bandera = 0;

    system("cls");
    printf("\n------- Lista de Empleados -------\n\n");

    printf(" ID          Nombre       Apellido       Salario       Sector \n\n");

    for(int i = 0; i < tam; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
            mostrarEmpleado(empleado[i]);
            bandera = 1;
        }
    }

    if(bandera == 0)
    {
    	system("cls");
        printf("\n-----No hay empleados que mostrar-----");
    }
    printf("\n\n");
}

/// @fn void sortEmployees(eEmpleados[], int)
/// @brief Ordena una lista de empleados cargados por Apellido y Sector.
/// @param empleados Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.

void sortEmployees(eEmpleados empleado[], int tam)
{
    eEmpleados auxEmpleado;

    system("cls");

    for(int i = 0; i < tam-1 ; i++)
    {
        for(int j = i + 1 ; j < tam ; j++)
        {
            if((empleado[i].isEmpty == 0) && (strcmp(empleado[i].lastName, empleado[j].lastName) == 1))
            {
                auxEmpleado = empleado[i];
                empleado[i] = empleado[j];
                empleado[j] = auxEmpleado;
            }
        }
    }
    printEmployees(empleado,tam);
}

/// @fn void totalPromedio(eEmpleados[], int)
/// @brief Promedio y total de los salarios de los empleados.
/// @param empleados Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.

void totalPromedio(eEmpleados empleados[],int tam)
{
    int contador;
    float total;
    float promedio;

    contador = 0;
    total = 0;
    promedio = 0;

    for(int i = 0 ; i < tam ; i++)
    {
        if(empleados[i].isEmpty == 0)
        {
        	contador++;
            total = total + empleados[i].salary;
        }
    }
    promedio = total / contador;

    system("cls");
    printf("\n---- Total y Promedio de Salarios ----\n");
    printf("\nLa suma total de los salarios es : %.2f ",total);
    printf("\nEl promedio es : %.2f ",promedio);
    printf("\n");
}

/// @fn void empleadosSalarioPromedio(eEmpleados[], int)
/// @brief Busca quien supero el promedio promedio.
/// @param empleados Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.

void empleadosSalarioPromedio(eEmpleados empleados[],int tam)
{
    int contador;
    float total;
    float promedio;
    int promedioSuperado;

    contador = 0;
    total = 0;
    promedio = 0;
    promedioSuperado = 0;

    for(int i = 0 ; i < tam ; i++)
    {
        if(empleados[i].isEmpty == 0)
        {
        	contador++;
            total = total + empleados[i].salary;
        }
    }
    promedio = total / contador;

    system("cls");
    printf("---- Empleados que superan el salario promedio ----\n");
    printf("\nEl promedio de los salarios es : %.2f ",promedio);
    printf("\nEmpleados :\n\n");

    for(int i = 0; i < tam ; i++)
    {
        if(empleados[i].isEmpty == 0 && empleados[i].salary > promedio)
        {
        	promedioSuperado++;
            mostrarEmpleado(empleados[i]);
        }
    }
    printf("Los empleados que lo superan son : %d",promedioSuperado);
    printf("\n");
}
