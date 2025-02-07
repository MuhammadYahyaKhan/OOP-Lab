#include<iostream>
using namespace std;

class Employee{
	public:
		string firstName;
		string lastName;
		double salary;
	Employee(double salary, string firstName, string lastName){
		this->salary = salary;
		this->firstName = firstName;
		this->lastName = lastName;
	}
};

int main(){
	Employee s(123.23,"asd","sasdad");
	Employee a(123.24,"asdas","sasdadas");
	cout << "First name : " << s.firstName << " \tLast Name: " << s.lastName << endl;
	cout << "Yearly Salary :" << s.salary * 12 << endl;
	cout << "First name : " << a.firstName << " \tLast Name: " << a.lastName << endl;
	cout << "Yearly Salry :" << a.salary*12 << endl;
	cout << "\n\nSalry after increment\n";
	
	
	cout << "First name : " << s.firstName << " \tLast Name: " << s.lastName << endl;
	cout << "Yearly Salary :" << s.salary * 12 * 1.1 << endl;
	cout << "First name : " << a.firstName << " \tLast Name: " << a.lastName << endl;
	cout << "Yearly Salry :" << a.salary*12 *1.1 << endl;
	
	return 0;
}