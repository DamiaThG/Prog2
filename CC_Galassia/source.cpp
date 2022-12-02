#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream input("input_Galassia.txt", fstream::in);
    if (!input.is_open()) cerr << "Errore! Non e' stato possibile aprire il file in lettura." << endl;

    fstream output("output.txt", fstream::out);
    if (!output.is_open()) cerr << "Errore! Non e' stato possibile aprire il file in scrittura." << endl;

    int n;
    unsigned long long int app, max;

    for (int cycle = 1; cycle <= 100; cycle++) {
        input >> n;

        input >> max;

        for (int i = 0; i < n-1; i++) {
            input >> app;
            if (app > max) max = app;
        }

        output << max << endl;
    }

    input.close();
    output.close();

    return 0;
}