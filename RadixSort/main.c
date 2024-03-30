/*
This code is to ilustrate the use of method Radixsort, in sorting a list of words in a lexical order choosen.
The first line require te number of words to be sorted. Second line is to get the lexical order (sequence of letters as you want). Next lines get the words
to be sorted.
This radixsort implements a couting sort, in which no "if" are used, beeing a echonomical sorting method.
Output is the words sorted.
*/

#include "radixsort.h"

int main(){
  //CODIGO PARA ORDENAÇÃO LEXICAL DE PALAVRAS
  int num, point=0, biger;
  char *key, **words;
  
  scanf("%i", &num);
  getchar();
  key = (char*)malloc(26*sizeof(char));
  scanf("%s", key);

  words = (char**)malloc(num*sizeof(char*));
  for(int i=0; i<num; i++){
    words[i] = (char*)malloc(20*sizeof(char));
    scanf("%s", words[i]);
  }
  
  fLower(words, num);
  biger = findBiger(words, num);
  words = RadixSort(words, key, biger, num);

  for(int i=0; i<num; i++){
    printf("%s\n", words[i]);
  }
  for(int i=0; i<num; i++){
    free(words[i]);
  }
  free(words);
  free(key);
  return 0;
}
