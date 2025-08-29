// =====================================================================================
// 08_Uebung_Phonebook.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>  // malloc, free
#include <crtdbg.h>
#include <string.h>

// ==========================================
// Kontakte-Verwaltung

#define MaxEntries           10
#define MaxNameBufferLength  32

#define NotEmpty             0
#define Empty                1

struct Entry
{
    char*     m_firstName;
    char*     m_lastName;
    size_t    m_phone;
    int       m_isEmpty;    // NotEmpty vs. Empty
};

// global
struct Entry g_phoneBook[MaxEntries];

// ==========================================
// function prototypes

static void initPhonebook();
static void enterEntry();
static void searchEntry();
static void printEntry(struct Entry* contact);
static void printEntries();
static void clearEntries();
static void printfMenu();

// ==========================================

static void initPhonebook()
{
    for (int i = 0; i < MaxEntries; i++) {

        g_phoneBook[i].m_isEmpty = Empty;
    }
}

static void enterEntry()
{
    char buffer[MaxNameBufferLength] = { '\0' };
    int  number;
    char* ptrFirstName;
    char* ptrLastName;

    printf("Bitte Vornamen eingeben: ");
    scanf_s("%s", buffer, MaxNameBufferLength);

    // allocate dynamic memory according to the exact size of the name
    size_t lenFirstName = 1 + strlen(buffer); // includíng '\0' !!!
    ptrFirstName = (char*)malloc(lenFirstName * sizeof(char));
    if (ptrFirstName == NULL) {
        return;
    }
    strcpy_s(ptrFirstName, lenFirstName * sizeof(char), buffer);

    printf("Bitte Nachnamen eingeben: ");
    scanf_s("%s", buffer, MaxNameBufferLength);

    // allocate dynamic memory according to the exact size of the name
    size_t lenLastName = 1 + strlen(buffer); // includíng '\0' !!!
    ptrLastName = (char*)malloc(lenLastName * sizeof(char));
    if (ptrLastName == NULL) {
        return;
    }
    strcpy_s(ptrLastName, lenLastName * sizeof(char), buffer);

    printf("Bitte Tel.Nummer eingeben: ");
    scanf_s("%d", &number);

    struct Entry tmp = { ptrFirstName , ptrLastName, number, NotEmpty };

    // enter temporary contact into global array
    int succeeded = 0;

    for (int i = 0; i < MaxEntries; i++) {

        if (g_phoneBook[i].m_isEmpty == Empty) {

            g_phoneBook[i] = tmp;
            succeeded = 1;
            break;
        }
    }

    if (succeeded == 0) {
        printf("Contacts Folder full !\n");
    }
}

static void searchEntry()
{
    char firstName[MaxNameBufferLength] = { 0 };
    char lastName[MaxNameBufferLength] = { 0 };;

    printf("Bitte Vornamen eingeben: ");
    scanf_s("%s", firstName, MaxNameBufferLength);

    printf("Bitte Nachnamen eingeben: ");
    scanf_s("%s", lastName, MaxNameBufferLength);

    // search corresponding contact in global array
    int succeeded = 0;

    for (int i = 0; i < MaxEntries; i++) {

        if (g_phoneBook[i].m_isEmpty == NotEmpty) {

            struct Entry tmp = g_phoneBook[i];

            if (strcmp(tmp.m_firstName, firstName) == 0 && strcmp(tmp.m_lastName, lastName) == 0)
            {
                printf("%s %s hat die Telefonnummer %zu\n", firstName, lastName, tmp.m_phone);
                succeeded = 1;
                break;
            }
        }
    }

    if (succeeded == 0) {
        printf("%s %s im Telefonbuch nicht gefunden!\n", firstName, lastName);
    }
}

static void printEntry(struct Entry* contact)
{
    printf("   Vorname:  %s\n", contact->m_firstName);
    printf("   Nachname: %s\n", contact->m_lastName);
    printf("   Phone:    %zu\n", contact->m_phone);
    printf("\n");
}

static void printEntries()
{
    for (int i = 0; i < MaxEntries; i++) {

        if (g_phoneBook[i].m_isEmpty == 0) {

            printEntry(&g_phoneBook[i]);
        }
    }
}

static void clearEntries()
{
    for (int i = 0; i < MaxEntries; i++) {

        if (g_phoneBook[i].m_isEmpty == 0) {

            free(g_phoneBook[i].m_firstName);
            free(g_phoneBook[i].m_lastName);

            g_phoneBook[i].m_firstName = NULL;
            g_phoneBook[i].m_lastName = NULL;

            g_phoneBook[i].m_isEmpty = Empty;
        }
    }
}

static void printfMenu()
{
    initPhonebook();

    int fertig = 1;   // 1 == nicht fertig, 0 ist fertig

    while (fertig != 0) {

        // printf - menu :)
        printf("\n\n");
        printf("Meine Kontakte:\n\n");
        printf("Bitte Aktion waehlen:\n");
        printf("(1) = Kontakte ausgeben\n");
        printf("(2) = Kontakt eingeben\n");
        printf("(3) = Kontakt suchen\n");
        printf("(4) = Alle Kontakte loeschen\n");
        printf("(5) = Programm verlassen\n");

        int aktion = -1;

        scanf_s("%d", &aktion);

        switch (aktion)
        {
        case 1:
            printEntrys();
            break;
        case 2:
            enterEntry();
            break;
        case 3:
            searchEntry();
            break;
        case 4:
            clearEntries();
            break;
        case 5:
            clearEntries();
            fertig = 0;
            break;
        default:
            printf("Menue unbekannt: %d\n", aktion);
            break;
        }
    }
}

void exercise_contacts_dynamic()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    printfMenu();
}

// =====================================================================================
// End-of-File
// =====================================================================================
