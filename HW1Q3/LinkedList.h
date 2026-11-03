#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct PosIntNode
{
	unsigned int value;
	struct PosIntNode* next;
} PosIntNode;

void freeMemory(PosIntNode* head);
void insertAtStart(PosIntNode** head, PosIntNode* newNode);
void deleteHead(PosIntNode** head);
PosIntNode* createIntNode(int value);
void printList(PosIntNode* head);


#endif // LINKEDLIST_H
