#include <stdio.h>

static void tausche(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void exercise_tauschen()
{
    int a = 3;
    int b = 5;

    printf("%d - %d\n", a, b);

    tausche(&b, &a);
    printf("%d - %d\n", a, b);
}