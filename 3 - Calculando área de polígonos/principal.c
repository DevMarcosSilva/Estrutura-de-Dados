//Atenção esse código roda apenas em um diretório(pasta) na área de trabalho 
#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main()
{
    FILE *arquivo = fopen("trianguloABC.txt", "r");
    int numVertices;

    // Abre o arquivo de entrada

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê o número de vértices
    fscanf(arquivo, "%d", &numVertices);

    // Aloca memória para armazenar os vértices
    Ponto *vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));

    if (vertices == NULL)
    {
        printf("Erro na alocação de memória.\n");
        fclose(arquivo);
        return 1;
    }

    // Lê as coordenadas dos vértices
    for (int i = 0; i < numVertices; i++)
    {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Calcula a área do polígono
    float area = calcularArea(vertices, numVertices);

    // Exibe a área do polígono
    printf("A area do poligono e %.2f\n", area);

        return 0;
}
