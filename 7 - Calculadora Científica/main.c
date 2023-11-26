#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    double stack[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, double value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->top++;
        stack->stack[stack->top] = value;
    } else {
        printf("Erro: Pilha está cheia.\n");
        exit(EXIT_FAILURE);
    }
}

double pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->stack[stack->top--];
    } else {
        printf("Erro: Pilha está vazia.\n");
        exit(EXIT_FAILURE);
    }
}

void calculateAndPush(Stack *stack, char operation) {
    double operand2, operand1;

    switch (operation) {
        case '+':
            operand2 = pop(stack);
            operand1 = pop(stack);
            push(stack, operand1 + operand2);
            break;
        case 'l':
            operand1 = pop(stack);
            push(stack, log10(operand1));
            break;
        case '/':
            operand2 = pop(stack);
            operand1 = pop(stack);
            push(stack, operand1 / operand2);
            break;
        case '*':
            operand2 = pop(stack);
            operand1 = pop(stack);
            push(stack, operand1 * operand2);
            break;
        case '^':
            operand2 = pop(stack);
            operand1 = pop(stack);
            push(stack, pow(operand1, operand2));
            break;
        case 's':
            operand1 = pop(stack);
            push(stack, sin(operand1 * 3.14159 / 180.0)); 
            break;
                   
        default:
            printf("Operador inválido: %c\n", operation);
            exit(EXIT_FAILURE);
    }
}

double evaluateExpression(char expression[]) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == ' ') {
            continue;
        } else {
            calculateAndPush(&stack, expression[i]);
        }
    }

    return pop(&stack);
}

int main() {
    char postfixExpression[] = "10 l 3  2 +";
    double result = evaluateExpression(postfixExpression);

    printf("Resultado: Aprox. %.3lf\n", result);

    return 0;
}
