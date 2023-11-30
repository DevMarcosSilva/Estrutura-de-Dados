#include "pilha.h"

int main() {
    const char *expressoes[] = {
        "3 4 + 5 *",
        "7 2 * 4 +",
        "8 5 2 4 + * +",
        "6 2 / 3 + 4 *",
        "9 5 2 8 * 4 + * +",
        "2 3 + l 5 /",
        "10 l 3 ^ 2 + ",
        "45 60 + 30 c *",
        "0.5 45 s 2 ^ + ",
        "3 4 + 5 t *"
    };

    for (int i = 0; i < sizeof(expressoes) / sizeof(expressoes[0]); ++i) {
        double resultado = avaliarExpressaoPosfixa(expressoes[i]);
        printf("Teste %d: Resultado: %.3f\n", i + 1, resultado);
    }

    return 0;
}
