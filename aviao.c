#include <stdio.h>
#include <stdlib.h>



//criando uma estrutura do tipo avião
typedef struct aviao
{
    int vagas;
    int numero;
    char origem[50];
    char destino[50];

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
