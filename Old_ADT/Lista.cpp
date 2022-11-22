#include <iostream>
using namespace std;

class Nodo {
    int val;
    Nodo* succ;

    public:
        Nodo(int n, Nodo* s) : val(n), succ(s) {}        
};

class List {
    Nodo* lista;
    int n_elementi;

    public:
        List() : n_elementi(0) {}

        void inserimentoInTesta(Nodo* testa, int elem) {
            Nodo* nuovo = new Nodo(elem, testa);
            testa = nuovo;
        }

        void eliminazioneConPos(Nodo* testa, int pos) {
            Nodo* app = testa;
            for (int i = 0; i < pos - 1; i++) {
                testa = testa->succ;
            }
            testa->succ = testa->succ->succ;
            testa = app;
        }

        void eliminazioneConElem(Nodo* testa, int elem) {
            Nodo* app = testa;
            Nodo* ant = NULL;
            while (testa->succ != nullptr) {
                if (testa->val == elem) {

                }
            }
        }

};

int main() {
    Nodo* Lista;
    Lista = new Nodo(10, Lista);
    Lista = new Nodo(5, Lista);

    return 0;
}