#include<iostream>
#include<cmath> 
using namespace std;

class Shape {
protected:
    string color;
    float positionX, positionY; // Basic position (interpretation varies by shape)
    float borderThickness;
    
public:
    Shape(float x, float y, string col, float border = 1.0) 
        : positionX(x), positionY(y), color(col), borderThickness(border) {}
        
    virtual void draw() {
        cout << "Drawing a generic shape at (" << positionX << "," << positionY 
             << ") with color " << color << endl;
    }
    
    virtual float calculateArea() {
        cout << "Area calculation not defined for generic shape" << endl;
        return 0;
    }
    
    virtual float calculatePerimeter() {
        cout << "Perimeter calculation not defined for generic shape" << endl;
        return 0;
    }
    
    virtual ~Shape() {} // Virtual destructor for proper cleanup
};

class Circle : public Shape {
private:
    float radius;
    
public:
    Circle(float x, float y, float r, string col, float border = 1.0) 
        : Shape(x, y, col, border), radius(r) {}
        
    void draw() override {
        cout << "Drawing a circle at center (" << positionX << "," << positionY 
             << ") with radius " << radius << " and color " << color << endl;
    }
    
    float calculateArea() override {
        return M_PI * radius * radius;
    }
    
    float calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    float width, height;
    
public:
    Rectangle(float x, float y, float w, float h, string col, float border = 1.0) 
        : Shape(x, y, col, border), width(w), height(h) {}
        
    void draw() override {
        cout << "Drawing a rectangle at top-left (" << positionX << "," << positionY 
             << ") with width " << width << ", height " << height 
             << " and color " << color << endl;
    }
    
    float calculateArea() override {
        return width * height;
    }
    
    float calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    float side1, side2, side3;
    
public:
    Triangle(float x, float y, float s1, float s2, float s3, string col, float border = 1.0) 
        : Shape(x, y, col, border), side1(s1), side2(s2), side3(s3) {}
        
    void draw() override {
        cout << "Drawing a triangle at vertex (" << positionX << "," << positionY 
             << ") with sides " << side1 << ", " << side2 << ", " << side3 
             << " and color " << color << endl;
    }
    
    float calculateArea() override {
        // Using Heron's formula
        float s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    
    float calculatePerimeter() override {
        return side1 + side2 + side3;
    }
};

class Polygon : public Shape {
private:
    int numSides;
    float sideLength;
    
public:
    Polygon(float x, float y, int sides, float length, string col, float border = 1.0) 
        : Shape(x, y, col, border), numSides(sides), sideLength(length) {}
        
    void draw() override {
        cout << "Drawing a " << numSides << "-sided polygon at center (" << positionX 
             << "," << positionY << ") with side length " << sideLength 
             << " and color " << color << endl;
    }
    
    float calculateArea() override {
        // Area formula for regular polygon: (n * s²) / (4 * tan(p/n))
        return (numSides * sideLength * sideLength) / (4 * tan(M_PI / numSides));
    }
    
    float calculatePerimeter() override {
        return numSides * sideLength;
    }
};

int main() {
    // Create some shapes
    Circle circle(100, 100, 50, "red");
    Rectangle rectangle(200, 200, 80, 60, "blue");
    Triangle triangle(300, 300, 30, 40, 50, "green");
    Polygon polygon(400, 400, 6, 25, "purple");
    
    // Test the shapes
    cout << "Testing Circle:\n";
    circle.draw();
    cout << "Area: " << circle.calculateArea() << endl;
    cout << "Perimeter: " << circle.calculatePerimeter() << endl << endl;
    
    cout << "Testing Rectangle:\n";
    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << endl;
    cout << "Perimeter: " << rectangle.calculatePerimeter() << endl << endl;
    
    cout << "Testing Triangle:\n";
    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << endl;
    cout << "Perimeter: " << triangle.calculatePerimeter() << endl << endl;
    
    cout << "Testing Polygon:\n";
    polygon.draw();
    cout << "Area: " << polygon.calculateArea() << endl;
    cout << "Perimeter: " << polygon.calculatePerimeter() << endl;
    
    return 0;
}