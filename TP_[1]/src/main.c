/*
 ============================================================================
 Name        : TP_[1]
 Author      : Galimany Patricio 1F
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include "biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	//Declaracion de variables.
	int opciones; // Verifica por donde paso el programa.
	float numero1; // Primer valor ingresado.
	float numero2; // Segundo valor ingresado.
	int numeroIngresado; // Eleccion tomada por el usuario.
	int bandera1; // Verifica si la opcion 1 fue utilizada.
	int bandera2; // Verifica si la opcion 2 fue utilizada.
	float suma; // Resultado de la suma.
	float resta; // Resultado de la resta.
	float division; // Resultado de la devision.
	float multiplicar; // Resultado de la multiplicacion.z

	// Inicializaciones de las variables.
	opciones = 0;
	bandera1 = 0;
	bandera2 = 0;

	// Llamadas a las funciones.
	do
	{
	    MostrarMenu(opciones, numero1, numero2);
	    numeroIngresado = EleccionTomada(numeroIngresado, "Ingrese unas de las opciones: ", "Error. Reingrese unas de las opciones mostradas: ", 0, 6);
	    opciones = OpcionTomada(numeroIngresado, bandera1, bandera2, opciones);

	    switch(numeroIngresado)
	    {
	        case 1:
	            numero1 = NumeroObtenido(numeroIngresado);
	            bandera1 = 1;
	            break;
	        case 2:
	            numero2 = NumeroObtenido(numeroIngresado);
	            bandera2 = 1;
	            break;
	        case 3:
	            if(opciones == 3)
	            {
	                suma = SumarOperadores(numero1, numero2);
	                resta = RestarOperadores(numero1, numero2);
	                division = DividirOperadores(numero1, numero2);
	                multiplicar = multiplicarOperadores(numero1, numero2);
	            }
	            else
	            {
	                printf("Error. Ingrese los operadores antes de ejecutar. \n");
	                printf("-----------------------------------------\n");
	            }
	            break;
	        case 4:
	            if(opciones == 4)
	            {
	                MostarSuma(numero1, numero2, suma);
	                MostrarResta(numero1, numero2, resta);
	                MostrarDivision(numero1, numero2, division);
	                MostrarMultiplicacion(numero1, numero2, multiplicar);
	                MostrarFactorial(numero1, numero2);
	            }
	            else
	            {
	                printf("Error. Ingrese los operadores para mostrar los resultados. \n");
	                printf("-----------------------------------------\n");
	            }
	            break;
	    }

	}while(numeroIngresado !=5);

	return EXIT_SUCCESS;
}
