#include <stdio.h>
#include "LinkedLIst.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    PosIntNode* first = NULL;
    PosIntNode* newNode = createIntNode(13);
    insertAtStart(&first, newNode);
    newNode = createIntNode(422);
    insertAtStart(&first, newNode);
    newNode = createIntNode(51);
    insertAtStart(&first, newNode);
    newNode = createIntNode(6);
    insertAtStart(&first, newNode);
    newNode = createIntNode(733);
    insertAtStart(&first, newNode);
    printList(first);
    deleteHead(&first);
    printList(first);

    return 0;
}

PosIntNode* createIntNode(int value)
{
    PosIntNode* newIntNode = new PosIntNode;
    newIntNode->value = value;
    newIntNode->next = NULL;
    return newIntNode;
}

void insertAtStart(PosIntNode** head, PosIntNode* newNode)
{
    if (!*head)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}

void deleteHead(PosIntNode** head)
{
    if (!*head)
    {
        return;
    }
    else
    {
        PosIntNode* temp = *head;
        *head = temp->next;
        delete temp;
    }
}

void printList(PosIntNode* head)
{
    PosIntNode* curr = head;
    printf("list\n");
    printf("--------\n");
    while (curr) // when curr == NULL, that is the end of the list, and loop will end (NULL is false)
    {
        printf("%d\n", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

void freeMemory(PosIntNode* head)
{
    PosIntNode* curr = head;
    PosIntNode* x = NULL;
    while (curr) // when curr == NULL, that is the end of the list, and loop will end (NULL is false)
    {
        x = curr->next;
        delete curr;
        curr = x;
    }
}
