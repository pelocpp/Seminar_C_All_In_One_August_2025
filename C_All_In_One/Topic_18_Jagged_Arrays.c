#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include <stdio.h>
#include <stdlib.h>

static void main_jagged_arrays_01()
{
    int* p1 = (int*)malloc(sizeof(int) * 3);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;

    int* p2 = (int*)malloc(sizeof(int) * 5);
    p2[0] = 10;
    p2[1] = 11;
    p2[2] = 12;
    p2[3] = 13;
    p2[4] = 14;

    int* p4 = (int*)malloc(sizeof(int) * 2);
    p4[0] = 20;
    p4[1] = 21;

    int* adressen[4];
    adressen[0] = p1;
    adressen[1] = p2;
    adressen[2] = NULL;
    adressen[3] = p4;

    int laengen[4] = { 3, 5, 0, 2 };

    // das jagged-Array ausgeben
    for (int i = 0; i != 4; ++i) {

        int* row = adressen[i];

        for (int k = 0; k != laengen[i]; ++k) {

            printf("%d:%d: %3d     ", i, k, row[k]);
        }
        printf("\n");
    }
}

static  void main_jagged_arrays_uebung_01()
{
    // Für den Anfang: Feste Anzahl Reihen
    int* adressen[10] = {};

    for (int i = 0; i != 10; ++i) {

        int* row = (int*)malloc(sizeof(int) * (i+1));

        for (int k = 0; k != i + 1; ++k) {
            row[k] = k + 1;
        }

        adressen[i] = row;
    }

    // Ausgeben
    for (int i = 0; i != 10; ++i) {

        int* row = adressen[i];

        for (int k = 0; k != (i+1); ++k) {

            printf("%3d", row[k]);
        }
        printf("\n");
    }
}

static  void main_jagged_arrays_uebung_02(int numRows)
{
    // Für den Anfang: Feste Anzahl Reihen
    // int* adressen[numRows] = {};

    int** adressen = malloc(numRows * sizeof(int*));

    for (int i = 0; i != numRows; ++i) {

        int* row = (int*)malloc(sizeof(int) * (i + 1));

        for (int k = 0; k != i + 1; ++k) {
            row[k] = k + 1;
        }

        adressen[i] = row;
    }

    // Ausgeben
    for (int i = 0; i != numRows; ++i) {

        int* row = adressen[i];

        for (int k = 0; k != (i + 1); ++k) {

            printf("%3d", row[k]);
        }
        printf("\n");
    }
}

// ===============================================

static int** createJaggedArray(int numRows)
{
    // Für den Anfang: Feste Anzahl Reihen
    // int* adressen[numRows] = {};

    int** adressen = malloc(numRows * sizeof(int*));

    for (int i = 0; i != numRows; ++i) {

        int* row = (int*)malloc(sizeof(int) * (i + 1));

        for (int k = 0; k != i + 1; ++k) {
            row[k] = k + 1;
        }

        adressen[i] = row;
    }

    return adressen;
}

static  void printJaggedArray(int** jaggedArray, int numRows)
{
    for (int i = 0; i != numRows; ++i) {

        int* row = jaggedArray[i];

        for (int k = 0; k != (i + 1); ++k) {

            printf("%3d", row[k]);
        }
        printf("\n");
    }
}

void releaseJaggedArray(int** jaggedArray, int numRows)
{
    for (int i = 0; i != numRows; ++i) {

        free(jaggedArray[i]);
    }

    free(jaggedArray);
}

static void main_jagged_arrays_uebung_03()
{
    int anzahlReihen = 10;

    int** jaggedArray = createJaggedArray(anzahlReihen);

    printJaggedArray(jaggedArray, anzahlReihen);

    releaseJaggedArray(jaggedArray, anzahlReihen);
}

void main_jagged_arrays()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    main_jagged_arrays_uebung_03();
}
