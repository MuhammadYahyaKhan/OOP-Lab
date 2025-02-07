#include<iostream>
#include<vector>
using namespace std;

class Matrix{
	
	public:
		
		int rows;
		int cols;
		Matrix(int rows,int cols){
			this->cols = cols;
			this->rows = rows;
		}
		//int matrix[rows][cols];
		
		int getRow(){
			return rows;
		}
		int getCol(){
			return cols;
		}
		vector<vector<int>> matrix;
		void setElemnt(int r, int c){
			for(int i = 0; i < r; i++){
				vector<int> cur;
				for(int j = 0; j < c; j++){
					int n;
					cin >> n;
					cur.push_back(n);
				}
				matrix.emplace_back(cur);
			}
		}
		vector<vector<int>> getMatrix(){
			return matrix;
		}
};

int main(){
	Matrix s(2,2);
	s.setElemnt(s.getRow(),s.getCol());
	int r,c;
	cout << "enter rows :"; cin >> r;
	cout << "Enter cols :"; cin >> c;
	if(r == s.getRow() && c == s.getCol()){
		vector<vector<int>> first = s.getMatrix();
		vector<vector<int>> second;
		cout << "Enter elements of matrix ";
		for(int i = 0; i < r; i++){
			vector<int> cur;
			for(int j = 0; j < c; j++){
				int n;
				cin >> n;
				cur.push_back(n);
			}
			second.emplace_back(cur);
		}
		
		
		cout << "Matrix after addition " << endl;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cout << first[i][j] + second[i][j] << " ";
			}
			cout << endl;
		}
		
	}else{
		cout << "matrix cannot be added";
	}
	
	if(c == s.getCol()){
		
	}else{
		cout << "Matrix can't be multiplied ";
	}
	
	
	return 0;
}