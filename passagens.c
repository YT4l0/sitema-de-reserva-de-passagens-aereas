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
    printf("Digite o nome:  ");
    scanf(" %[^\n]", passagem->nome);
    printf("\n");

    printf("Digite a origem: ");
    scanf(" %[^\n]", passagem->origem);
    printf("\n");

    printf("Digite o destino: ");
    scanf(" %[^\n]", passagem->destino);
    printf("\n");

    printf("Digite o numero do aviao: ");
    scanf(" %d", &passagem->numero_aviao);
    printf("\n");

    FILE* arquivo = fopen("entradaPassagem.txt", "a"); 
    if(arquivo ==NULL){  
        printf("Erro ao abrir o arquivo: "); 
        exit(1); 
    }

    
    fprintf(arquivo, "%s\t%s\t%s\t%d\t\n", passagem->nome, passagem->origem, passagem->destino, passagem->numero_aviao); 

    fclose(arquivo); 

    return passagem; 
}


Lista * lst_retira(Lista*l){

    char name[50];
    Lista* ant = NULL; 
    Lista* p = l; 
    

    printf("\nDigite o nome do passageiro a ser removido: ");
    scanf("%[^\n]", name);


    while(strcmp(p->info->nome, name)!=0){
        
    	if (p==NULL)
        	return l; 
        ant = p;
        p = p->prox;
           
    }
   
    if (ant==NULL){
    
        l = p->prox;
    }    
    else{
    
        ant->prox = p->prox;
    }
        printf("==== nome removido com sucesso =====\n\n");

    free(p);
    return l;
}



Lista* inserir_passagem(Lista* lista_passagem, Passagem * nome){

    Lista* new_passagem = (Lista*)malloc(sizeof(Lista));
    new_passagem->info = nome;
    new_passagem->prox = lista_passagem;
    return new_passagem;
}


void lst_listar(Lista* lista_passagem){
    Lista*contador;
    for(contador=lista_passagem; contador!=NULL; contador=contador->prox){
        printf("----passagem----\n");

        exibe_passagem(contador->info);
        
        printf("----------------\n");
       
    }
}




void exibe_passagem(Passagem* lista_passagem){ 
    printf("Nome: %s\nOrigem: %s\nDestino: %s\nNumero do aviao: %d\n\n", lista_passagem->nome, lista_passagem->origem, lista_passagem->destino, lista_passagem->numero_aviao);
}


Lista * lst_busca(Lista* lista_passagem){
  
    char nome_buscado[50];
  
    printf("Nome que deseja buscar? ");
    scanf("%[^\n]", nome_buscado);
    
    
	Lista * aux;

	for(aux=lista_passagem; aux!=NULL; aux=aux->prox){

		if (strcmp(aux->info->nome, nome_buscado)==0){

             printf("O nome %s foi encontrado!\n\n", nome_buscado);
   

            

			return aux;
        }

	}
   
    printf("O nome buscado nao foi encontrado!\n\n");
    printf("----------------\n");
    

	return NULL;

}

/*
Lista* lst_insere_ordenada(Lista * lista_passagem){
    char name_ordena[50];
	Lista * novo;
	Lista * ant = NULL;
	Lista * p = lista_passagem;
	while(p!=NULL && p->info<name_ordena){
		ant = p;
		p = p->prox;

	}
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = name_ordena;
	if(ant ==NULL){
		novo->prox = l;
		l = novo;
	}
	else {
		novo->prox = ant-> prox;
		ant->prox = novo;
	}
	return lista_passagem;
}

*/






/*
Lista* ler_arquivo(Lista *lista_passagem){

    int n;

    char linha[100];


    FILE* arquivo = fopen("entradaPassagem.txt", "r"); //criando um arquivo
    if(arquivo ==NULL){  //compararando para ver se o arquivo ?? nulo
        printf("Erro ao abrir o arquivo: "); // caso arquivo seja nulo eexibe ao usuario erro

        exit(1); //abortando o proganma
    }

 // Ler os dados do arquivo de entrada 
    while (fgets(linha,100,arquivo) != NULL){
        // Passando os dados do vetor linha para o vetor v
        sscanf( arquivo, "%s\t%s\t%s\t%d\t\n", lista_passagem->info->nome, lista_passagem->info->origem, lista_passagem->info->destino, &lista_passagem->info->numero_aviao);
        n++;
    }
    return lista_passagem;
}
*/

void quantidade(Lista *lista_passagem){
    Lista * i;
    int conta = 0;

    for (i = lista_passagem; i != NULL; i = i->prox) {
        conta++;
    }

    printf("======== QUANTIDADE DE PASSAGEIROS ========\n");
    printf("\n\t   existe %d passageiros!\n\n", conta);
    printf("===========================================\n\n");
}

void quant_vags(Lista *lista_passagem){
    Lista * i;
    int pass = 100;
    
    for (i = lista_passagem; i != NULL; i = i->prox) {
        pass--; 
    }

    printf("========= QUANTIDADE DE VAGAS =========\n");
    printf("\n\t  existe %d vagas!\n\n", pass);
    printf("=======================================\n\n");
}
