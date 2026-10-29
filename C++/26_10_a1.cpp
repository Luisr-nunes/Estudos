#include <iostream>
#include <vector>
using namespace std;

vector<int> buscaSequencialTodos(const vector<int>& v, int valor) {
    vector<int> posicoes;

    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] == valor) {
            posicoes.push_back(i);
        }
    }

    return posicoes;
}

int buscaBinariaInsercao(const vector<int>& v, int valor) {
    int inicio = 0;
    int fim = (int)v.size() - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (v[meio] == valor) {
            return meio;
        }

        if (v[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return inicio;
}

int main() {
    vector<int> vetor = {4, 8, 2, 8, 5, 8, 1};
    int valor = 8;

    vector<int> posicoes = buscaSequencialTodos(vetor, valor);

    cout << "Busca sequencial para o valor " << valor << ": ";
    if (posicoes.empty()) {
        cout << "valor nao encontrado" << endl;
    } else {
        for (size_t i = 0; i < posicoes.size(); i++) {
            cout << posicoes[i];
            if (i + 1 < posicoes.size()) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    vector<int> vetorOrdenado = {1, 2, 4, 5, 8, 8, 8};
    int valorParaInserir = 6;

    cout << "Busca binaria: o valor " << valorParaInserir
         << " deve ser inserido na posicao "
         << buscaBinariaInsercao(vetorOrdenado, valorParaInserir) << endl;

    return 0;
}
