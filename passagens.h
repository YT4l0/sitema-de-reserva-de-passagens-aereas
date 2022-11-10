#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct passagem Passagem; //renomeando a strutura

typedef struct lista Lista;

Lista* lista_cria();

// renomeando a estrutura

Passagem* reserva_passagem(void); //criando uma função que faz uma reserva da passagem
void imprime_passagem(Passagem *passagem); //criando criando uma função para imprimir os dados salvo


