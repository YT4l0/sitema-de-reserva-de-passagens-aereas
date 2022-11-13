#include <stdio.h>
#include <stdlib.h>
#include "passagens.h"

/* criar a struct passagem */

struct passagem{

    char nome[50];
    char origem[50];
    char destino[50];
    int numero_aviao;

};

/*função para criar a lista*/

struct lista {
    Passagem* info;
    struct lista* prox;
}; 

/*função que pede ao usuario as infos
da passagem*/

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


/*função para iserir a passagem dentro dos nos e assim criar a lista*/

Lista* inserir_passagem(Lista* lista_passagem, Passagem * nome){

    Lista* new_passagem = (Lista*)malloc(sizeof(Lista));
    new_passagem->info = nome;
    new_passagem->prox = lista_passagem;
    return new_passagem;
}

/*função para o contador percorrer a todos os nos da lista e passar a info como pararametro para exibir
a lista*/
void lst_listar(Lista* lista_passagem){
    Lista*contador;
    for(contador=lista_passagem; contador!=NULL; contador=contador->prox){
        printf("----passagem----\n");

        exibe_passagem(contador->info);
        
        printf("----------------\n");
       
    }
}


/* função para exibir os elementos da passagem */

void exibe_passagem(Passagem* lista_passagem){ 
    printf("Nome: %s\nOrigem: %s\nDestino: %s\nNumero do aviao: %d\n\n", lista_passagem->nome, lista_passagem->origem, lista_passagem->destino, lista_passagem->numero_aviao);
}


Lista * lst_busca(char *nome_buscado, Lista* lista_passagem){

	Lista * aux;
    
	for(aux=lista_passagem; aux!=NULL; aux=aux->prox){

		if (strcmp(aux->info->nome, nome_buscado)==0);

			return aux;
	}

	return NULL;
    

}


/*

void exibe_exibe_arquivo(Lista *lista_passagem){

     Passagem* passagem = (Passagem*)malloc(sizeof(Passagem));

     FILE* arquivo = fopen("entradaPassagem.txt", "r");
      if(arquivo ==NULL){  //compararando para ver se o arquivo é nulo
        printf("Erro ao abrir o arquivo: "); // caso arquivo seja nulo eexibe ao usuario erro
        exit(1); //abortando o proganma
    }

     while(fgets(arquivo,10000,entradaPassagem.txt) != NULL){
        sscanf(arquivo, "Nome: %s\nOrigem: %s\nDestino: %s\nNumero do aviao: %d\n\n", passagem->nome, passagem->origem, passagem->destino, passagem->numero_aviao); //salvando os dados do usuario dentro do arquivo
     }

}

*/

/*
Lista * lst_retira(Lista* lista_passagem, char name){
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while(p->info!=name){
    	if (p==NULL)
        	return lista_passagem; /* n�o achou: retorna lista original */
        ant = p;
        p = p->prox;
            /* verifica se achou elemento */

    }
    /* retira elemento */
    if (ant==NULL)
    /* retira elemento do inicio */
        lista_passagem = p->prox;
    else
    /* retira elemento do meio da lista */
        ant->prox = p->prox;
    free(p);
    return lista_passagem;;
}
*/





