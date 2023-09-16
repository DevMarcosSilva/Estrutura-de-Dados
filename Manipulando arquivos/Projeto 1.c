#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    // Abre o arquivo de entrada para leitura e o arquivo de saída para escrita.
    FILE *arquivoEntrada = fopen("DadosEntrada.csv", "r");
    FILE *arquivoSaida = fopen("SituacaoFinal.csv", "w");

    float nota1, nota2, media;
    char nome[50], telefone[50], curso[50], nota1_str[50], nota2_str[50], situacao[50];
    char linha[256];
    bool primeiraLinha = true;

    if (arquivoEntrada == NULL || arquivoSaida == NULL)
    {
        printf("Erro ao abrir os arquivoss!\n");
        exit(1);
    }

    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL)
    {
        if (primeiraLinha)
        {
            primeiraLinha = false;
            continue; // Ignora a primeira linha do arquivo.
        }

        // Lê os dados da linha do arquivo de entrada.
        if (sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", nome, telefone, curso, &nota1, &nota2) == 5)
        {
            // Calcula a média das notas.
            media = (nota1 + nota2) / 2;
        }

        // Determina a situação do aluno com base na média.
        if (media >= 7.0)
        {
            sprintf(situacao, "Aprovado!");
        }
        else
        {
            sprintf(situacao, "Reprovado!");
        }

        // Escreve os dados formatados no arquivo de saída.
        fprintf(arquivoSaida, "%s,%0.2f,%s\n", nome, media, situacao);
    }

    // Fecha os arquivos.
    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    // Mensagem de conclusão.
    printf("Compilacao realizada com sucesso!\n");

    return 0;
}
