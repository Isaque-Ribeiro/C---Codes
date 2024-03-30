/*
Execution of the alghorit mergesort. This code require two lines to test, the first is to get the quantity of numbers to be sorted
*/

#include "mergesort.h"

int main(){
  int len, *item, deep = 0;
  //initialize estructure data type: list
  tipoLista chaves = iniciaLista();

  // FIRST LINE REQUIRE THE NUMBER OF
  scanf("%i", &len);
  item = (int*)malloc(len*sizeof(int));

  //SECOND LINE REQUIRES NUMBERS TO BE SORTED
  for(int i=0; i<len; i++){
    scanf("%i", &item[i]);
    chaves = insereDado(chaves, item[i]);
  }
  
  printf("Imprime\n");
  chaves = MergeSort(chaves, len);
  imprimeLista(chaves);
  printf("\n");
  deep = measureProfundit(len);
  printf("Profundidade de recursão: %i", deep);
  liberaLista(chaves);
}
