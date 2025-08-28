#include <stdio.h>

void variables_datatypes_01()
{
    int n = 123;

    size_t m = 123;

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


void variables_datatypes_02()
{
    printf("sizeof(int):       %zd\n", sizeof(int));
    printf("sizeof(short):     %zd\n", sizeof(short));
    printf("sizeof(long long): %zd\n", sizeof(long long));

    short s = 123;

    long long n = 456;

    n = s; // geht das ???
           // implizite Typkonvertierung: ein short passt immer in ein int

    s = (short) n; // explizite Typkonvertierung:  Cast-Operation 

    // ===========================

    double d = 123.456;

    float f = 123.456f;

    n = (int) f;

    n = (int) d;
}

void variables_datatypes()
{
    variables_datatypes_02();
}