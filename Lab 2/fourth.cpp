#include<iostream>
using namespace std;
struct Employee{
	string name;
	int employee_id;
	int salary;
};
struct Organistation{
	string orginisation_name;
	int orginisation_id;
	Employee emp;
};

int main(){
	struct Organistation s1;
	cout << "Organisation Name : ";
	cin >> s1.orginisation_name;
	cout << "Organisation ID : ";
	cin >> s1.orginisation_id;
	cout << "Employee Name : ";
	cin >> s1.emp.name;
	cout << "Employee ID : ";
	cin >> s1.emp.employee_id;
	cout << "Salary : ";
	cin >> s1.emp.salary;
	system("cls");
	cout << "Organisation Name 		: " << s1.orginisation_name << endl;
	cout << "Organisation ID 		: " << s1.orginisation_id << endl;
	cout << "Employee Name 			: " << s1.emp.name << endl;
	cout << "Employee ID 			: " << s1.emp.employee_id << endl;
	cout << "Employee Salary 		: " << s1.emp.salary << endl;
	return 0;
}