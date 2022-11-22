#include <iostream>
using namespace std;

class Cerchio {
    double raggio;
    public:
        Cerchio(double r) {
            raggio = r;
        };

        void setRaggio(double r) {
            raggio = r;
        };

        double getRaggio() {
            return raggio;
        };

        double perimetro() {
            return (2 * 3.14 * raggio);
        };

        double area() {
            return (3.14 * (raggio * raggio));
        };
};

int main() {
    Cerchio c1(3.5);

    cout<<"il perimetro e' "<<c1.perimetro()<<endl;
    cout<<"l'area e' "<<c1.area()<<endl;

    return 0;
}
