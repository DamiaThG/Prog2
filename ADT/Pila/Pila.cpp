#include <iostream>
using namespace std;

template <typename T>
class Nodo {
    T x;
    Nodo<T>* succ;

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
            temp->setSucc(this->head);
            this->head = temp;
        }

        void insertTail(T x) {                                                //O(n) faremo esattamente n passi sempre
            if (this->isEmpty()) {
                this->head = new Nodo<T>(x);
                return;
            }

            Nodo<T>* app = this->head;
            while (app->getSucc() != nullptr) {
                app = app->getSucc();
            }

            Nodo<T>* temp = new Nodo<T>(x);
            app->setSucc(temp);
        }

        void insertInOrder(T x) {                                               //O(n) 
            if (this->isEmpty() || x <= this->head->getX()) {
                this->head = new Nodo<T>(x);
                return;
            }

            Nodo<T>* app = this->head;
            while (app->getX() <= x && app->getSucc() != nullptr) {
                if (app->getSucc()->getX() >= x) break;
                app = app->getSucc();
            }

            Nodo<T>* temp = new Nodo<T>(x);
            if (app->getSucc() == nullptr) {
                this->insertTail(x);
            }
            else {
                temp->setSucc(app->getSucc());
                app->setSucc(temp);
            }
        }

        void deleteHead() {                                                         //O(1)
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* temp = this->head;
            this->head = this->head->getSucc();
            delete temp;
        }

        void deleteTail() {                                                         //O(n) faremo esattamente n passi sempre
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* thi = this->head;
            Nodo<T>* prec = nullptr;

            while (thi->getSucc() != nullptr) {
                prec = thi;
                thi = thi->getSucc();
            }

            prec->setSucc(nullptr);
            delete thi;
        }

        void deleteNode(T x) {                                                      //O(n)
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* thi = this->head;
            Nodo<T>* prec = nullptr;

            while (thi != nullptr || thi->getX() != x) {
                prec = thi;
                thi = thi->getSucc();
            }

            if (thi == nullptr) {
                cerr << "Errore! Il nodo cercato non e' presente nella lista." << endl;
                return;
            }

            prec->setSucc(thi->getSucc());
            delete thi;
        }

        Nodo<T>* ricerca(T x) {
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return nullptr;
            }

            Nodo<T>* app = this->head;
            while (app != nullptr || app->getX() != x) {
                app = app->getSucc();
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