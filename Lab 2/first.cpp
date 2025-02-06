#include<iostream>
using namespace std;

int calc(int *arr,int size,int i){
	if(i == size){
		return 0;
	}
	return *(arr + i) + calc(arr,size,i+1);
}

int main(int argc, char *argv[]){
	int size = argc - 1;
	int arr[size];
	
	for(int i = 0; i < argc;i++){
		arr[i-1] = atoi(argv[i]);
	}
	
	int sum = calc(arr,size,0);
	cout << sum;
	
	
	return 0;
}