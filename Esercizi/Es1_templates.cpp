#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 10

class Rect {
    int base, altezza, area;

    public:
        Rect(int b, int h) : base(b), altezza(h), area(b*h) {}
        Rect() : base(0), altezza(0), area(0) {}

        int getBase() {return base;}
        int getAltezza() {return altezza;}
        int getArea() {return area;}
        int calcolaArea() {return (base*altezza);}
        void setBase(int b) {base = b;}
        void setAltezza(int h) {altezza = h;}
        void setArea(int a) {area = a;}

        bool operator> (Rect& obj) {
            if (area > obj.area) return true;
            else return false;
        }
};

template <typename T>
void bubbleSort(T a[], int n) {
    bool ordinato;
    do {
        ordinato = true;
        for (int i = 1; i < n; i++) {
            if (a[i-1] > a[i]) {
                T app = a[i-1];
                a[i-1] = a[i];
                a[i] = app;
                ordinato = false;
            }
        }
        n--;
    } while(ordinato == false);
}

/*void bubbleSort (Rect a[], int n) {
    bool ordinato;
    do {
        ordinato = true;
        for (int i = 1; i < n; i++) {
            if (a[i-1].getArea() > a[i].getArea()) {
                Rect app;
                app.setBase(a[i-1].getBase());
                app.setAltezza(a[i-1].getAltezza());
                app.setArea(a[i-1].getArea());
                a[i-1].setBase(a[i].getBase());
                a[i-1].setAltezza(a[i].getAltezza());
                a[i-1].setArea(a[i].getArea());
                a[i].setBase(app.getBase());
                a[i].setAltezza(app.getAltezza());
                a[i].setArea(app.getArea());
                ordinato = false;
            }
        }
        n--;
    } while(ordinato == false);
}*/

int main() {
    int interi[N];
    char caratteri[N];
    Rect rettangoli[N];
    int P = 122 - 97;

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        interi[i] = ((rand() % 100) + 1);
        caratteri[i] = ((rand() % P) + 97);
        rettangoli[i].setBase((rand() % 100) + 1);
        rettangoli[i].setAltezza((rand() % 100) + 1);
        rettangoli[i].setArea(rettangoli[i].getBase() * rettangoli[i].getAltezza());
    }

    cout << "Array di interi non ordinato:" << endl;
    for (int i = 0; i < N; i++) cout << interi[i] << " ";
    cout << endl << endl;

    cout << "Array di caratteri non ordinato:" << endl;
    for (int i = 0; i < N; i++) cout << caratteri[i] << " ";
    cout << endl << endl;

    cout << "Array di rettangoli non ordinato (si mostra l'area):" << endl;
    for (int i = 0; i < N; i++) cout << rettangoli[i].getArea() << " ";
    cout << endl << endl;

    bubbleSort(interi, N);
    bubbleSort(caratteri, N);
    bubbleSort(rettangoli, N);

    cout << "Array di interi ordinato:" << endl;
    for (int i = 0; i < N; i++) cout << interi[i] << " ";
    cout << endl << endl;

    cout << "Array di caratteri ordinato:" << endl;
    for (int i = 0; i < N; i++) cout << caratteri[i] << " ";
    cout << endl << endl;

    cout << "Array di rettangoli ordinato (si mostra l'area):" << endl;
    for (int i = 0; i < N; i++) cout << rettangoli[i].getArea() << " ";
    cout << endl << endl;

    return 0;
}