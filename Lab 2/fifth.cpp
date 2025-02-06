#include<iostream>
using namespace std;

struct nameID{
	string name;
	int id;
};

int main(){
	int n;
	cout << "Enter the number of persons you want to add :";
	cin >> n;
	struct nameID arr[n];
	for(int i = 0; i < n; i++){
		cout << "Enter ID for person " << i+1;
		cin >> arr[i].id;
		cout << "Enter name for person " << i+1;
		cin >> arr[i].name;
	}
	cout << "Sort according to ID:" << endl;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(arr[i].id > arr[j].id){
				struct nameID temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << i+1 << ".) Name " << arr[i].name << endl;
		cout << "    ID :"<<arr[i].id << endl;
	}
	cout << "Sort according to name first Caharacter:" << endl;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(arr[i].name[0] > arr[j].name[0]){
				struct nameID temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << i+1 << ".) Name " << arr[i].name << endl;
		cout << "    ID: "<<arr[i].id << endl;
	}
	return 0;
}