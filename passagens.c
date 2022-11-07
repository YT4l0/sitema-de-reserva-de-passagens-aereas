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

    FILE* arquivo;
    char entradaPassagem[50];

    printf("Digite o nome do arquivo: ");
    scanf(" %[^\n]", entradaPassagem);

    arquivo = fopen(entradaPassagem, "w");
    if(arquivo ==NULL){
        printf("Erro ao abrir o arquivo: ");
        exit(1);
    }

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

    fprintf(arquivo, %s %s %s %d, passagem->nome, passagem->origem, passagem->destino, passagem->numero_aviao);

    fclose(arquivo):

    return passagem;
}

