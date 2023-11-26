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

float media = calcularMedia(X);
&nbsp; &nbsp; printf("Média: %.2f\n", media);