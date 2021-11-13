#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);
int parser_SaveDataEmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_SaveDataEmployeeBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif
