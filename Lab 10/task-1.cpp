#include<iostream>
#include<fstream>
using namespace std;

string encrypt(string a){
	string b = a;
	for(int i = 0; i < a.length(); i++){
		b[i] = a[i] + (i+1);
	}
	return b;
}

string decrypt(string c){
	string b = c;
	for(int i = 0; i < c.length(); i++){
		b[i] = c[i] - (i+1);
	}
	return b;
}

int main(){
	string a;
	getline(cin,a);
	fstream myFile;
	myFile.open("text.txt", ios::out);
	string b = encrypt(a);
	
	cout << "ENcrypter text in file " << endl;
	cout << b << endl;
	if(myFile.is_open()){
		myFile << b << endl;
	}else{
		cout << "can open file" << endl;
	}
	
	fstream file;
	file.open("text.txt", ios::in);
	
	if(file.is_open()){
		string c;
		getline(file,c);
		c = decrypt(c);
		cout << "string decrypted" << endl;
		cout << c << endl;
	}else{
		cout << "Cant load the file" << endl;
	}
	
	
	return 0;
}