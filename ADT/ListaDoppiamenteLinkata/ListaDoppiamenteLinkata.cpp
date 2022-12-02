#include <iostream>
using namespace std;

template <typename T>
class Nodo {
    T x;
    Nodo<T>* succ, *prec;

    friend class Lista;

    public:
        Nodo(T val) : x(val), succ(nullptr), prec(nullptr) {}

        T getX() {return this->x;}
        Nodo<T>* getSucc() {return this->succ;}
        Nodo<T>* getPrec() {return this->prec;}
        void setX(T val) {this->x = val;}
        void setSucc(Nodo<T>* next) {this->succ = next;}
        void setPrec(Nodo<T>* prev) {this->prec = prev;}
};

template <typename T>
class Lista {
    Nodo<T>* head, *tail;

    public:
        Lista () : head(nullptr), tail(nullptr) {}

        bool isEmpty() {return this->head == nullptr;}

        Nodo<T>* getHead() {return this->head;}

        Nodo<T>* getTail() {return this->tail;}

        void insertHead(T x) {
            if (this->isEmpty()) {
                this->head = new Nodo<T>(x);
                this->tail = this->head;
                return;
            }

            Nodo<T>* temp = new Nodo<T>(x);
            temp->succ = this->head;
            this->head->prec = temp;
            this->head = temp;
        }

        void insertTail(T x) {
            if (this->isEmpty()) {
                this->head = new Nodo<T>(x);
                this->tail = this->head;
                return;
            }

            Nodo<T>* temp = new Nodo<T>(x);
            temp->prec = this->tail;
            this->tail->succ = temp;
            this->tail = temp;
        }

        void insertInOrder(T x) {
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
                temp->prec = app;
                app->succ = temp;
                temp->succ->prec = temp;
            }
        }

        void deleteHead() {
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* temp = this->head;
            this->head = this->head->succ;
            delete temp;
        }

        void deleteTail() {
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* temp = this->tail;
            this->tail = this->tail->prec;
            delete temp;
        }

        void deleteNode(T x) {
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* thi = this->head;

            while (thi != nullptr || thi->x != x) {
                thi = thi->succ;
            }

            if (thi == nullptr) {
                cerr << "Errore! Il nodo cercato non e' presente nella lista." << endl;
                return;
            }

            thi->prec->succ = thi->succ;
            thi->succ->prec = thi->prec;
            delete thi;
        }

        Nodo<T>* ricerca(T x) {
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return nullptr;
            }

            Nodo<T>* thi = this->head;
            while (thi != nullptr || thi->x != x) {
                thi = thi->succ;
            }

            if (thi == nullptr) {
                cerr << "Errore! Il nodo cercato non e' presente nella lista." << endl;
                return nullptr;
            }

            return thi;
        }
};

int main() {
    return 0;
}