#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	string firstName = argv[1];
	string secondName = argv[2];
	
	float sum = 0;
	for(int i = 0; i < 5; i++){
		sum += stof(argv[i+3]);
	}
	float avg = sum/5.0;
	printf("%.2f",avg);
	
	
	return 0;
}