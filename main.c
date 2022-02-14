// Bibliotecas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array_list_int.h"

int main(){
  time_t inicio,fim; // Tipo da lib 'time.h' para calcular o tempo
  int n, i, x, erro;
  array_list_int *l01 = array_list_create(); // Criando uma struct de array na variável 'l01'
  scanf("%d", &n); // Tamanho do array
  inicio = time(0);
  for ( i=0 ; i<n ; ++i ){ 
    scanf("%d",&x); // Laço para adicionar elementos no array
    if (array_list_push_back(l01, x) != (i + 1)){ // Se o elemento não for adicionado no array //
      fprintf(stderr,"\033[0;31mErro:\033[0m:\tValor %d não inserido!\n",x); // Mostrar erro e o elemento não inserido //
      fprintf(stderr,"\tA lista possui %d elementos.\n", array_list_size(l01)); // Senão, mostrar tamanho do array //
      exit(1);
    }
  }
  fim=time(0);
  // Imprime o tempo de processamento do laço anterior //
  fprintf(stderr,"Inserção de %d elementos em %.4lf ms.\n", n,(((double)fim-(double)inicio)/CLOCKS_PER_SEC)*1000);

  array_list_size(l01); // Tamanho do array
  array_list_find(l01, 5); // Encontrar indice elemento
  array_list_pop_back(l01); // Remove último elemento
  array_list_insert_at(l01, 3, 15); // Adiciona um valor
  array_list_remove_from(l01, 2); // Remove um elemento do indice
  array_list_capacity(l01); // Retorna o espaço efetivamente reservado para a lista.
  array_list_percent_occupied(l01); // Percentual do espaço reservado efetivamente ocupado por elementos da lista.

  for ( i=0 ; i < array_list_size(l01) ; ++i){
    x = array_list_get(l01, i, &erro); 
    if (!erro){ // Se não tiver erro na adição do elemento, imprime o array. //
      printf("%d ", x); 
    } else {
      fprintf(stderr,"ERRO: índice %d não é válido!\n",i); // Se tiver, imprime o índice onde o erro se encontra. //
      exit(2);
    }
  }
  printf("\n");
  return 0;
}
