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

/// @fn int getInt(int, char[], char[], int, int)
/// @brief Verifica el entero ingresado.
/// @param numero int
/// @param mensaje char
/// @param mensajeError char
/// @param minimo int
/// @param maximo int
/// @return El entero verificado.

int getInt(int numero, char mensaje[], char mensajeError[], int minimo, int maximo)
{
    char cadena[51];
    int bandera = 0;

    printf("%s", mensaje);

	bandera = getIntAndRange(bandera, cadena, numero, minimo, maximo);
	numero = atoi(cadena);

    while(bandera == 0 || bandera == 1)
    {
    	printf("-------------------------------------------");
    	printf("%s", mensajeError);
    	bandera = getIntAndRange(bandera, cadena, numero, minimo, maximo);
    	numero = atoi(cadena);
    }
    numero = atoi(cadena);

    return numero;
}

/// @fn int getIntAndRange(int, char[], int, int, int)
/// @brief Valida un entero dentro del rango.
/// @param bandera int
/// @param cadena char
/// @param numero int
/// @param minimo int
/// @param maximo int
/// @return 2 si el numero esta dentro del rango, 1 si no esta dentro del rango.

int getIntAndRange(int bandera, char cadena[], int numero, int minimo, int maximo)
{
	int validarEntero = 0;
	int verificar;

    fflush(stdin);
    gets(cadena);

    verificar = verificarEnter(cadena);

    if(verificar == 0)
    {
		validarEntero = validarNumeroEntero(cadena);

		if(validarEntero == 1)
		{
			bandera = 1;
			numero = atoi(cadena);

			if(numero >= minimo && numero <= maximo)
			{
				bandera = 2;
			}
		}
    }
    else
    {
    	bandera = 1;
    }
    return bandera;
}

/// @fn int validarNumeroEntero(char[])
/// @brief Verifica si la cadena ingresada es un numero entero.
/// @param numero char
/// @return 1 si la cadena es entera, de lo contrario devolvera 0.

int validarNumeroEntero(char numero[])
{
	int retorno = 1;

	for(int i = 0; i < strlen(numero); i++)
	{
		if(!(numero[i] >= 48 && numero[i] <= 57))
		{
			retorno = 0;
		}
	}
	return retorno;
}

/// @fn void verificarRetorno(char*, char*, int)
/// @brief Muestra si lo realizado se ha hecho correctamente o no.
/// @param mensaje char*
/// @param mensajeError char*
/// @param retorno int

void verificarRetorno(char* mensaje, char* mensajeError, int retorno)
{
    if(retorno == 0)
    {
        printf("%s", mensaje);
    }
    else
    {
        printf("%s", mensajeError);
    }
}

/// @fn int createId(int)
/// @brief Recibe un ID inicializada y agregar un ID al nuevo empleado.
/// @param id int
/// @return Nuevo ID.

int createId(int id)
{
	id++;

	return id;
}

/// @fn void getOnlyString(char[], char[], char[])
/// @brief Valida que solo se haya ingresado letras.
/// @param nombre char
/// @param mensaje char
/// @param mensajeError char

void getOnlyString(char nombre[], char mensaje[], char mensajeError[])
{
    int validar = 0;
    int verificar;

    printf("%s", mensaje);
    fflush(stdin);
    gets(nombre);
    verificar = verificarEnter(nombre);

    if(verificar == 0)
    {
		validar = validateOnlyString(nombre);
    }

    while(validar == -1 || verificar == -1)
    {
    	printf("--------------------------------------");
    	printf("%s", mensajeError);
    	fflush(stdin);
    	gets(nombre);
    	verificar = verificarEnter(nombre);
    	validar = validateOnlyString(nombre);
    }
}

/// @fn float getFloat(float, char[], char[], float, float)
/// @brief Verifica el flotante ingresado.
/// @param numero float
/// @param mensaje char
/// @param mensajeError char
/// @param minimo float
/// @param maximo float
/// @return El flotante verificado.

float getFloat(float numero, char mensaje[], char mensajeError[], float minimo, float maximo)
{
    char cadena[51];
    int bandera = 0;

    printf("%s", mensaje);

    bandera = getFloatAndRange(bandera, cadena, numero, minimo, maximo);
    numero = atof(cadena);

    while(bandera == 0 || bandera == 1)
    {
    	printf("%s", mensajeError);
    	bandera = getFloatAndRange(bandera, cadena, numero, minimo, maximo);
    	numero = atof(cadena);
    }
    numero = atof(cadena);

    return numero;
}

/// @fn int getFloatAndRange(int, char[], float, float, float)
/// @brief Valida un flotante dentro del rango.
/// @param bandera int
/// @param cadena char
/// @param numero float
/// @param minimo float
/// @param maximo float
/// @return 2 si el numero esta dentro del rango, 1 si no esta dentro del rango.

int getFloatAndRange(int bandera, char cadena[], float numero, float minimo, float maximo)
{
	int validar = 0;
	int verificar;

    fflush(stdin);
    gets(cadena);

    verificar = verificarEnter(cadena);

    if(verificar == 0)
    {
    	validar = validarNumeroFlotante(cadena);

    	if(validar == 1)
		{
			bandera = 1;
			numero = atoi(cadena);

			if(numero >= minimo && numero <= maximo)
			{
				bandera = 2;
			}
		}
    }
    else
    {
    	bandera = 1;
    }
    return bandera;
}

/// @fn int validarNumeroFlotante(char[])
/// @brief Verifica si la cadena ingresada es un numero flotante.
/// @param numero char
/// @return 1 si la cadena es flotante, de lo contrario devolvera 0.

int validarNumeroFlotante(char numero[])
{
	int retorno = 1;

	for(int i = 0; i < strlen(numero); i++)
    {
		if(!(numero[i] >= 48 && numero[i] <= 57))
        {
			if(numero[i] != '.' || numero[i - 1] == '.')
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

/// @fn int verificarEnter(char[])
/// @brief Valida que no se haya ingresado Enter.
/// @param cadena char
/// @return 0 si esta ok.

int verificarEnter(char cadena[])
{
	int retorno = 0;
	int cantidad;

	cantidad = strlen(cadena);
	if(cantidad == 0)
	{
		retorno = -1;
	}

	return retorno;
}

/// @fn int validateOnlyString(char[])
/// @brief Verifica que la cadena solo tenga letras o espacios.
/// @param nombre char
/// @return 0 si la cadena tiene solo letras, de lo contrario devuelve -1.

int validateOnlyString(char nombre[])
{
	int retorno = 0;

    for(int i = 0 ; i < strlen(nombre); i++)
    {
        if(!(nombre[i] >= 65 && nombre[i] <= 90) && !(nombre[i] >= 97 && nombre[i] <= 122))
        {
            if(nombre[i] != ' ' || nombre[i - 1] == ' ')
            {
				retorno = -1;
            }
        }
    }
    return retorno;
}
