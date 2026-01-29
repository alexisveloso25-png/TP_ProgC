#include "operator.h"
// affichage 
int somme(int num1, int num2) { return num1 + num2; }
int difference(int num1, int num2) { return num1 - num2; }
int produit(int num1, int num2) { return num1 * num2; }
int quotient(int num1, int num2) { return (num2 != 0) ? (num1 / num2) : 0; }
int modulo(int num1, int num2) { return (num2 != 0) ? (num1 % num2) : 0; }
int et_bit(int num1, int num2) { return num1 & num2; }
int ou_bit(int num1, int num2) { return num1 | num2; }
int negation_bit(int num1) { return ~num1; }

