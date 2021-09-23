#include <stdio.h>
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

void MostrarMenu(int opcion,float numeroUno,float numeroDos);
void MostarSuma(float numeroUno, float numeroDos, float sumaTotal);
void MostrarResta(float numeroUno, float numeroDos, float restaTotal);
void MostrarDivision(float numeroUno, float numeroDos, float divisionTotal);
void MostrarMultiplicacion(float numeroUno, float numeroDos, float multiplicacionTotal);
void MostrarFactorial(float numeroUno, float numeroDos);
int EleccionTomada(int eleccion, char mensaje[], char error[], int minimo, int maximo);
int OpcionTomada(int eleccion, int banderaA, int banderaB, int bandera);
float NumeroObtenido(int eleccion);
float SumarOperadores(float numeroUno, float numeroDos);
float RestarOperadores(float numeroUno, float numeroDos);
float DividirOperadores(float numeroUno, float numeroDos);
float multiplicarOperadores(float numeroUno, float numeroDos);

#endif /* BIBLIOTECA_H_ */
