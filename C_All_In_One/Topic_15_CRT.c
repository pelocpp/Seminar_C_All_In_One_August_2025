// #define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>

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



void test_crt()
{
    crt_03();
}