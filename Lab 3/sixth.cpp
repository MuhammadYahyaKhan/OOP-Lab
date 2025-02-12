#include<iostream>
#include<vector>
using namespace std;

class Matrix {
public:
    int rows;
    int cols;
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
    }
    int getRow() {
        return rows;
    }
    int getCol() {
        return cols;
    }
    vector<vector<int>> matrix;
    void setElement(int r, int c) {
        for (int i = 0; i < r; i++) {
            vector<int> cur;
            for (int j = 0; j < c; j++) {
                int n;
                cin >> n;
                cur.push_back(n);
            }
            matrix.emplace_back(cur);
        }
    }
    vector<vector<int>> getMatrix() {
        return matrix;
    }
    Matrix add(Matrix other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            vector<int> row;
            for (int j = 0; j < cols; j++) {
                row.push_back(matrix[i][j] + other.matrix[i][j]);
            }
            result.matrix.emplace_back(row);
        }
        return result;
    }
    Matrix multiply(Matrix other) {
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            vector<int> row;
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += matrix[i][k] * other.matrix[k][j];
                }
                row.push_back(sum);
            }
            result.matrix.emplace_back(row);
        }
        return result;
    }
};

int main() {
    int r1, c1;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    Matrix m1(r1, c1);
    cout << "Enter elements of first matrix:" << endl;
    m1.setElement(r1, c1);

    int r2, c2;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    Matrix m2(r2, c2);
    cout << "Enter elements of second matrix:" << endl;
    m2.setElement(r2, c2);

    // Add matrixc
    Matrix sum = m1.add(m2);
    if (sum.getRow() != 0 && sum.getCol() != 0) {
        cout << "Sum of matrices:" << endl;
        vector<vector<int>> sumMatrix = sum.getMatrix();
        for (int i = 0; i < sum.getRow(); i++) {
            for (int j = 0; j < sum.getCol(); j++) {
                cout << sumMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Multiplicaton
    Matrix product = m1.multiply(m2);
    if (product.getRow() != 0 && product.getCol() != 0) {
        cout << "Product of matrices:" << endl;
        vector<vector<int>> productMatrix = product.getMatrix();
        for (int i = 0; i < product.getRow(); i++) {
            for (int j = 0; j < product.getCol(); j++) {
                cout << productMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
