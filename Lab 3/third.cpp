#include<iostream>
using namespace std;

class Glass{
	public:
		
	int liquidLevel;
	void drink(int mililiters){
		this->liquidLevel = this->liquidLevel - mililiters;
	}
	void refill(){
		liquidLevel = 200;
	}
	Glass(int liquidLevel){
		this->liquidLevel = liquidLevel;
	}
};

int main(){
	Glass s(200);
	int terminate = 1;
	cout << "Enter 0 to terminate and any other interger to continue" << endl;
	cin >> terminate;
	while(terminate){
		int mililiter;
		cout << "Enter the amount";
		cin>> mililiter;
		s.drink(mililiter);
		if(s.liquidLevel <= 100){
			s.refill();
			cout << "Refilled" << endl;
		}
		cout << "Enter 0 to terminate and any other interger to continue" << endl;
		cin >> terminate;
	}
	return 0;
}