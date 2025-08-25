#include <stdio.h>

void variables_datatypes()
{
    int n = 123;

    int mc = sizeof(char);   // Special ... Byte
    int mi = sizeof(int);
    int ms = sizeof(short);
    int ml = sizeof(long);
    int mll = sizeof(long long);

    int mf = sizeof(float);
    int md = sizeof(double);

    printf("sizeof(char):      %d\n", mc);
    printf("sizeof(int):       %d\n", mi);
    printf("sizeof(short):     %d\n", ms);
    printf("sizeof(long):      %d\n", ml);
    printf("sizeof(long long): %d\n", mll);

    float f = 123.456f;

    printf("a float:           %f\n", f);

    printf("sizeof(float):     %d\n", mf);
    printf("sizeof(double):    %d\n", md);
}