#ifndef _ARRAY_LIST_INT_H_ 
#define _ARRAY_LIST_INT_H_

typedef struct array_list_int array_list_int;

/* Cria uma nova lista em memória. */
array_list_int * array_list_create();

/* Retorna um elemento localizado no índice index. */
int array_list_get(array_list_int * list, int index, int *error);

/* Adiciona um novo elemento ao final da lista. */
unsigned int array_list_push_back(array_list_int * list, int i);

/* Remove um elemento do final da lista, caso exista. */
unsigned int array_list_pop_back(array_list_int * list);

/* Retorna a quantidade de elementos na lista. */
unsigned int array_list_size(array_list_int * list);

/* Busca um elemento na lista. */
int array_list_find(array_list_int * list, int element);


/* Insere um novo elemento na lista, aumentando a quantidade de elementos. 
O elemento inserido deve se localizar no índice index. */
unsigned int array_list_insert_at(array_list_int * list, int index, int value);


/* Remove elemento localizado no índice index. */
unsigned int array_list_remove_from(array_list_int * list, int index);


/* Retorna o espaço efetivamente reservado para a lista. */
unsigned int array_list_capacity(array_list_int * list);


/* Retorna o percentual do espaço reservado efetivamente ocupado por elementos da lista. */
double array_list_percent_occupied(array_list_int * list); 

/* Libera memória usado pela lista list. */
void array_list_destroy(array_list_int * list); 

#endif
