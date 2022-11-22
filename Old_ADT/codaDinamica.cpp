#include <iostream>
using namespace std;

class codaDinamica {
    int* melo;
    int N;
    int n_elementi
    int testa; 
    int coda;

    public:
        codaDinamica(int n) : N(n), testa(0), coda(-1), n_elementi(0) {
            melo = new int[N];
            for (int i = 0; i < N; i++) {
                melo[i] = 0;
            }
        }

        bool isEmpty() {
            if (N == 0) return true;
            else return false;
        }

        bool isFull() {
            if (n_elementi == N) return true;
            else return false;
        }
}

int main() {
    return 0;
}