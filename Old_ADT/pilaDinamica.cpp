#include <iostream>
using namespace std;

class pilaDinamica {
    int* melo;
    int n_elementi;
    int index;

    public:
        pilaDinamica(int n) {
            n_elementi = n;
            index = 0;
            melo = new int[n_elementi];
            for (int i = 0; i < n_elementi; i++) {
                melo[i] = 0;
            }
        }

        void push(int elem) {
            if (index == n_elementi - 1) exit(0);

            index++;
            melo[index] = elem;
        }

        int pop() {
            if (index == 0) return -1;

            return melo[index--];
        }
};

int main() {
    return 0;
}