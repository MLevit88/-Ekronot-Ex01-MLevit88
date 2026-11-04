#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void initStack(Stack* s)
{
	s->head = NULL;

}

bool isEmpty(Stack* s)
{ 
	return s->head == NULL;
}

bool isFull(Stack* s)
{
	// Assuming the stack is implemented as a linked list, it's never full
	return false;
}

void push(Stack* s, unsigned int element)
{
	PosIntNode* newNode = createIntNode(element);
	insertAtStart(&(s->head), newNode);
 }
int pop(Stack* s)// Return -1 if stack is empty
{
	if (isEmpty(s))
	{
		return -1;
	}
	else
	{
		int value = s->head->value;
		deleteHead(&(s->head));
		return value;
	}
}

void cleanStack(Stack* s)
{
	freeMemory(s->head);
	s->head = NULL;
}