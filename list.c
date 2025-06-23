#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct node {
    char key[15];
    int value;
    struct node* next;
};

struct list {
    struct node* first;
};

static struct node* list_find(List* l, const char* key) {
    struct node* cur = l->first;
    while(cur) {
        if(strcmp(cur->key, key) == 0) return cur;
        cur = cur->next;
    }
    return NULL;
}

List* new_list() {
    List* l = calloc(1, sizeof(List));
    l->first = NULL;
    return l;
}

void set_variable(List* l, const char* key, int value) {
    struct node* n = list_find(l, key);
    if(n) {
        n->value = value; // atualiza
    } else {
        // cria novo nó
        struct node* new_node = calloc(1, sizeof(struct node));
        strncpy(new_node->key, key, 14);
        new_node->key[14] = '\0';
        new_node->value = value;
        new_node->next = l->first;
        l->first = new_node;
    }
}

int get_variable(List* l, const char* key, int* out_value) {
    struct node* n = list_find(l, key);
    if(n) {
        *out_value = n->value;
        return 1;
    }
    return 0;
}

void list_print(List* l) {
    struct node* cur = l->first;
    printf("Variáveis:\n");
    while(cur) {
        printf("  %s = %d\n", cur->key, cur->value);
        cur = cur->next;
    }
}
