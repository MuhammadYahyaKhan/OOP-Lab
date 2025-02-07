#include<iostream>
using namespace std;

class Date{
	public:
		int day;
		int month;
		int year;
	Date(int day, int month, int year){
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void getInfo(){
		cout << day << "\\" << month << "\\" << year << endl;  
	}
};

int main(){
	Date s(12,2,2024);
	s.getInfo();
	return 0;
}