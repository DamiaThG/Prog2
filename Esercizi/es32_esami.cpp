#include <iostream>
#include <string.h>
using namespace std;

double function(string ***M, char c1, char c2, int n){
	int o1 = 0, o2 = 0;
	double ris;
	
	for (int i = 0; i < n; i++){
		if (M[i][i] == NULL) continue;
		for (int j = 0; j < (*M)[i][i].length(); j++){
			if ((*M)[i][i][j] == c1) o1++;
		}
	}
	
	for (int i = 0; i < n; i++){
		for (int j = n; j > 0; j--){
			if (M[i][j] == NULL) continue;
			for (int k = 0; k < (*M)[i][j].length(); k++){
				if ((*M)[i][j][k] == c2) o2++;
			}
		}
	}
	
	ris = (double) o1 / (double) o2;
	return ris;
}

int main(){
	return 0;
}
