// Função "calcularArea" que calcula a área de um polígono com base em seus vértices.
#include "ponto.h"

float calcularArea(Ponto *vertices, int numVertices)
{
    float area = 0.0;

    // Loop para calcular a área usando a fórmula de Shoelace.
    for (int i = 0; i < numVertices; i++)
    {
        int j = (i + 1) % numVertices;
        area += (vertices[i].X * vertices[j].Y - vertices[j].X * vertices[i].Y);
    }

    // Converte a área para um valor positivo.
    area = area / 2.0;
    if (area < 0)
        area = -area;

    return area;
}
