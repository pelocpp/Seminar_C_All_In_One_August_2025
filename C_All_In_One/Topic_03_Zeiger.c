#include <stdio.h>

void pointer()
{
    int n = 123;  // = 7B hex

    printf("n: %d\n", n);

    int* ip = NULL;   // integer pointer

    // An welcher Adresse liegt n in diesem Programm

    ip = &n;

    // Wert 456 der Variablen n zuweisen, ohne den Variablennamen
    // n zu verwenden :)
    *ip = 456;    // Wert-von // Value-of Operator
}

