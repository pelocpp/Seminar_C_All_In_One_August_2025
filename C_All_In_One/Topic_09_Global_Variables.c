#include <stdio.h>

#include "Common.h"

static int g_fileGlobalValue = 123;

static void test_using_global_variabe()
{
    printf("g_globalValue: %d\n", g_globalValue);

    g_globalValue = 456;

    printf("g_globalValue: %d\n", g_globalValue);
}

static void test_using_file_global_variabe()
{
    printf("g_fileGlobalValue: %d\n", g_fileGlobalValue);

    g_fileGlobalValue = 456;

    printf("g_fileGlobalValue: %d\n", g_fileGlobalValue);
}

static void test_using_function_global_variabe()
{
    static int functionGlobalValue = 123;

    ++functionGlobalValue;

    printf("functionGlobalValue: %d\n", functionGlobalValue);
}

extern void test_using_local_variabes_inner();

static void test_using_local_variabes_outer()
{
    int a = 1;
    int b = 2;

    test_using_local_variabes_inner();

    a = 3;
    b = 4;
}


static void test_using_local_variabes_inner()
{
    int x = 101;
    int y = 102;
    int z = 103;

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

void test_variabes_visibility()
{
    test_using_function_global_variabe();
    test_using_function_global_variabe();
    test_using_function_global_variabe();
}