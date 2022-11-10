#ifndef PASSAGENS_H
#define PASSAGEM_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct passagem Passagem; //renomeando a strutura

typedef struct lista Lista;

Lista* lista_cria(); //criando uma lista

Passagem* reserva_passagem(void); //criando uma função que faz uma reserva da passagem

#endif