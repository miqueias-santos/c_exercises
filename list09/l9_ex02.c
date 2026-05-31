#include <stdio.h>
#include <stdlib.h>

typedef struct Tarefa {
    int id;
    int prioridade;
    struct Tarefa *prox;
} Tarefa;

typedef struct {
    Tarefa *head;
    Tarefa *tail;
} Queue; // Interessante. Além do usos que uma struct traz (associar um conjunto de variáveis sobre um identificador), passar uma struct por referência
// permite ter a referência a ser campos. Podeia fazer sem a struct queue, mas funções (como insere), que alteram os dois ponteiros ao mesmo tempo precisariam de duas referências

Tarefa *NewTarefa() {
    Tarefa *new = malloc(sizeof(Tarefa));
    new->prox = NULL;
    return new;
}

int Insere(Queue *q, int id, int prioridade) {
    Tarefa *new = NewTarefa();
    if (new == NULL) return 1;

    if (q->head == NULL) q->head = q->tail = new;
    else {
        q->tail->prox = new;
        q->tail = new;
    }
    new->id = id;
    new->prioridade = prioridade;

    return 0;
}

void Remover(Queue *q) {
    if (q->head == NULL) {
        puts("Fila vazia");
        return;
    }

    Tarefa *head = q->head;
    printf("Removida: id=%d prioridade=%d\n", head->id, head->prioridade);

    q->head = q->head->prox;
    free(head);
}

void Listar(Queue *q) {
    if (q->head == NULL) {
        puts("Fila vazia");
        return;
    }

    Tarefa *t = q->head;
    while(t != NULL) {
        printf("id=%d prioridade=%d\n", t->id, t->prioridade);
        t = t->prox;
    }
}

int main() {
    Queue q;
    q.head = NULL;
    q.tail = NULL;

    char op;
    int id, prior;

    scanf(" %c", &op);
    while (op != 'F') {
        if (op == 'I') {
            scanf("%d %d", &id, &prior);
            Insere(&q, id, prior);
        }
        else if (op == 'L') Listar(&q);
        else Remover(&q);

        scanf(" %c", &op);
    }
}
