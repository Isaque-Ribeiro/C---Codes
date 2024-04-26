// function's implementaion

#include "mergesort.h"


struct item{
  int dado;
  struct item *prox;
};

typedef struct item tipoItem;
typedef tipoItem *tipoLista;

//Funções Lista
int listaVazia(tipoLista lista){
  return lista == NULL;
}

tipoLista iniciaLista(void){
  return NULL;
}


tipoLista insereDado(tipoLista lista, int dado){
  tipoLista novoI, aux;
  novoI = (tipoLista)malloc(sizeof(tipoItem));
  if(novoI){
    novoI->dado = dado;
    novoI->prox = NULL;
    if(listaVazia(lista)){
      return novoI;
    }
    else{
      lista->prox = insereDado(lista->prox, dado);
      return lista;
    }
  }
}


void imprimeLista(tipoLista lista){
  tipoLista aux;
  if(!listaVazia(lista)){
    aux = lista;
    while(aux->prox != NULL){
      printf("%i ", aux->dado);
      aux = aux->prox;
    }
    printf("%i ", aux->dado);
  }
}

tipoLista Merge(tipoLista lista1, tipoLista lista2){
  tipoLista aux1 = lista1, aux2 = lista2, aux3 = iniciaLista();
  while(aux1 != NULL || aux2 != NULL){
    if(aux1 == NULL){
      aux3 = insereDado(aux3, aux2->dado);
      aux2 = aux2->prox;
    }
    else if(aux2 == NULL){
      aux3 = insereDado(aux3, aux1->dado);
      aux1 = aux1->prox;
    }
    else if(aux1->dado < aux2->dado){
      aux3 = insereDado(aux3, aux1->dado);
      aux1 = aux1->prox;
    }
    else if(aux2->dado < aux1->dado){
      aux3 = insereDado(aux3, aux2->dado);
      aux2 = aux2->prox;
    }
  }
  lista1 = NULL;
  while (aux3 != NULL){
    lista1 = insereDado(lista1, aux3->dado);
    aux3 = aux3->prox;
  }
  return lista1;
}

tipoLista MergeSort(tipoLista lista, int len){
  if(!listaVazia(lista)){
    if(len > 1){
      tipoLista aux1, aux2, aux3;
      int cont=0;
      aux1 = lista;
      aux3 = lista; // guarda fim da secção
      aux2 = lista->prox; //segura a segu
      if(len%2 != 0){
        while(cont<len/2){
          aux3 = aux3->prox;
          aux2 = aux2->prox;
          cont++;
        }  
      }
      else{
        while(cont<len/2-1){
          aux3 = aux3->prox;
          aux2 = aux2->prox;
          cont++;
        }
      }
      aux3->prox = NULL;
      aux1 = MergeSort(aux1, cont+1);
      aux2 = MergeSort(aux2, len-cont-1);
      lista = Merge(aux1, aux2);
      return lista;
    }
    return lista;
  }
}


int measureProfundit(int size){
  int cont = 0;
  while(size>1){
    if(size%2 > 0){
      size = size/2 + 1;
    }
    else{
      size /= 2;
    }
    cont++;
  }
  return cont;
}

void liberaLista(tipoLista key){
  tipoLista aux;
  while(key != NULL){
    aux = key;
    key = key->prox;
    aux->prox = NULL;
    free(aux);
  }
}
