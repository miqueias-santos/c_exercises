#include "linked_list.h"

int main() {
    Node *stack = NULL;

    char c;
    while (scanf(" %c", &c) != EOF) {
        if (stack != NULL) {
            if (stack->value == 'g' && c == 'b' || stack->value == 'b' && c == 'g') { RemoveAtBeginning(&stack); c = 'c'; }
            else if (stack->value == 'r' && c == 'b' || stack->value == 'b' && c == 'r') { RemoveAtBeginning(&stack); c = 'm'; }
            else if (stack->value == 'r' && c == 'g' || stack->value == 'g' && c == 'r') { RemoveAtBeginning(&stack); c = 'y'; }

            if (stack != NULL) {
                if (c == stack->value && stack->next != NULL) {
                    if (c == (stack->next)->value) {
                        RemoveAtBeginning(&stack);
                        RemoveAtBeginning(&stack);
                    }
                    else InsertAtBeginning(&stack, (int)c);
                }
                else InsertAtBeginning(&stack, (int)c);
            }
            else InsertAtBeginning(&stack, (int)c);
        }
        else InsertAtBeginning(&stack, (int)c);

        PrintList(stack);
        putc('\n', stdout);
    }
    printf("Thank You So Much For Playing My Game!\n");
    return 0;
}
