//Trabalho final
//Grupo:
//Jose Gerardo Araujo Rocha
//


#ifndef fila_fifo_h
#define fila_fifo_h

#include <stdio.h>
#include <stdlib.h>

void log_inicializar(Log **);
void log_registrar(Log **, int, int , int , int);
float log_media_por_classe(Log **, int );
int log_obter_soma_por_classe(Log **, int );
int log_obter_contagem_por_classe(Log **, int );

#endif /* fila_fifo_h */
