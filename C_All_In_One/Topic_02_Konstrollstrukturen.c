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
    int n = 10;

    while ( n < 5 )
    {
        printf("n: %d\n", n);

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

void control_structures_for_02()
{
    for (int i = 0; i != 10; ++i) {

        if (i == 3) {
            continue;
        }

        printf("%d: Hello World\n", i);

        if (i == 8) {
            break;
        }
    }
}

void control_structures_do_while()
{
    int n = 1;

    do
    {
        printf("%d: Hello World\n", n);

        --n;

    } while (n != 0);
}

void control_structures_switch()
{
    int n = 5;

    switch (n)
    {
    case 1:
        printf("Ist 1\n");
        break;   // jmp
    case 2:
        printf("Ist 2\n");
        break;   // jmp
    case 3:
        printf("Ist 3\n");
        break;   // jmp
    default:
        printf("Ist weder 1, 2 oder 3\n");
        break;
    }

    printf("Done\n");
}

void control_structures_switch_01()
{
    int n = 2;

    switch (n)
    {
    case 1:
        printf("Ist Montag\n");
        break;   // jmp
    case 2:
        printf("Ist Dienstag\n");
        break;   // jmp
    case 3:
        printf("Ist Mittwoch\n");
        break;   // jmp
    case 4:
        printf("Ist Donnerstag\n");
        break;   // jmp
    case 5:           // Fall-through
    case 6:           // Fall-through
    case 7:
        printf("Ist Wochenende\n");
        break;   // jmp
    default:
        printf("Ist kein Wochentag\n");
        break;
    }

    printf("Done\n");
}

void operators_precedence()
{
    int n = 1 + 2 * 3;

    int x = 1;
    int y = 2;
    int a = 3;
    int b = 4;

    if ( (a > b &&  x < y) || (a <= b && x <= y) )
        ;   // empty statement

    // left-to right oder right-to-left
    int result = x - y - a;  // (1 - 2) - 3 = -1 -3 = -4
                             // 1 - (2 - 3) = 1 - (-1) = 2

    a = b = x = 3;

    // Auch eine Wertzuweisung hat ein Ergebnis // bzw. einen Wert
    // Trivial: x = 3 + 4;  // Addition: +
  
    a = (b = (x = 3+4));  // right - to - left

    printf("n: %d\n", n);

    x = (a >= b) ? 10 : 20;

    for (int i = 0; i != 3; ++i) {
        printf("hello\n");
    }

    if (a == 7) {
        return;
    }
        
    printf("Done\n");
}

void control_structures()
{
    operators_precedence();
}
