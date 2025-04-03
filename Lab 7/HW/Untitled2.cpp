#include <iostream>
using namespace std;

class Shape {
private:
    double area;

public:
    
    Shape(double a = 0.0) : area(a) {}

    
    void setArea(double a) {
        area = a;
    }

    
    double getArea() const {
        return area;
    }

    
    Shape operator+(const Shape& other) const {
        return Shape(area + other.area);
    }

    
    double Area() const {
        return area;
    }
};

int main() {
    

    return 0;
}