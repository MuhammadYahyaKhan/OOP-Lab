#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;

class PolynomialUtils; // Forward declaration

class Polynomial {
private:
    vector<int> coefficients;
    
    // Helper function to remove leading zeros
    void trim() {
        while (coefficients.size() > 1 && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

public:
    // Constructors
    Polynomial() = default;
    
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        trim();
    }

    // Accessor
    const vector<int>& getCoefficients() const { return coefficients; }

    // Arithmetic operators
    Polynomial operator+(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }
        
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] += other.coefficients[i];
        }
        
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }
        
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] -= other.coefficients[i];
        }
        
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        
        return Polynomial(result);
    }

    // Output operator
    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) {
            os << "0";
            return os;
        }

        bool firstTerm = true;
        
        for (int i = p.coefficients.size() - 1; i >= 0; --i) {
            int coeff = p.coefficients[i];
            
            if (coeff == 0) continue;
            
            // Handle sign
            if (!firstTerm) {
                if (coeff > 0) {
                    os << " + ";
                } else {
                    os << " - ";
                    coeff = -coeff;
                }
            } else if (coeff < 0) {
                os << "-";
                coeff = -coeff;
            }
            
            // Print coefficient
            if (coeff != 1 || i == 0) {
                os << coeff;
            }
            
            // Print variable part
            if (i > 0) {
                os << "x";
                if (i > 1) {
                    os << "^" << i;
                }
            }
            
            firstTerm = false;
        }
        
        return os;
    }

    // Friend declaration for utility class
    friend class PolynomialUtils;
};

class PolynomialUtils {
public:
    // Evaluate polynomial at point x
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        for (size_t i = 0; i < p.coefficients.size(); ++i) {
            result += p.coefficients[i] * static_cast<int>(pow(x, i));
        }
        return result;
    }

    // Compute derivative of polynomial
    static Polynomial derivative(const Polynomial& p) {
        if (p.coefficients.size() <= 1) {
            return Polynomial({0});
        }
        
        vector<int> deriv(p.coefficients.size() - 1);
        for (size_t i = 1; i < p.coefficients.size(); ++i) {
            deriv[i - 1] = p.coefficients[i] * i;
        }
        
        return Polynomial(deriv);
    }
};

int main() {
    // Test cases
    Polynomial p1({1, 2, 3}); // 3x^2 + 2x + 1
    Polynomial p2({-1, 0, 4}); // 4x^2 - 1
    Polynomial p3({0, 1}); // x
    
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    
    cout << "p1 + p2: " << p1 + p2 << endl;
    cout << "p1 - p2: " << p1 - p2 << endl;
    cout << "p1 * p3: " << p1 * p3 << endl;
    
    cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << endl;
    cout << "Evaluate p1 at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    
    return 0;
}