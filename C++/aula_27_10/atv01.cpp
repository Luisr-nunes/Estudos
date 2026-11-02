#include <iostream>

void buscaSequencial(int vetor[], int tamanho, int valor) {
    int encontrou = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            cout<<"Encontrado na posicao: " << i << "\n";
            encontrou = 1;
        }
    }

    if (!encontrou) {
        cout<<"Valor nao encontrado.\n";
    }
}

int main() {
    int vetor[] = {4, 8, 2, 8, 5, 8, 1};
    int tamanho = 7;
    int valor = 8;

    buscaSequencial(vetor, tamanho, valor);

    return 0;
}