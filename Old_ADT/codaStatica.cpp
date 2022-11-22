#include <iostream>
using namespace std;

#define N 10

class codaStatica {
    int melo[N];
    int n_elementi;
    int coda;

    public:
        codaStatica() : n_elementi(0) ,coda(-1) {
            for (int i = 0; i < N; i++) melo[i] = 0;
        }

        bool isEmpty() {
            if (n_elementi == 0) return true;
            else return false;
        }

        bool isFull() {
            if (coda == N-1) return true;
            else return false;
        }

        void inserimentoInCoda(int elem) {
            if (isFull()) exit(0);

            melo[++coda] = elem;
        }

        int estrazioneInTesta() {
            if (isEmpty()) return -1;

            int app = melo[0];
            for (int i = 0; i < n_elementi-1; i++) {
                melo[i] = melo[i+1];
            }
            coda--;
            n_elementi--;
            return app;
        }

        int front() {return melo[0];}


};

int main() {
    return 0;
}