#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;

class BigInteger {
private:
    vector<int> digits;  // stores digits in little-endian order (least significant first)
    bool isNegative = false;

    // Helper functions
    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;  // -0 is not allowed
        }
    }

    void normalize() {
        for (size_t i = 0; i < digits.size(); ++i) {
            if (digits[i] >= 10) {
                if (i == digits.size() - 1) {
                    digits.push_back(0);
                }
                digits[i+1] += digits[i] / 10;
                digits[i] %= 10;
            } else if (digits[i] < 0) {
                if (i == digits.size() - 1) {
                    throw runtime_error("Negative digit encountered");
                }
                int borrow = (abs(digits[i]) + 9) / 10;
                digits[i+1] -= borrow;
                digits[i] += borrow * 10;
            }
        }
        removeLeadingZeros();
    }

    // Comparison ignoring sign
    bool absoluteLess(const BigInteger& other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() < other.digits.size();
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return digits[i] < other.digits[i];
            }
        }
        return false;  // equal
    }

public:
    // Constructors
    BigInteger() : digits({0}), isNegative(false) {}
    
    BigInteger(const string& numStr) {
        if (numStr.empty()) {
            digits = {0};
            return;
        }

        size_t start = 0;
        if (numStr[0] == '-') {
            isNegative = true;
            start = 1;
        }

        for (int i = numStr.size() - 1; i >= static_cast<int>(start); --i) {
            if (!isdigit(numStr[i])) {
                throw invalid_argument("Invalid character in number string");
            }
            digits.push_back(numStr[i] - '0');
        }

        removeLeadingZeros();
    }

    BigInteger(long long num) {
        if (num < 0) {
            isNegative = true;
            num = -num;
        }
        
        if (num == 0) {
            digits = {0};
            return;
        }

        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    // Arithmetic operators
    BigInteger operator+(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return *this - (-other);
        }

        BigInteger result;
        result.isNegative = isNegative;
        result.digits.resize(max(digits.size(), other.digits.size()) + 1, 0);

        for (size_t i = 0; i < result.digits.size() - 1; ++i) {
            int a = (i < digits.size()) ? digits[i] : 0;
            int b = (i < other.digits.size()) ? other.digits[i] : 0;
            result.digits[i] += a + b;
            
            if (result.digits[i] >= 10) {
                result.digits[i+1] += 1;
                result.digits[i] -= 10;
            }
        }

        result.removeLeadingZeros();
        return result;
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        if (result.digits.size() == 1 && result.digits[0] == 0) {
            return result;  // -0 is not allowed
        }
        result.isNegative = !isNegative;
        return result;
    }

    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return *this + (-other);
        }

        if (absoluteLess(other)) {
            BigInteger result = other - *this;
            result.isNegative = !isNegative;
            return result;
        }

        BigInteger result;
        result.isNegative = isNegative;
        result.digits.resize(digits.size(), 0);

        int borrow = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int a = digits[i];
            int b = (i < other.digits.size()) ? other.digits[i] : 0;
            
            int diff = a - b - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            
            result.digits[i] = diff;
        }

        result.removeLeadingZeros();
        return result;
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);
        result.isNegative = isNegative != other.isNegative;

        for (size_t i = 0; i < digits.size(); ++i) {
            for (size_t j = 0; j < other.digits.size(); ++j) {
                result.digits[i+j] += digits[i] * other.digits[j];
                if (result.digits[i+j] >= 10) {
                    result.digits[i+j+1] += result.digits[i+j] / 10;
                    result.digits[i+j] %= 10;
                }
            }
        }

        result.normalize();
        return result;
    }

    // Comparison operators
    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        if (isNegative) {
            return absoluteLess(other) ? false : !(absoluteLess(other) || *this == other);
        }
        return absoluteLess(other);
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    // I/O operators
    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        if (num.isNegative) {
            os << '-';
        }
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            os << num.digits[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& num) {
        string input;
        is >> input;
        num = BigInteger(input);
        return is;
    }
};

int main() {
    // Test cases
    BigInteger a("12345678901234567890");
    BigInteger b("98765432109876543210");
    BigInteger c = -a;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a * c = " << a * c << endl;
    
    cout << boolalpha;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a > b: " << (a > b) << endl;
    
    // Interactive test
    BigInteger x, y;
    cout << "Enter two big integers (one per line):" << endl;
    cin >> x >> y;
    cout << "x + y = " << x + y << endl;
    cout << "x - y = " << x - y << endl;
    
    return 0;
}