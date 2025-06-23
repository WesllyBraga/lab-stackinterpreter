#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack
{
    int *values;
    int capacity;
    int top;
};

Stack *new_stack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
        return NULL;

    stack->values = (int *)malloc(size * sizeof(int));

    if (!stack->values)
    {
        free(stack);
        return NULL;
    }

    stack->top = -1;
    stack->capacity = size;

    return stack;
}

void stack_push(Stack *s, int value)
{
    if (s->top >= s->capacity - 1)
    {
        printf("Pilha cheia\n");
        return;
    }
    else
    {
        s->values[++s->top] = value;
        printf("Valor %d empilhado.\n", value);
    }
}

int stack_pop(Stack *s)
{
    if (s->top < 0)
    {
        printf("Erro: pilha vazia!\n");
        return -1;
    }
    return s->values[(s->top)--];
}

void stack_print(Stack *s)
{
    if (s->top < 0)
    {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->values[i]);
    }
    printf("\n");
}
