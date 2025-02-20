#include<iostream>
using namespace std;

class Matrix{
	double** arr;
	int rows;
	int cols;
	public:
		// Default Constructor
		Matrix(){
			rows = 0;
			cols = 0;
			arr = nullptr;
		}
		// Paremetrized Constructor
		Matrix(int rows, int cols){
			this->rows = rows;
			this->cols = cols;
			
			this->arr = new double*[rows];
			for(int i = 0; i < rows; i++){
				arr[i] = new double[cols];
				for(int j = 0; j < cols; j++){
					arr[i][j] = 0;
				}
			}
		}
		// Copy Constructor
		Matrix(const Matrix& obj){
			double** newArr;
			newArr = new double*[obj.rows];
			for(int i = 0; i < rows; i++){
				newArr[i] = new double[obj.cols];
				for(int j = 0; j < cols; j++){
					newArr[i][j] = obj.arr[i][j];
				}
			}
			this->arr = newArr;
		}
		// Assignment Opeartor
		Matrix& operator=(const Matrix& orignal){
			if(this != &orignal){
				delete arr;
				this->rows = orignal.rows;
				this->cols = orignal.cols;
				double **newArr;
				newArr = new double*[this->rows];
				for(int i = 0; i < this->rows; i++){
					newArr[i] = new double[cols];
					for(int j = 0; j < cols; j++){
					newArr[i][j] = orignal.arr[i][j];
				}
			}
			this->arr = newArr;
				
		}
			return *this;
		}
		
		// Move Constructor
		Matrix(Matrix&& obj) noexcept{
			this->rows = obj.rows;
			this->cols = obj.cols;
			double** newArr;
			newArr = new double*[rows];
			for(int i = 0; i < rows; i++){
				newArr[i] = new double[cols];
				for(int j = 0;  j < cols; j++){
					newArr[i][j] = obj.arr[i][j];
				}
			}
			this->arr = newArr;
			obj.arr = nullptr;
			obj.rows = 0;
			obj.cols = 0;
			
		}
		// Move Assignment Operator
		Matrix& operator=(Matrix&& other) noexcept{
			this->rows = other.rows;
			this->cols = other.cols;
			double** newArr;
			newArr = new double*[rows];
			for(int i = 0; i < rows;i++){
				newArr[i] = new double[cols];
				for(int j = 0; j < cols; j++){
					newArr[i][j] = other.arr[i][j];
				}
			}
			this->arr = newArr;
			other.arr = nullptr;
			other.rows = 0;
			other.cols = 0;
		
		}
		~Matrix(){
			cout << "Destructor is called" << endl;
			delete[] arr;
		}
		int getRows(){
			return rows;
		}
		int getCols(){
			return cols;
		}
		void fill(int value){
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < cols; j++){
					arr[i][j] = value;
				}
			}
		}
		
		//
		void transpose() {
    
    double** TransposeArr = new double*[cols];
    for (int i = 0; i < cols; i++) {
        TransposeArr[i] = new double[rows];
        for (int j = 0; j < rows; j++) {
            TransposeArr[i][j] = arr[j][i]; 
        }
    }
		for(int i = 0; i < cols; i++){
			for(int j = 0; j < rows; j++){
				cout << TransposeArr[i][j] << " ";
			}
			cout << endl;
		}
    // Deallocate the original matrix
    
}
		
		
		//
		
		// Print the orignal matrix
		void getMat(){
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < cols; j++){
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
		}
		double* at(int r,int c){
			return &arr[r][c];
		}
		
		
};


int main(){
	
	Matrix a(3,2);
	a.fill(4);
	cout << "Orignal matrix" << endl;
	a.getMat();
	cout << "Transpose Matrix" << endl;
	a.transpose();
	
	
	return 0;
}