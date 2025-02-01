#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	
	int size = argc - 1;
	float arr[size];
	for(int i = 1; i < argc; i++){
		arr[i-1] = stof(argv[i]);
	}
	
	for(int i = 0; i < size-1; i++){
		for(int j = i+1; j < size; j++){
			int first = *(arr + i);
			int second = *(arr + j);
			if(first > second){
				int temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			} 
		}
	}
	
	int highest = arr[size -1];
	for(int i = size -1; i >= 0; i--){
		if(arr[i] != highest){
			cout << arr[i];
			return 0;
			
		}
	}
	
	return 0;
}
