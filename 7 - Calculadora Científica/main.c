#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TAMANHO_MAX 100

typedef struct {
    double pilha[TAMANHO_MAX];
    int topo;
} Pilha;

int ehNumerico(char c) {
    return (c >= '0' && c <= '9') || c == '.';
}

void empilhar(Pilha *pilha, double valor) {
    if (pilha->topo < TAMANHO_MAX - 1) {
        pilha->topo++;
        pilha->pilha[pilha->topo] = valor;
    } else {
        printf("Erro: Pilha está cheia.\n");
        exit(EXIT_FAILURE);
    }
}

double desempilhar(Pilha *pilha) {
    if (pilha->topo >= 0) {
        return pilha->pilha[pilha->topo--];
    } else {
        printf("Erro: Pilha está vazia.\n");
        exit(EXIT_FAILURE);
    }
}

void calcularEEmpilhar(Pilha *pilha, char operacao) {
    double operando2, operando1;

    switch (operacao) {
        case '+':
            operando2 = desempilhar(pilha);
            operando1 = desempilhar(pilha);
            empilhar(pilha, operando1 + operando2);
            break;
        case 'l':
            operando1 = desempilhar(pilha);
            empilhar(pilha, log10(operando1));
            break;
        case '^':
            operando2 = desempilhar(pilha);
            operando1 = desempilhar(pilha);
            empilhar(pilha, pow(operando1, operando2));
            break;
        case 's':
            operando1 = desempilhar(pilha);
            empilhar(pilha, sin(operando1 * 3.14 / 180.0)); // Converter graus para radianos para a função seno
            break;
        case '/':
            operando2 = desempilhar(pilha);
            operando1 = desempilhar(pilha);
            empilhar(pilha, operando1 / operando2);
            break;
        default:
            if (ehNumerico(operacao)) {
                empilhar(pilha, atof(&operacao));
            } else {
                printf("Operador inválido: %c\n", operacao);
                exit(EXIT_FAILURE);
            }
    }
}

double avaliarExpressao(char expressao[]) {
    Pilha pilha;
    pilha.topo = -1;

    for (int i = 0; i < strlen(expressao); i++) {
        if (isdigit(expressao[i]) || expressao[i] == '.') {
            empilhar(&pilha, atof(&expressao[i]));
            while (isdigit(expressao[i + 1]) || expressao[i + 1] == '.') {
                i++;
            }
        } else if (expressao[i] == ' ') {
            continue;
        } else {
            calcularEEmpilhar(&pilha, expressao[i]);
        }
    }

    return desempilhar(&pilha);
}

int main() {
    char expressaoPosfixa[] = "0.5 45 s 2  + ";
    double resultado = avaliarExpressao(expressaoPosfixa);

    printf("Resultado: %.3lf\n", resultado);

    return 0;
}
