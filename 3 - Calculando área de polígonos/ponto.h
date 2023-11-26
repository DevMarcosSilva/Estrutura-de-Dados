// Este arquivo de cabeçalho (ponto.h) define uma estrutura "Ponto" com coordenadas X e Y e declara a função "calcularArea".
#define PONTO_H

typedef struct {
    float X;
    float Y;
} Ponto;

float calcularArea(Ponto *vertices, int numVertices);
