#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue *NewQueue(); // NewQueue chama init_queue. Para protação - não quero que seja chamada -, não está no header. Interessante! Quase um encapsulamento
void DeleteQueue(Queue *q);
int enqueue(Queue *q, int value);
int dequeue(Queue *q);


#endif
