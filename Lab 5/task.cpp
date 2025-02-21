#include<iostream>
using namespace std;

class Engine{
	bool isRunning;
	public:
		
		void start(){
			cout << "Engine Start" << endl;
			isRunning = true;
		}
		void stop(){
			cout << "Engine stop " << endl;
			isRunning = false;
		}
		
};

class Car{
	private:
		Engine e;
	public:
		
		void startCar(){
			e.start();
		}
		void stopCar(){
			e.stop();
		}
};



int main(){
	
	return 0;
}