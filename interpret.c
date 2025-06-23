#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "interpret.h"
#include "stack.h"
#include "list.h"

static Stack *s = NULL;
static List *vars = NULL;

void interpreter_init() {
    s = new_stack(100);
    vars = new_list();
}

// Função auxiliar que verifica se string é número (inteiro)
static int is_number(const char* str) {
    if (!str || *str == '\0') return 0;
    int i = 0;
    if (str[0] == '-' || str[0] == '+') i = 1;
    for (; str[i]; i++) {
        if (!isdigit((unsigned char)str[i])) return 0;
    }
    return 1;
}

void interpret(const char *source) {
    char op[10];
    char arg[20] = {0};

    int n = sscanf(source, "%9s %19s", op, arg);

    if (n < 1) return; // linha vazia

    printf("operação: %s\n", op);
    if (n == 2) printf("argumento: %s\n", arg);

    if (strcmp(op, "push") == 0) {
        if (n != 2) {
            printf("Erro: push precisa de argumento\n");
            return;
        }

        if (is_number(arg)) {
            int val = atoi(arg);
            stack_push(s, val);
        } else {
            int val;
            if (get_variable(vars, arg, &val)) {
                stack_push(s, val);
            } else {
                printf("Variável não encontrada: %s\n", arg);
            }
        }
    }
    else if (strcmp(op, "pop") == 0) {
        if (n != 2) {
            printf("Erro: pop precisa de nome de variável\n");
            return;
        }
        int val = stack_pop(s);
        if (val == -1) {
            // pilha vazia, erro já reportado
            return;
        }
        set_variable(vars, arg, val);
        printf("Variável %s atualizada com valor %d\n", arg, val);
    }
    else if (strcmp(op, "add") == 0) {
        int b = stack_pop(s);
        int a = stack_pop(s);
        if (a == -1 || b == -1) return;
        stack_push(s, a + b);
    }
    else if (strcmp(op, "sub") == 0) {
        int b = stack_pop(s);
        int a = stack_pop(s);
        if (a == -1 || b == -1) return;
        stack_push(s, a - b);
    }
    else if (strcmp(op, "mul") == 0) {
        int b = stack_pop(s);
        int a = stack_pop(s);
        if (a == -1 || b == -1) return;
        stack_push(s, a * b);
    }
    else if (strcmp(op, "div") == 0) {
        int b = stack_pop(s);
        int a = stack_pop(s);
        if (a == -1 || b == -1) return;
        if (b == 0) {
            printf("Erro: divisão por zero\n");
            return;
        }
        stack_push(s, a / b);
    }
    else if (strcmp(op, "print") == 0) {
        int val = stack_pop(s);
        if (val == -1) return;
        printf("%d\n", val);
    }
    else if (strcmp(op, "exit") == 0) {
        printf("Saindo...\n");
        exit(0);
    }
    else {
        printf("Comando desconhecido: %s\n", op);
    }

    stack_print(s);
    list_print(vars);
}
