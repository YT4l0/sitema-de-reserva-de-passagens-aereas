#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include "passagens.c"

#define TITULO_OPCAO1 "Realizar reserva"
#define TITULO_OPCAO2 "Excluir reserva"
#define TITULO_OPCAO3 "listar reservas"
#define TITULO_OPCAO4 "Buscar reservas"
#define TITULO_OPCAO5 "consultar vagas disponiveis"
#define TITULO_OPCAO6 "consultar quantidade de passageiros"
#define TITULO_OPCAO7 "sair"

#define N_OPCOES 7

#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'

/****
* Função: LimpaBuffer()
* Descrição: Lê e descarta caracteres encontrados na entrada
* Parâmetros: Nenhum
* Retorno: Nada
****/
void LimpaBuffer(void) {
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}
/****
* Função: LeOpcao()
* Descrição: Lê e valida a opção digitada pelo usuário
* Parâmetros:
*   menorValor (entrada): o menor valor válido
*   maiorValor (entrada): o maior valor válido
* Retorno: A opção lida é validada
****/
int LeOpcao(int menorValor, int maiorValor) {
    int op;
    while (1) {
        printf("\nDigite sua opcao: ");
        op = getchar();
        if (op >= menorValor && op <= maiorValor) {
            LimpaBuffer();
            break;
        }
        else {
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre %c e %c. \n",
                   menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    return op;
}


/****
* Função: ApresentaMenu
* Descrição: Apresenta menu com número indeterminado de opções
* Parâmetros:
*   nItens (entrada): número de itens no menu
*   menorOpcao (entrada): caractere associado ao item I
* Retorno: Nada
****/
void ApresentaMenu(int nItens, int menorOpcao, ...) {
    int i;
    va_list argumentos;
    /* Inicia lista de argumentos variáveis */
    va_start(argumentos, menorOpcao);
    /* Lê cada argumento e imprime na tela. Note que o */
    /* tipo de cada argumento é char *, que é o tipo que */
    /* representa strings em C */
    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);/* Encerra processamento de argumentos */
}

int main(void) {
    unsigned char op;
    Lista* lista_passagem = NULL;
    
    unsigned int saida = 0;

    do {
        ApresentaMenu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5, TITULO_OPCAO6, TITULO_OPCAO7);
        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch(op) {
            case OPCAO1:
                Beep(1000,500); /* Emite um beep */
                Passagem*passagem = reserva_passagem();
                Lista * lista_de_passagem = inserir_passagem(lista_passagem, passagem);
                
                break;

            case OPCAO2:
                Beep(1000,500);
              
          
                break;

            case OPCAO3:
                Beep(1000,500);
                Passagem* imprime_l =  exibe_passagem();
             
             
               
                break;

            case OPCAO4:
                Beep(1000,500);
             ;
                break;

            case OPCAO5:
                Beep(1000,500);

                break;
            case OPCAO6:
            Beep(1000,500);

            break;

            case OPCAO7:
            

             Beep(1000,500);
                saida = 1;
                printf("Obrigado por usar este programa.");


            break;

            default:
                printf("Este programa possui um bug.");
                return 1;
        }
    } while(!saida);
    return 0;
}