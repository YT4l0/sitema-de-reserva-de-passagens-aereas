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

//criando uma estrutura para lista
typedef struct lista
{
    Aviao info;

    struct list*prox; //criando um nó


}

//criando uma função para criar a lista
lista*cria(int numero, char origem, char destino, lista*l)
{
    lista *novo =(lista*)malloc(sizeof(lista));
}
