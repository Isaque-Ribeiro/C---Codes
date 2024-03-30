// functions catalog

#include <stdio.h>
#include <stdlib.h>


struct item{
  int dado;
  struct item *prox;
};

typedef struct item tipoItem;
typedef tipoItem *tipoLista;


int listaVazia(tipoLista);
void imprimeLista(tipoLista);
tipoLista iniciaLista(void);
tipoLista insereDado(tipoLista,int);
tipoLista Merge(tipoLista,tipoLista);
tipoLista MergeSort(tipoLista,int);
void liberaLista(tipoLista);
int measureProfundit(int);
