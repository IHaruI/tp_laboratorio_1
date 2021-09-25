#include "biblioteca.h"

/// @fn void MostrarMenu(int, float, float)
/// @brief Muestra el menu asignado.
/// @param opcion Muestra el menu segun la opcion que se haya tomado y coloca el numero ingresado en el menu.
/// @param numeroUno Primer numero asignado.
/// @param numeroDos Segundo numero asignado.

void MostrarMenu(int opcion, float numeroUno, float numeroDos)
{
    switch(opcion)
    {
    	case 0:
    	case 4:
			printf("1. Ingresar 1er operando (A=X)\n");
			printf("2. Ingresar 2do operando (B=Y)\n");
			printf("3. Calcular todas las operaciones\n");
			printf("a) Calcular la suma (A+B)\n");
			printf("b) Calcular la resta (A-B)\n");
			printf("c) Calcular la division (A/B)\n");
			printf("d) Calcular la multiplicacion (A*B)\n");
			printf("e) Calcular el factorial (A!)\n");
			printf("4. Informar resultados\n");
			printf("5. Salir\n");
			printf("-----------------------------------------\n");
			break;

    	case 1:
			printf("1. Ingresar 1er operando (A=%g)\n",numeroUno);
			printf("2. Ingresar 2do operando (B=y)\n");
			printf("3. Calcular todas las operaciones\n");
			printf("a) Calcular la suma (%g + B)\n",numeroUno);
			printf("b) Calcular la resta (%g - B)\n",numeroUno);
			printf("c) Calcular la division (%g / B)\n",numeroUno);
			printf("d) Calcular la multiplicacion (%g * B)\n",numeroUno);
			printf("e) Calcular el factorial (%g!)(B!)\n",numeroUno);
			printf("4. Informar resultados\n");
			printf("5. Salir\n");
			printf("-----------------------------------------\n");
			break;

    	case 2:
			printf("1. Ingresar 1er operando (A=x)\n");
			printf("2. Ingresar 2do operando (B=%g)\n",numeroDos);
			printf("3. Calcular todas las operaciones\n");
			printf("a) Calcular la suma (A + %g)\n",numeroDos);
			printf("b) Calcular la resta (A - %g)\n",numeroDos);
			printf("c) Calcular la division (A / %g)\n",numeroDos);
			printf("d) Calcular la multiplicacion (A * %g)\n",numeroDos);
			printf("e) Calcular el factorial (A!)(%g!)\n",numeroDos);
			printf("4. Informar resultados\n");
			printf("5. Salir\n");
			printf("-----------------------------------------\n");
			break;

		case 3:
			printf("1. Ingresar 1er operando (A=%g)\n",numeroUno);
			printf("2. Ingresar 2do operando (B=%g)\n",numeroDos);
			printf("3. Calcular todas las operaciones\n");
			printf("a) Calcular la suma (%g + %g)\n",numeroUno,numeroDos);
			printf("b) Calcular la resta (%g - %g)\n",numeroUno,numeroDos);
			printf("c) Calcular la division (%g / %g)\n",numeroUno,numeroDos);
			printf("d) Calcular la multiplicacion (%g * %g)\n",numeroUno,numeroDos);
			printf("e) Calcular el factorial (%g!)(%g!)\n",numeroUno,numeroDos);
			printf("4. Informar resultados\n");
			printf("5. Salir\n");
			printf("-----------------------------------------\n");
			break;
    }
}

/// @fn int EleccionTomada(int, char[], char[], int, int)
/// @brief Pide y devuelve un numero validado.
/// @param eleccion Eleccion tomada.
/// @param mensaje Mensaje de ingreso.
/// @param error Mensaje de error.
/// @param minimo El valor minimo del rango de validacion.
/// @param maximo El valor maximo del rango de validacion.
/// @return La opcion validada.

int EleccionTomada(int eleccion, char mensaje[], char error[], int minimo, int maximo)
{
    printf("%s", mensaje);
    scanf("%d", &eleccion);

    while(!(eleccion > minimo && eleccion < maximo))
    {
        printf("%s", error);
        scanf("%d", &eleccion);
    }
    return eleccion;
}

/// @fn float NumeroObtenido(int)
/// @brief Pide el ingreso del operando.
/// @param eleccion Opcion tomada.
/// @return El numero ingresado.

