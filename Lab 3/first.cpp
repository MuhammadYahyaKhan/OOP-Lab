#include<bits/stdc++.h>
using namespace std;


class User{
	public:
		int Age;
		string name;
	User(int Age,string name){
		this->Age = Age;
		this->name = name;
	}
};
int main(){
	User s(24,"Teo");
	cout << "My name is :" << s.name << endl;
	cout << "I am " << s.Age << "Year old" << endl; 
	
	
	return 0;
}