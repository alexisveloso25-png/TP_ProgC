#include "operator.h"
int somme(int n1, int n2) { return n1 + n2; }
int difference(int n1, int n2) { return n1 - n2; }
int produit(int n1, int n2) { return n1 * n2; }
int quotient(int n1, int n2) { return (n2 != 0) ? n1 / n2 : 0; }
int modulo(int n1, int n2) { return (n2 != 0) ? n1 % n2 : 0; }
int et_bit(int n1, int n2) { return n1 & n2; }
int ou_bit(int n1, int n2) { return n1 | n2; }
int negation_bit(int n1) { return ~n1; }