float NumeroObtenido(int eleccion)
{
    float numero;

    if(eleccion == 1)
    {
        printf("1. Ingresar 1er operando (A=X): ");
        scanf("%f", &numero);
        printf("-----------------------------------------\n");
    }
    else
    {
        printf("2. Ingresar 2do operando (B=Y): ");
        scanf("%f", &numero);
        printf("-----------------------------------------\n");
    }
    return numero;
}

/// @fn int OpcionTomada(int, int, int, int)
/// @brief Verifica la opcion que haya sido ingresada.
/// @param eleccion Opcion tomada.
/// @param banderaA Determina si hubo ingreso en la primera opcion.
/// @param banderaB Determina si hubo ingreso en la segunda opcion.
/// @param bandera Determina que menu debe mostrar y que opcion se ha tomado.
/// @return El valor de la opcion ingresada.

int OpcionTomada(int eleccion, int banderaA, int banderaB, int bandera)
{
    if(eleccion == 1)
    {
        bandera = 1;
    }
    else if(eleccion == 2)
    {
        bandera = 2;
    }
    // Verifica si se ingreso las primeras dos opciones.
    else if(eleccion == 3 && banderaA == 1 && banderaB == 1)
    {
        bandera = 3;
    }
    // Verifica si se ingreso las primeras tres opciones.
    else if(eleccion == 4 && banderaA == 1 && banderaB == 1 && bandera == 3)
    {
        bandera = 4;
    }
    return bandera;
}

/// @fn float SumarOperadores(float, float)
/// @brief Suma los operadores ingresados.
/// @param numeroUno Primer operador ingresado.
/// @param numeroDos Segundo operador ingresado.
/// @return El resultado de la suma.

float SumarOperadores(float numeroUno, float numeroDos)
{
    float resultadoSuma;

    resultadoSuma = numeroUno + numeroDos;

    return resultadoSuma;
}

/// @fn float RestarOperadores(float, float)
/// @brief Resta los operadores ingresados.
/// @param numeroUno Primer operador ingresado.
/// @param numeroDos Segundo operador ingresado.
/// @return El resultado de la resta.

float RestarOperadores(float numeroUno, float numeroDos)
{
    float resultadoResta;

    resultadoResta = numeroUno - numeroDos;

    return resultadoResta;
}

/// @fn float DividirOperadores(float, float)
/// @brief Divide los operadores ingresados.
/// @param numeroUno Primer operador ingresado.
/// @param numeroDos Segundo operador ingresado.
/// @return El resultado de la division.

float DividirOperadores(float numeroUno, float numeroDos)
{
    float resultadoDivision;

    if(numeroUno != 0 && numeroDos != 0)
    {
        resultadoDivision = numeroUno / numeroDos;
    }
    else
    {
        resultadoDivision = 0;
    }

    return resultadoDivision;
}

/// @fn float multiplicarOperadores(float, float)
/// @brief Multiplica los operadores ingresados.
/// @param numeroUno Primer operador ingresado.
/// @param numeroDos Segundo operador ingresado.
/// @return El resultado de la multiplicacion.

float multiplicarOperadores(float numeroUno, float numeroDos)
{
    float resultadoMultiplicacion;

    resultadoMultiplicacion = numeroUno * numeroDos;

    return resultadoMultiplicacion;
}

/// @fn void MostarSuma(float, float, float)
/// @brief Muestra el resultado de la suma de los operando.
/// @param numeroUno Primer operador ingresado.
/// @param numeroDos Segundo operador ingresado.
/// @param sumaTotal Resultado de la suma.

void MostarSuma(float numeroUno, float numeroDos, float sumaTotal)
{
    printf("La suma de %g y %g es: %g\n", numeroUno, numeroDos, sumaTotal);
}

/// @fn void MostrarResta(float, float, float)
/// @brief Muestra el resultado de la resta de los operando.
/// @param numeroUno Primer operador ingresado.
/// @param numeroDos Segundo operador ingresado.
/// @param restaTotal Resultado de la suma.

void MostrarResta(float numeroUno, float numeroDos, float restaTotal)
{
    printf("La resta de %g y %g es: %g\n", numeroUno, numeroDos, restaTotal);
}

/// @fn void MostrarDivision(float, float, float)
/// @brief Muestra el resultado de la division de los operando y valida si se ingreso un cero.
/// @param numeroUno Primer operador ingresado.
/// @param numeroDos Segundo operador ingresado.
/// @param divisionTotal Resultado de la division.

