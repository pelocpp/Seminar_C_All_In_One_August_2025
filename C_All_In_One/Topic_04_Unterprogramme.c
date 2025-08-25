#include <stdio.h>


void ausgabe()
{
    int result = printf("Hello Unterprogramm\n");

    printf("Result: %d\n", result);

    // Rücksprung
    return;   // als LETZTE Anweisung kann man return weglassen !!!
}

int product(int left, int right)
{
    int result;

    result = left * right;

    return result;
}

void unterprogramm_01()
{
    ausgabe();

    int result;

    result = product(5, 6);
}

// ===========================================

void malZwei(int wert)
{
    wert = wert * 2;
}

// 2. Variante: Aufruf mit einer Adresse einer Variablen
void malZweiEx(int* ptr)   
{
    // Stilistik: Beginner // Learner

    int value;

    value = *ptr;    // Lesenden Zugriff 

    value = value * 2;

    *ptr = value;    // Schreibenden Zugriff 

    // Stilistik: Professional
    // *ptr = *ptr * 2;
}

// 3. Variante: Rückgabe des Ergebnisses via Return
int malZweiExEx(int value)
{
    value = value * 2;

    return value;
}


void unterprogramm_02()
{
    int n = 10;
    printf("n: %d\n", n);

    malZwei(n);
    printf("n: %d\n", n);

    malZweiEx(&n);
    printf("n: %d\n", n);

    n = malZweiExEx(n);
    printf("n: %d\n", n);

}

// =========================================

void tausche(int a, int b)    // Swap
{
    // to be done .....
}


void unterprogramm()
{
    int x = 5;
    int y = 6;

    printf("x: %d, y: %d\n", x, y);

    tausche(x, y);

    printf("x: %d, y: %d\n", x, y);
}