#include <iostream>
using namespace std;

class Polynomial {
    double* coefficients;
    int degree;

public:
    // Default Constructor
    Polynomial() {
        degree = 0;
        coefficients = new double[1];
        coefficients[0] = 0.0;
    }

    // Parameterized Constructor
    Polynomial(int deg, double* coeffs) {
        degree = deg;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = coeffs[i];
        }
    }

    // Copy Constructor
    Polynomial(const Polynomial& obj) {
        degree = obj.degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = obj.coefficients[i];
        }
    }

    // Move Constructor
    Polynomial(Polynomial&& obj) noexcept {
        degree = obj.degree;
        coefficients = obj.coefficients;
        obj.coefficients = nullptr;
        obj.degree = 0;
    }

    // Destructor
    ~Polynomial() {
        delete[] coefficients;
    }

    // Get Degree
    int getDegree() const {
        return degree;
    }

    // Evaluate polynomial at x
    double evaluate(double x) const {
        double result = 0.0;
        double power = 1.0;
        for (int i = 0; i <= degree; i++) {
            result += coefficients[i] * power;
            power *= x;
        }
        return result;
    }

    // Add two polynomials
    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        double* newCoeffs = new double[maxDegree + 1]{};

        for (int i = 0; i <= degree; i++) {
            newCoeffs[i] += coefficients[i];
        }
        for (int i = 0; i <= other.degree; i++) {
            newCoeffs[i] += other.coefficients[i];
        }

        Polynomial result(maxDegree, newCoeffs);
        delete[] newCoeffs;
        return result;
    }

    // Multiply two polynomials
    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* newCoeffs = new double[newDegree + 1]{};

        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        Polynomial result(newDegree, newCoeffs);
        delete[] newCoeffs;
        return result;
    }

    // Print polynomial
    void print() const {
        for (int i = degree; i >= 0; i--) {
            cout << coefficients[i] << "x^" << i;
            if (i > 0) cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    double coeffs1[] = {3, 2, 1};  // 3 + 2x + x^2
    double coeffs2[] = {1, 4};     // 1 + 4x

    Polynomial p1(2, coeffs1);
    Polynomial p2(1, coeffs2);

    cout << "Polynomial 1: ";
    p1.print();
    cout << "Polynomial 2: ";
    p2.print();

    Polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.print();

    Polynomial product = p1.multiply(p2);
    cout << "Product: ";
    product.print();

    double x = 2.0;
    cout << "P1 evaluated at " << x << ": " << p1.evaluate(x) << endl;

    return 0;
}
