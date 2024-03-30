// function's implementation

#include "radixsort.h"

void fLower(char **mat, int lines){
  int cont1=0, cont2=0, cont3=0;
  char *lower;
  lower = (char*)malloc((lines*20)*sizeof(char));

  while(cont1<lines){
    if(cont2 >= strlen(mat[cont1])){
      cont1++;
      cont2 = 0;
    }
    if(cont1>=lines){
      break;
    }
    lower[cont3] = mat[cont1][cont2];
    cont3++;
    cont2++;
  }//TRANFERE LISTA DE PALAVRAS PARA UM VETOR CARACTERE POR CARACTERE

  for(int i=0; i<strlen(lower); i++){
    if(lower[i]>64 && lower[i]<91){
      lower[i] = lower[i] + 32;
    }
  }
  cont1 = 0;
  cont2 = 0; 
  cont3 = 0;
  while(cont3<strlen(lower)){
    if(cont2 >= strlen(mat[cont1])){
      cont1++;
      cont2 = 0;
    }
    if(cont1>=lines){
      break;
    }
    mat[cont1][cont2] = lower[cont3];
    cont3++;
    cont2++;
  }//RETORNAR OS CARACTERES EM MINUSCULO PARA A LISTA DE PALAVRAS 

}


int findBiger(char **mat, int lines){
  int biger=0, cont1=0, cont2=0, cont3=0, times=0;

  for(int i=0; i<lines; i++){
    if(strlen(mat[i]) > biger){
      biger = strlen(mat[i]);
    }
  }
  printf("%i\n", biger);
  for(int i=0; i<lines; i++){
    times = times + (biger - (strlen(mat[i])));
  }//TOTAL DE ESPAÇOS PARA COMPLETAR TODA A LISTA DE PALVRAS

  cont2 = strlen(mat[cont1]);
  while(cont3 < times){
    if(cont2 < biger){
      mat[cont1][cont2] = ' ';
      cont2++;
      cont3++;
    }
    else{
      cont1++;
      cont2 = strlen(mat[cont1]);
    }
  }
  return biger;
}



char findnKey(char ob, char* vet){
  for(int i=0; i<strlen(vet); i++){
    if(ob == vet[i]){
      return i;
    }
  }
}



char** CountingSort(char **mat, char *key, int lines, int column){
  char **Baux;
  int *Caux;
  int cont1=0, cont2=0;

  Caux = (int*)malloc(27*sizeof(int));
  for(int i=0; i<27; i++){
    Caux[i] = 0;
  }

  while(cont1 < lines){
    if(mat[cont1][column] == ' '){
      Caux[0]++;
    }
    else{
      cont2 = findnKey(mat[cont1][column], key);
      Caux[cont2+1]++;
    }
    cont1++;
  }//CONFERE DIGITOS NA ORDEM LEXICOGRAFICA E COMPUTA EM C


  for(int i=1; i<27; i++){
    Caux[i] = Caux[i] + Caux[i-1];
  }
  for(int i=0; i<27; i++){
    printf("%i ", Caux[i]);
  }
  printf("\n");

  //PARTE 4
  Baux = (char**)malloc(lines*sizeof(char*));
  cont1 = lines-1;
  cont2 = 0;
  while(cont1 >= 0){
    if(mat[cont1][column] == ' '){
      Baux[Caux[0]-1] = mat[cont1];
      Caux[0]--;
    }
    else{
      cont2 = findnKey(mat[cont1][column], key);
      Baux[Caux[cont2+1]-1] = mat[cont1];
      Caux[cont2+1]--;
    }
    cont1--;
  }
  return Baux;
  //FIM PARTE 4
}


char** RadixSort(char** mat, char *key, int biger, int lines){
  for(int i=biger-1; i>=0; i--){
    mat = CountingSort(mat, key, lines, i);
  }
  return mat;
}
