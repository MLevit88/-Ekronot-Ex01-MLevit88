#include <stdio.h>
#include "Queue.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

/*int main()
{
    bool cont = true; // flag to ask the user if he want to continue
    int maxSize = 0, currNum = 0, choise = 0;
    cout << "Enter queue max size\n";
    cin >> maxSize;
    Queue*q = new Queue;
    initQueue(q, maxSize);
    while (cont)
    {
        cout << "1 for enqueue; 2 for dequeue; 3 for printing the elemnts; any other number for stoping\n";
        cin >> choise;
        switch (choise) 
        {
            case 1:
                cout << "Enter new element\n";
                cin >> currNum;
                enqueue(q, currNum);
                break;
            case 2:
                cout << "Removed element: " << dequeue(q) << "\n";
                break;
            case 3:
                for (int i = 0; i < q->currentSize; i++)
                {
                    int index = (q->front + i) % q->capacity;
                    cout << i << ":" << q->elements[index] << "\n";
                }
                break;
            default:
                cont = false;
            }
    }
    for (int i = 0; i < q->currentSize; i++)
    {
        int index = (q->front + i) % q->capacity;
        cout << i << ":" << q->elements[index] << "\n";
    }
    
    return 0;
}*/

void initQueue(Queue* q, unsigned int size)
{
    q->elements = new int[size];
    q->currentSize = 0;
    q->capacity = size;
    q->front = 0;
    q->rear = -1;
    /* Return the pointer */
}

void enqueue(Queue* q, unsigned int newValue)
{
    if (isFull(q))
    {
        cout << "Queue is full\n";
    }
    else
    {
        q->currentSize++;
        q->rear++;

        if (q->rear == q->capacity)
        {
            q->rear = 0;
        }

        q->elements[q->rear] = newValue;
    }
    return;

}

int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        cout << "Queue is Empty\n";
        return -1;
    }

    int poppedValue = q->elements[q->front];

    q->front++;
    q->currentSize--;
    if (q->front == q->capacity)
    {
        q->front = 0;
    }

    return poppedValue;
}
    

void cleanQueue(Queue* q)
{
    delete[] q->elements;
    delete q;
}

bool isFull(Queue* s)
{
    return s->capacity == s->currentSize;
}
bool isEmpty(Queue* s)
{
    return s->currentSize == 0;
}
