#include<iostream>
using namespace std;

class Viechle{
	public:
		int price;
		Viechle(int p):price(p){
			
		}
};

class MotorCycle:public Viechle{
	public:
		int nGears;
		int nCylinders;
		int nWheels;
		MotorCycle(int p,int nG, int nC, int nW):Viechle(p),nGears(nG),nCylinders(nC), nWheels(nW){
			
		}
		
};


class Yamaha:public MotorCycle{
	public:
		string make;
		Yamaha(int p,int nG,int nC, int nW,string m):MotorCycle(p,nG,nC,nW),make(m){}
		void displayDetails(){
			cout << "Price " << price << endl;
			cout << "Number of Gears " << nGears << endl;
			cout << "Number of cylinders " << nCylinders << endl;
			cout << "Number of Wheels " << nWheels << endl;
			cout << "Make " << make << endl;
		}
};

class Car:public Viechle{
	public:
		int capacity;
		int nDoors;
		string fType;
		Car(int p, int c,int nD, string fT):Viechle(p),capacity(c), nDoors(nD),fType(fT){}
		
		
};

class Audi:public Car{
	public:
		string model;
		Audi(int p,int c, int nD, string fT, string m):Car(p,c,nD,fT),model(m){}
		void displayDetail(){
			cout << "Model " << model << endl;
			cout << "Price " << price << endl;
			cout << "Capacity " << capacity << endl;
			cout << "Number of doors " << nDoors << endl;
			cout << "Fuel Type " << fType << endl;
		}
};


int main(){
	
	
	
	return 0;
}