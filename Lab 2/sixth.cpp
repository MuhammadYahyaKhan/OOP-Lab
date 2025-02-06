#include <iostream>
#include<string>
#include<algorithm>
#include <vector>
#include <string>

using namespace std;

struct Subject {
    string name;
};

struct Student {
    int ID;
    Subject subjects[3];
};

int main() {
    vector<Student> students;
    int num_students;
    
    cout << "Enter the number of students: ";
    cin >> num_students;
    
    for (int i = 0; i < num_students; ++i) {
        Student s;
        cout << "Enter ID for student " << i + 1 << ": ";
        cin >> s.ID;
        
        for (int j = 0; j < 3; ++j) {
            cout << "Enter subject " << j + 1 << " for student " << s.ID << ": ";
            cin >> s.subjects[j].name;
        }
        
        students.push_back(s);
    }
    
    for (int i = 0; i < students.size(); ++i) {
        cout << "Student ID: " << students[i].ID << "\nSubjects: ";
        for (int j = 0; j < 3; ++j) {
            cout << students[i].subjects[j].name << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
