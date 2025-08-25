#include <stdio.h>

void control_structures_if_01()
{
    int n = 1; 
    int m = 2;

    if (m > n)
    {
        printf("Bedingung erfuellt\n");
    }

    if (m)
    {
        printf("Bedingung erfuellt\n");
    }

    m = 0;

    if (m != 0)
    {
        printf("Bedingung erfuellt (m != 0)\n");
    }

    if (m == 0)
    {
        printf("Bedingung erfuellt (m == 0)\n");
    }
}

void control_structures_if_02()
{
    int n = 2;
    int m = 1;

    if (m > n)
    {
        printf("Bedingung erfuellt\n");
    }
    else
    {
        printf("Bedingung nicht erfuellt\n");
    }
}

void control_structures_if_03()
{
    int n = 3;

    // Hier die Bedingung MAXIMAL dreimal evaluiert - es kann auch nur einmal sein - oder in-between

    if (n == 1)
    {
        printf("n == 1\n");
    }
    else if (n == 2)
    {
        printf("n == 2\n");
    }
    else if (n == 3)
    {
        printf("n == 3\n");
    }
    else
    {
        printf("weder 1, 2 oder 3\n");
    }

    // Was ist der Unterschied hierzu ????
    // Hier wird DREIMAL die Bedingung evaluiert.

    if (n == 1)
    {
        printf("n == 1\n");
    }
    
    if (n == 2)
    {
        printf("n == 2\n");
    }

    if (n == 3)
    {
        printf("n == 3\n");
    }
}

void control_structures_if_04()
{
    int n = 2;
    int m = 1;

    int x = 10;
    int y = 11;

    if (m > n && x < y)  // Logisch UND
    {
        printf("Bedingung erfuellt (A)\n");
    }

    if (m > n || x < y)  // Logisch ODER
    {
        printf("Bedingung erfuellt (B)\n");
    }

    if ( ! ( m > n ) )   // Logisch NICHT
    {
        printf("Bedingung erfuellt (C)\n");
    }
}

void control_structures_while_01()
{
    int n = 1;

    while ( n < 5 )
    {
       // printf("n: %d\n", n);

        n = n + 1;
    }

    printf("Done\n");
}

void control_structures_while_02()
{
    int n = 10;

    while (n != 0)    // n != 0
    {
        printf("n: %d\n", n);

        n = n - 1;
    }

    printf("Done\n");
}

void operators()
{
    int n = 1;

    printf("n: %d\n", n);

    // n = n + 1;
    n++;  // Post-Inkrement
    ++n;  // Pre-Inkrement
    
    printf("n: %d\n", n);
}

void operators_01()
{
    int n = 1;

    printf("n: %d\n", n);  // n = 1

    // Vorsicht !!!!!!!!!!!
    // int m = n++;      // Post-Inkrement
    // int m = ++n;      // Pre-Inkrement

    // Besser // More Secure:
    int m = n;
    n++;

    printf("n: %d\n", n);  // n = 1
    printf("m: %d\n", m);  // m = 1
}

void operators_02()
{
    int n = 1;
    int m = 2;

    int x = 10;
    int y = 11;

    //if (n < x + y) {   // x + y ist eine temporäre Variable
    //    printf("bin hier\n");
    //}

    if (n < m && x < y++) {
        printf("bin hier\n");
    }

    printf("y: %d\n", y);  // y == 12
    printf("Done\n");
}

void control_structures()
{
    operators_02();
}
