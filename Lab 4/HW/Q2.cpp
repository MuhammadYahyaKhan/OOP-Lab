#include <iostream>
using namespace std;

class Account {
    double balance;

public:
    // Constructor
    Account(double initialBalance) {
        if (initialBalance < 0) {
            cout << "Initial balance is invalid. Setting balance to 0." << endl;
            balance = 0;
        } else {
            balance = initialBalance;
        }
    }

    // Credit function to add money
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Invalid credit amount!" << endl;
        }
    }

    // Debit function to withdraw money
    void debit(double amount) {
        if (amount > balance) {
            cout << "Debit amount exceeded account balance!" << endl;
        } else {
            balance -= amount;
        }
    }

    // Function to get the balance
    double getBalance() const {
        return balance;
    }

    // Display account balance
    void display() const {
        cout << "Current Balance: " << getBalance() << endl;
    }
};

int main() {
    double initialAmount;
    cout << "Enter initial account balance: ";
    cin >> initialAmount;

    Account myAccount(initialAmount);
    myAccount.display();

    double creditAmount, debitAmount;
    cout << "Enter amount to credit: ";
    cin >> creditAmount;
    myAccount.credit(creditAmount);
    myAccount.display();

    cout << "Enter amount to debit: ";
    cin >> debitAmount;
    myAccount.debit(debitAmount);
    myAccount.display();

    return 0;
}