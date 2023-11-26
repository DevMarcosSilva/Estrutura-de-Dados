#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Abre o arquivo de entrada "htmltag.html" para leitura e o arquivo de saída "arquivoSaida.txt" para escrita.
    FILE *arquivo = fopen("htmltag.html", "r");
    FILE *arquivosaida = fopen("arquivoSaida.txt", "w");

    // Verifica se o arquivo de entrada foi aberto com sucesso.
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int dentrodastags = 0;
    char conteudo;

    // Lê o arquivo de entrada caractere por caractere.
    while ((conteudo = fgetc(arquivo)) != EOF)
    {
        if (conteudo == '<')
        {
            dentrodastags = 1; // Entrou em uma tag HTML
        }
        else if (conteudo == '>')
        {
            dentrodastags = 0; // Saiu da tag HTML
        }
        else if (!dentrodastags)
        {
            fputc(conteudo, arquivosaida); // Escreve o caractere no arquivo de saída
        }
    }

    // Imprime uma mensagem de conclusão e fecha os arquivos.
    printf("\tExtracao de dados concluida com sucesso!\n\tFoi gerado um arquivo de saida em sua pasta output.\n");
    fclose(arquivo);
    fclose(arquivosaida);

    return 0;
}
