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

void rightrotate(ARV *A, Lg *w);

void leftrotate(ARV *A, Lg *v);

Lg *createnode(Lg *, int cnt, int class, int tempo, int cashier,int op);

void adjust(ARV *, Lg *);

ARV *log_inicializar();

void log_registrar(ARV *, int , int , int , int , int );

int log_obter_soma_por_classe(ARV *, Lg *, Class );

int log_obter_contagem_por_classe(ARV *, Lg *, Class );

float log_media_por_classe(ARV *, Lg *, Class );

void inorder(ARV *, Lg *);

int alt_black(ARV *);

Lg* maximum(ARV *);

Rodar roll(ARV *, Class);

#endif /* logtree_h */



