#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == valor) {
            return meio;
        }
        else if (vetor[meio] < valor) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return inicio;
}

int main() {
    int vetor[] = {2, 5, 8, 12, 16, 20};
    int tamanho = 6;
    int valor = 10;

    int posicao = buscaBinaria(vetor, tamanho, valor);

    printf("Posicao: %d\n", posicao);

    return 0;
}