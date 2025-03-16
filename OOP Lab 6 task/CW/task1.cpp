#include<iostream>
using namespace std;

class BankAccount{
	protected:
		string accountNumber;
		int balance;
		bool isFreez;
	public:
		BankAccount(string AN, int b) : accountNumber(AN),balance(b){}
		virtual void deposit(int amount){
			balance += amount;
		}
		void widthraw(int amount){
			if(balance - amount < 0){
				cout << "Not sufficient balance" << endl;
				return;
			}
			balance -= amount;
			cout << "New balance " << balance << endl;
		}
		void freez(){
			isFreez = true;
		}
		void unFreez(){
			isFreez = false;
		}
};

class SavingAccount: public BankAccount{
	protected:
	float mInterest;
	public:
		SavingAccount(string AN, int b,float MI): BankAccount(AN,b), mInterest(MI){}
		void setMinterest(int MI){
			mInterest = MI;
		}
};

class CheckingAccount: public BankAccount{
	protected:
	int overDraftLimit;
	public:
		CheckingAccount(string AN, int b, int ODL):BankAccount(AN,b),overDraftLimit(ODL){}
		
		void setOverDraftLimit(int ODL){
			overDraftLimit = ODL;
		}
		
};

class BuisnessAccount:public BankAccount{
	protected:
	int corporateTax;
	public:
		BuisnessAccount(string AN, int b,int CT):BankAccount(AN,b),corporateTax(CT){} 
		void deposit(int amount){
			if(balance + amount - corporateTax <= 0){
				balance  = 0;
				return;
			}
			balance += amount - corporateTax;
		}
		void setCorporateTax(int CT){
			corporateTax = CT;
		}
};


class Customer{
	public:
		
	void deposit(BankAccount &acc, int amount){
		acc.deposit(amount);
	}
	void widthraw(BankAccount &acc, int amount){
		acc.widthraw(amount);
	}
};

class Teller: public Customer{
	public:
		
	void freezAccount(BankAccount &acc){
		acc.freez();
	}
	void unFreeAccount(BankAccount &acc){
		acc.unFreez();
	}
};

class Manager:public Teller{
	void changeOverDrafeLimit(CheckingAccount &acc,int newODL){
		acc.setOverDraftLimit(newODL);
	}
	void changeCorporateTax(BuisnessAccount &acc,int newCT){
		acc.setCorporateTax(newCT);
	}
	void changeMonthlyInterest(SavingAccount &acc,float newMI){
		acc.setMinterest(newMI);
	}
};

int main(){
	
	return 0;
}