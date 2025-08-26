#include <stdio.h>

static void test_char()
{
    char ch = '?';

    printf("ch: %c\n", ch);

    int n = ch;

    printf("n: %d\n", n);
}

static void test_ascii_table()
{
    for (int i = 0; i != 128; ++i) {
        printf("%02d: %c\n", i, i);
    }
}

static void test_schreibmaschine()
{
    printf("Schreibbbbbbbbbbbbbbbbbbb%c%cmaschine\n", 13, 10);

    printf("Schreibbbbbbbbbbbbbbbbbbb\nmaschine\n");

    // Oberes drehbares Teil:  Wagen

    // Oberes drehbares Teil nach links schieben:  Wagenrücklauf // Carriage Return
}

static void test_string()
{
    "12345";

    // a) Ausgabe einer Zeichenkette 
    printf("%s\n", "12345");

    // b) Eine Zeichenkette in einem Feld von Zeichen
    char vieleZeichen[] = "ABC";

    printf("%s\n", vieleZeichen);

    // c) Noch eine Zeichenkette in einem Feld von Zeichen
    // ACHTUNG: Dies ist KEINE Zeichenkette, weil die terminierende Null fehlt
    char weitereZeichen[] = { 'X', 'Y', 'Z' };

    printf(">>>%s<<<\n", weitereZeichen);

    // d) Nochmals eine Zeichenkette in einem Feld von Zeichen
    char andereZeichen[] = { 'a', 'b', 'c', 0 };

    printf(">>>%s<<<\n", andereZeichen);

    // e) Eine Zeichenkette definiert durch eine Adresse:

    const char* cp = "aaabbbccc";

    printf(">>>%s<<<\n", cp);

    // f) Eine Zeichenkette mit einer '\0' mitten drin:
    // Das ist ein Foul ;)

    const char* cp2 = "aaabbb\0ccc";

    printf(">>>%s<<<\n", cp2);   // Ausgabe: aaabbb

    // g) Nochmals eine Zeichenkette in einem Feld von Zeichen
    char wiederVieleZeichen[] = { 'Q', 'W', 'E', 0 };

    printf(">>>%s<<<\n", wiederVieleZeichen);

    // Vermutung: Wofür steht der Name 'wiederVieleZeichen' in Wirklichkeit ???
    // Der Name 'wiederVieleZeichen'  steht für die ADRESSE des ERSTEN Elements
    // in dem Feld 'wiederVieleZeichen':  
    // Der Name  'wiederVieleZeichen' repräsentiert eine ANFANGSADRESSE
}

static void test_string_02()
{
    const char* cp = "123";

    // Indirekter Zugriff auf einen Wert im Speicher mit Hilfe seiner Adresse:

    // *cp = '!';   // 0xc0000005 (Access Violation) // Why // Warum

    // der lesende Zugriff ist erlaubt
    // 
    char ch = *cp;

    // ==============================
    // Möchte man eine Zeichenkette verändern  // Verarbeitung
    char feld[] = "789";

    printf("%s\n", feld);

    feld[0] = '!';

    printf("%s\n", feld);
}


void test_char_string()
{
    test_string_02();
}