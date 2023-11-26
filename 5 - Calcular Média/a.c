#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int chave;
    // Outros componentes (...)
    struct Item *proximo; // Próximo elemento da lista
} Item;

typedef struct Lista {
    Item *cabeca; // Indica o primeiro elemento da lista
    int tamanho;
} Lista;

// Implementando a função para imprimir todos os elementos da lista

void exibirLista (Lista *lista) {
    printf("Lista: ");
    Item *atual = lista->cabeca; //Inicializei atual com o primeiro item da lista
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    }
    printf("\n");
}
float calcularMedia(Lista *lista) {
    if (lista->tamanho == 0) {
        printf("A lista está vazia, não é possível calcular a média.\n");
        return 0.0;
    }

    Item *atual = lista->cabeca;
    int soma = 0;

    while (atual != NULL) {
        soma += atual->chave;
        atual = atual->proximo;
    }

    return (float)soma / lista->tamanho;
}

// Função para criar lista vazia

Lista *criarListaVazia() {
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));
    if(novaLista == NULL) {
        printf("Erro ao alocar memória para a lista. \n");
        exit(1);
    }
    novaLista->cabeca = NULL;
    novaLista->tamanho = 0;
    return novaLista;
}

// Função para inserir um elemento em posição específica da lista.

void inserirNaPosicao(Lista *lista, int posicao, Item *item) {
    if(posicao < 0 || posicao > lista->tamanho) {
        printf("Posicao invalida.\n");
        return;
    }
    if(posicao == 0) {
        item->proximo = lista->cabeca;
        lista->cabeca = item;
    } else {
        Item *temp = lista->cabeca;
        for(int i = 0; i < posicao-1; i++) {
            temp = temp->proximo;
        }
        item->proximo = temp->proximo;
        temp->proximo = item;
    }
    lista->tamanho++;    
}





// Função para remover um elemento em posição específica da lista.

void removerDaPosicao(Lista *lista, int posicao) {
    if(posicao < 0 || posicao > lista->tamanho) {
        printf("Posicao invalida.\n");
        return;
    }
    if(posicao == 0) {
        Item *temp = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
        free(temp);
    } else {
        Item *temp = lista->cabeca;
        for(int i = 0; i < posicao-1; i++) {
            temp = temp->proximo;
        }
        Item *aux = temp->proximo;
        temp->proximo = aux->proximo;
        free(aux);
    }
    lista->tamanho--;    
}









int main() {
    Lista *X = criarListaVazia();

    Item *I1 = (Item *) malloc(sizeof(Item));
    I1->chave = 10;
    Item *I2 = (Item *) malloc(sizeof(Item));
    I2->chave = 20;
    Item *I3 = (Item *) malloc(sizeof(Item));
    I3->chave = 30;    
    Item *I4 = (Item *) malloc(sizeof(Item));
    I4->chave = 40;

    inserirNaPosicao(X, 0, I1);
    inserirNaPosicao(X, 0, I2);
    inserirNaPosicao(X, 0, I3);
    inserirNaPosicao(X, 0, I4);

    printf("Tamanho: %d\n", X->tamanho);
    exibirLista (X);
    removerDaPosicao(X, 0);
    printf("Tamanho: %d\n", X->tamanho);
    exibirLista (X);
    float media = calcularMedia(X);
    printf("Média: %.2f\n", media);
}