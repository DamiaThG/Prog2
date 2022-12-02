#include <iostream>
using namespace std;

template <typename T>
class NodoBST {
    T x;
    NodoBST<T>* dx, * sx, *parent;
    bool verbose = false;

    friend class BST;

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

        friend ostream& operator<< (ostream& out, NodoBST<T>& nodo) {
            if (nodo.verbose) {
                out << "Node@" << &nodo << " key = " << nodo.x << " left = " << nodo.sx << " right = " << nodo.dx << " parent = " << nodo.parent << endl;
            } else {
                out << "key = " << nodo.x << endl;
            }

            return out;
        }
};

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
            if(ptr->sx == nullptr && x <= ptr->x) {
                ptr->sx = new NodoBST<T>(x);
                ptr->sx->parent = ptr;
                return;
            }
            if(ptr->dx == nullptr && x > ptr->x) {
                ptr->dx = new NodoBST<T>(x);
                ptr->dx->parent = ptr;
                return;
            }
            else if(x <= ptr->x)
                insert(ptr->sx, x);
            else
                insert(ptr->dx, x);
        }

        void visita(NodoBST<T>* nodo) {cout << *nodo << endl;}

        void visitPre(NodoBST<T>* ptr) {
            if (ptr == nullptr) return;

            visita(ptr);
            visitPre(ptr->sx);
            visitPre(ptr->dx);
        }

        void visitPre() {visitPre(this->getRoot());}

        void visitPost(NodoBST<T>* ptr) {
            if (ptr == nullptr) return;

            visitPre(ptr->sx);
            visitPre(ptr->dx);
            visita(ptr);
        }

        void visitPost() {visitPost(this->getRoot());}

        void visitIn(NodoBST<T>* ptr) {
            if (ptr == nullptr) return;

            visitIn(ptr->sx);
            vista(ptr);
            visitIn(ptr->dx);
        }

        void visitIn() {visitIn(this->getRoot());}

        NodoBST<T>* ricerca(T x) {ricerca(this->getRoot(), x);}

        NodoBST<T>* ricerca(NodoBST<T>* ptr, T x) {
            if (ptr == nullptr) return nullptr;
            if (ptr->x == x) return ptr;

            if (x <= ptr->x) ricerca(ptr->sx, x);
            else ricerca(ptr->dx, x);

            return nullptr;
        }

        NodoBST<T>* min() {return min(this->getRoot());}

        NodoBST<T>* min(NodoBST<T>* nodo) {
            if (this->isEmpty()) return nullptr;

            NodoBST<T>* ptr = nodo;
            while (ptr->sx) ptr = ptr->sx;

            return ptr;
        }

        NodoBST<T>* max() {return max(this->getRoot());}

        NodoBST<T>* max(NodoBST<T>* nodo) {
            if (this->isEmpty()) return nullptr;

            NodoBST<T>* ptr = nodo;
            while (ptr->dx) ptr = ptr->dx;

            return ptr;
        }

        NodoBST<T>* successore(NodoBST<T>* nodo) {
            if (this->isEmpty()) return nullptr;

            if (nodo->dx) return this->min(nodo->dx);

            NodoBST<T>* p = nodo->parent;

            while (p != nullptr && nodo == p->dx) {
                nodo = p;
                p = p->parent;
            }

            return p;
        }

        NodoBST<T>* predecessore(NodoBST<T>* nodo) {
            if (this->isEmpty()) return nullptr;

            if (nodo->sx) return this->max(nodo->sx);

            NodoBST<T>* p = nodo->parent;

            while (p != nullptr && nodo == p->sx) {
                nodo = p;
                p = p->parent;
            }

            return p;
        }

        NodoBST<T>* remove(NodoBST<T>* nodo) {
            if (nodo == this->getRoot() && nodo->dx == nullptr && nodo->sx == nullptr) {
                this->root = nullptr;
                return nodo;
            }

            if (nodo->dx == nullptr && nodo->sx == nullptr) {
                if (nodo->parent->dx == nodo) nodo->parent->dx = nullptr;
                else if (nodo->parent->sx == nodo) nodo->parent->sx = nullptr;

                return nodo;
            } 

            if (nodo->dx != nullptr && nodo->sx == nullptr) {
                nodo->dx->parent = nodo->parent;

                if (nodo->parent->sx == nodo) nodo->parent->sx = nodo->dx;
                else if (nodo->parent->dx == nodo) nodo->parent->dx = nodo->dx;

                return nodo;
            }

            if (nodo->dx == nullptr && nodo->sx != nullptr) {
                nodo->sx->parent = nodo->parent;

                if (nodo->parent->sx == nodo) nodo->parent->sx = nodo->sx;
                else if (nodo->parent->dx == nodo) nodo->parent->dx = nodo->sx;

                return nodo;
            }

            return nullptr;
        }

        NodoBST<T>* remove(T x) {
            if (this->isEmpty()) return nullptr;

            NodoBST<T>* nodo = this->ricerca(x);
            if (nodod == nullptr) return nullptr;

            NodoBST<T>* toDelete = this->remove(nodo);
            if (toDelete != nullptr) return toDelete;

            NodoBST<T>* succ = this->successore(nodo);
            T temp = nodo->x;
            nodo->x = succ->x;
            succ->x = temp;

            toDelete = this->remove(succ);

            return toDelete;
        }
};

int main() {
    return 0;
}