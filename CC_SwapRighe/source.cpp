#include <iostream>
#include <fstream>
using namespace std;

void scambia(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int* creaArray(int **M, int r, int c) {
    int *arr = new int[r];
    int somma;

    for (int i = 0; i < r; i++) {
        somma = 0;
        for (int j = 0; j < c; j++) {
            somma += M[i][j];
        }

        arr[i] = somma;
    }

    return arr;
}

int ordinamentoAdiacenti(int* arr, int n) {
    bool ordinato = false;
    int tot_scambi = 0;

    while (!ordinato) {
        ordinato = true;

        for (int i = 1; i < n; i++) {
            if (arr[i-1] > arr[i]) {
                scambia(arr[i-1], arr[i]);
                ordinato = false;
                tot_scambi++;
            }
        }
    }

    return tot_scambi;
}

int main() {
    fstream input("input_SwapRighe.txt", fstream::in);
    if (!input.is_open()) cerr << "Errore! Non e' stato possibile aprire il file in lettura." << endl;

    fstream output("output.txt", fstream::out);
    if (!output.is_open()) cerr << "Errore! Non e' stato possibile aprire il file in scrittura." << endl;

    int **matrix, *arr, count,  r, c;

    for (int cycle = 1; cycle <= 100; cycle++) {
        input >> r >> c;

        matrix = new int*[r];
        for (int i = 0; i < r; i++) matrix[i] = new int[c];

        arr = new int[r];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                input >> matrix[i][j];
            }
        }

        arr = creaArray(matrix, r, c);

        count = ordinamentoAdiacenti(arr, r);

        output << count << endl;
    }

    input.close();
    output.close();

    return 0;
}