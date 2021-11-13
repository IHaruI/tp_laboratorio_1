#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int controlarOpcion(LinkedList* listaEmpleados);
int listaDeEmpleados(LinkedList* pArrayListEmployee, int indice);
int modificarEmpleado(LinkedList* pArrayListEmployee);
int buscarId(char mensaje[], char mensajeError [],LinkedList* pArrayListEmployee);
int findEmployeeById(int id,LinkedList* pArrayListEmployee);
int eliminarEmpleado(LinkedList* pArrayListEmployee);
int ordenarEmpleados(LinkedList* cloneList);

#endif
