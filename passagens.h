#ifndef PASSAGENS_H
#define PASSAGEM_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct passagem Passagem; //renomeando a strutura

typedef struct lista Lista;

Lista* lista_cria(); //criando uma lista

Passagem* reserva_passagem(void); //criando uma função que faz uma reserva da passagem

Lista * lst_retira(Lista*l);

Lista* inserir_passagem(Lista* lista_passagem, Passagem* nome);


void exibe_passagem(Passagem* lista_passagem);

void lst_listar(Lista* lista_passagem);

Lista * lst_busca(Lista* lista_passagem);



/*
Passagem* ler_arquivo(void);
*/

/*
Lista* ler_arquivo(void);
*/

#endif