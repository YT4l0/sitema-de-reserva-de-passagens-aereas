#include <stdio.h>
#include <stdlib.h>
#include "passagens.h"

struct passagem{

    char nome[50];
    char origem[50];
    char destino[50];
    int numero_aviao;

    


};

struct No{

    Passagem info;

    no *next; //proximo elemento
    no  *prior; //elemento anterior

};
struct Lista{

    Passagem info;

    lista *next;
    lista *prior; 

}lista;

lista* lista_insere(lista *l, int i){
    lista *new =(lista*)malloc(sizeof(lista));
    if(new==NULL){
        printf("sem espaço");
        exit(1)
    }

    new-> info = i;
    new -> next = l;
    next -> prior = l;



return new;
}

Passagem* reserva_passagem(void){




    Passagem* passagem = (Passagem*)malloc(sizeof(Passagem));
    printf("digite o nome:  ");
    scanf(" %[^\n]", passagem->nome);
    printf("\n");

    printf("Digite a origem: ");
    scanf(" %[^\n]", passagem->origem);
    printf("\n");

    printf("Digite o destino: ");
    scanf(" %[^\n]", passagem->destino);
    printf("\n");

    printf("digite o numero do aviao:");
    scanf(" %d", &passagem->numero_aviao);
    printf("\n");

    return passagem;
}

