#ifndef LISTA_H
#define LISTA_H

typedef struct list List;
// Cria uma nova lista vazia
List* new_list();
// Adiciona ou atualiza uma variável na lista
void set_variable(List* l, const char* key, int value);
// Busca o valor de uma variável; retorna 1 se achou, 0 caso contrário
int get_variable(List* l, const char* key, int* out_value);
// Imprime todas as variáveis (para debug)
void list_print(List* l);

#endif
