#include <stdio.h>

// 1. Beispiel: Länge einer Zeichenkette

// Zum Berechnen der Länge einer Zeichenkette wird diese
// nicht verändert - deshalb const

int str_length(const char* s)  
{
    const char* ptr = s;

    int len = 0;

    while (*ptr != '\0') {
        ++len;
        ++ptr;
    }

    return len;
}

// 2. Beispiel: Eine Zeichenkette an eine andere Zeichenkette dranhängen / anfügen.

// Beispiel: "123" ==> "XYZ"  : Ergebnis: "123XYZ"
 
// 1. Parameter: Ausgangszeichenkette 'src'
// 2. Parameter: Die anzuhängende Zeichenkette 'toAppend'
// 3. Parameter: Platz für das Ergebnis: dest (Anfangsadresse eines Puffers)
// 4. Parameter: Länge des Puffers im 3. Parameter

int str_append(const char* src, const char* toAppend, char* dest, int destLen)
{
    // Länge von src
    int lenSrc = str_length(src);
    int lenToAppend = str_length(toAppend);

    if (lenSrc + lenToAppend + 1 > destLen) {
        printf("Zielpuffer ist zu klein\n");
        return 0;  // 0 == Failure
    }

    for (int i = 0; i != lenSrc; ++i) {

        // *(dest + i) = *(src + i);   // Ginge
        dest[i] = src[i];              // Index-Notation ist leichter lesbar
    }

    for (int i = 0; i != lenToAppend; ++i) {

        dest[lenSrc + i] = toAppend[i];
    }

    dest[lenToAppend + lenSrc] = '\0';

    return 1;  // 1 == Success
}

static void str_toUpper(char* src)
{

}


void test_zeichenketten_verarbeitung_vorsicht()
{
    char data[] = "abc";

    // str_toUpper(data);

    str_toUpper("ABC");
}



void test_zeichenketten_verarbeitung()
{ 
    const char* kette = "123";

    int len = str_length(kette);

    char result[7] = {};

    str_append("123", "XYZ", result, 7);

    printf("%s ==> %s = %s\n", kette, "XYZ", result);
}