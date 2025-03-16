#include<iostream>
using namespace std;


class Book{
	protected:
		string genere;
	public:
		
		Book(string g):genere(g){}
};

class Novel:public Book{
	string title;
	string author;
	public:
		Novel(string g,string t,string a): Book(g), title(t),author(a){
			
		} 
		void displayDetails(){
			cout << "Genere " << genere << endl;
			cout << "Title  " << title << endl;
			cout << "Author " << author << endl;
		}
};


class Narrative:public Book{
	string title;
	string author;
	public:
		Narrative(string g,string t,string a): Book(g), title(t),author(a){
			
		} 
		void displayDetails(){
			cout << "Genere " << genere << endl;
			cout << "Title  " << title << endl;
			cout << "Author " << author << endl;
		}
};

int main(){
	
	
	
	return 0;
}