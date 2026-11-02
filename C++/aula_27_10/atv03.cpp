#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    int posicao = -1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == valor) {
            posicao = meio;
            fim = meio - 1;
        }
        else if (vetor[meio] < valor) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return posicao;
}

int main() {
    int vetor[] = {2, 4, 4, 4, 7, 9, 11};
    int tamanho = 7;
    int valor = 4;

    int resultado = buscaBinaria(vetor, tamanho, valor);

    printf("Primeira ocorrencia: %d\n", resultado);

    return 0;
}