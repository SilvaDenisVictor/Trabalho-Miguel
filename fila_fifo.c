//Trabalho final
//Grupo:
//Jose Gerardo Araujo Rocha
//
//

#include <stdio.h>
#include <stdlib.h>
#include "fila_fifo.h"

typedef struct F
{
	int front;
	int rear;
	int counter;
	Customer array[FSIZE];
} F;

void f_inicializar (Fila_FIFO **f){
  int i;
	f->counter = 0;
	f->front = 0;
	f->rear = 0;
	for (i = 0; i < FSIZE; i++)
		CustInitialize( &(f->array[i]) );
}
int f_inserir (Fila_FIFO **f, int chave, int valor){
  if {
    (f->counter == FSIZE)
  }
		return 0;
	else
	{
		f->counter++;
		CustAssign( &(f->array[f->rear]) ,valor);
		f->rear = ( f->rear + 1 )% FSIZE;
	}
	return 1;
}
int f_obter_proxima_chave (Fila_FIFO **f){

}
int f_consultar_proxima_chave (Fila_FIFO **f){
  return front *f;
}
int f_consultar_proximo_valor (Fila_FIFO **f){
  return front f;
}
int f_num_elementos (Fila_FIFO **f){
  return f->counter;
}
int f_consultar_chave_por_posicao (Fila_FIFO **f, int posicao){

}
int f_consultar_valor_por_posicao (Fila_FIFO **f, int posicao){

}
