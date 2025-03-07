#include<iostream>
using namespace std;

class bankAccount{
	public:
		string accNumber;
		int balance;
		int deposit;
		int widthraw;
		

	
};

class savingAccount:public bankAccount{
	public:
		float interest;
		
		
};

class checkingAccount:public bankAccount{
	public:
	int overDraftLimit;
	
};

class buisnessAccount:public bankAccount{
	public:
	int corperateTax;
	

};

class coustomer:public checkingAccount, public buisnessAccount, public savingAccount{
	public:
		void deposit(int amount){
			bankAccount.balance += bankAccount.balance;
		}
		void widthraw(int amount){
			if(bankAccount.balance - amount < 0){
				cout << "No sufficient Balance" << endl;
			}
		}
		
};

class teller:public coustomer{
	public:
		void freez(bool accountFreez){
			accountFreez = false;
			cout << "Account freez" << endl;
		}
	
};

class Manager:public coutomer{
	public:
		void changeLimit(){
			cout << "Enter new Interest ";
			cin >> interest;
			cout << "Enter new Overdraft Limit";
			cin >> overDraftLimit;
			cout << "Enter new corporate tax";
			cin >> corporateTax;
		}
};

int main(){
	
	return 0;
}