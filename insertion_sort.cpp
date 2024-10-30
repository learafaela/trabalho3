#include <iostream>
#include <vector>
using namespace std;

// Função de ordenação usando Insertion Sort
void insertionSort(vector<float>& data) {
    for (int i = 1; i < data.size(); i++) {
        float key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Função de ordenação usando Bubble Sort
void bubbleSort(vector<float>& data) {
    for (int i = 0; i < data.size() - 1; i++) {
        for (int j = 0; j < data.size() - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

// Função de ordenação usando Selection Sort
void selectionSort(vector<float>& data) {
    for (int i = 0; i < data.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[j] < data[minIdx]) {
                minIdx = j;
            }
        }
        swap(data[i], data[minIdx]);
    }
}

// Função principal
int main() {
    int numElements;

    cout << "Digite o número de elementos do conjunto de dados: ";
    cin >> numElements;

    // Verifica se o número de elementos é válido
    while (numElements <= 0) {
        cout << "Valor incorreto. Digite um número positivo: ";
        cin >> numElements;
    }

    vector<float> data(numElements);

    cout << "Insira os valores do conjunto de dados:\n";
    for (int i = 0; i < numElements; i++) {
        cin >> data[i];
        // Verifica se o valor inserido é positivo
        while (data[i] < 0) {
            cout << "Valor incorreto. Digite um valor positivo: ";
            cin >> data[i];
        }
    }

    // Exibe lista original
    cout << "Lista original: ";
    for (float value : data) cout << value << " ";
    cout << endl;

    // Seleciona e executa o algoritmo de ordenação com base no número de elementos
    if (numElements <= 20) {
        insertionSort(data);
        cout << "Algoritmo utilizado: Insertion Sort\n";
    } else if (numElements <= 30) {
        bubbleSort(data);
        cout << "Algoritmo utilizado: Bubble Sort\n";
    } else {
        selectionSort(data);
        cout << "Algoritmo utilizado: Selection Sort\n";
    }

    // Exibe lista ordenada
    cout << "Lista ordenada: ";
    for (float value : data) cout << value << " ";
    cout << endl;

    return 0;
}
