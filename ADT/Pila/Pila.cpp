#include <iostream>
using namespace std;

template <typename T>
class Nodo {
    T x;
    Nodo<T>* succ;

    friend class Lista;

    public:
        Nodo(T val) : x(val), succ(nullptr) {}

        T getX() {return this->x;}
        Nodo<T>* getSucc() {return this->succ;}
        void setX(T val) {this->x = val;}
        void setSucc(Nodo<T>* next) {this->succ = next;}
};

template <typename T>
class Lista {
    Nodo<T>* head;

    public:
        Lista() : head(nullptr) {}

        bool isEmpty() {return this->head == nullptr;}

        Nodo<T>* getHead() {return this->head;}

        void insertHead(T x) {                                                //O(1)
            if (this->isEmpty()) {
                this->head = new Nodo<T>(x);
                return;
            }

            Nodo<T>* temp = new Nodo<T>(x);
            temp->succ = this->head;
            this->head = temp;
        }

        void insertTail(T x) {                                                //O(n) faremo esattamente n passi sempre
            if (this->isEmpty()) {
                this->head = new Nodo<T>(x);
                return;
            }

            Nodo<T>* app = this->head;
            while (app->succ != nullptr) {
                app = app->succ;
            }

            Nodo<T>* temp = new Nodo<T>(x);
            app->succ = temp;
        }

        void insertInOrder(T x) {                                               //O(n) 
            if (this->isEmpty() || x <= this->head->x) {
                this->head = new Nodo<T>(x);
                return;
            }

            Nodo<T>* app = this->head;
            while (app->x <= x && app->succ != nullptr) {
                if (app->succ->x >= x) break;
                app = app->succ;
            }

            Nodo<T>* temp = new Nodo<T>(x);
            if (app->succ == nullptr) {
                this->insertTail(x);
            }
            else {
                temp->succ = app->succ;
                app->succ = temp;
            }
        }

        void deleteHead() {                                                         //O(1)
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* temp = this->head;
            this->head = this->head->succ;
            delete temp;
        }

        void deleteTail() {                                                         //O(n) faremo esattamente n passi sempre
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* thi = this->head;
            Nodo<T>* prec = nullptr;

            while (thi->succ != nullptr) {
                prec = thi;
                thi = thi->succ;
            }

            prec->succ = nullptr;
            delete thi;
        }

        void deleteNode(T x) {                                                      //O(n)
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* thi = this->head;
            Nodo<T>* prec = nullptr;

            while (thi != nullptr || thi->x != x) {
                prec = thi;
                thi = thi->succ;
            }

            if (thi == nullptr) {
                cerr << "Errore! Il nodo cercato non e' presente nella lista." << endl;
                return;
            }

            prec->succ = thi->succ;
            delete thi;
        }

        Nodo<T>* ricerca(T x) {
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return nullptr;
            }

            Nodo<T>* app = this->head;
            while (app != nullptr || app->x != x) {
                app = app->succ;
            }

            if (app == nullptr) {
                cerr << "Errore! Il nodo cercato non e' presente nella lista." << endl;
                return nullptr;
            }

            return app;
        }
};

template <typename T>
class Stack : protected Lista<T> {
    int n_elementi = 0;

    public:
        Stack() : Lista<T>() {}

        bool isEmpty() {return this->n_elementi == 0;}

        Nodo<T>* top() {
            if (this->isEmpty()) return nullptr;

            return Lista<T>::getHead();
        }

        void push(T x) {
            Lista<T>::insertHead(x);
            this->n_elementi++;
        }

        Nodo<T>* pop() {
            if (this->isEmpty()) return nullptr;

            Nodo<T>* temp = this->top();
            Lista<T>::deleteHead();
            this->n_elementi--;
            return temp;
        }
};

int main() {
    return 0;
}