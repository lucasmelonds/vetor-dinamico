


// Bibliotecas
#include "array_list_int.h"
#include <stdlib.h>

// Struct para coletar os elementos, tamanho e capacidade do array.
struct array_list_int {
    int * data;
    unsigned int size,capacity;
};

// Função para aumentar a memória
int increase_memory(array_list_int *list){
  return 0;
}

struct array_list_int * array_list_create(){
  /* Cria uma nova lista 'new_list' para armazenar o endereço da memória alocada */
  array_list_int *new_list = (array_list_int*)malloc(sizeof(array_list_int));
  /* Se apontar para nada, retorna 0. */
  if (new_list==0)
    return 0;
  /* Chamando a função 'malloc', ele vai reservar espaço para 10 elementos do tipo int */
  new_list->data = (int*)malloc(sizeof(int)*10);
  /* Se não tiver nada, libera a memória usada e retorna 0. */
  if (new_list->data==0){ 
    free(new_list);
    return 0;
  }
  /* Tamanho inicialmente igual a 0. */
  new_list->size=0;
  /* Capacidade inicialmente igual a 10. */
  new_list->capacity = 10;
  /* Retorna a lista recém criada. */
  return new_list;
}

/* Função para pegar um elemento de um índice.
Parâmetros: 'array_list_int * list' é um ponteiro do endereço de memória da lista.
            'int index' é o índice de um elemento do tipo inteiro.
            '*error' aponta para um espaço de memória. */
int array_list_get(array_list_int * list, int index, int *error){
    *error=0;
    /* Caso o índice seja menor que 0 ou maior que o tamanho da lista '*error' = 1.
    Lembrando que a quantidade de elementos determina os índices válidos. Se eu tiver 5 elementos,
    os índices é de 0 a 4. Nunca menor, nem maior. */
    if (index < 0 || index >= list->size){
        *error = 1;
        return 0;
    }
    /* Retorna um elemento localizado no índice 'index'.  */
    return list->data[index];
}

/* Função para adicionar elemento no final da lista.
Parâmetros: 'array_list_int * list' é um ponteiro do endereço de memória da lista.
            'int value' valor a ser adicionado. */
unsigned int array_list_push_back(array_list_int * list, int value){
  /* Se a capacidade da lista ultrapassar o tamanho da lista, a lista vai aumentar o tamanho na memória e retorná-la. */
  if (list->capacity == list->size){
    if (!increase_memory(list))
      return array_list_size(list);
  }
  /* Adiciona o valor no último índice da lista (já que ela aumentou +1) */
  list->data[list->size] = value;
  /* Incrementa o tamanho */
  list->size++;
  /* Retorna com o novo tamanho da lista */
  return array_list_size(list);
}

/* Função para remover elemento no final da lista, caso exista.
Parâmetro: 'array_list_int * list' é um ponteiro do endereço de memória da lista.  */
unsigned int array_list_pop_back(array_list_int * list){
  /* Se o tamanho da lista for menor ou igual a 1, deve retornar a lista com o único elemento da lista ou
  com nada, se for menor que 1. */
  if (list->size <= 1) return array_list_size(list);
  /* Senão, decrementa o tamanho, removendo o último elemento. */
  list->size--;
  /* Retorna com a lista sem o último elemento. */
  return array_list_size(list);
}

/* Função que retorna a quantidade de elementos na lista. */
unsigned int array_list_size(array_list_int * list){
    return list->size;
}

/* Função para buscar elemento da lista.
Parâmetro: 'array_list_int * list' é um ponteiro do endereço de memória da lista. 
           'element' é o elemento a ser buscado. */
int array_list_find(array_list_int * list, int element){
  int i;
  /* Percorre toda lista pelos índices */
  for (i = 0 ; i < list->size ; i++) {
    /* Se o valor que está no índice for igual ao elemento, retorna o índice onde se encontra. */
    if (list->data[i] == element) return i;
  }
  /* Senão, retorna -1. */
  return -1;
}

/* Função para inserir um novo elemento na lista, aumentando a quantidade de elementos.
Parâmetro: 'array_list_int * list' é um ponteiro do endereço de memória da lista. 
           'int index' é o indice onde o valor tem que ser adicionado.
           'int value' é o valor a ser adicionado. */
unsigned int array_list_insert_at(array_list_int * list, int index, int value){
    int i, k;
    /* Percorre começando pelo tamanho da lista até o índice, e vai decremetando. */
    for (i = list->size ; i > index ; i--) 
      /* Então, quando tiver no índice vai 'mover' os elementos para direita. */
      list->data[i] = list->data[i-1];
    /* Adiciona o valor no índice desejado */
    list->data[index] = value;
    /* Aumenta o tamanho da lista */
    list->size++;
    return 0;
}

/* Função para remover um novo elemento da lista pelo indice.
Parâmetro: 'array_list_int * list' é um ponteiro do endereço de memória da lista. 
           'int index' é o indice que tem que ser removido. */
unsigned int array_list_remove_from(array_list_int * list, int index){
  int i;
  /* Percorre começando pelo indice até o tamanho da lista. */
  for (i = index; i < list->size ; ++i) {
      /* Então, quando percorrer toda lista, vai 'deslocar' para esquerda. */
      list->data[i] = list->data[i+1];
    }
  /* Assim, a lista vai remover o elemento que está no último indice (O que foi escolhido, por causa do laço.) */
  list->size--;
  /* Retorna o novo tamanho da lista. */
  return array_list_size(list);
}

/* Função para retornar o espaço efetivamente reservado para a lista. */
unsigned int array_list_capacity(array_list_int * list) {
  return list->capacity;
}

/* Função que retorna o percentual do espaço reservado efetivamente ocupado por elementos da lista. */
double array_list_percent_occupied(array_list_int * list){
  double percent = (100 * list->size) / list->capacity;
  return percent;
}

/* Função que libera memória usado pela lista 'list'. */
void array_list_destroy(array_list_int * list){
  /* Função 'free' libera o bloco de memória alocada. */
  free(list);
}



