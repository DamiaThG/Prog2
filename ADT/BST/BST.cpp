#include <iostream>
using namespace std;

template <typename T>
class NodoBST {
    T x;
    NodoBST<T>* dx, * sx, *parent;
    bool verbose = false;

    public:
        NodoBST(T val, bool verbose = true) : x(val), dx(nullptr), sx(nullptr), parent(nullptr), verbose(verbose) {}

        void setDestro(NodoBST<T>* dx) {this->dx = dx;}

        void setSinistro(NodoBST<T>* sx) {this->sx = sx;}

        void setParente(NodoBST<T>* parent) {this->parent = parent;}

        void setX(T x) {this->x = x;}

        NodoBST<T>* getDestro() {return this->dx;}

        NodoBST<T>* getSinistro() {return this->sx;}

        NodoBST<T>* getParente() {return this->parent;}

        T getX() {return this->x;}

        friend ostream& operator<< (ostream& out, NodoBST<T>& nodo);
};

template <typename T>
ostream& operator<< (ostream& out, NodoBST<T>& nodo) {
    if (nodo.verbose) {
        out << "Node@" << &nodo << " key = " << nodo.x << " left = " << nodo.sx << " right = " << nodo.dx << " parent = " << nodo.parent << endl;
    } else {
        out << "key = " << nodo.x << endl;
    }

    return out;
}

template <typename T>
class BST {
    NodoBST<T>* root;

    public:
        BST() : root(nullptr) {}

        bool isEmpty() {return this->root == nullptr;}

        NodoBST<T>* getRoot() {return this->root;}

        void insert(T x) {
            if(this->isEmpty()) {
                root = new NodoBST<T>(x);
                return;
            }
            insert(root, x);
        }
        
        void insert(NodoBST<T>* ptr, T x) {
            if(ptr->getSinistro() == nullptr && x <= ptr->getX()) {
                ptr->setSinistro(new NodoBST<T>(x));
                ptr->getSinistro()->setParente(ptr);
                return;
            }
            if(ptr->getDestro() == nullptr && x > ptr->getX()) {
                ptr->setDestro(new NodoBST<T>(x));
                ptr->getDestro()->setParente(ptr);
                return;
            }
            else if(x <= ptr->getX())
                insert(ptr->getSinistro(), x);
            else
                insert(ptr->getDestro(), x);
        }

        void visita(NodoBST<T>* nodo) {cout << *nodo << endl;}

        void visitPre(NodoBST<T>* ptr) {
            if (ptr == nullptr) return;

            visita(ptr);
            visitPre(ptr->getSinistro());
            visitPre(ptr->getDestro());
        }

        void visitPre() {visitPre(this->getRoot());}

        void visitPost(NodoBST<T>* ptr) {
            if (ptr == nullptr) return;

            visitPre(ptr->getSinistro());
            visitPre(ptr->getDestro());
            visita(ptr);
        }

        void visitPost() {visitPost(this->getRoot());}

        void visitIn(NodoBST<T>* ptr) {
            if (ptr == nullptr) return;

            visitPre(ptr->getSinistro());
            vista(ptr);
            visitPre(ptr->getDestro());
        }

        void visitIn() {visitIn(this->getRoot());}
};

int main() {
    return 0;
}