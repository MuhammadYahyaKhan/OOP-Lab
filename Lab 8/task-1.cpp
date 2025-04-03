#include<iostream>
#include<string>
using namespace std;

class Account{
    public:
        string accNumber;
        int balance;
        string accHolderName;
        string accType;
        
        Account(string accNumber, int balance, string accHolderName, string accType = "Generic")
            : accNumber(accNumber), balance(balance), accHolderName(accHolderName), accType(accType) {}
        
        void deposit(int amount) {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        }    
        
        virtual void withdraw(int amount) {
            if(balance - amount < 0) {
                cout << "Not sufficient balance" << endl;
                return;
            } else {
                balance -= amount;
                cout << "Withdrew " << amount << ". New balance: " << balance << endl;
            }
        }
        
        virtual void calculateInterest() {
            cout << "No interest for generic account" << endl;
        }
        
        virtual void printStatement() {
            cout << "=== Account Statement ===" << endl;
            cout << "Account Number: " << accNumber << endl;
            cout << "Holder Name: " << accHolderName << endl;
            cout << "Account Type: " << accType << endl;
            cout << "Current Balance: " << balance << endl;
        }
        
        void getAccountInfo() {
            cout << "Account Info - Number: " << accNumber 
                 << ", Holder: " << accHolderName 
                 << ", Type: " << accType 
                 << ", Balance: " << balance << endl;
        }
};

class SavingsAccount : public Account {
    public:
        float interestRate;
        int minimumBalance;
        
        SavingsAccount(string accNumber, int balance, string accHolderName, 
                       float interestRate, int minimumBalance)
            : Account(accNumber, balance, accHolderName, "Savings"), 
              interestRate(interestRate), minimumBalance(minimumBalance) {}
        
        void calculateInterest() override {
            float interest = balance * interestRate / 100;
            cout << "Interest calculated: " << interest << endl;
        }
        
        void withdraw(int amount) override {
            if(balance - amount < minimumBalance) {
                cout << "Cannot withdraw. Minimum balance requirement not met." << endl;
            } else {
                Account::withdraw(amount);
            }
        }
        
        void printStatement() override {
            Account::printStatement();
            cout << "Interest Rate: " << interestRate << "%" << endl;
            cout << "Minimum Balance Required: " << minimumBalance << endl;
        }
};

class CheckingAccount : public Account {
    public:
        int transactionFee;
        
        CheckingAccount(string accNumber, int balance, string accHolderName, int transactionFee = 10)
            : Account(accNumber, balance, accHolderName, "Checking"), 
              transactionFee(transactionFee) {}
        
        void withdraw(int amount) override {
            if(balance - amount - transactionFee < 0) {
                cout << "Not sufficient balance (including transaction fee)" << endl;
            } else {
                balance -= (amount + transactionFee);
                cout << "Withdrew " << amount << " with fee " << transactionFee 
                     << ". New balance: " << balance << endl;
            }
        }
        
        void printStatement() override {
            Account::printStatement();
            cout << "Transaction Fee per withdrawal: " << transactionFee << endl;
        }
};

class FixedDepositAccount : public Account {
    public:
        string maturityDate;
        float fixedInterestRate;
        
        FixedDepositAccount(string accNumber, int balance, string accHolderName, 
                           float fixedInterestRate, string maturityDate)
            : Account(accNumber, balance, accHolderName, "Fixed Deposit"), 
              fixedInterestRate(fixedInterestRate), maturityDate(maturityDate) {}
        
        void calculateInterest() override {
            float interest = balance * fixedInterestRate / 100;
            cout << "Fixed interest calculated: " << interest << endl;
        }
        
        void withdraw(int amount) override {
            cout << "Cannot withdraw from Fixed Deposit before maturity date: " << maturityDate << endl;
        }
        
        void printStatement() override {
            Account::printStatement();
            cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
            cout << "Maturity Date: " << maturityDate << endl;
        }
};

int main() {
    // Testing the account classes
    SavingsAccount sa("SA123", 1000, "John Doe", 2.5, 500);
    CheckingAccount ca("CA456", 2000, "Jane Smith");
    FixedDepositAccount fd("FD789", 5000, "Bob Johnson", 5.0, "2025-12-31");
    
    cout << "\nTesting Savings Account:\n";
    sa.deposit(500);
    sa.withdraw(200);
    sa.withdraw(800);  // Should fail due to minimum balance
    sa.calculateInterest();
    sa.printStatement();
    
    cout << "\nTesting Checking Account:\n";
    ca.deposit(300);
    ca.withdraw(400);  // Should include transaction fee
    ca.printStatement();
    
    cout << "\nTesting Fixed Deposit Account:\n";
    fd.deposit(1000);
    fd.withdraw(500);  // Should fail - can't withdraw before maturity
    fd.calculateInterest();
    fd.printStatement();
    
    return 0;
}