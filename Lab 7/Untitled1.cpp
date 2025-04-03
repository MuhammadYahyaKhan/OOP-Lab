#include <iostream>
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
    int numerator;
    int denominator;

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }
    
    // Getter functions
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Arithmetic operators
    Fraction operator+(const Fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator-(const Fraction& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator*(const Fraction& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Cannot divide by zero");
        }
        int new_num = numerator * other.denominator;
        int new_den = denominator * other.numerator;
        return Fraction(new_num, new_den);
    }

    // Relational operators
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    bool operator>(const Fraction& other) const {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }

    bool operator<=(const Fraction& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>=(const Fraction& other) const {
        return (*this > other) || (*this == other);
    }

    // Friend I/O operators
    friend ostream& operator<<(ostream& os, const Fraction& f);
    friend istream& operator>>(istream& is, Fraction& f);
};

ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.numerator;
    if (f.denominator != 1) {
        os << "/" << f.denominator;
    }
    return os;
}

istream& operator>>(istream& is, Fraction& f) {
    int num, den = 1;
    char slash;
    
    is >> num;
    if (is.peek() == '/') {
        is >> slash >> den;
    }
    
    f = Fraction(num, den);
    return is;
}

int main() {
    // Test arithmetic operators
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    
    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout << "f1 + f2: " << f1 + f2 << endl;
    cout << "f1 - f2: " << f1 - f2 << endl;
    cout << "f1 * f2: " << f1 * f2 << endl;
    cout << "f1 / f2: " << f1 / f2 << endl;
    
    // relational operators
    cout << boolalpha;
    cout << "f1 == f2: " << (f1 == f2) << endl;
    cout << "f1 != f2: " << (f1 != f2) << endl;
    cout << "f1 < f2: " << (f1 < f2) << endl;
    cout << "f1 > f2: " << (f1 > f2) << endl;
    cout << "f1 <= f2: " << (f1 <= f2) << endl;
    cout << "f1 >= f2: " << (f1 >= f2) << endl;
    
    // Test I/O
    Fraction f3;
    cout << "Enter a fraction (format: a/b or a): ";
    cin >> f3;
    cout << "You entered: " << f3 << endl;
    
    return 0;
}