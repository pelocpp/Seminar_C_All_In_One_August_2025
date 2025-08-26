#include <stdio.h>

#include "Common.h"


// extern int g_globalValue;

void test_using_global_variabe()
{
    printf("g_globalValue: %d\n", g_globalValue);

    g_globalValue = 456;

    printf("g_globalValue: %d\n", g_globalValue);
}

void test_using_local_variabes()
{
    int n = 123;  // lebt bis zum Ende der Funktion
    printf("n: %d\n", n);

    // Blockschachtelung // Nested Scope

    {
        int m = 456;  // lebt bis zum Ende des  Blocks  // { }
        printf("m: %d\n",m);

        int n = 789;   // Verdecken von n im ‰uﬂeren Scope
        printf("n: %d\n", n);
    }

    printf("n: %d\n", n);
}