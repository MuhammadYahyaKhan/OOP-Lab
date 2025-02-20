#include <iostream>
#include <cmath>
using namespace std;

class Circle {
    double radius;
    const double PI = 3.141592653589793;

public:
    // Constructor
    Circle(double r) {
        radius = r;
    }

    // Getter for area
    double getArea() const {
        return PI * radius * radius;
    }

    // Getter for perimeter (circumference)
    double getPerimeter() const {
        return 2 * PI * radius;
    }

    // Display Circle details
    void display() const {
        cout << "Circle with radius " << radius << " has: " << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

int main() {
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;

    Circle c(r);
    c.display();

    return 0;
}
