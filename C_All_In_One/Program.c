#include <stdio.h>

extern void variables_datatypes();
extern void control_structures();
extern void pointer();
extern void unterprogramm();

void exercise_teuflische_folge();
void exercise_zinsberechnung();
void exercise_tauschen();

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
    exercise_tauschen();

    return 0;
}

