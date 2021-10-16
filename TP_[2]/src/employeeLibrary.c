#include "employeeLibrary.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

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
    printf("\n----- Menu de Opciones -----\n\n");
    printf("1. Alta de empleado.\n");
    printf("2. Baja de empleado.\n");
    printf("3. Modificar de empleado.\n");
    printf("4. Informar.\n");
    printf("5. Salir.\n\n");
    printf("Ingrese unas de las opciones: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

/// @fn int altaEmpleado(eEmpleados[], int, int)
/// @brief Se pide los datos del nuevo empleado, se guarda en una validacion temporal y si la validacion esta correctamente se guarda en la lista de empleado.
/// @param empleado Es el array de la estructura eEmpledos.
/// @param tam Cantidad maxima de empleados.
/// @param id Se asigna a cada empleado registrado.
/// @return	Retorna un 1 si se completo el alta con exito.

int altaEmpleado(eEmpleados empleado[],int tam, int id)
{
    int retorno;
    int indice;
    char name[51];
    char lastname[51];
    char ingresarSalario[51];
    float salary;
    char ingresarSector[51];
    int sector;
    int validarCadena;
    int validarNumeroFlotante;
    int validarNumeroEntero;

    retorno = 0;

    printf("\n----- Alta de Empleados -----\n\n");

    indice = buscarIndiceLibre(empleado, tam);

    if(indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas empleados.\n");
    }
    else
    {
    	printf("Ingrese su nombre: ");
    	fflush(stdin);
    	fgets(name, 51, stdin);
    	cambio(name);
    	validarCadena = ValidarCadena(name);

    	while(validarCadena == 1)
    	{
    		printf("Error. Ingrese solo cadena de caracteres.\n\n");
    		printf("Ingrese su nombre: ");
			fflush(stdin);
	    	fgets(name, 51, stdin);
	    	cambio(name);
			validarCadena = ValidarCadena(name);
    	}

    	printf("Ingrese su apellido: ");
    	fflush(stdin);
    	fgets(lastname, 51, stdin);
    	cambio(lastname);
    	validarCadena = ValidarCadena(lastname);

    	while(validarCadena == 1)
    	{
    		printf("Error. Ingrese solo cadena de caracteres.\n\n");
        	printf("Ingrese su apellido: ");
        	fflush(stdin);
        	fgets(lastname, 51, stdin);
        	cambio(lastname);
        	validarCadena = ValidarCadena(lastname);
    	}

        printf("Ingrese su salario: ");
    	fflush(stdin);
    	fgets(ingresarSalario, 51, stdin);
    	cambio(ingresarSalario);
    	validarNumeroFlotante = ValidarNumeroFlotante(ingresarSalario);

    	while(validarNumeroFlotante == 1)
    	{
    		printf("Error. Ingrese solo numeros flotantes.\n\n");
            printf("Ingrese su salario: ");
        	fflush(stdin);
        	fgets(ingresarSalario, 51, stdin);
        	cambio(ingresarSalario);
        	validarNumeroFlotante = ValidarNumeroFlotante(ingresarSalario);
    	}

    	salary = atof(ingresarSalario);    // Transforma la cadena de caracteres a un valor flotante.

        printf("Ingrese su sector: ");
    	fflush(stdin);
    	fgets(ingresarSector, 51, stdin);
    	cambio(ingresarSector);
    	validarNumeroEntero = ValidarNumeroEntero(ingresarSector);

    	while(validarNumeroEntero == 1)
    	{
    		printf("Error. Ingrese solo numeros enteros.\n\n");
            printf("Ingrese su sector: ");
        	fflush(stdin);
        	fgets(ingresarSector, 51, stdin);
        	cambio(ingresarSector);
        	validarNumeroEntero = ValidarNumeroEntero(ingresarSector);
    	}

    	sector = atoi(ingresarSector);    // Transforma la cadena de caracteres a un valor entero.

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

/// @fn void cambio(char[])
/// @brief Cambia el \n del fgets a \0.
/// @param palabra Recibe una cadena de caracteres.

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

/// @fn int ValidarCadena(char[])
/// @brief Verifica si se ingreso algun numero en el string.
/// @param cadena Recibe una cadena de caracteres.
/// @return Un 0 si no se ingreso ningun numero, de lo contrario retorna 1.

int ValidarCadena(char cadena[])
{
	int i;
	int j;
	int validarCadena;

	i = 0;
	validarCadena = 0;

	j = strlen(cadena);

	while(i < j && validarCadena == 0)
	{
		if(isalpha(cadena[i]) != 0) // isalpha = Regresa un valor diferente de 0, si el caracter que lleva como por parametro
		{							//			 se encuentra entre los rangos del codgo ASCII (65 a 90 y 97 a 122).
			i++;
		}
		else
		{
			validarCadena = 1;
		}
	}
	return validarCadena;
}

/// @fn int ValidarNumeroFlotante(char[])
/// @brief Verifica si se ingreso algun caracter en el pedido de un flotante.
/// @param numeroFlotante Recibe el numero flotante en cadena de caracteres.
/// @return Un 0 si no se ingreso ningun numero, de lo contrario retorna 1.

int ValidarNumeroFlotante(char numeroFlotante[])
{
	int i;
	int j;
	int validarCadena;

	i = 0;
	validarCadena = 0;

	j = strlen(numeroFlotante);

	while(i < j && validarCadena == 0)
	{
		if(isdigit(numeroFlotante[i]) != 0 || numeroFlotante[i] == '.')
		{
			i++;
		}
		else
		{
			validarCadena = 1;
		}
	}
	return validarCadena;
}

/// @fn int ValidarNumeroEntero(char[])
/// @brief Verifica si se ingreso algun caracter en el pedido de un entero.
/// @param numeroEntero Recibe el numero entero en cadena de caracteres.
/// @return Un 0 si no se ingreso ningun numero, de lo contrario retorna 1.

int ValidarNumeroEntero(char numeroEntero[])
{
	int i;
	int j;
	int validarCadena;

	i = 0;
	validarCadena = 0;

	j = strlen(numeroEntero);

	while(i < j && validarCadena == 0)
	{
		if(isdigit(numeroEntero[i]) != 0)  // isdigit = Regresa un valor diferente de 0, si el caracter que lleva como por parametro es un numero.
		{								   // 			Entre el rango de (48 a 57) del codigo ASCII.
			i++;
		}
		else
		{
			validarCadena = 1;
		}
	}
	return validarCadena;
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
/// @return Retorna un 1 si se completo la baja con exito.

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
        fflush(stdin);
        scanf("%d", &id);

        indice = findEmployeeById(id, empleado, tam);

        if(indice == -1 )
        {
            printf("\nNo tenemos registrado ese ID.\n");
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
                printf("\n\nSe ha cancelado la baja.\n");
            }
            system("pause");
        }
    }
    else
    {
        printf("No hay ningun empleado cargado. . .\n");
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
    printf(" %2d      %10s     %10s      %6.2f        %2d \n",
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
/// @return Retorna un 1 si se completo la modificacion con exito.

int modificarEmpleado(eEmpleados empleado[], int tam)
{
    int retorno;
    int indice;
    char salir;
    char name[51];
    char lastName[51];
    char ingresarSalario[51];
    float salario;
    char ingresarSector[51];
    int Sector;
    int validarCadena;
    int validarNumeroFlotante;
    int validarNumeroEntero;

    retorno = 0;
    salir = 'n';

    if(buscarEmpleado(empleado,tam))
    {
        printf("\n----- Modificacion de Empleado -----\n\n");

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
                		validarCadena = ValidarCadena(name);

                    	while(validarCadena == 1)
                    	{
                    		printf("Error. Ingrese solo cadena de caracteres.\n\n");
                    		printf("Ingrese su nombre: ");
                			fflush(stdin);
                	    	fgets(name, 51, stdin);
                	    	cambio(name);
                			validarCadena = ValidarCadena(name);
                    	}

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
                		validarCadena = ValidarCadena(lastName);

                    	while(validarCadena == 1)
                    	{
                    		printf("Error. Ingrese solo cadena de caracteres.\n\n");
                        	printf("Ingrese su apellido: ");
                        	fflush(stdin);
                        	fgets(lastName, 51, stdin);
                        	cambio(lastName);
                        	validarCadena = ValidarCadena(lastName);
                    	}

                		strcpy(empleado[indice].lastName, lastName);
                		printf("\nApellido actualizado.\n");
                		retorno = 1;
                		salir = getchar();
                		break;

                	case 3:
                		printf("Ingrese nuevo salario: ");
                		fflush(stdin);
                		fgets(ingresarSalario, 51, stdin);
                		cambio(ingresarSalario);
                		validarNumeroFlotante = ValidarNumeroFlotante(ingresarSalario);

                		while (validarNumeroFlotante == 1)
                		{
							printf("Error. Ingrese solo numeros flotantes.\n\n");
							printf("Ingrese su salario: ");
							fflush(stdin);
							fgets(ingresarSalario, 51, stdin);
							cambio(ingresarSalario);
							validarNumeroFlotante = ValidarNumeroFlotante(ingresarSalario);
                		}

                		salario = atof(ingresarSalario);
                    	empleado[indice].salary = salario;
                    	printf("\nSalario del empleado actualizado.\n");
                    	retorno = 1;
                    	salir = getchar();
                    	break;

                	case 4:
                		printf("Ingrese nuevo sector: ");
                		fflush(stdin);
                		fgets(ingresarSector, 51, stdin);
                		cambio(ingresarSector);
                		validarNumeroEntero = ValidarNumeroEntero(ingresarSector);

                		while (validarNumeroEntero == 1)
                		{
                			printf("Error. Ingrese solo numeros enteros.\n\n");
                			printf("Ingrese su sector: ");
                			fflush(stdin);
                			fgets(ingresarSector, 51, stdin);
                			cambio(ingresarSector);
                			validarNumeroEntero = ValidarNumeroEntero(ingresarSector);
                		}

                		Sector = atoi(ingresarSector);
                		empleado[indice].sector = Sector;
                		printf("\nSector del empleado actualizado.\n");
                		retorno = 1;
                		salir = getchar();
                		break;

                	case 5:
                		salir = getchar();
                		break;

                	default:
                		printf("Error. Opcion invalida.\n");
                }
            }
            while(salir == 'n');
        }
    }
    else
    {
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
    printf("\n----- ¿Que desea Modificar? -----\n\n");
    printf("1. Nombre.\n");
    printf("2. Apellido.\n");
    printf("3. Salario.\n");
    printf("4. Sector.\n");
    printf("5. Salir.\n\n");
    printf("Ingrese unas de las opciones: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
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
            		printf("\nError. Opcion invalida.\n");
            }
        }
        while(salir == 'n');
    }
    else
    {
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

    printf("\n---------------------------- Informes ----------------------------\n\n");
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

    printf("\n----------------------- Lista de Empleados -----------------------\n\n");

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
        printf("\n----- No hay empleados que mostrar -----");
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
    printf("\n------------------ Total y Promedio de Salarios ------------------\n");
    printf("\nLa suma total de los salarios es: %.2f ", total);
    printf("\nEl promedio es: %.2f\n ", promedio);
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

    printf("\n----------- Empleados que superan el salario promedio -----------\n");
    printf("\nEl promedio de los salarios es: %.2f ",promedio);
    printf("\nEmpleados :\n\n");

    for(int i = 0; i < tam ; i++)
    {
        if(empleados[i].isEmpty == 0 && empleados[i].salary > promedio)
        {
        	promedioSuperado++;
            mostrarEmpleado(empleados[i]);
        }
    }
    printf("Los empleados que lo superan son: %d\n",promedioSuperado);
}
