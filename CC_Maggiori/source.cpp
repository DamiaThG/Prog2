#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream input("input.txt", fstream::in);
    if (!input.is_open()) cerr << "Errore nell'apertura del file in input" << endl;

    fstream output("output.txt", fstream::out);
    if(!output.is_open()) cerr << "Errore nell'apertura del file in output" << endl;

    int* arr_maggiori, n, x, temp, counter, j;
    
    for (int cycle = 0; cycle < 100; cycle++) {
        input >> n >> x;
        arr_maggiori = new int[n];
        counter = 0;
        j = 0;
        for (int i = 0; i < n; i++) {
            input >> temp;
            if (temp > x) {
                arr_maggiori[j] = temp;
                counter++;
                j++;
            }
        }

        output << counter << " ";
        for (int i = 0; i < counter; i++) output << arr_maggiori[i] << " ";
        output << endl;
    }
    return 0;
}