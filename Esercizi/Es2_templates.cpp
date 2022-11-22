#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdlib.h>
#define N 10
using namespace std;


class Punto {
    int x, y;

    public: 
        Punto() : x(0), y(0) {}

        int getX() {return x;}
        int getY() {return y;}
        void setX(int asc) {x = asc;}
        void setY(int ord) {y = ord;}

        bool operator== (Punto& obj) {
            if (x == obj.x && y == obj.y) return true;
            else return false;
        }

        friend ostream& operator<< (ostream& out, Punto obj);
        friend istream& operator>> (istream& in, Punto obj);
};

ostream& operator<< (ostream& out, Punto obj) {
    out << "(" << obj.x << "," << obj.y << ")";
    return out;
}

istream& operator>> (istream& in, Punto obj) {
    string str;
    in >> str;
    string substring = str.substr(0, str.find(",") - 1);
    str = str.substr(str.find(",") + 1);

    obj.x = stoi(substring);
    obj.y = stoi(str);
    return in;
}

template <typename T>
int ricerca(T dato, T v[], int dim) {
    if (dim == 0) return -2;
    for (int i = 0; i < dim; i++) {
        if (v[i] == dato) return i;
    }
    return -1;
}

int main() {
    srand(time(NULL));
    int P = 122 - 97;
    int input_int;
    char input_char;
    Punto input_punto;

    int interi[N];
    char caratteri[N];
    Punto punti[N];

    for (int i = 0; i < N; i++) {
        interi[i] = (rand() % 100) + 1;
        caratteri[i] = (rand() % P) + 97;
        punti[i].setX((rand() % 100) + 1);
        punti[i].setY((rand() % 100) + 1);
    }

    cout << "array di interi" << endl;
    for (int i = 0; i < N; i++) cout << interi[i] << " ";
    cout << endl;

    cout << "array di caratteri" << endl;
    for (int i = 0; i < N; i++) cout << caratteri[i] << " ";
    cout << endl;

    cout << "array di punti" << endl;
    for (int i = 0; i < N; i++) cout << punti[i] << " ";
    cout << endl;

    cout << "Inserire il valore da cercare nell'array di interi: ";
    cin >> input_int;

    cout << "Inserire il valore da cercare nell'array di caratteri: ";
    cin >> input_char;

    cout << "Inserire il valore da cercare nell'array di punti (con notazione X,Y): ";
    cin >> input_punto;

    //if (ricerca(input, ))

    return 0;
}