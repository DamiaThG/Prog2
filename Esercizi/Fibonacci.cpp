#include <iostream>
using namespace std;

int fibR(int n) {
    if (n == 0 || n == 1) return 1;
    return fibR(n - 1) + fibR(n - 2);
}

int main() {
    cout << fibR(1000) << endl;
    return 0;
}