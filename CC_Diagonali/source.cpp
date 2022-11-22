#include <iostream>
#include <fstream>
using namespace std;

int* sommeDiagonali(int** matrix, int n, int m) {
    int n_diagonali = n + m - 1;
    int* arr_temp = new int[n_diagonali];
    int somma, index = 0;

    if (n <= m) {
        for (int i = n-1; i >= 0; i--) {
            somma = 0;
            for (int j = 0; j < n - i; j++) {
                somma += matrix[i+j][j];
            }
            arr_temp[index] = somma;
            index++;
        }
        for (int j = 1; j < n; j++) {
            somma = 0;
            for (int i = 0; i < n - j; i++) {
                somma += matrix[i][j];
            }
            arr_temp[index] = somma;
            index++;
        }
        return arr_temp;
    } else if (n > m) {
        for (int i = n-1; i >= 0; i--) {
            somma = 0;
            for (int j = 0; j < n - i; j++) {
                somma += matrix[i+j][j];
            }
            arr_temp[index] = somma;
            index++;
        }
        for (int j = 1; j < m; j++) {
            somma = 0;
            for (int i = 0; i < m - j; i++) {
                somma += matrix[i][j];
            }
            arr_temp[index] = somma;
            index++;
        }
        return arr_temp;
    }
}

void merge(int arr[], int start, int end, int mid) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int* arr1 = new int[n1];
    int* arr2 = new int[n2];

    for (int i = 0; i < n1; i++) {
       arr1[i] = arr[start+i]; 
    }

    for (int j = 0; j < n2; j++) {
        arr2[j] = arr[mid+j+1];
    }

    int i = 0, j = 0;

    for (int k = start; k <= end; k++) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
    }

    delete [] arr1;
    delete [] arr2;
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int q = (start + end) / 2;
        mergeSort(arr, start, q);
        mergeSort(arr, q+1, end);
        merge(arr, start, end, q);
    }
}

int main() {
    fstream input("input.txt", fstream::in);
    if (!input.is_open()) cerr << "Errore nell'apertura del file in input" << endl;
    
    fstream output("output.txt", fstream::out);
    if (!output.is_open()) cerr << "Errore nell'apertura del file in output" << endl;

    int n, m, in;

    for (int cycle = 0; cycle < 100; cycle++) {
        input >> n >> m;
        int ** matrix = new int*[n];
        for (int i = 0; i < n; i++) matrix[i] = new int[m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                input >> matrix[i][j];
            }
        }

        int* temp = new int[n+m-1];
        temp = sommeDiagonali(matrix, n, m);
        mergeSort(temp, 0, n + m - 1);

        for (int i = 0; i < n + -1; i++) {
            output << temp[i] << " ";
        }
        output << endl;
    }

    return 0;
}