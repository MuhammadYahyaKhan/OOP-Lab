#include <iostream>
using namespace std;
class Matrix{
int rows;
int cols;
double **matrix;
public:
Matrix(){
matrix=nullptr;
rows=0;
cols=0;
}
Matrix(int rows,int cols){
this->rows=rows;
this->cols=cols;
matrix = new double*[rows];
for (int i=0;i<rows;i++) {
            matrix[i]=new double[cols];
            }
            for(int i=0;i<this->getRows();i++){
for(int j=0;j<this->getCols();j++){
matrix[i][j]=0.0;
}
}
}
Matrix(const Matrix &other){
this->rows=other.rows;
this->cols=other.cols;
matrix = new double*[rows];
            for (int i=0;i<rows;i++) {
                matrix[i]=new double[cols];
            }
for(int i=0;i<this->getRows();i++){
for(int j=0;j<this->getCols();j++){
matrix[i][j]=other.matrix[i][j];
}
}
}
Matrix(Matrix& other){
this->rows=other.rows;
this->cols=other.cols;
this->matrix=other.matrix;
other.matrix=nullptr;
other.rows=0;
other.cols=0;
}
int getRows(){
return rows;
}
int getCols(){
return cols;
}
void fill(double value){
for(int i=0;i<this->getRows();i++){
for(int j=0;j<this->getCols();j++){
matrix[i][j]=value;
}
}
}
~Matrix(){
for(int i=0;i<this->getRows();i++){
delete[] matrix[i];
}
delete[] matrix;
}
double at(int i,int j){
return this->matrix[i][j];
}
Matrix transpose(){
Matrix transposed(this->cols,this->rows);
for(int i=0;i<this->rows;i++){
for(int j=0;j<this->cols;j++){
transposed.matrix[j][i]=this->matrix[i][j];
}
}
return transposed;
}
};
int main(){
Matrix m1;
Matrix m2(2,3);
m2.fill(4.0);
for (int i=0;i<m2.getRows();i++){
        for(int j=0;j<m2.getCols();j++){
            cout << m2.at(i,j) << " ";
        }
        cout << endl;
    }
    cout << "Matrix Tranposed" << endl;
    Matrix transpose=m2.transpose();
for (int i=0;i<transpose.getRows();i++){
        for(int j=0;j<transpose.getCols();j++){
            cout << transpose.at(i,j) << " ";
        }
        cout << endl;
    }
Matrix m3=m2;
Matrix m4=move(m3);
return 0;
}
