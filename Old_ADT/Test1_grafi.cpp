 #include <iostream>
 using namespace std;
 #define N 30

 class Graph {
    bool matrix[N][N];
    int nodes[N];
    int n_nodi;

    public:
        Graph() : n_nodi(0) {
            for (int i = 0; i < N; i++) {
                nodes[i] = 0;
                for (int j = 0; j < N; j++) {
                    matrix[i][j] = false;
                }
            }
        }

        int search(int index) {return nodes[index];}

        int searchNumberOfArcs(int index) {
            int counter = 0;
            for (int i = 0; i < n_nodi; i++) {
                if (matrix[index][i] == true) counter++;
            }

            return counter;
        }

        int searchWithKey(int key) {
            for (int i = 0; i < n_nodi; i++) {
                if (nodes[i] == key) return i;
            }
            return -1;
        }

        bool insertNode(int elem) {
            if (n_nodi == N) return false;
            else {
                nodes[n_nodi] = elem;
                n_nodi++;
                return true;
            }
        }

        bool insertArc(int index_node1, int index_node2) {
            if (index_node1 >= n_nodi || index_node2 >= n_nodi) return false;
            else {
                matrix[index_node1][index_node2] = matrix[index_node2][index_node1] = true;
                return true;
            }
        }

        void newNode(int key, int other_node) {
            if (insertNode(key)) {
                int index = searchWithKey(other_node);
                if (insertArc(n_nodi - 1, index)) {
                    cout << "Nodo creato con successo!" << endl;
                } else {
                    cerr << "Errore! Non esiste il nodo a cui collegare quello appena creato" << endl;
                }
            } else {
                cerr << "Errore! Raggiunto il numero massimo di nodi" << endl;
            }
        }

        void newNode(int key) {
            if (insertNode(key)) cout << "Nodo creato con successo!" << endl;
            else cerr << "Errore! Nodo non inserito correttamente" << endl;
        }

        void seeGraph() {
            cout << "NODI: ";
            for (int i = 0; i < n_nodi; i++) cout << nodes[i] << " ";

            cout << endl << endl;

            cout << "---MATRICE DI ADIACENZA---" << endl << endl << "  ";
            for (int i = 0; i < n_nodi; i++) {
                cout << i << " ";
            }
            cout << endl;
            for (int i = 0; i < n_nodi; i++) {
                cout << i << " ";
                for (int j = 0; j < n_nodi; j++) cout << matrix[i][j] << " ";
                cout << endl;
            }
        }
 };

 int main() {
    Graph grafo;
    grafo.newNode(5);
    grafo.newNode(10);
    grafo.newNode(7, 5);
    grafo.newNode(18, 10);
    grafo.newNode(1, 10);
    grafo.newNode(6);
    grafo.newNode(15, 18);

    grafo.seeGraph();
    return 0;
 }