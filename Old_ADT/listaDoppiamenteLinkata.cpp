#include <iostream>
using namespace std;

class listaDL {
    int val;
    listaDL* succ;
    listaDL* prec;

    public:
        listaDL(int v, listaDL* s, listaDL* p) : val(v), succ(s), prec(p) {}
        listaDL(int v) : val(v), succ(nullptr), prec(nullptr) {}
        listaDL() : val(0), succ(nullptr), prec(nullptr) {}

        void inserimentoInTesta(listaDL* list, int elem) {
            listaDL* app = new listaDL(elem, list, nullptr);
            list = app;
        }

        void inserimentoInPos(listaDL* list, int elem, int pos) {
            listaDL* testa = list;
            for (int i = 0; i < pos; i++) list = list->succ;
            listaDL* precedente = list->prec;
            listaDL* app = new listaDL(elem, list, list->prec);
            list->prec = app;
            precedente->succ = app;
            list = testa;
        }

        bool isEmpty(listaDL* list) {
            if (list == nullptr) return true;
            else return false;
        }

        void visitaLista(listaDL* list) {
            if (isEmpty(list)) cout<<"La lista e' vuota"<<endl;

            listaDL* app = list;
            int counter = 0;
            do {
                counter++;
                cout<<"L'elemento "<<counter<<" della lista e': "<<list->val<<endl;
                list = list->succ;
            } while (list->succ != nullptr);
        }
};

int main() {
    listaDL* lista;
    for (int i = 0; i < 10; i++) lista->inserimentoInTesta(lista, i);

    lista->visitaLista(lista);
    return 0;
}