#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Book{
	string bookName;
	int ISBN;
	string author;
	string publisher;
	public:
		
	void setdetail(string bookName, int ISBN, string publisher, string author){
		this->bookName = bookName;
		this->author = author;
		this->ISBN = ISBN;
		this->publisher = publisher;
	}
	void getBookInfo(){
		string sp = "  ";
		string res = bookName + sp + author + sp + to_string(ISBN) + sp + publisher;
		cout << res << endl;
	}
};
int main(){
	Book b[5];
	for(int i = 0; i < 5; i++){
		string name;
		int ISBN;
		string publisher;
		string author;
		cout << "Enter book name : "; cin >> name;
		cout << "ENter ISBN :"; cin >> ISBN;
		cout << "Enter publisher name : "; cin >> publisher;
		cout << "Enter author name : "; cin >> author;
		b[i].setdetail(name,ISBN,publisher,author);
	}
	for(int i = 0; i < 5; i++){
		b[i].getBookInfo();	
	}
	
	return 0;
}