#include <iostream>
#include <fstream>
using namespace std;

int fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    else {
        int* arr_temp = new int[n];
        arr_temp[1] = 1;
        arr_temp[2] = 1;
        for (int j = 3; j <= n; j++) {
            arr_temp[j] = arr_temp[j-1] + arr_temp[j-2];
        }
        return arr_temp[n];
    }
}

int main() {
    fstream input("input.txt", fstream::in);
    if (!input.is_open()) cerr << "Errore nell'apertura del file in input" << endl;
    
    fstream output("output.txt", fstream::out);
    if (!output.is_open()) cerr << "Errore nell'apertura del file in output" << endl;

    int n;

    for (int i = 0; i < 100; i++) {
        input >> n;
        output << fibonacci(n) << endl;
    }

    input.close();
    output.close();
    return 0;
}