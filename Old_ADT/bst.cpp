#include <iostream>
using namespace std;

class Nodo {
    public:
        Nodo* left, *right, *father;
        int val;
        Nodo(Nodo* sx, Nodo* dx, Nodo* pa, int v) : left(sx), right(dx), father(pa), val(v) {}
        Nodo(int v) : left(nullptr), right(nullptr), father(nullptr), val(v) {}
};

class bst {
    Nodo* root;

    public:
        void inserimento(Nodo* r, int elem) {
            Nodo* x = r;
            Nodo* padre = nullptr;

            while (x != nullptr) {
                padre = x;
                if (elem < x->val) x = x->left;
                else x = x->right;
            }

            x = new Nodo(nullptr, nullptr, padre, elem);
            
            if (padre == nullptr) r = x;
            else if (x->val < padre->val) padre->left = x;
            else padre->right = x;
        }

        void visitaPreorder(Nodo* r) {
            if (r != nullptr) {
                cout << r->val << " ";
                visitaPreorder(r->left);
                visitaPreorder(r->right);
            }
        }

        void visitaInorder(Nodo* r) {
            if (r != nullptr) {
                visitaInorder(r->left);
                cout << r->val << " ";
                visitaInorder(r->right);
            }
        }

        void visitaPostorder(Nodo* r) {
            if (r != nullptr) {
                visitaPostorder(r->left);
                visitaPostorder(r->right);
                cout << r->val << " ";
            }
        }

        Nodo* ricerca(Nodo* r, int elem) {
            if (r == nullptr || elem == r->val) return r;
            if (elem < r->val) return ricerca(r->left, elem);
            else return ricerca(r->right, elem);
        }

        Nodo* max(Nodo* r) {
            Nodo* x = r;
            while (x != nullptr) x = x->right;
            return x;
        }

        Nodo* min(Nodo* r) {
            Nodo* x = r;
            while (x != nullptr) x = x->left;
            return x;
        }

        void trapianta(Nodo* r, Nodo* u, Nodo* v) {
            if (u->father == nullptr) r = v;
            else if (u == u->father->left) u->father->left = v;
            else u->father->right = v;
            if (v != nullptr) v->father = u->father;
        }

        void cancellazione(Nodo* elem) {
            if (elem->left == nullptr) trapianta(this->root, elem, elem->right);
            else if (elem->right == nullptr) trapianta(this->root, elem, elem->left);
            else {
                Nodo* y = min(this->root->right);
                if (y->father != elem) {
                    trapianta(this->root, y, y->right);
                    y->right = elem->right;
                    y->right->father = y;
                }
                trapianta(this->root, elem, y);
                y->left = elem->left;
                y->left->father = y;
            }
        }

};

int main() {
    bst* Lista = new bst;
    Lista->inserimento(Lista, 6);
    Lista->inserimento(Lista, 12);
    Lista->inserimento(Lista, 20);
    Lista->inserimento(Lista, 18);
    Lista->inserimento(Lista, 2);
    Lista->inserimento(Lista, 8);
    Lista->visitaInorder(Lista);

    delete Lista;
    return 0;
}