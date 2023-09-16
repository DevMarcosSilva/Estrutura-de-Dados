#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Declarando um array de strings chamado 'nomes' com 20 strings de até 20 caracteres cada.

char nomes[20][20] = {"maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};

char nomes[20][20] = {"maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};


// Função 'ordenar' que recebe dois ponteiros de inteiros como parâmetros.
void ordenar(int *trocas, int *comparacao)
{
    int x, y, r;
    char aux[80];

    *trocas = 0;
    *comparacao = 0;

    // Algoritmo de ordenação de bolha.
    for (x = 0; x <= 19; x++)
    {
        for (y = x + 1; y <= 19; y++)
        {
            (*comparacao)++;
            r = strcmp(nomes[x], nomes[y]);
            if (r > 0)
            {
                strcpy(aux, nomes[x]);
                strcpy(nomes[x], nomes[y]);
                strcpy(nomes[y], aux);
                (*trocas)++; // Incrementa o contador de trocas.
            }
        }
    }
}

int main()
{
    // Abre um arquivo chamado "arquivoSaida.txt" para escrita.
    FILE *arquivo = fopen("ArquivoSaida.txt","w");

    int x, trocas, comparacao;

    // Imprime os nomes não ordenados na tela e no arquivo.
    printf(" Vetor nao ordenado!\n\n");
    fprintf(arquivo," Vetor nao ordenado!\n\n");
    
    for (x = 0; x <= 19; x++)
    {
        printf("(%d) %s, ",x+1, nomes[x]);
        fprintf(arquivo,"(%d) %s ,",x+1, nomes[x]);
    }

    ordenar(&trocas, &comparacao);

    // Imprime os nomes ordenados na tela e no arquivo.
    printf("\n\n Vetor ordenado!\n\n");
    fprintf(arquivo,"\n\n Vetor ordenado!\n\n");
    
    for (x = 0; x <= 19; x++)
    {
        printf("(%d) %s, ",x+1, nomes[x]);
        fprintf(arquivo,"(%d) %s, ",x+1, nomes[x]);
    }
     
    // Imprime o número de trocas e comparações na tela e no arquivo.
    printf("\n\nNumero de trocas: %d\n", trocas);
    fprintf(arquivo,"\n\nNumero de trocas: %d\n", trocas);
    printf("Numero de comparacoes realizadas foram : %d\n",comparacao);
    fprintf(arquivo,"Numero de comparacoes realizadas foram : %d\n",comparacao);

    // Imprime a string mediana e escreve no arquivo.
    printf("A String mediana e: %s\n", nomes[9]);
    fprintf(arquivo,"A String mediana e: %s\n", nomes[9]);

    // Fecha o arquivo.
    fclose(arquivo);

    return 0;
}