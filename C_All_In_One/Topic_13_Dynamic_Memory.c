#include <stdio.h>
#include <stdlib.h>

void dynamic_data_01()
{
    // eine int-Variable:   4 Bytes
    // eine char-Variable:  1 Byte

    int wieviel = sizeof(int);  // BYTES !!!!
    int* ptr = (int*) malloc(wieviel);

    if (ptr == NULL) {

        printf("Kein Speicher mehr vorhanden!\n");
    }
    else
    {
        *ptr = 123;

        printf("Wert auf dem Heap: %d\n", *ptr);

        free(ptr);
    }
}


void weitereVerarbeitung(int* data)
{
    *data = 456;
    printf("Wert: %d\n", *data);

    // Frage:
    free(data);    // geht das ???
} 

void dynamic_data_02()
{
    int* ptr = (int*) malloc(sizeof(int));

    *ptr = 123;
    printf("Wert auf dem Heap: %d\n", *ptr);

    weitereVerarbeitung(ptr);

    free(ptr);    // geht das ???
}

void dynamic_data_03()
{
    // Anlegen eines Arrays
    // int zahlen[10];  <======  FIXED SIZE: 10

    // Anlegen eines int-Arrays mit einer variablen Länge / berechneten Länge
    int count = 10; // Ergebnis einer Berechung // scanf ...

    int* ptr = (int*) malloc(sizeof(int) * count);

    // Wie kann man in diesem Fall auf das Array zugreifen:
    // A) Mit Zeigern // Zeiger-Arithmetik
    for (int i = 0; i != count; ++i) {

        *(ptr + i) = 2 * i;
    }

    for (int i = 0; i != count; ++i) {
        printf("%d: %d\n", i, *(ptr + i));
    }

    // Wie kann man in diesem Fall auf das Array zugreifen:
    // B) Wie auf ein FIXED-SIZE Array
    for (int i = 0; i != count; ++i) {

        ptr[i] = 3 * i;
    }

    for (int i = 0; i != count; ++i) {
        printf("%d: %d\n", i, ptr[i]);
    }


    free(ptr);
}


void vorbelegen(int* ptr, int count, int wert)
{
    for (int i = 0; i != count; ++i) {
        ptr[i] = wert * i;                     // oder *(ptr + i)
    }
}

void ausgeben(int* ptr, int count)
{
    for (int i = 0; i != count; ++i) {
        printf("%d: %d\n", i, *(ptr + i));  // oder ptr[i]
    }
}

void dynamic_data_04()
{
    // Anlegen eines Arrays
    // int zahlen[10];  <======  FIXED SIZE: 10

    // Anlegen eines int-Arrays mit einer variablen Länge / berechneten Länge
    int count = 10; // Ergebnis einer Berechung // scanf ...

    int* ptr = (int*)malloc(sizeof(int) * count);

    vorbelegen(ptr, count, 2);
    ausgeben(ptr, count);

    vorbelegen(ptr, count, 4);
    ausgeben(ptr, count);

    free(ptr);
}

void dynamic_data()
{
    dynamic_data_04();
}