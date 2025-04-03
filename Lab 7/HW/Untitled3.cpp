#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    int employeeID;

public:
    // Member functions
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }

    void displayData() {
        cout << "Employee ID: " << employeeID << endl;
    }
};

// Derived class Admin
class Admin : public Person {
private:
    string name;
    double monthlyIncome;

public:
    // Member functions
    void getData() {
        Person::getData(); // Get base class data
        cout << "Enter Employee Name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() {
        Person::displayData(); // Display base class data
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
    }

    double bonus() {
        return monthlyIncome * 12 * 0.05; // 5% of annual income
    }
};

// Derived class Accounts
class Accounts : public Person {
private:
    string name;
    double monthlyIncome;

public:
    // Member functions
    void getData() {
        Person::getData(); // Get base class data
        cout << "Enter Employee Name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() {
        Person::displayData(); // Display base class data
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
    }

    double bonus() {
        return monthlyIncome * 12 * 0.05; // 5% of annual income
    }
};

int main() {
    
    return 0;
}