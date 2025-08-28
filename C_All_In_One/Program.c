#include <stdio.h>
#include <stdbool.h>

#include "Common.h"

// ===========================
// global variables
int g_globalValue = 123;

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

int main()
{
    test_crt();

    return 0;
}
