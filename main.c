#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array_list_int.h"

int main(){
  time_t inicio,fim;
  int n,i,x,erro;
  array_list_int *l01 = array_list_create();
  scanf("%d",&n);
  inicio = time(0);
  for ( i=0 ; i<n ; ++i ){
    scanf("%d",&x);
    if (array_list_push_back(l01,x)!=(i+1)){
      fprintf(stderr,"\033[0;31mErro:\033[0m:\tValor %d não inserido!\n",x);
      fprintf(stderr,"\tA lista possui %d elementos.\n",array_list_size(l01));
      exit(1);
    } 
  }
  printf("d = %f\n", array_list_percent_occupied(l01));
  fim=time(0);
  
  printf("Tamanho = %d\n", array_list_size(l01));
  // printf("Indice que o elemento se encontra = %d\n",array_list_find(l01, 5)); // Encontrar indice elemento
  // array_list_pop_back(l01); // Remove último elemento
  // array_list_insert_at(l01, 3, 15); // Adiciona um valor
  // array_list_remove_from(l01, 2); // Remove um elemento do indice
  // printf("porcent = %.5f \n", array_list_percent_occupied(l01));
  for ( i=0 ; i<array_list_size(l01) ; ++i){
    x = array_list_get(l01,i,&erro);
    if (!erro){
      printf("%d ",x);
    } else {
      fprintf(stderr,"ERRO: índice %d não é válido!\n",i);
      exit(2);
    }
  }
  printf("\n");
  fprintf(stderr,"Inserção de %d elementos em %.4lf milisegundos.\n", n,(((double)fim-(double)inicio)/CLOCKS_PER_SEC)*1000);
  return 0;
}
