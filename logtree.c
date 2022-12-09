//Trabalho final
//Grupo:
//Jose Gerardo Araujo Rocha
//Denis da Silva Victor


#include <stdio.h>
#include <stdlib.h>
#include "logtree.h"

ARV *initialize(){
  ARV *A = malloc(sizeof(ARV));
  Lg *nul = malloc(sizeof(Lg));

  nul->esq = nul->dir = nul->pai = NULL;
  nul->color = black;
  nul->op = nul->key = nul->cnt = nul->cashier = -1;

  A->nul = nul;
  A->root = A->nul;
  return A;
}
void rightrotate(ARV *A, Lg *w) {
  Lg *v = w->esq;
  w->esq = v->dir;

  if (v->dir != A->nul)
    v->dir->pai = w;

  v->pai = w->pai;

  if (w->pai == A->nul)
    A->root = v;
  else if (w == w->pai->esq)
    w->pai->esq = v;
  else
    w->pai->dir = v;

  v->dir = w;
  w->pai = v;
}

void leftrotate(ARV *A, Lg *v) {
  Lg *w = v->dir;
  v->dir = w->esq;

  if (w->esq != A->nul)
    w->esq->pai = v;

  w->pai = v->pai;

  if (v->pai == A->nul)
    A->root = w;
  else if (v == v->pai->esq)
    v->pai->esq = w;
  else
    v->pai->dir = w;

  w->esq = v;
  v->pai = w;
}
Lg *createnode(Lg *pai, int cnt, int class, int tempo, int cashier,int op) {
  Lg *n;
  n = malloc(sizeof(Lg));
  n->key = tempo;
  n->class = (Class)class;
  n->cnt = cnt;
  n->cashier = cashier;
  n->op = op;
  n->pai = pai;
  n->esq = n->dir = NULL; 
  n->color = red;

  return n;
}
void adjust(ARV *A, Lg *cl) {
  Lg *f;
  while (A->root != cl && cl->color == red && cl->pai->color == red) {
    if (cl->pai == cl->pai->pai->esq) {
      f = cl->pai->pai->dir;
     
      if (f->color == red) {
        cl->pai->color = black;
        f->color = black;
        cl = cl->pai->pai;
        cl->color = red;
      } else {
        if (cl == cl->pai->dir) {
          cl = cl->pai;
          leftrotate(A, cl);
        }
        cl->pai->color = black;
        cl->pai->pai->color = red;
        rightrotate(A, cl->pai->pai);
      }

    } else {
      f = cl->pai->pai->esq;

      if (f->color == red) {
        cl->pai->color = black;
        f->color = black;
        cl = cl->pai->pai;
        cl->color = red;
      } else {
        if (cl == cl->pai->esq) {
          cl = cl->pai;
          rightrotate(A, cl);
        }
        cl->pai->color = black;
        cl->pai->pai->color = red;
        leftrotate(A, cl->pai->pai);
      }
    }
  }

  A->root->color = black;
}
void register(ARV *A, int cnt, int class, int tempo, int cashier,int op){ 
  Lg *n, *root = A->root, *pai = A->nul;
  int key = tempo;

  while (root != A->nul) {
    pai = root;
    if (key <= root->key)
      root = root->esq;
    else
      root = root->dir;
  }

  n = createnode(pai, cnt, class, tempo, cashier, op);

  if (pai == A->nul)
    A->root = n;
  else if (n->key <= pai->key)
    pai->esq = n;
  else
    pai->dir = n;

  n->dir = n->esq = A->nul;
  adjust(A, n);
  
}

int sum_by_class(ARV *A, Lg *n, Class class ){
   if (n == A->nul) {
    return 0;
  } else {
    if (n->class == class) {
      return n->key + sum_by_class(A, n->esq, class) +
             sum_by_class(A, n->dir, class);
    } else {
      return 0 + sum_by_class(A, n->esq, class) +
             sum_by_class(A, n->dir, class);
    }
  }
}

int count_by_class(ARV *A, Lg *n, Class class ){
   if (n == A->nul) {
    return 0;
  } else {
    if (n->class == class) {
      return 1 + count_by_class(A, n->esq, class) +
             count_by_class(A, n->dir, class);
    } else {
      return 0 + count_by_class(A, n->esq, class) +
             count_by_class(A, n->dir, class);
    }
  }
}

float av_by_class(ARV *A, Lg *n, Class class){
   int clients, ttotal;
  float av;

  ttotal = sum_by_class(A, n, class);
  clients = count_by_class(A, n, class);

  if (clients == 0)
    return 0;

  av = (float)ttotal / (float)clients;
  return av;
}

void inorder(ARV *A, Lg *n){
    if (n != A->nul) {
    inorder(A, n->esq);
    printf("%d\n", n->key);
    inorder(A, n->dir);
  }
}

int alt_black(ARV *A){
   int alt = 0;
  Lg *n = A->root;

  while (n != A->nul) {
    if (n->color == black)
      alt++;
    n = n->esq;
  }
  return alt;
}

Lg* maximum(ARV *A){
  Lg *n;
  if (A->root == A->nul)
    return NULL;
  n = A->root;
  while (n->dir != A->nul)
    n = n->dir;

  return n;
}

Rodar roll(ARV *A, Class class){
  Rodar teste;
  Lg *agr, *bef;
  teste.op = teste.clients = teste.ttotal = 0;

  if (A->root == A->nul)
    return teste;

  agr = A->root;
  while (agr != A->nul) {

    if (agr->esq == A->nul) {
      if (agr->class == class) {
        teste.op += agr->op;
        teste.clients++;
        teste.ttotal += agr->key;
      }
      agr = agr->dir;
    } else {
      bef = agr->esq;
      while (bef->dir != A->nul && bef->dir != agr)
        bef = bef->dir;

      if (bef->dir == A->nul) {
        bef->dir = agr;
        agr = agr->esq;
      }

      else {
        bef->dir = A->nul;

        if (agr->class == class) {
          teste.op += agr->op;
          teste.clients++;
          teste.ttotal += agr->key;
        }
        agr = agr->dir;
      }
    }
  }

  return teste;
}
