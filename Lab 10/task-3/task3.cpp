#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    cout<<"TYP -1 TO EXIT\n";
    int choise;
    while(1){
        cin>>choise;
        if(choise==-1){
            exit(1);
        }else{
            char tempp;
            cin>>tempp;

            ofstream fiel;
            fiel.open("Qustion 4.txt", ios::app);
            if(!fiel){
                cout<<"Failled to open file!\n";
                return 1;
            }
            fiel<<tempp;
            fiel.close();
            
            ifstream felb;
            felb.open("Qustion 4.txt", ios::in);
            if(!felb){
                cout<<"Failled to open file!\n";
                return 1;
            }
            int coutn=0;
            string jab;
            while(getline(felb,jab)){
                coutn+=jab.size();
            }
            if(coutn>=1000000){
                cout<<"File size has incresed more then 1 MB\n";
                felb.close();
                exit(1);
            }
        }
    }
return 0;
}
