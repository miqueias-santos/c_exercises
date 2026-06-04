#include "queue.h"

// Se faz necessário. Supõe-se que uma fila vazia tem front == NULL (também, em menos importância, rear == NULL)
void init_queue(Queue *q) { // A FUNÇÃO NÃO ESTÁ DECLARADA NO CABEÇARIO. É INVISÍVEL A PROGRAMAS FORA DE QUEUE.C
    q->front = NULL;
    q->rear = NULL;
}

Queue *NewQueue() {
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL) printf("Erro ao alocar queue.\n");
    else init_queue(q);
    return q;
}
void DeleteQueue(Queue *q) {
    DeleteList(&q->front);
    free(q);
}

int enqueue(Queue *q, int value) {
    Node *new = NewNode(value);
    if (new == NULL) return 1;
    new->next = NULL;

    if(IsEmptyList(q->front)) q->front = q->rear = new;
    else {
        // enqueue vai costurando uma linked list
        q->rear->next = new;
        q->rear = new;
    }
    return 0;
    // Interessante, poderia usar as funções da linked list, mas com um ponteiro para última struct, me livra do custo de usar InsertAtEnd (O(n), percorrendo a lista)
}

// Retorna 1 caso erro e valor removido da fila em caso de sucesso
int dequeue(Queue *q) {
    int value_deleted = q->front->value;
    if (IsEmptyList(q->front)) {
        printf("Queue underflow, vazia.\n");
        return 1;
    }
    else RemoveAtBeginning(&q->front);

    if(IsEmptyList(q->front)) q->rear = NULL; // Sutileza. Do contrário, rear apontaria para um nó "morto", já dado free
    return value_deleted;
}
// Só usei NewNode, IsEmptyList e RemoveAtBeginning. Não preciso das funções de manipular linked lists, só dá lógica dos nós


// Uma cobrinha na memória kk