void MostrarDivision(float numeroUno, float numeroDos, float divisionTotal)
{
    if(divisionTotal != 0)
    {
        printf("La division de %g y %g es: %.2g\n", numeroUno, numeroDos, divisionTotal);
    }
    else
    {
        printf("No es posible dividir por cero\n");
    }
}

/// @fn void MostrarMultiplicacion(float, float, float)
/// @brief Muestra el resultado de la multiplicacion de los operando.
/// @param numeroUno Primer operador ingresado.
/// @param numeroDos Segundo operador ingresado.
/// @param multiplicacionTotal Resultado de la multiplicacion.

void MostrarMultiplicacion(float numeroUno, float numeroDos, float multiplicacionTotal)
{
    printf("La multiplicacion de %g y %g es: %g\n", numeroUno, numeroDos, multiplicacionTotal);
}

/// @fn void MostrarFactorial(float, float)
/// @brief Muestra el factorial de los operando y verifica si se ingreso un decimal o un negativo.
/// @param numeroUno Primer operador ingresado.
/// @param numeroDos Segundo operador ingresado.

void MostrarFactorial(float numeroUno, float numeroDos)
{
	int i;
	int factorialA;
	int factorialB;
    int verEnteros;
    int verEnteroUno;
    int verEnteroDos;

    factorialA = 1;
    factorialB = 1;

    verEnteros = ValidarEntero(numeroUno, numeroDos);
    verEnteroUno = ValidarNumeroUno(numeroUno);
    verEnteroDos = ValidarNumeroDos(numeroDos);

    for(i = 1; i <= numeroUno; i++)
    {
    	factorialA = factorialA * i;
    }
    for(i = 1; i <= numeroDos; i++)
    {
    	factorialB = factorialB * i;
    }

    if(verEnteros == 1)
    {
    	printf("El factorial de %g es: %d y el El factorial de %g es: %d\n", numeroUno, factorialA, numeroDos, factorialB);
    	printf("-----------------------------------------\n");
    }
    else if(verEnteroUno == 1)
    {
    	printf("El factorial de %g es: %d, y el El factorial de %g es: No hay factorial de este numero.\n", numeroUno, factorialA, numeroDos);
    	printf("-----------------------------------------\n");
    }
    else if(verEnteroDos == 1)
    {
      	printf("El factorial de %g es: No hay factorial de este numero, y el El factorial de %g es: %d.\n", numeroUno, numeroDos, factorialB);
       	printf("-----------------------------------------\n");
    }
    else
    {
    	printf("Solo se puede factoriar numero enteros.\n");
    	printf("-----------------------------------------\n");
    }
}

/// @fn int ValidarEntero(float, float)
/// @brief Verifica si los numeros ingresados son enteros positivos.
/// @param numeroA Primer operador ingresado.
/// @param numeroB Segundo operador ingresado.
/// @return Si es verdadero o falso.

int ValidarEntero(float numeroA, float numeroB)
{
	int verEntero = 0;
	int validarUno;
	int validarDos;

	validarUno = numeroA;
	validarDos = numeroB;

	if (validarUno == numeroA && validarDos == numeroB && numeroA >= 0 && numeroB >= 0)
	{
		verEntero = 1;
	}

	return verEntero;
}

/// @fn int ValidarNumeroUno(float)
/// @brief Verifica si el primer numero ingresado es un entero positivo.
/// @param numeroA Primer operador ingresado.
/// @return Si es verdadero o falso.

int ValidarNumeroUno(float numeroA)
{
	int verNumeroUno = 0;
	int validarUno;

	validarUno = numeroA;

	if (validarUno == numeroA && numeroA >= 0)
	{
		verNumeroUno = 1;
	}

	return verNumeroUno;
}

/// @fn int ValidarNumeroDos(float)
/// @brief Verifica si el segundo numero ingresado es un entero positivo.
/// @param numeroB Segundo operador ingresado.
/// @return Si es verdadero o falso.

int ValidarNumeroDos(float numeroB)
{
	int verNumeroDos = 0;
	int validarDos;

	validarDos = numeroB;

	if (validarDos == numeroB && numeroB >= 0)
	{
		verNumeroDos = 1;
	}

	return verNumeroDos;
}
