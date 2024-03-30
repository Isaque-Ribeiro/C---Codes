// Functions catalog

#include <stdio.h>
#include <stdlib.h>


struct nohArvore{
  int dado;
  int fb;
  struct nohArvore *avlE, *avlD;
};

typedef struct nohArvore TipoNohArvore;
typedef TipoNohArvore *TipoArvore;


//FUNÇÕES DE ARVORE
TipoArvore Inicializa();
TipoArvore GeraNoh(int);
TipoArvore rotLL(TipoArvore);
TipoArvore rotRR(TipoArvore);
TipoArvore rotRL(TipoArvore);
TipoArvore rotLR(TipoArvore);
TipoArvore Ordena(TipoArvore);
TipoArvore Insere(TipoArvore, int);
TipoArvore exclui(TipoArvore, int);
TipoArvore Remove(TipoArvore, int, int);
int semFilhos(TipoArvore);
int altura(TipoArvore, int);
int swap(TipoArvore, int);
void calibraFB(TipoArvore);
int Busca(TipoArvore, int, int);
void imprimeOrdem(TipoArvore);
void imprimeEstrutural(TipoArvore);
