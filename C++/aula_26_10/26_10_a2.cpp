#include <iostream>
#include <vector>
using namespace std;

int buscaBinariaPrimeiraOcorrencia(const vector<int>& v, int valor) {
    int inicio = 0;
    int fim = (int)v.size() - 1;
    int resultado = -1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (v[meio] == valor) {
            resultado = meio;
            fim = meio - 1; // procura mais à esquerda
        } else if (v[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return resultado;
}

int main() {
    vector<int> v = {2, 4, 4, 4, 7, 9, 11};
    int valor = 4;

    int posicao = buscaBinariaPrimeiraOcorrencia(v, valor);

    if (posicao == -1) {
        cout << "Valor nao encontrado." << endl;
    } else {
        cout << "A primeira ocorrencia do valor " << valor
             << " aparece na posicao " << posicao << endl;
    }

    return 0;
}
