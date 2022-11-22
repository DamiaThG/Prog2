#include <iostream>
using namespace std;

int sum(int a, int b){
	if (b == 0)
		return a;
	return 1 + sum(a, b-1);		
}

int fatt(int n){
	if (n == 0)
		return 1;
	return n * fatt(n-1);	
}

int fibonacci(int n){
	if (n == 0 || n == 1)
		return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci_iterativo(int n){
	if (n == 0 || n == 1)
		return 1;
	//somma1 rappresenta il numero fino a n-1, somma2 invece fino a n-2	
	int somma1 = 1, somma2 = 1, aux;
	for (int i = 2; i <= n; i++){
		aux = somma2;
		somma2 = somma1;
		somma1 = aux + somma2;
	}
	return somma1;
}

int main(){
	int somma1 = sum(3, 6);
	int fatt1 = fatt(0), fatt2 = fatt(1), fatt3 = fatt(10);
	int fib1 = fibonacci(1), fib2 = fibonacci(3), fib3 = fibonacci(5);
	
	cout<<"la somma tra 3 e 6 e': "<<somma1<<endl;
	
	cout << "il fattoriale di 0 e': " << fatt1 << endl;
	cout << "il fattoriale di 1 e': " << fatt2 << endl;
	cout << "il fattoriale di 10 e': " << fatt3 << endl;
	
	cout << "il primo numero di fibonacci e': " << fib1 << endl;
	cout<<"il terzo numero di fibonacci e': "<<fib2<<endl;
	cout<<"il quinto numero di fibonacci e': "<<fib3<<endl;
	return 0;
}
