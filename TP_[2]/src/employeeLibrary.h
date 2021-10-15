#ifndef employeeLibrary
#define employeeLibrary

/// @struct
/// @brief Estructura de datos del empleado.

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmpleados;

// Declaraciones de prototipos.

int menu();
void initEmployees(eEmpleados empleados[], int tam);
int altaEmpleado(eEmpleados empleado[],int tam, int id);
int buscarIndiceLibre(eEmpleados empleados[], int tam);
eEmpleados addEmployees(int id, char name[], char lastname[], float salary, int sector);
int bajaEmpleado(eEmpleados empleado[], int tam);
int buscarEmpleado(eEmpleados empleado[], int tam);
int findEmployeeById(int id, eEmpleados empleado[], int tam);
void mostrarEmpleado(eEmpleados xPersona);
int modificarEmpleado(eEmpleados empleado[], int tam);
int modificarDatos();
void cambio(char palabra[51]);
void informar(eEmpleados empleados[], int tam);
int menuInformes();
void printEmployees(eEmpleados empleado[], int tam);
void sortEmployees(eEmpleados empleado[], int tam);
void totalPromedio(eEmpleados empleados[],int tam);
void empleadosSalarioPromedio(eEmpleados empleados[],int tam);
void VerificarNombreYApellido(eEmpleados empleados[], char nombre, char apellido);

#endif /* BIBLIOTECA_H_ */
