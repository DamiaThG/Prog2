#include <iostream>
using namespace std;
#define N 10

template <typename T>
void scambio(T &a, T &b) {
    T temp = a; 
    a = b; 
    b = temp;
}

//template <typename T>
int ricercaLineare(int arr[], int n, int key) {                                             //O(n)
    if (n == 0) return -1; //ritorno -1 nel caso in cui l'array passato sia vuoto

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return 1; //ritorno 1 quando viene trovato l'elemento
    }

    return -2; //ritorno -2 se l'elemento non viene trovato
}

//template <typename T>
int ricercaBinaria(int arr[], int n, int key) {                                                 //O(log n)
    if (n == 0) return -1; //ritorno -1 se l'array e' vuoto
    bool trovato = false;

    int start = 0, end = n-1;
    int pivot = end / 2;

    while (trovato == false && start != end) {
        if (key == arr[pivot]) trovato = true; //set di trovato a true per uscire dal ciclo
        if (key < arr[pivot]) {
            end = pivot;
            pivot = end / 2;
        }                                          //aggiorno gli indici di inizio e fine e aggiorno il pivot
        else {
            start = pivot + 1;
            pivot = (end + start) / 2;
        }
    }

    if (trovato == true) return 1; //ritorno 1 se trovo l'elemento
    else return -2; //ritorno -2 se non trovo l'elemento
}

void ordinamentoPerScambio(int arr[], int n) {                                  //O(n^2)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) scambio(arr[i], arr[j]);
        }
    }
}

void selectionSort(int arr[], int n) {                              //O(n^2)
    int indexMin;

    for (int i = 0; i < n; i++) {
        indexMin = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[indexMin]) indexMin = j;
        }
        scambio(arr[i], arr[indexMin]);
    }
}

void insertionSort(int arr[], int n) {                              //O(n^2)
    int j, app;

    for (int i = 1; i < n; i++) {
        app = arr[i];
        for (j = i; j > 0; j--) {
            if (app < arr[j-1]) 
                arr[j] = arr[j-1];
            else
                break;
        }
        arr[j] = app;
    }
}

void bubbleSort(int arr[], int n) {                                         //O(n^2)
    bool ordinato;

    do {
        ordinato = true;
        for (int i = 1; i < n; i++) {
            if (arr[i-1] > arr[i]) {
                scambio(arr[i-1], arr[i]);
                ordinato = false;
            }
        }
        n--;
    } while (ordinato == false);
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
    int arr1[N], arr2[N], arr3[N] = {1, 4, 8, 2, 5, 10, 9, 7, 6, 3};
    for (int i = 0; i < N; i++) {
        arr1[i] = i + 1;
        arr2[i] = i + 1;
    }

    //cout<<ricercaLineare(arr1, N, 6)<<endl;
    //cout<<ricercaBinaria(arr2, N, 9)<<endl;
    selectionSort(arr3, N);
    for (int i = 0; i < N; i++) cout<<arr3[i]<<endl;
    //cout<<ricercaBinaria(arr3, N, 10)<<endl;
    return 0;
}