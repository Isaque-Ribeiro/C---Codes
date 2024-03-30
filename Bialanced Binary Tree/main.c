/*Ths code requires three lines, as specified next. After insertion, the tree is orderable. So, some sheets can be removed and the tree is ordered again. 
Next a data can be searched.
This ordenament makes tree be balanced, to have almort the same height to each side, as a binary tree.
*/

#include "arvoreBin.h"


int main() {
  int item = 0, busca,cont;
  TipoArvore avl = Inicializa();

//FIRST LINE REQUIRE VALUES TO INSERT, TO STOP PRESS -1
  scanf("%i", &item);
  while(item != -1){
    avl = Insere(avl, item);
    scanf("%i", &item);
  }
  avl = Ordena(avl);
//SECOND LINE REQUIRE VALUES TO BE REMOVED, TO STOP, PRESS -1
  item = 0;
  while(item != -1){
    scanf("%i", &item);
    avl = Remove(avl, item, 0);
  }
  avl = Ordena(avl);
//THIRD LINE REQUIRE A VALUE TO BE SEARCHED
  scanf("%i", &item);
  busca = Busca(avl, item, 0);
  if(!busca){
    printf("Valor não encontrado\n");
  }
  else{
    printf("Valor encontrado no nível %i da árvore\n", busca);
  }
//SHOW TREE
  printf("Imprime Ordenado: ");
  imprimeOrdem(avl);
  printf("\nImprime Estrutural: ");
  imprimeEstrutural(avl);
  return 0;
}
