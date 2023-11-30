// pilha.h
#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXP 100

typedef struct Node {
    double dado;
    struct Node *proximo;
} Node;

typedef struct {
    Node *topo;
} Pilha;

void inicializar(Pilha *pilha);
void empilhar(Pilha *pilha, double valor);
double desempilhar(Pilha *pilha);
double calcularLog(double valor);
double calcularSen(double valor);
double calcularCos(double valor);
double calcularTan(double valor);
double calcularPotencia(double base, double expoente);
double calcularRaiz(double valor);
double avaliarExpressaoPosfixa(const char *expressao);

double converterParaDouble(const char *expressao, int *posicao);

#endif 
