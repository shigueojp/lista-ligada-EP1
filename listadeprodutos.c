#include "listadeprodutos.h"

PLISTA criarLista(){
  PLISTA res = (PLISTA) malloc(sizeof(LISTADEPRODUTOS));
  res->cabeca = (PONT) malloc(sizeof(REGISTRO));
  res->cabeca->id=-1;
  res->cabeca->tipo=-1;
  res->cabeca->quantidade=0;
  res->cabeca->valorUnitario=0;
  res->cabeca->proxProd=NULL;
  return res;
}


int tamanho(PLISTA l){
  PONT atual = l->cabeca->proxProd;
  int tam = 0;
  while (atual) {
    atual = atual->proxProd;
    tam++;
  }
  return tam;
}

PONT buscarID(PLISTA l, int id){
  PONT atual = l->cabeca->proxProd;
   while (atual) {
    if (atual->id == id) return atual;
    atual = atual->proxProd;
  }
  return NULL;
}

void exibirLog(PLISTA f){
  int numElementos = tamanho(f);
  printf("Log lista [elementos: %i]\n    ", numElementos);
  PONT atual = f->cabeca->proxProd;
  while (atual){
    printf(" [%i;%i;%i;%i;$%i]", atual->id, atual->tipo, atual->quantidade, atual->valorUnitario, atual->quantidade*atual->valorUnitario);
    atual = atual->proxProd;
  }
  printf("\n\n");
}

int consultarValorUnitario(PLISTA l, int id){
  PONT atual = l->cabeca->proxProd;
   while (atual) {
    if (atual->id == id) return atual->valorUnitario;
    atual = atual->proxProd;
  }
  return 0;
}





bool inserirNovoProduto(PLISTA l, int id, int tipo, int quantidade, int valor){
  if (tipo <= 0 || quantidade <= 0 || valor <= 0)  return false;

  PONT atual = l->cabeca->proxProd;
  while (atual) {
    if (atual->id == id) return false;
    atual = atual->proxProd;
  }

  PONT novoProduto = (PONT) malloc(sizeof(REGISTRO))
  novoProduto->id = id;
  novoProduto->tipo = tipo;
  novoProduto->quantidade = quantidade;
  novoProduto->valor = valor;
  PONT atual->proxProd = novoProduto;

  return true;
}



bool removerItensDeUmProduto(PLISTA l, int id, int quantidade){
  if (id <= 0 || quantidade <= 0) return false;

  PONT atual = l->cabeca->proxProd;
  PONT anterior = (PONT) malloc(sizeof(REGISTRO));
  int qde = 0;
  while (atual) {
    qde = atual->quantidade - quantidade;
    if (atual->id == id && qde > 0) {
      atual->quantidade = qde;

      return true;
    } else if (atual->id == id && qde = 0) {
      PONT toBePointed = atual->proxProd;
      anterior->proxProd = toBePointed;
      free(atual);

      return true;
    }
    anterior = atual;
    atual = atual->proxProd;
  }

  return false;
}


bool atualizarValorDoProduto(PLISTA l, int id, int valor){
  PONT atual = l->cabeca->proxProd;
  PONT anterior = (PONT) malloc(sizeof(REGISTRO));
  PONT regAux = (PONT) malloc(sizeof(REGISTRO));
  while (atual) {
    if (atual->id = id) {
      atual->valorUnitario = valor;
      regAux = atual;
    }
     anterior = atual;
     atual = atual->proxProd;
  }
        
    valorTotalAtual = atual->valorUnitario*atual->quantidade;
    valorTotalProx = atual->proxProd->valorUnitario*atual->proxProd->quantidade;
    while (valorTotalAtual > valorTotalProx) {
      atual = atual->proxProd;  
      valorTotalProx = atual->proxProd->valorUnitario*atual->proxProd->quantidade;
    }
    anterior->proxProd = regAux->proxProd;
    

    //Pegar Proximo Produto e ordenar, dps de ordernar, pega o elemento alocado e seta o proxProd (que era o antigo do atual)
    proximoprod = atual->proxProd;
    atual->proxProd = regAux;
    regAux->proxProd = proximoprod;

   
  }

  return false;
}
