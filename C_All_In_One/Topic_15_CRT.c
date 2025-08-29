// #define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void crt_01()
{
    char text[] = "This is a simple string";
    size_t length;

    length = strlen(text);
    printf("String \"%s\" has %zu characters.\n", text, length);
}

static void crt_02()
{
    char text[20] = { '\0' };

    // 'strcpy': This function or variable may be unsafe.
    // Consider using strcpy_s instead.
    // To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
    //
    // Meine Empfehlung:
    // Go for Secure Functions

    //strcpy(text, "Hallo!");
    //printf("%s\n", text);

    //strcpy(text, "Yes - You!");
    //printf("%s\n", text);

    size_t s = sizeof(text);

    strcpy_s(text, sizeof(text), "Hallo!");
    printf("%s\n", text);

    strcpy_s(text, sizeof(text), "Yes - You!");
    printf("%s\n", text);
}

static void crt_03()
{
    char* s = "123456789";
    void* ptr = NULL;

    printf("%zu\n", strlen(s));
    printf("%zu\n", sizeof("123456789"));
    printf("%zu\n", sizeof(s));
    printf("%zu\n", sizeof(ptr));

    // string concatenation
    char dest[50] = "ABCDEF";   // STACK 
    //char* dest = "ABCDEF";  // <====== VORSICHT // KEIN PLATZ DANACH
    strcat_s(dest, 50, "123456789");
    printf("%s\n", dest);
}

static void crt_04()
{
    const char string1[] = "Hello";
    const char string2[] = "World";
    const char string3[] = "Hello";

    if (strcmp(string1, string2) == 0)
    {
        printf("The strings %s und %s are identical.\n", string1, string2);
    }
    else
    {
        printf("The strings %s und %s are different.\n", string1, string2);
    }

    if (strcmp(string1, string3) == 0)
    {
        printf("The strings %s und %s are identical.\n", string1, string3);
    }
    else
    {
        printf("The strings %s und %s are different.\n", string1, string3);
    }
}

static void crt_05()
{
    // single character functions
    char ch;

    ch = 'A';
    printf("%d\n", isalpha(ch));

    ch = '1';
    printf("%d\n", isalpha(ch)); // a .. z, A .. Z

    printf("%d\n", isdigit(ch));  // 0 .. 9 

    printf("%d\n", isalnum(ch));  //  a .. z, A .. Z und 0..9

    ch = 'A';
    ch = tolower(ch);     // ch >= 'a' && ch <= 'z'
    printf("%c\n", ch);

    ch = toupper(ch);
    printf("%c\n", ch);
}

static void crt_06()
{
    // ascii to integer
    int n =     atoi("1234");   // ascii to integer 
    printf("%d\n", n);

    n = atoi("1234XXX");
    printf("%d\n", n);

    n = atoi("XXX1234");
    printf("%d\n", n);

    n = atoi("0");
    printf("%d\n", n);
}

static void crt_07()
{
    // Eingabe von num. Werten
    printf("Eingabe: ");
    int n = 0;
    scanf_s("%d", &n);
    printf("Wert: %d\n", n);

    // Eingabe einer Zeichenkette (ohne Leerzeichen)
    printf("Eingabe Zeichenkette: ");
    char buffer[64];
    scanf_s("%s", buffer, 64);
    printf("Wert: %s\n", buffer);

    // Eingabe einer Zeichenkette (ohne Leerzeichen)
    printf("Eingabe Zeichenkette: ");
    gets_s(buffer, 64);
    scanf_s("%s", buffer, 64);
    printf("Wert: %s\n", buffer);
}

void test_crt()
{
    crt_07();
}