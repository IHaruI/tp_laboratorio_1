#ifndef UTN_H_
#define UTN_H_

int getInt(int numero, char mensaje[], char mensajeError[], int minimo, int maximo);
int getIntAndRange(int bandera, char cadena[], int numero, int minimo, int maximo);
int validarNumeroEntero(char numero[]);
void verificarRetorno(char* mensaje, char* mensajeError, int retorno);
int createId(int id);
void getOnlyString(char nombre[], char mensaje[], char mensajeError[]);
int verificarEnter(char nombre[]);
int validateOnlyString(char cadena[]);

//Funciones que no se utilizaron por medio de que todos los sueldos mostrados son enteros. Aun asi se fueron elaboradas.
float getFloat(float numero, char mensaje[], char mensajeError[], float minimo, float maximo);
int getFloatAndRange(int flag, char cadena[], float numero, float minimo, float maximo);
int validarNumeroFlotante(char numero[]);

#endif /* UTN_H_ */
