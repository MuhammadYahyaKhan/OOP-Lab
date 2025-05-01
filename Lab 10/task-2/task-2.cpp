#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/* ------------First put this dummy data in text2.txt file-------------------------
1, Alice, manager, 3
2, Bob, developer, 1
3, Charlie, manager, 1
4, David, designer, 4
5, Eve, manager, 5
6, Frank, developer, 2
7, Grace, manager, 4
8, Helen, analyst, 3
9, Ian, developer, 5
10, Jane, manager, 2

 */



int main(){
	fstream file;
	file.open("task2.txt", ios::in);
	vector<string> res;
	vector<string> snV;
	vector<string> nameV;
	vector<string> desV;
	vector<string> expV;
	if(file.is_open()){
		string a;
		while(getline(file, a)){
			string sn;
			string name;
			string des;
			string exp;
			
			file >> sn >> name >> des >> exp;
			if(des == "manager," && stoi(exp) >= 2){
				res.push_back(name);
				snV.push_back(sn);
				nameV.push_back(name);
				desV.push_back(des);
				expV.push_back(exp);
			}
		}
		
	}else{
		cout << "Error opening file" << endl;
	}
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
	file.close();
	
	fstream myFile;
	myFile.open("task2.txt", ios::out);
	for(int i = 0; i < res.size(); i++){
		myFile << snV[i] << " " << nameV[i] << " " << desV[i] << " " << stoi(expV[i])+1 << endl;
	}
	
	return 0;
}