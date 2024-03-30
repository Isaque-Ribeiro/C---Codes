#include "arvoreBin.h"

//FUNÇÕES DE 
TipoArvore Inicializa() { 
  return NULL; 
}

TipoArvore GeraNoh(int item) {
  TipoArvore novoI;
  novoI =
    (TipoArvore)malloc(sizeof(TipoNohArvore));
  novoI->avlE = NULL;
  novoI->avlD = NULL;
  novoI->dado = item;
  novoI->fb = 0;
  return novoI;
}


int Busca(TipoArvore pai, int num, int cont) {
  if (pai != NULL) {
    if(num == pai->dado){
      return cont;
    }
    else if (num < pai->dado){
      cont++;
      return Busca(pai->avlE, num, cont);
    }
    else{
      cont++;
      return Busca(pai->avlD, num, cont);
    }
  }
  return 0;
}


int altura(TipoArvore pai, int fb){
  int a = fb, b = fb;
  if(pai != NULL){
    if(!semFilhos(pai)){
      fb++;
      a = altura(pai->avlE, fb);
      b = altura(pai->avlD, fb);
    }
    if(a > b){
      return a;
    }
    else if(a < b){
      return b;
    }
  }
  else
    return 0;
}



TipoArvore rotLL(TipoArvore pai) {
  TipoArvore aux;
  aux = pai->avlE;
  pai->avlE = aux->avlD;
  aux->avlD = pai;
  aux->fb = altura(aux->avlD, 0) - altura(aux->avlE, 0);
  return aux; 
}


TipoArvore rotRR(TipoArvore pai) {
  TipoArvore aux;
  aux = pai->avlD;
  pai->avlD = aux->avlE;
  aux->avlE = pai;
  aux->fb = altura(aux->avlD, 0) - altura(aux->avlE, 0);
  return aux;
}


TipoArvore rotRL(TipoArvore pai) {
  pai->avlD = rotLL(pai->avlD);
  return rotRR(pai);
}


TipoArvore rotLR(TipoArvore pai) {  
  pai->avlE = rotRR(pai->avlE);
  return rotLL(pai); 
}


int semFilhos(TipoArvore pai) {
  if(pai != NULL){
    if(pai->avlE == NULL && pai->avlD == NULL)
      return 1;
    else
      return 0;
  }
  return 1;
}


TipoArvore rot(TipoArvore pai){
  if((pai != NULL) && !semFilhos(pai)){
    TipoArvore aux1 = pai->avlE, aux2 = pai->avlD;
    if(pai->fb > 2){
    //FILHO DIREITA E NETO DIREITA
      if(aux2->fb >= 0){
        pai = rotRR(pai);
      }
    //FILHO DIREITA E NETO ESQUERDA
      else if(aux2->fb < 0){
        pai = rotRL(pai);
      }
    }
    else if(pai->fb < -2){
    //FILHO ESQUERDA E NETO ESQUERDA
      if(aux1->fb <= 0){
        pai = rotLL(pai);
      }
    //FILHO ESQUERDA E NETO DIREITA
      else if(aux1->fb > 0){
        pai = rotLR(pai);
      }
    }
  }
  return pai;
}

TipoArvore Ordena(TipoArvore pai){
  if(pai != NULL){
    pai->avlE = Ordena(pai->avlE);
    pai->avlD = Ordena(pai->avlD);
    pai = rot(pai);
    return pai;
  }
  else 
    return NULL;
}

TipoArvore Insere(TipoArvore pai, int item) {
  if(pai != NULL){
    if(item == pai->dado){
      pai = GeraNoh(item);
    }
    else if(item < pai->dado){
      pai->avlE = Insere(pai->avlE, item); 
      pai->fb = pai->fb - 1;
    }
    else{
      pai->avlD = Insere(pai->avlD, item);
      pai->fb = pai->fb + 1;
    }
  }
  else
    pai = GeraNoh(item);
  return pai;
}



int swap(TipoArvore pai, int lado){
  if(pai != NULL){
    int hand;
    if(lado == 0 ){
      if(pai->avlE){
        hand = swap(pai->avlE, -1);
      }
      else{
        hand = swap(pai->avlD, 1);
      }
    }
    else if(lado == -1){
      if(pai->avlD){
        lado = 1;
        hand = swap(pai->avlD, lado);
      }
      else{
        hand = pai->dado;
      }
    }
    else{
      if(pai->avlE){
        lado = -1;
        hand = swap(pai->avlE, lado);
      }
      else{
        hand = pai->dado;
      }
    }
    return hand;
  }
}

TipoArvore exclui(TipoArvore pai, int lado){
  if(pai != NULL){
    if(lado == 0 ){
      if(pai->avlE){
        pai->avlE = exclui(pai->avlE, -1);
      }
      else{
        pai->avlD = exclui(pai->avlD, -1);
      }
    }
    else if(lado == -1){
      if(pai->avlD){
        lado = 1;
        pai->avlD = exclui(pai->avlD, lado);
      }
      else{
        pai = pai->avlE;
      }
    }
    else{
      if(pai->avlE){
        lado = -1;
        pai->avlE = exclui(pai->avlE, lado);
      }
      else{
        pai = pai->avlD;
      }
    }
    return pai;
  }
}


TipoArvore Remove(TipoArvore pai, int item, int lado){
  if(pai != NULL){
    if(item < pai->dado){
      pai->fb++;
      lado = -1;
      pai->avlE = Remove(pai->avlE, item, lado);
    }
    else if(item > pai->dado){
      lado = 1;
      pai->fb--;
      pai->avlD = Remove(pai->avlD, item, lado);
    }
    else if (item == pai->dado){
      if(lado == 0 || lado == -1){
        if(!semFilhos(pai)){
          pai->fb++;
          pai->dado = swap(pai, lado);
          pai = exclui(pai, lado);
        }
        else{
          pai = NULL;
        }
      }
      else if(lado == 1){
        if(!semFilhos(pai)){
          pai->fb--;
          pai->dado = swap(pai, lado);
          pai = exclui(pai, lado);
        }
      }
      else{
        pai = NULL;
      }
    }
  }
  //  CHECAR ORDEM DOS FATORES APÓS REMOÇÃO
  return pai;
}



void imprimeOrdem(TipoArvore pai) {
  if (pai != NULL) {
    imprimeOrdem(pai->avlE);
    printf("%i ", pai->dado);
    imprimeOrdem(pai->avlD);
  }
}


void imprimeEstrutural(TipoArvore pai) {
  if (pai != NULL) {
    printf("%i ", pai->dado);
    imprimeEstrutural(pai->avlE);
    imprimeEstrutural(pai->avlD);
  }
}
