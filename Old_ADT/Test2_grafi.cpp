#include <iostream>
using namespace std;

class Node {
    int val;
    Node* succ;
    friend class List;

    public:
        Node() : val(0), succ(nullptr) {}
        Node(int v) : val(v), succ(nullptr) {}
        Node(int v, Node* s) : val(v), succ(s) {}

        Node* getNext() {return this->succ;}
};

class List {
    Node* head;

    public:
        List() : head(nullptr) {}

        bool isEmpty() {return head == nullptr;}

        void inHead(int v) {
            if (this->isEmpty()) {
                Node* temp = new Node(v);
                this->head = temp;
                return;
            }

            Node* tempor = new Node(v, this->head);
            this->head = tempor;
        }

        void inTail(int v) {
            if (this->isEmpty()) {
                inHead(v);
                return;
            }

            Node* ptr = head;
            while (ptr->getNext() != nullptr) {
                ptr = ptr->getNext();
            }
            Node* temp = new Node(v);
            ptr->succ = temp;
        }
};

int main() {
    return 0;
}