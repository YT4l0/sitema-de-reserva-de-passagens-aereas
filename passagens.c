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

Lista* lista_cria(){
    return NULL;
}
Lista* lst_insere(Lista* l, Passagem p){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = p;
	novo->prox = l;
	return novo;


}
void lst_imprime(Lista*l){

	Lista*pr;
	for(pr=l; pr!=NULL; pr=pr->prox){
		printf(" Info = %d \n", pr->info);
	}

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

    FILE* arquivo = fopen("entradaPassagem.txt", "a"); //criando um arquivo
    if(arquivo ==NULL){  //compararando para ver se o arquivo é nulo
        printf("Erro ao abrir o arquivo: "); // caso arquivo seja nulo eexibe ao usuario erro
        exit(1); //abortando o proganma
    }

    
    fprintf(arquivo, "Nome: %s\nOrigem: %s\nDestino: %s\nNumero do aviao: %d\n\n", passagem->nome, passagem->origem, passagem->destino, passagem->numero_aviao); //salvando os dados do usuario dentro do arquivo

    fclose(arquivo); //fechando o arquivo

    return passagem; //retornando passagem
}


Lista * lst_retira(Lista*l, Passagem p){
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* pr = l; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while(pr->info!=p){
    	if (pr==NULL)
        	return l; /* n�o achou: retorna lista original */
        ant = pr;
        point = pr->prox;
            /* verifica se achou elemento */

    }
    /* retira elemento */
    if (ant==NULL)
    /* retira elemento do inicio */
        l = pr->prox;
    else
    /* retira elemento do meio da lista */
        ant->pr = pr->prox;
    free(pr);
    return l;
}


