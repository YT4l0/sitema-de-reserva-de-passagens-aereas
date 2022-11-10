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
Aviao* aviao_cria();
    