#include <stdio.h>

#include "Common.h"

// Hello World
//int main()
//{
//    printf("Hello World");
//
//    return 0;
//}

void eingabe()
{
    printf("Bitte Wert eingeben: ");

    int n = 0;

    scanf_s("%d", &n);   // & ist WICHTIG: Adresse

    printf("n: %d\n", n);

    // gerade / ungerade 
    if (n % 2 == 0) {
        printf("gerade\n");
    }
    else {
        printf("ungerade\n");
    }
}


extern void test_arrays_01();

int main()
{
    test_arrays();

    return 0;
}

