#include <stdio.h>

// Hilfsfunktion

static void test_arrays_00()
{
    // designated array initializer
    int zahlen[3] = {
        [0] = 1, [1] = 2, [2] = 3
    };
}



static void test_arrays_01()
{
    // Vereinbarung// mit Vorbelegung
    int zahlen1[10] = {};

    int zahlen2[10] = { 1, 2, 3 };

    int zahlen3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int zahlen4[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Zugriff - schreibend
    for (int i = 0; i != 10; ++i) {
        zahlen1[i] = 2 * i;
    }

    // Zugriff - lesend
    for (int i = 0; i != 10; ++i) {
        printf("%02d: %3d\n", i, zahlen1[i]);
    }
}

static void test_arrays_02()
{
    int zahlen[10] = {};

    // ...
    int n = 10;

//    zahlen[n] = 123;

    printf("Done!\n");
}

#define Max  5   // Vorsicht !!!!!!!!! KEIN Semikolon am Ende

// const int Max2 = 5;

static void test_arrays_03()
{
    int n = Max;

    int m = 5;;

    int zahlen[Max] = {};

    // int zahlen2[5;] = {};

    printf("Done!\n");

    // Zugriff - schreibend
    for (int i = 0; i != Max; ++i) {
        zahlen[i] = 2 * i;
    }

    // Zugriff - lesend
    for (int i = 0; i != Max; ++i) {
        printf("%02d: %3d\n", i, zahlen[i]);
    }
}

void test_arrays()
{
    test_arrays_00();
}