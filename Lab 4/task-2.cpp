#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Polynomial {
private:
    vector<double> coefficients;
    int highestDegree;

public:
    // Default Constructor
    Polynomial() {
        highestDegree = 0;
        coefficients.push_back(0);
    }

    // Parameterized Constructor
    Polynomial(int degree, vector<double> coeff) {
        highestDegree = degree;
        coefficients = coeff;
    }

    // Copy Constructor (Deep copy)
    Polynomial(const Polynomial& other) {
        highestDegree = other.highestDegree;
        coefficients = other.coefficients;
    }

    // Move Constructor
    Polynomial(Polynomial&& other) noexcept {
        highestDegree = other.highestDegree;
        coefficients = move(other.coefficients); 
        other.highestDegree = 0;  
    }

    // Destructor
    ~Polynomial() {
        cout << "Destructor Called" << endl;
    }

    
    int getDegree() const {
        return highestDegree;
    }


    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= highestDegree; ++i) {
            result += coefficients[i] * pow(x, i);  
        }
        return result;
    }

    // Add two polynomials
    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(highestDegree, other.highestDegree);
        vector<double> resultCoefficients(maxDegree + 1, 0);

       
        for (int i = 0; i <= maxDegree; ++i) {
            if (i <= highestDegree) resultCoefficients[i] += coefficients[i];
            if (i <= other.highestDegree) resultCoefficients[i] += other.coefficients[i];
        }

        return Polynomial(maxDegree, resultCoefficients);
    }

    
    Polynomial multiply(const Polynomial& other) const {
        int resultDegree = highestDegree + other.highestDegree;
        vector<double> resultCoefficients(resultDegree + 1, 0);

        
        for (int i = 0; i <= highestDegree; ++i) {
            for (int j = 0; j <= other.highestDegree; ++j) {
                resultCoefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(resultDegree, resultCoefficients);
    }

    // Display the polynomial
    void display() const {
        for (int i = highestDegree; i >= 0; --i) {
            cout << coefficients[i] << "x^" << i;
            if (i != 0) cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    // Create a polynomial 2x^2 + 3x + 1
    vector<double> coeff1 = {1, 3, 2};
    Polynomial p1(2, coeff1);
    p1.display();

    // Create another polynomial 4x^2 + 2x + 5
    vector<double> coeff2 = {5, 2, 4};
    Polynomial p2(2, coeff2);
    p2.display();

    // Add the two polynomials
    Polynomial p3 = p1.add(p2);
    cout << "Sum: ";
    p3.display();

    // Multiply the two polynomials
    Polynomial p4 = p1.multiply(p2);
    cout << "Product: ";
    p4.display();

    // Evaluate a polynomial at x = 2
    cout << "p1 evaluated at x=2: " << p1.evaluate(2) << endl;

    return 0;
}
