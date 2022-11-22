#include <iostream>
using namespace std;

template <typename T> class MyArray{
	
	int length = 0;
	T* array;
	
	public:
		MyArray(int n) : length(n){
			array = new T[length];
		}
		
		T at(int i){
			return array[i];
		}
		
		void at(T arr, int i){
			array[i] = arr;
		}
		
		int size(){
			return length;
		}	
		
		T* getPointer();
};

int main(){
	MyArray<int> array(10);
	return 0;
}
