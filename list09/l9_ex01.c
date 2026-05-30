#include "queue.h"

int main() {
    // Queue q; Assim poderia ser, mas só para evitar passar por referência
    Queue *q = NewQueue();
    enqueue(q, 8);
    DeleteList(&q->front); // Sem funções como DeleteQueue ou NewQueue
    free(q);
    return 0;
}
