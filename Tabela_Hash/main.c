/*
This code ilustrate the use of a Hash Table. Here are the functions used and the main, in which the functions are tested.
The first line is to get number of data to be inserted on the hash table. Second line gets numbers to be inserted. Third line get a number
to be searched, and if foudn, removed.
Output is the hash table.
*/

#include <stdio.h>
#include <stdlib.h>

int hash1(int, int);
int hash2(int , int);
int hashF(int, int, int);
void insere(int*, int , int);
int* fBusca(int*, int, int);
void remover(int*, int*, int);
void imprimir(int*, int);


int main(void) {
  int m, k, a, busca, *positions *tabelaH;

  scanf("%i", &m);
  tabelaH = (int*)malloc(m*sizeof(int));
  for(int j=0; j<m; j++){
    tabelaH[j] = -1;
  }
  
  scanf("%i", &k);
  while(k >= 0){
    insere(tabelaH, k, m);
    scanf("%i", &k);
  }

  scanf("%i", &busca);
  positions = fBusca(tabelaH, busca, m);
  if(fBusca(tabelaH, busca, m) > 0){
    remover(tabelaH, busca, m);
  }
  printf("\n");
  imprimir(tabelaH, m);
  printf("\n");
  
  free(tabelaH);
  return 0; 
}


int hash1(int chave, int len){
  return (chave % len);
}


int hash2(int chave, int len){
  return (1 + (chave % (len - 1)));
}


int hashF(int chave, int indice, int len){
  int a, b;
  a = hash1(chave, len);
  b = hash2(chave, len);
  return ((a + indice*b) % len);
}



void insere(int* tabela, int chave, int len){
  int i=0, indice;
  while(i < len){
    indice = hashF(chave, i, len);
    if(tabela[indice] == -1){
      tabela[indice] = chave;  
      break;
    }
    else{
     i++;
    }
  }
}

int* fBusca(int* tabela, int busca, int len){
  int i=0, j=0, indice;
  int apoio[len], *positions;
  while(i < len){
    indice = hashF(busca, i, len);
    if(tabela[indice] == busca){
      apoio[j] indice;
      j++;
    }
    i++;
  }
  positions = (int*)malloc((j+1)*sizeof(int));
  for(int w = 0; w<j; w++){
    positions[w] = apoio[w];
  }
  positionss[j+1] = j;
  if(j == 0){
    printf( "Valor nao encontrado");
    return 0;
  }
}

void imprimir(int* tabela, int len){
  for(int i=0; i<len; i++){
    if(tabela[i] >= 0)
      printf("%i ", tabela[i]);
    else{
      if(tabela[i] == -1)
        printf("/ ");
      else if (tabela[i] == -2)
        printf("D ");
    }
  } 
}


void remover(int* tabela, int* positions, int len){
  int i=0;
  while(i < positions[j+1]){
    if(tabela[positions[i]] == deletar){
      tabela[i] = -2;  
    }
    i++;  
  }
}
