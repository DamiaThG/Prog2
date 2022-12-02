#include <iostream>
#include <fstream>
using namespace std;

int ricercaBinaria(int arr[], int n, int key) {                                                 //O(log n)
    if (n == 0) return -1; //ritorno -1 se l'array e' vuoto
    bool trovato = false;

    int start = 0, end = n-1;
    int pivot = end / 2;
    int n_accessi = 0;

    while (trovato == false && start != end) {
        if (key == arr[pivot]) {
            trovato = true; //set di trovato a true per uscire dal ciclo
            n_accessi++;
        } else if (key < arr[pivot]) {
            end = pivot;
            pivot = end / 2;
            n_accessi++;
        }                                          //aggiorno gli indici di inizio e fine e aggiorno il pivot
        else {
            start = pivot + 1;
            pivot = (end + start) / 2;
            n_accessi++;
        }
    }

    if (trovato == true) return n_accessi; //ritorno 1 se trovo l'elemento
    else return n_accessi; //ritorno -2 se non trovo l'elemento
}

int main() {
    fstream input("input_Dicotomica.txt", fstream::in);
    if (!input.is_open()) cerr << "Errore! Non e' stato possibile aprire il file in lettura." << endl;

    fstream output("output.txt", fstream::out);
    if (!output.is_open()) cerr << "Errore! Non e' stato possibile aprire il file in scrittura." << endl;

    int n, *arr, x;

    for (int cycle = 1; cycle <= 100; cycle++) {
        input >> n;

        arr = new int[n];

        for (int i = 0; i < n; i++) input >> arr[i];

        input >> x;

        output << ricercaBinaria(arr, n, x) << endl;
    }

    input.close();
    output.close();

    return 0;
}