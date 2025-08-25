#include <stdio.h>

extern void variables_datatypes();
extern void control_structures();
extern void pointer();
extern void unterprogramm();

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
    unterprogramm();

    return 0;
}

