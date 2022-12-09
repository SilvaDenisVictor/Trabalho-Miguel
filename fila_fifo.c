//Trabalho final
//Grupo:
//Jose Gerardo Araujo Rocha
//Denis da Silva Victor
//

#include <stdlib.h>
#include <stdio.h>
#include "fila_fifo.h"

void teste(fila *f){
  node* p = f->primeiro;

  while(p != NULL){
    printf("%d ", p->valor->numero_conta);
    p = p->prox;
  }
  printf("\n\n");
}

void f_inicializar(fila *f){
  f->primeiro =  NULL;
  f->ultimo = NULL;
  f->tamanho = 0;
}

int f_inserir(fila *f, int chave, cliente *c){
  node* ult = f->ultimo;
  node* p = f->primeiro;
  node* no_c = (node*)malloc(sizeof(node));
  int bool = 1;

  no_c->valor = c;
  no_c->chave = chave;

  if(p == NULL){
    no_c->prox = NULL;
    no_c->ant = NULL;
    f->primeiro = no_c;
    f->ultimo = no_c;
    f->tamanho++;

    return 1;
  }

  for(int n = 0; n < f->tamanho; n++){
    if(p->chave == no_c->chave){
      bool = 0;
    }
    p = p->prox;
  }

  if(bool){
    no_c->ant = ult;
    no_c->prox = NULL;
    ult->prox = no_c;
    f->ultimo = no_c;
    f->tamanho++;

    return 1;
  }

  return 0;
}

cliente* f_obter_proximo_valor(fila *f){
  if(f->primeiro == NULL) return NULL;

  node* aux = f->primeiro;
  node* p = f->primeiro->prox;

  if(p != NULL){
    p->ant = NULL;
  }else{
    f->ultimo = NULL;
  }
  f->primeiro = p;
  f->tamanho--;

  return aux->valor;
}

cliente* f_consultar_proximo_valor (fila *f){
  return f->primeiro->valor;
}

int f_consultar_proxima_chave (fila *f){
  if(f->primeiro != NULL){
    return f->primeiro->chave;
  }
  return -1;
}

int f_num_elementos (fila *f){
  return f->tamanho;
}

int f_consultar_chave_por_posicao (fila *f, int posicao){
  node* p = f->primeiro;
  int c = 0;

  while(p != NULL && f->tamanho > posicao){
    if(c == posicao){
      return p->chave;
    }
    p = p->prox;
    c++;
  }

  return -1;
}

cliente* f_consultar_valor_por_posicao (fila *f, int posicao){
  node* p = f->primeiro;
  int c = 0;

  while(p != NULL && f->tamanho > posicao){
    if(c == posicao){
      return p->valor;
    }
    p = p->prox;
    c++;
  }

  return NULL;
}

