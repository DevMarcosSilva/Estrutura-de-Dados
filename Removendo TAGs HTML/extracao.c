#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *arquivo = fopen("htmltag.html", "r");
    FILE *arquivosaida = fopen("arquivoSaida.txt","w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int dentrodastags = 0;
    char conteudo;

    while ((conteudo = fgetc(arquivo)) != EOF)
    {
        if (conteudo == '<')
        {
            dentrodastags = 1;
        }
        else if (conteudo == '>')
        {
            dentrodastags = 0;
        }
        else if (!dentrodastags)
        {
            fputc(conteudo, arquivosaida);
            
        }
    }
    printf("\tExtracao de dados concluida com sucesso! \n\tfoi gerado um arquivo de saida em sua pasta output");
    fclose(arquivo);
    fclose(arquivosaida);
    return 0;
}
