#include <stdio.h>

// Vorwärtsdeklaration (Hilfsfunktionen)
static int summeAllerElemente(int* feld, int len);
static int summeAllerElementeEx(int* feld, int len);
static int summeAllerElementeExEx(int* feld, int len);

// Vorspann

static void test_ein_feld()
{
    int numbers[] = { 1, 2, 3, 4, 5 };

    int sum = summeAllerElementeExEx(numbers, 5);

    int weitereZahlen[] = { 10, 11, 12 };

    sum = summeAllerElemente(weitereZahlen, 3);

}

static int summeAllerElemente(int* feld, int len)
{
    int sum = 0;

    for (int i = 0; i != len; ++i) {

        int tmp = *(feld + i);
        sum = sum + tmp;
    }

    return sum;
}

static int summeAllerElementeEx(int* feld, int len)
{
    int sum = 0;

    for (int i = 0; i != len; ++i) {

        int tmp = 0;

        tmp = *(feld + i);   // Zeiger Arithmetik

        tmp = feld[i];         // mit Index-Notation 

        sum = sum + tmp;
    }

    return sum;
}

static int summeAllerElementeExEx(int* feld, int len)
{
    int sum = 0;

    int* ptr = feld;

    for (int i = 0; i != len; ++i) {

        int tmp = *ptr;
        sum = sum + tmp;
        ++ptr;  // auch hier wird die Adresse um 4 erhoeht - weil int-Zeiger
    }

    return sum;
}

void test_adress_arithmetik()
{
    test_ein_feld();
}