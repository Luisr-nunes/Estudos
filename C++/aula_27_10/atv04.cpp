#include <stdio.h>

void insertionSort(int vetor[], int tamanho) {
    int i, j, chave;

    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;
    }
}

int contarAcimaLimite(int vetor[], int tamanho, int limite) {
    int contador = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > limite) {
            contador++;
        }
    }

    return contador;
}

int main() {
    int tempos[] = {35, 10, 50, 20, 45, 15, 60};
    int tamanho = 7;
    int limite;

    insertionSort(tempos, tamanho);

    printf("Tempos ordenados: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", tempos[i]);
    }

    printf("\nInforme o limite de espera: ");
    scanf("%d", &limite);

    int quantidade = contarAcimaLimite(tempos, tamanho, limite);

    printf("Pacientes que esperaram mais de %d minutos: %d\n",
           limite, quantidade);

    return 0;
}