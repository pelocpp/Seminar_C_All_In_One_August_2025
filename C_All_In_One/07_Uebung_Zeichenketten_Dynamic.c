// =====================================================================================
// ZeichenkettenverarbeitungDynamisch.c
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* str_append_01(const char* original, const char* toAppend)
{
    // Berechne Länge des Ergebnisstrings
    size_t lenTotal = strlen(original) + strlen(toAppend) + 1;

    // Speicher fuer Ergebniszeichenkette reservieren
    char* result = malloc(sizeof(char) * lenTotal);
    if (result == NULL) return NULL;

    // Speicher fuer Ergebniszeichenkette fuellen: Ersten Teil umkopieren
    int i = 0;
    while (original[i] != '\0') {
        result[i] = original[i];
        i++;
    }

    // Speicher fuer Ergebniszeichenkette fuellen: Zweiten Teil umkopieren
    int j = 0;
    while (toAppend[j] != '\0') {
        result[i] = toAppend[j];
        j++;
        i++;
    }

    // terminierende Null anhängen
    result[i] = '\0';

    return result;
}

static size_t str_append_02(const char* original, const char* toAppend, char** result)
{
    // Berechne Länge des Ergebnisstrings
    size_t lenTotal = strlen(original) + strlen(toAppend) + 1;

    // Speicher fuer Ergebniszeichenkette reservieren
    char* tmp = malloc(sizeof(char) * lenTotal);
    if (result == NULL) return -1;

    // Speicher fuer Ergebniszeichenkette fuellen: Ersten Teil umkopieren
    int i = 0;
    while (original[i] != '\0') {
        tmp[i] = original[i];
        i++;
    }

    // Speicher fuer Ergebniszeichenkette fuellen: Zweiten Teil umkopieren
    int j = 0;
    while (toAppend[j] != '\0') {
        tmp[i] = toAppend[j];
        j++;
        i++;
    }

    // Terminierende Null anhängen
    tmp[i] = '\0';

    // Heap-Zeigervariable nach aussen reichen
    *result = tmp;

    return lenTotal;
}

void exercise_zeichenkettenverarbeitung_dynamisch()
{
    char* result = NULL;

    // 1. Variante: einfachere Betrachtung
    result = str_append_01("Hello ", "World!");   // malloc
    printf("Ergebnis 1: %s\n", result);
    
    free(result);                                 // free

    // 2. Variante: Rückgabe des Ergebnisses durch einen Adress-Parameter
    result = NULL;
    size_t length = str_append_02("Hello ", "World!", &result);
    printf("Ergebnis 2: %s (Length: %zd)\n", result, length);
    free(result);
}

// =====================================================================================
// End-of-File
// =====================================================================================
