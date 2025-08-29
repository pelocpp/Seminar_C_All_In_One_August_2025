#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct entry
{
    char*   m_firstName;
    char*   m_lastName;
    size_t  m_number;
    int     m_isEmpty;     // 0 == ist frei, ungleich 0: ist belegt.
};

#define MaxEntries 10

// Syntax: ALT NEU
typedef struct entry Entry;

struct entry g_entries[MaxEntries];  // mehr wie 100 geht da mal nicht ...

void addEntry()
{
    struct entry nextEntry = { NULL, NULL, 0, 0 };

    // Eingabe einer Zeichenkette (ohne Leerzeichen)
    printf("Eingabe Vorname: ");
    char buffer[64];
    scanf_s("%s", buffer, 64);
    printf("Vorname: %s\n", buffer);

    // Länge des Namens
    int len = strlen(buffer);

    char* tmp = (char*) malloc(sizeof(char) * (len + 1));  // +1 für term. Nullzeichen.

    strcpy_s(tmp, len + 1, buffer);  // Buffer (Stack) nach tmp (Heap) umkopiert

    nextEntry.m_firstName = tmp;

    // dieser Eintrag ist nun belegt
    nextEntry.m_isEmpty = 1;

    // diesen Eintrag in das globale Array g_entries umkopieren
    int emptySlot = 0;

    while (emptySlot != MaxEntries) {

        if (g_entries[emptySlot].m_isEmpty == 0) {

            g_entries[emptySlot] = nextEntry;
            break;
        }

        ++emptySlot;
    }

    if (emptySlot == MaxEntries) {
        printf("Telefonbuch ist voll !\n");
    }
}

void main_array_of_structs()
{
    printf("Telefonbuchverwaltung:\n");

    while (1) {

        printf("Menue:\n");
        printf("1:  Eintrag eingeben:\n");
        printf("2:  Alle Eintraege ausgeben:\n");
        printf("3:  Tel.Nr. suchen:\n");
        printf("8:  Buch loeschen:\n");
        printf("10: Programm verlassen:\n");
        printf("\n");
        printf("Eingabe: \n");

        int n = 0;
        scanf_s("%d", &n);
        printf("Ihre Eingabe: %d\n", n);
        printf("\n");

        switch (n)
        {
        case 1:
            addEntry();
            break;

        case 10:
            break;
        }

        if (n == 10) {
            break;
        }

    }


    printf("Done.\n");
}
