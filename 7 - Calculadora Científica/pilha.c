// pilha.c
#include "pilha.h"

void inicializar(Pilha *pilha) {
    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, double valor) {
    Node *novoNo = (Node *)malloc(sizeof(Node));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    novoNo->dado = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

double desempilhar(Pilha *pilha) {
    if (pilha->topo != NULL) {
        Node *temp = pilha->topo;
        double valor = temp->dado;
        pilha->topo = temp->proximo;
        free(temp);
        return valor;
    } else {
        fprintf(stderr, "Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

double calcularLog(double valor) {
    return log10(valor);
}

double calcularSen(double valor) {
    return sin(valor);
}

double calcularCos(double valor) {
    return cos(valor);
}

double calcularTan(double valor) {
    return tan(valor);
}

double calcularPotencia(double base, double expoente) {
    return pow(base, expoente);
}

double calcularRaiz(double valor) {
    return sqrt(valor);
}

double converterParaDouble(const char *expressao, int *posicao) {
    double resultado = 0.0;
    int decimalEncontrado = 0;
    int casasDecimais = 0;

    while (isdigit(expressao[*posicao]) || expressao[*posicao] == '.') {
        if (expressao[*posicao] == '.') {
            decimalEncontrado = 1;
        } else {
            resultado = resultado * 10 + (expressao[*posicao] - '0');
            if (decimalEncontrado) {
                casasDecimais++;
            }
        }
        (*posicao)++;
    }

    while (casasDecimais > 0) {
        resultado /= 10.0;
        casasDecimais--;
    }

    return resultado;
}

double avaliarExpressaoPosfixa(const char *expressao) {
    Pilha pilha;
    inicializar(&pilha);

    for (int i = 0; expressao[i] != '\0'; ++i) {
        if (isdigit(expressao[i]) || (expressao[i] == '-' && isdigit(expressao[i + 1]))) {
            int posicao = i;
            double valor = converterParaDouble(expressao, &posicao);
            empilhar(&pilha, valor);
            i = posicao - 1;
        } else if (expressao[i] == ' ' || expressao[i] == '\t') {
            continue;
        } else {
            double operando2, operando1;

            switch (expressao[i]) {
                case '+':
                    operando2 = desempilhar(&pilha);
                    operando1 = desempilhar(&pilha);
                    empilhar(&pilha, operando1 + operando2);
                    break;
                case '-':
                    operando2 = desempilhar(&pilha);
                    operando1 = desempilhar(&pilha);
                    empilhar(&pilha, operando1 - operando2);
                    break;
                case '*':
                    operando2 = desempilhar(&pilha);
                    operando1 = desempilhar(&pilha);
                    empilhar(&pilha, operando1 * operando2);
                    break;
                case '/':
                    operando2 = desempilhar(&pilha);
                    operando1 = desempilhar(&pilha);
                    if (operando2 != 0.0) {
                        empilhar(&pilha, operando1 / operando2);
                    } else {
                        fprintf(stderr, "Erro: Divisão por zero\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case 'l':
                    empilhar(&pilha, calcularLog(desempilhar(&pilha)));
                    break;
                case 's':
                    empilhar(&pilha, calcularSen(desempilhar(&pilha)));
                    break;
                case 'c':
                    empilhar(&pilha, calcularCos(desempilhar(&pilha)));
                    break;
                case 't':
                    empilhar(&pilha, calcularTan(desempilhar(&pilha)));
                    break;
                case '^':
                    operando2 = desempilhar(&pilha);
                    operando1 = desempilhar(&pilha);
                    empilhar(&pilha, calcularPotencia(operando1, operando2));
                    break;
                case 'r':
                    empilhar(&pilha, calcularRaiz(desempilhar(&pilha)));
                    break;
                default:
                    fprintf(stderr, "Erro: Operador inválido\n");
                    exit(EXIT_FAILURE);
            }
        }
    }

    return desempilhar(&pilha);
}
