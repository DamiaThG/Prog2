#include <iostream>
using namespace std;

template <typename T>
class Nodo {
    T x;
    Nodo<T>* succ, *prec;
    friend class Lista;

    public:
        Nodo() : x(0), succ(nullptr), prec(nullptr) {}
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
            temp->setSucc(this->head);
            this->head->setPrec(temp);
            this->head = temp;
        }

        void insertTail(T x) {
            if (this->isEmpty()) {
                this->head = new Nodo<T>(x);
                this->tail = this->head;
                return;
            }

            Nodo<T>* temp = new Nodo<T>(x);
            temp->setPrec(this->tail);
            this->tail->setSucc(temp);
            this->tail = temp;
        }

        void insertInOrder(T x) {
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
                temp->setPrec(app);
                app->setSucc(temp);
                temp->getSucc()->setPrec(temp);
            }
        }

        void deleteHead() {
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* temp = this->head;
            this->head = this->head->getSucc();
            delete temp;
        }

        void deleteTail() {
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* temp = this->tail;
            this->tail = this->tail->getPrec();
            delete temp;
        }

        void deleteNode(T x) {
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return;
            }

            Nodo<T>* thi = this->head;

            while (thi != nullptr || thi->getX() != x) {
                thi = thi->getSucc();
            }

            if (thi == nullptr) {
                cerr << "Errore! Il nodo cercato non e' presente nella lista." << endl;
                return;
            }

            thi->getPrec()->setSucc(thi->getSucc());
            thi->getSucc()->setPrec(thi->getPrec());
            delete thi;
        }

        Nodo<T>* ricerca(T x) {
            if (this->isEmpty()) {
                cerr << "Errore! La lista e' vuota." << endl;
                return nullptr;
            }

            Nodo<T>* thi = this->head;
            while (thi != nullptr || thi->getX() != x) {
                thi = thi->getSucc();
            }

            if (thi == nullptr) {
                cerr << "Errore! Il nodo cercato non e' presente nella lista." << endl;
                return nullptr;
            }

            return thi;
        }
};

template <typename T>
class Coda : protected Lista<T> {
    int n_elementi = 0;

    public:
        Coda() : Lista<T>() {}

        bool isEmpty() {return this->n_elementi == 0;}

        void enqueue(T x) {
            Lista<T>::insertTail(x);
            this->n_elementi++;
        }

        Nodo<T> dequeue() {
            Nodo<T> empty;
            if (this->isEmpty()) return empty;

            Nodo<T> temp = *(Lista<T>::getHead());
            Lista<T>::deleteHead();
            this->n_elementi--;
            return temp;
        }
};

int main() {
    return 0;
}