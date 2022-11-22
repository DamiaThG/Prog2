#include <iostream>
using namespace std;

#define N 30

class pilaStatica {
    int melo[N];
    int top;

    public:
        pilaStatica() {
            for (int i = 0; i < N; i++) melo[i] = 0;
            top = 0;
        }

        void push(int elem) {
            if (top == 30) exit(0);

            melo[top] = elem;
            top++;
        }

        int pop() {
            if (top == 0) return -1;

            top--;
            return melo[top+1];
        }
};

int main() {
    pilaStatica pila1;
    
    return 0;
}