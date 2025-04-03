#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}

    
    Number& operator--() {
        value *= 4;
        return *this;
    }

    
    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    
};

int main() {
    

    return 0;
}