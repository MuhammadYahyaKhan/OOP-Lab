#include <iostream>
#include <string>
using namespace std;

// Base Person class
class Person {
public:
    string name;
    string id;
    
    Person(string n, string i) : name(n), id(i) {}
    
    virtual void showInfo() {
        cout << "Name: " << name << "\nID: " << id << endl;
    }
};

// Student class
class Student : public Person {
public:
    string major;
    
    Student(string n, string i, string m) : Person(n, i), major(m) {}
    
    void showInfo() override {
        Person::showInfo();
        cout << "Major: " << major << endl;
    }
};

// Professor class
class Professor : public Person {
public:
    string department;
    
    Professor(string n, string i, string d) : Person(n, i), department(d) {}
    
    void showInfo() override {
        Person::showInfo();
        cout << "Department: " << department << endl;
    }
};

// Course class
class Course {
public:
    string code;
    string title;
    Professor* teacher;
    
    Course(string c, string t, Professor* prof) : code(c), title(t), teacher(prof) {}
    
    void showInfo() {
        cout << "Course: " << code << " - " << title << endl;
        cout << "Taught by: " << teacher->name << endl;
    }
};

int main() {
    // Create a professor
    Professor prof("Dr. Smith", "P100", "Computer Science");
    
    // Create a student
    Student student("Alice", "S200", "CS");
    
    // Create a course taught by the professor
    Course cs101("CS101", "Programming Basics", &prof);
    
    // Display information
    cout << "=== Professor ===" << endl;
    prof.showInfo();
    
    cout << "\n=== Student ===" << endl;
    student.showInfo();
    
    cout << "\n=== Course ===" << endl;
    cs101.showInfo();
    
    return 0;
}