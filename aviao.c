#include <stdio.h>
#include <stdlib.h>

#define vagas 100
#define MAX 5
//criando uma estrutura do tipo avião
typedef struct aviao
{
    int numero;
    char origem;
    char destino;
}Aviao;

//criando uma função para iniciar
void inicializa(Aviao **avioes, int n)
{
    int i;
    for(i = 0; i < n; i++)
    avioes[i] = NULL;
}
void origem(int n, Aviao** avioes)
{
    static i = 0;

    if(i<n){
        avioes[i] = (Aviao *) malloc(n * sizeof(Aviao)); 
        if(avioes[i]==NULL){
                        printf("Memoria cheia \n");
                        exit(1);
                }

    else
    {
        printf("Origem do aviao:\n numero do aviao:\n destino do aviao:\n");
        scanf("%s", &avioes[i]->origem);
        scanf("%d", &avioes[i]->numero);
        scanf("%s", &avioes[i]->destino);
       
    }

    }
    

}