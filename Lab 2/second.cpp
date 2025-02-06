#include<iostream>
using namespace std;

void* func(void *arr,int size){
	int* arr1 = (int*)arr;
	for(int i = 0; i < size; i++){
		arr1[i]++;
	}
	return ((void*)arr);
}

int main(int argc, char* argv[]){
	int size = argc - 1;
	int arr[size];
	for(int i = 1; i < argc; i++){
		arr[i-1] = atoi(argv[i]);
	}
	
	void *result = func((void*)arr,size);
	for(int i = 0; i < size; i++){
		cout << arr[i] << endl;
	}
	
	
	
	return 0;
}