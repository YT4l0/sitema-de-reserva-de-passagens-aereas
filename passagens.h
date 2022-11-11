#ifndef PASSAGENS_H
#define PASSAGEM_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct passagem Passagem; //renomeando a strutura

typedef struct lista Lista;

Lista* lista_cria(); //criando uma lista

Passagem* reserva_passagem(void); //criando uma função que faz uma reserva da passagem

Lista* inserir_passagem(Lista* lista_passagem, Passagem* nome);

Lista * lst_busca(int elemento, Lista* lista_passagem);

void exibe_passagem(Passagem* lista_passagem);

void lst_listar(Lista* lista_passagem);

Lista * lst_busca(char *nome_buscado, Lista* lista_passagem);



#endif