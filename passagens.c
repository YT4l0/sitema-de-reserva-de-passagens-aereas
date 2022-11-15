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

    printf("digite o numero do aviao: ");
    scanf(" %d", &passagem->numero_aviao);
    printf("\n");

    FILE* arquivo = fopen("entradaPassagem.txt", "a"); //criando um arquivo
    if(arquivo ==NULL){  //compararando para ver se o arquivo é nulo
        printf("Erro ao abrir o arquivo: "); // caso arquivo seja nulo eexibe ao usuario erro
        exit(1); //abortando o proganma
    }

    
    fprintf(arquivo, "%s\n%s\n%s\n%d\n", passagem->nome, passagem->origem, passagem->destino, passagem->numero_aviao); //salvando os dados do usuario dentro do arquivo

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


Lista * lst_busca(Lista* lista_passagem){
    FILE *arquivo1 = fopen("./entradaPassagem.txt", "r");
    char nome_buscado[50];
    Passagem *Lista_passagem1;
  
    printf("Nome que deseja buscar?\n");
    fscanf(arquivo1, "%[^\n]", nome_buscado);
    
    
	Lista * aux;
	for(aux=lista_passagem; aux!=NULL; aux=aux->prox){

		if (strcmp(aux->info->nome, nome_buscado)==0){


            

			return aux;
        }
	}
            printf("o nome buscado %s foi encontrado!\n\n", nome_buscado);
            printf("Passagem de %s:\nOrigem: %s\nDestino: \nNumero doa aviao: ", nome_buscado, Lista_passagem1->origem, Lista_passagem1->destino, Lista_passagem1->numero_aviao);
            printf("\n----------------\n");
    printf("o nome buscado nao foi encontrado!\n\n");
    printf("----------------\n");
    fclose(arquivo1);

	return NULL;

}




