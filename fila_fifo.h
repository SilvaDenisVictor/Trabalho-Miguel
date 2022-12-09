//Trabalho final
//Grupo:
//Jose Gerardo Araujo Rocha
//Denis da Silva Victor


#ifndef FILA_FIFO_H 
#define FILA_FIFO_H

typedef struct _Cliente{
   int numero_conta;
   int tipo;
   int operacoes;
}cliente;

typedef struct _Node{
   struct _Node *prox;
   struct _Node *ant;
   int chave;
   cliente *valor;
}node;

typedef struct _Fila{
   node* primeiro;
   node* ultimo;
   int tamanho;
}fila;

void teste(fila *f);

void f_inicializar (fila *f);

int f_inserir (fila *f, int chave, cliente *c);

cliente* f_obter_proximo_valor (fila *f);

cliente* f_consultar_proximo_valor (fila *f);

int f_consultar_proxima_chave (fila *f);

int f_num_elementos (fila *f);

int f_consultar_chave_por_posicao (fila *f, int posicao);

cliente* f_consultar_valor_por_posicao (fila *f, int posicao);

#endif
