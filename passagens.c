#include <stdio.h>
#include <stdlib.h>
#include "passagens.h"

struct passagem{

    char nome[50];
    char origem[50];
    char destino[50];
    int numero_aviao;

    


};



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

   

   

   
    FILE* arquivo = fopen("entradaPassagem.txt", "a");
    if(arquivo ==NULL){
        printf("Erro ao abrir o arquivo: ");
        exit(1);
    }

    fprintf(arquivo, "Nome: %s\nOrigem: %s\nDestino %s\n Numero do aviao: %d\n", passagem->nome, passagem->origem, passagem->destino, passagem->numero_aviao);

    fclose(arquivo);

    return passagem;
}

