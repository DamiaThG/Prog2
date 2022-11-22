#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream input("input.txt", std::fstream::in);
    if (input.is_open() == false) cerr << "Errore nell'apertura del file di input" << endl; 

    fstream output("output.txt", std::fstream::out);
    if (output.is_open() == false) cerr << "Errore nell'apertura del file di output" << endl;

    int n, temp, j;
    int* arr_disp;

    for (int cycle = 0; cycle < 100; cycle++) {
        input >> n;
        arr_disp = new int[n];
        j = 0;

        for (int i = 0; i < n; i++) {
            input >> temp;
            if ((temp % 2) != 0) {
                arr_disp[j] = temp;
                output << arr_disp[j] << " ";
                j++;
            }
        }

        if (cycle != 99) output << endl;
    }

    input.close();
    output.close();
    return 0;
}