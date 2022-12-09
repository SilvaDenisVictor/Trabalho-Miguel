//Trabalho final
//Grupo:
//Jose Gerardo Araujo Rocha
//Denis da Silva Victor


#ifndef logtree_h
#define logtree_h

#include <stdio.h>
#include <stdlib.h>

void f_inicializar (Fila_FIFO **);
int f_inserir (Fila_FIFO **, int , int );
int f_obter_proxima_chave (Fila_FIFO **);
int f_consultar_proxima_chave (Fila_FIFO **);
int f_consultar_proximo_valor (Fila_FIFO **);
int f_num_elementos (Fila_FIFO **);
int f_consultar_chave_por_posicao (Fila_FIFO **, int );
int f_consultar_valor_por_posicao (Fila_FIFO **, int);

#endif /* logtree_h */



