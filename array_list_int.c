#include "array_list_int.h"
#include <stdlib.h>

struct array_list_int {
    int * data;
    unsigned int size,capacity;
};

int increase_memory(array_list_int *list){
  return 0;
}


struct array_list_int * array_list_create(){
  array_list_int *new_list = (array_list_int*)malloc(sizeof(array_list_int));
  if (new_list==0)
    return 0;
  new_list->data = (int*)malloc(sizeof(int)*10000);
  if (new_list->data==0){ 
    free(new_list);
    return 0;
  }
  new_list->size=0;
  new_list->capacity = 10000;
  return new_list;
}


int array_list_get(array_list_int * list, int index, int *error){
    *error=0;
    if (index<0 || index>=list->size){
        *error=1;
        return 0;
    }
    return list->data[index];
}


unsigned int array_list_push_back(array_list_int * list, int value){
  if (list->capacity==list->size){
    if (!increase_memory(list))
      return array_list_size(list);
  }
  list->data[list->size] = value;
  list->size++;
  return array_list_size(list);
}


unsigned int array_list_pop_back(array_list_int * list){
  if (list->size <= 1) return array_list_size(list);
  list->size--;
  return array_list_size(list);
}


unsigned int array_list_size(array_list_int * list){
    return list->size;
}

int array_list_find(array_list_int * list, int element){
  int i;
  for (i = 0 ; i < list->size ; i++) {
    if (list->data[i] == element) return i;
  }
  return -1;
}

unsigned int array_list_insert_at(array_list_int * list, int index, int value){
    int i;
      for (i = list->size ; i > index ; i--) list->data[i] = list->data[i-1];
    list->data[index] = value;
    list->size++;
    return 0;
}

unsigned int array_list_remove_from(array_list_int * list, int index){
  int i;
  for (i=index; i < list->size ; ++i) {
      list->data[i] = list->data[i+1];
    }
  list->size--;
  return array_list_size(list);
}

unsigned int array_list_capacity(array_list_int * list) {
  return list->capacity;
}

double array_list_percent_occupied(array_list_int * list){
  double percent = (100 * list->size)/list->capacity;
  return percent;
}

void array_list_destroy(array_list_int * list){
  free(list);
} 
