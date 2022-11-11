#include <stdio.h>
#include <stdlib.h>
#include "passagens.h"

struct passagem{

    char nome[50];
    char origem[50];
    char destino[50];
    int numero_aviao;

};


struct lista {
    Passagem* info;
    struct lista* prox;
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

    FILE* arquivo = fopen("entradaPassagem.txt", "a"); //criando um arquivo
    if(arquivo ==NULL){  //compararando para ver se o arquivo é nulo
        printf("Erro ao abrir o arquivo: "); // caso arquivo seja nulo eexibe ao usuario erro
        exit(1); //abortando o proganma
    }

    
    fprintf(arquivo, "Nome: %s\nOrigem: %s\nDestino: %s\nNumero do aviao: %d\n\n", passagem->nome, passagem->origem, passagem->destino, passagem->numero_aviao); //salvando os dados do usuario dentro do arquivo

    fclose(arquivo); //fechando o arquivo

    return passagem; //retornando passagem
}




Lista* inserir_passagem(Lista* lista_passagem, Passagem * nome){

    Lista* new_passagem = (Lista*)malloc(sizeof(Lista));
    new_passagem->info = nome;
    new_passagem->prox = lista_passagem;
    return new_passagem;
}


/*
void lst_listar(Lista* lista_passagem){
    Lista*contador;
    for(contador=lista_passagem; contador! = NULL; contador=contador->prox){
        printf("", contador->info, );
    }
}
*/


/*
void exibe_passagem(Passagem* lista_passagem){
    printf("Nome: %s\nOrigem: %s\nDestino: %s\nNumero do aviao: %d\n\n", lista_passagem->nome, lista_passagem->origem, lista_passagem->destino, passagem->numero_aviao);
}
*/