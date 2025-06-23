#ifndef list_h
#define list_h

typedef struct list List;

List* new_list();
void list_append (List* s, char* key, int value);
int list_get (List* s, char* key);
void list_set (List* s, char* key, int value);
int list_exist (List* s, char* key);
void list_print (List* s);

#endif
