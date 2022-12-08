//Trabalho final
//Grupo:
//Jose Gerardo Araujo Rocha
//
//

#ifndef fila_fifo_h
#define fila_fifo_h

#include <stdio.h>
#include <stdlib.h>

void log_inicializar(Log **l);
void log_registrar(Log **l, int conta, int classe, int timer, int caixa);
float log_media_por_classe(Log **l, int classe);
int log_obter_soma_por_classe(Log **l, int classe);
int log_obter_contagem_por_classe(Log **l, int classe);

#endif /* fila_fifo_h */
