#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

// Base class for all currencies
class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; // Rate to convert to base currency (USD)
    
public:
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}
    
    // Convert this currency to base currency (USD)
    virtual double convertToBase() {
        return amount * exchangeRate;
    }
    
    // Convert this currency to target currency
    virtual double convertTo(Currency* target) {
        double baseAmount = this->convertToBase();
        return baseAmount / target->exchangeRate;
    }
    
    // Display currency details
    virtual void displayCurrency() {
        cout << fixed << setprecision(2);
        cout << currencySymbol << amount << " (" << currencyCode << ")";
    }
    
    virtual ~Currency() {} // Virtual destructor for proper cleanup
};

// Derived currency classes
class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    
    void displayCurrency() override {
        cout << fixed << setprecision(2);
        cout << currencySymbol << amount;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 0.93) {} // 1 USD = 0.93 EUR
    
    void displayCurrency() override {
        cout << fixed << setprecision(2);
        cout << amount << currencySymbol << " (" << currencyCode << ")";
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "?", 83.38) {} // 1 USD = 83.38 INR
    
    void displayCurrency() override {
        cout << fixed << setprecision(2);
        cout << currencySymbol << amount << " (" << currencyCode << ")";
    }
};

class Yen : public Currency {
public:
    Yen(double amt) : Currency(amt, "JPY", "¥", 151.61) {} // 1 USD = 151.61 JPY
    
    void displayCurrency() override {
        cout << fixed << setprecision(2);
        cout << currencySymbol << amount << " (" << currencyCode << ")";
    }
};

int main() {
    // Create some currency objects
    Dollar usd(100.0);
    Euro eur(100.0);
    Rupee inr(100.0);
    Yen jpy(100.0);
    
    // Display original amounts
    cout << "Original amounts:\n";
    cout << "USD: "; usd.displayCurrency(); cout << endl;
    cout << "EUR: "; eur.displayCurrency(); cout << endl;
    cout << "INR: "; inr.displayCurrency(); cout << endl;
    cout << "JPY: "; jpy.displayCurrency(); cout << endl << endl;
    
    // Convert between currencies
    cout << "Conversion examples:\n";
    
    // Convert USD to other currencies
    cout << "100 USD to EUR: ";
    eur.displayCurrency(); 
    cout << " = "; 
    Dollar tempUsd(100.0);
    cout << tempUsd.convertTo(&eur) << " EUR" << endl;
    
    cout << "100 USD to INR: ";
    usd.displayCurrency(); 
    cout << " = "; 
    cout << tempUsd.convertTo(&inr) << " INR" << endl;
    
    cout << "100 USD to JPY: ";
    usd.displayCurrency(); 
    cout << " = "; 
    cout << tempUsd.convertTo(&jpy) << " JPY" << endl << endl;
    
    // Convert other currencies to USD
    cout << "100 EUR to USD: ";
    eur.displayCurrency(); 
    cout << " = "; 
    cout << eur.convertToBase() << " USD" << endl;
    
    cout << "100 INR to USD: ";
    inr.displayCurrency(); 
    cout << " = "; 
    cout << inr.convertToBase() << " USD" << endl;
    
    cout << "100 JPY to USD: ";
    jpy.displayCurrency(); 
    cout << " = "; 
    cout << jpy.convertToBase() << " USD" << endl << endl;
    
    // Convert between non-USD currencies
    cout << "100 EUR to INR: ";
    eur.displayCurrency(); 
    cout << " = "; 
    cout << eur.convertTo(&inr) << " INR" << endl;
    
    cout << "100 INR to JPY: ";
    inr.displayCurrency(); 
    cout << " = "; 
    cout << inr.convertTo(&jpy) << " JPY" << endl;
    
    return 0;
}