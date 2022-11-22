#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

template <typename T>
void scambio(T &a, T &b) {
    T temp = a; 
    a = b; 
    b = temp;
}

int main() {
    fstream input("input.txt", fstream::in);
    if (!input.is_open()) cerr << "Errore nell'apertura del file in input" << endl;
    
    fstream output("output.txt", fstream::out);
    if (!output.is_open()) cerr << "Errore nell'apertura del file in output" << endl;

    string str;
    int counter_char[26], counter_spazi, tot, counter, j;
    float percentuali[26];
    char caratteri[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}, caratteri_effettivi[26];
    output.precision(2);

    for (int cycle = 0; cycle < 100; cycle++) {
        for (int i = 0; i < 26; i++) counter_char[i] = 0;
        counter_spazi = 0;
        counter = 0;
        getline(input, str);
        for (int i = 0; i < str.length(); i++) {
            switch (str.at(i)) {
                case 'a': 
                    counter_char[0]++;
                    break;
                case 'b':
                    counter_char[1]++;
                    break;
                case 'c':
                    counter_char[2]++;
                    break;
                case 'd':
                    counter_char[3]++;
                    break;
                case 'e':
                    counter_char[4]++;
                    break;
                case 'f':
                    counter_char[5]++;
                    break;
                case 'g':
                    counter_char[6]++;
                    break;
                case 'h':
                    counter_char[7]++;
                    break;
                case 'i':
                    counter_char[8]++;
                    break;
                case 'j':
                    counter_char[9]++;
                    break;
                case 'k':
                    counter_char[10]++;
                    break;
                case 'l':
                    counter_char[11]++;
                    break;
                case 'm':
                    counter_char[12]++;
                    break;
                case 'n':
                    counter_char[13]++;
                    break;
                case 'o':
                    counter_char[14]++;
                    break;
                case 'p':
                    counter_char[15]++;
                    break;
                case 'q':
                    counter_char[16]++;
                    break;
                case 'r':
                    counter_char[17]++;
                    break;
                case 's':
                    counter_char[18]++;
                    break;
                case 't':
                    counter_char[19]++;
                    break;
                case 'u':
                    counter_char[20]++;
                    break;
                case 'v':
                    counter_char[21]++;
                    break;
                case 'w':
                    counter_char[22]++;
                    break;
                case 'x':
                    counter_char[23]++;
                    break;
                case 'y':
                    counter_char[24]++;
                    break;
                case 'z':
                    counter_char[25]++;
                    break;
                default: 
                    counter_spazi++;
                    break;
            }  
        }
        tot = str.length()-counter_spazi;
        j = 0;

        for (int i = 0; i < 26; i++) {
            if (counter_char[i] != 0) {
                percentuali[j] = ((float) counter_char[i] / (float) tot) * 100;
                caratteri_effettivi[j] = caratteri[i];
                counter++;
                j++;
            }
        }

        int indexMin;

        for (int i = 0; i < counter; i++) {
            indexMin = i;
            for (int j = i + 1; j < counter; j++) {
                if (percentuali[j] < percentuali[indexMin]) indexMin = j;
            }
            scambio(percentuali[i], percentuali[indexMin]);
            scambio(caratteri_effettivi[i], caratteri_effettivi[indexMin]);
        }

        for (int i = 0; i < counter; i++) output << fixed << caratteri_effettivi[i] << ":" << percentuali[i] << " ";
        output << endl;
            
    }

    input.close();
    output.close();

    return 0;
}