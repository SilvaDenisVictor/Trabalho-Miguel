//Trabalho final
//Grupo:
//Jose Gerardo Araujo Rocha
//Denis da Silva Victor


#ifndef logtree_h
#define logtree_h

#include <stdio.h>
#include <stdlib.h>

typedef enum class {
  Leezu = 5,
  Bronze = 4,
  Prata = 3,
  Ouro = 2,
  Premium = 1,
  nulo = 0
} Class;

typedef struct _client {
    int cnt;
    Class class; 
    int op;
} Client;

typedef enum { black, red } Color;

typedef struct _lg {
  Class class;
  Color color;
  int key, cashier, cnt, op;
  struct _lg *pai,*esq, *dir;
} Lg;

typedef struct _rodar{
  int op, clients, ttotal;
}Rodar;

typedef struct arv {
  Lg *root;
  Lg *nul;
} ARV;

ARV *initialize();

void register(ARV *, int , int , int , int , int );

int sum_by_class(ARV *, Lg *, Class );

int count_by_class(ARV *, Lg *, Class );

float av_by_class(ARV *, Lg *, Class );

void inorder(ARV *, Lg *);

int alt_black(ARV *);

Lg* maximum(ARV *);

Rodar roll(ARV *, Class);

#endif /* logtree_h */



