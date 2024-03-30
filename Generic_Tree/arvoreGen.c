#include "arvoreGen.h"

//Funções Lista
int listaVazia(TipoLista lista){
  return lista==NULL;
}

TipoLista inicializaLista(TipoLista lista){
  return NULL;
}

TipoLista destroiLista(TipoLista lista){
  TipoNoh *ptrAux;
  if(lista!=NULL){
    lista->prox = destroiLista(lista->prox);
    destroiArvore(lista->item);
  }
  return NULL;
}

TipoLista insereNoFinal(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh;
  if(lista==NULL){
    novoNoh = (TipoNoh *) malloc(sizeof(TipoNoh));
    novoNoh->item = item;
    novoNoh->prox = NULL;
    return novoNoh;
  }
  else{
    lista->prox = insereNoFinal(lista->prox,item);
    return lista;
  }
}

TipoLista insereNoInicio(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh *) malloc(sizeof(TipoNoh));
  novoNoh->item = item;
  novoNoh->prox = lista;
  return novoNoh;
}

TipoLista removeDoFinal(TipoLista lista,TipoItem *item){
  if(lista!=NULL){
    if(lista->prox==NULL){
      *item = lista->item;
      free(lista);
      return NULL;
    }
    else{
      lista->prox = removeDoFinal(lista->prox,item);
      return lista;
    }
  }
  return NULL;
}

TipoLista removeDoInicio(TipoLista lista,TipoItem *item){
  TipoNoh *ptrAux;
  if(lista!=NULL){
    ptrAux = lista;
    lista = lista->prox;
    *item = ptrAux->item;
    free(ptrAux);
    return lista;
  }
  return NULL;
}

void imprimeListaParagrafada(TipoLista lista,int n){
  if(lista!=NULL){
    imprimeArvoreParagrafada(lista->item,n);
    imprimeListaParagrafada(lista->prox,n);
  }
}

void imprimeListaAninhada(TipoLista lista){
  if(lista!=NULL){
    imprimeArvoreAninhada(lista->item);
    if(lista->prox!=NULL)
      imprimeListaAninhada(lista->prox);
    else
      printf(")");
  }
}


//Funções da Árvore
int arvoreVazia(TipoArvore arvore){
  return arvore==NULL;
}

TipoArvore inicializaArvore(TipoArvore arvore){
  return NULL;
}

TipoArvore destroiArvore(TipoArvore arvore){
  if(!arvoreVazia(arvore)){
    arvore->listaFilhos = destroiLista(arvore->listaFilhos);
    printf("Destruindo %c\n",arvore->dado);
    free(arvore);
  }
  return NULL;
}

TipoArvore instanciaArvore(TipoArvore arvore,char dado){
  arvore = (TipoArvore) malloc(sizeof(TipoNohArvore));
  arvore->dado = dado;
  arvore->listaFilhos = inicializaLista(arvore->listaFilhos);
  return arvore;
}

TipoArvore insereNaArvore(TipoArvore pai,TipoArvore filho){
  TipoItem item;
  item = filho;
  pai->listaFilhos = insereNoFinal(pai->listaFilhos,item);
  return pai;
}

void imprimeArvoreParagrafada(TipoArvore arvore,int n){
  int i;
  if(!arvoreVazia(arvore)){
    for(i=0;i<n;i++){
      printf(" ");
    }
    printf("%c\n",arvore->dado);
    imprimeListaParagrafada(arvore->listaFilhos,n+1);
  }
}

void imprimeArvoreAninhada(TipoArvore arvore){
  if(!arvoreVazia(arvore)){
    if(listaVazia(arvore->listaFilhos)){
      printf("%c ", arvore->dado);
    }
    else{
      printf("%c ", arvore->dado);
      printf("(");
      imprimeListaAninhada(arvore->listaFilhos);
    }
  }
}

void aninhaArvore(TipoArvore arvore){
  printf("(");
  imprimeArvoreAninhada(arvore);
  printf(")");
}

// ( A ( B ( E  F ) C D ( G H ) ) )
