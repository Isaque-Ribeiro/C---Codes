// function's iplementation

#include "quicksort.h"


void imprimeLista(int* vet, int len){
  int i = 0;
  while(i<len){
    printf("%i ", vet[i]);
    i++;
  }
  printf("\n");
}


void swap(int* vet, int i, int j){
  int hand = vet[i];  
  vet[i] = vet[j];
  vet[j] = hand;
}

int CrashByEnd(int* vet, int begin, int end){
  int j= begin;
  for (int i=begin; i<end; i++){
    if(vet[i]<vet[end]){
      swap(vet, i, j);
      j++;
    }
  }
  swap(vet, j, end);
  return j;
}


void CrashByMedian(int* vet, int begin, int end){
  int middle = (begin+end)/2;

  if((vet[begin] >= vet[end] && vet[begin] <= vet[middle]) || (vet[begin] <= vet[end] && vet[begin] >= vet[middle]))
  {
    swap(vet, begin, end);
  }
  else if((vet[middle] >= vet[end] && vet[middle] <= vet[begin]) || (vet[middle] <= vet[end] && vet[middle] >= vet[begin]))
  {
    swap(vet, middle, end);
  }
}


int EndQuickSort(int* vet, int begin, int end){
  if(begin<end){
    int cont1 = 0, cont2 = 0;
    int middle = CrashByEnd(vet, begin, end);
    printf("%i ", middle);
    if(begin < middle-1){
      cont1 = countLR(vet, begin, middle-1, cont1);
    }
    if(middle+1 < end){
      cont2 = countLR(vet, middle+1, end, cont2);
    }

    printf("%i ", cont1);
    printf("%i\n", cont2);
    if(cont1>cont2){
      return cont1-cont2;
    }
    else {
      return cont2-cont1;
    }
  }
}



int countLR(int* vet, int begin, int end, int cont){
  if(begin<end){
    int middle = CrashByEnd(vet, begin, end);
    cont++;
    cont = countLR(vet, begin, middle-1, cont);
    cont = countLR(vet, middle+1, end, cont);
    return cont;
  }
}



int MedianQuickSort(int* vet, int begin, int end){
  if(begin<end){
    int cont1 = 0, cont2 = 0;
    if(begin<end-1){
      CrashByMedian(vet, begin, end);
    }
    int middle = CrashByEnd(vet, begin, end);

    cont1 = countLR(vet, begin, middle-1, cont1);
    cont2 = countLR(vet, middle+1, end, cont2);

    if(cont1>cont2){
      return cont1-cont2;
    }
    else {
      return cont2-cont1;
    }
  }
}
