#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

struct node {
    char key [15];
    int value;
    struct node* next;
};
struct list {
    struct node* first;
};

static struct node* list_find (List* l, char* key) {
    struct node* next = l->first;
    while (next) {
        if (strcmp(next->key, key) == 0)
            return next;
        next= next->next;    
    }
    return NULL;
    
}   

List* new_list () {
    List* l = calloc (1, sizeof(List));
    l->first = NULL
    return l;
}

void list_append (List* l, char* key, int value) {
    struct node* node = calloc (1, sizeof(struct node));
    strcpy(node->key, key);
    node->value = value;
    node->next = l->first;
    l->first = node;
    
}

int list_get (List* l, char* key){
    struct node* n;
    if ((n = list_find(l, key)) != NULL) {
        return n->value;
        
    } 
    return -1;
}


void list_set (List* l, char* key, int value){
    struct node* n;
    if ((n = list_find(l, key)) != NULL) {
         n->value = value;
        
    } 
    
}

int list_exist (List* l, char* key){
    return list_find(l, key) != NULL;
}

void list_print (List* l){
    struct node* next = l->first;
    while (next) {
        printf("%s -> %d\n",next->key, next->value);
        next = next->next;
    }
}

