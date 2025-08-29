#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include <stdio.h>
#include <stdlib.h>

// =======================================================
// types

struct ListItem
{
    int              m_value;
    struct ListItem* m_next;
};

struct LinkedList
{
    struct ListItem* m_root;
    size_t           m_count;
};

// =======================================================
// functions

static int  addHead         (struct LinkedList* anchor, int value);
static void printLinkedList (const struct LinkedList* anchor);
static void freeLinkedList  (struct LinkedList* anchor);

// NO GO static void readElemOfLinkedList(struct LinkedList* anchor, int pos); // Pos = Index 4000


static int addHead(struct LinkedList* anchor, int value)
{
    struct ListItem* item = (struct ListItem*) malloc(sizeof (struct ListItem));
    if (item == NULL) {
        return 0;
    }

    // fill item
    item->m_next = NULL;
    item->m_value = value;

    // if first item, connect with anchor
    if (anchor->m_root == NULL) {

        anchor->m_root = item;
    }
    else
    {
        item->m_next = anchor->m_root;

        anchor->m_root = item;
    }

    return 1;
}

static void printLinkedList(const struct LinkedList* anchor)
{
    // Inhalt der Liste ausgeben - mit Hilfe des Ankers
    struct ListItem* tmp = anchor->m_root;

    while (tmp != (struct ListItem*)0) {

        int value = tmp->m_value;
        printf("Value: %d\n", value);

        tmp = tmp->m_next;
    }
}

static void freeLinkedList(struct LinkedList* anchor)
{
    struct ListItem* tmp = anchor->m_root;
    struct ListItem* next = NULL;

    while (tmp != NULL) {

        next = tmp->m_next;

        free(tmp);

        tmp = next;
    }
}

// ===================================================================

static void test_linked_list_01()
{
    // Erster Versuch, eine solche Liste aufzubauen
    // Da kann man zu Demonstrationszwecken alle Elemente auf dem STACK hinlegen
    struct LinkedList anchor = { (struct ListItem*) 0, 0};

    // ein erstes Element anlegen:
    struct ListItem first = { 123, (struct ListItem*)0 };

    anchor.m_root = &first;
    anchor.m_count++;

    // ein zweites Element anlegen:
    struct ListItem second = { 456, (struct ListItem*)0 };

    // an das Ende der Liste anhängen
    first.m_next = &second;
    anchor.m_count++;

    // ein drittes Element anlegen:
    struct ListItem third = { 789, (struct ListItem*)0 };

    // an das Ende der Liste anhängen
    second.m_next = &third;
    anchor.m_count++;

    // ein viertes Element anlegen:
    struct ListItem fourth = { 999, (struct ListItem*)0 };

    // an das Ende der Liste anhängen
    third.m_next = &fourth;
    anchor.m_count++;

    // Inhalt der Liste ausgeben - mit Hilfe des Ankers
    struct ListItem* tmp = anchor.m_root;

    while (tmp != (struct ListItem*) 0) {

        int value = tmp->m_value;
        printf("Value: %d\n", value);

        tmp = tmp->m_next;
    }
}

static void test_linked_list_02()
{
    // anchor: Hier am Stack - mit malloc auf der Halde
    struct LinkedList anchor = { (struct ListItem*)0, 0 };

    addHead(&anchor, 1);
    addHead(&anchor, 2);
    addHead(&anchor, 3);
    addHead(&anchor, 4);
    addHead(&anchor, 5);
    addHead(&anchor, 6);
    addHead(&anchor, 7);
    addHead(&anchor, 8);
    addHead(&anchor, 9);
    addHead(&anchor, 10);

    printLinkedList(&anchor);

    freeLinkedList(&anchor);
}

static void test_linked_list_03()
{
    // anchor: Hier am Stack - mit malloc auf der Halde
    struct LinkedList anchor = { (struct ListItem*)0, 0 };

    addHead(&anchor, 1);
    addHead(&anchor, 2);

    printLinkedList(&anchor);

    freeLinkedList(&anchor);
}

void test_linked_list()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    test_linked_list_02();
}
