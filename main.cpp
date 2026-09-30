#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

// Print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// Add two matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& matrixA,
                                const vector<vector<int>>& matrixB) {
    int N = matrixA.size();
    vector<vector<int>> result(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return result;
}

// Multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& matrixA,
                                     const vector<vector<int>>& matrixB) {
    int N = matrixA.size();
    vector<vector<int>> result(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}

// Find diagonal sums
void diagonalSums(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    int mainSum = 0;
    int secondarySum = 0;

    for (int i = 0; i < N; i++) {
        mainSum += matrix[i][i];
        secondarySum += matrix[i][N - 1 - i];
    }

    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Secondary diagonal sum: " << secondarySum << endl;
}

// Swap two rows
void swapRows(vector<vector<int>>& matrix, int row1, int row2) {
    int N = matrix.size();

    if (row1 >= 0 && row1 < N && row2 >= 0 && row2 < N) {
        swap(matrix[row1], matrix[row2]);
        printMatrix(matrix);
    } else {
        cout << "Invalid row index." << endl;
    }
}

// Swap two columns
void swapColumns(vector<vector<int>>& matrix, int col1, int col2) {
    int N = matrix.size();

    if (col1 >= 0 && col1 < N && col2 >= 0 && col2 < N) {
        for (int i = 0; i < N; i++) {
            swap(matrix[i][col1], matrix[i][col2]);
        }

        printMatrix(matrix);
    } else {
        cout << "Invalid column index." << endl;
    }
}

// Update one element
void updateElement(vector<vector<int>>& matrix, int row, int col, int value) {
    int N = matrix.size();

    if (row >= 0 && row < N && col >= 0 && col < N) {
        matrix[row][col] = value;
        printMatrix(matrix);
    } else {
        cout << "Invalid row or column index." << endl;
    }
}

int main() {
    string filename;

    cout << "Enter input file name: ";
    cin >> filename;

    ifstream file(filename);

    if (!file) {
        cout << "Error opening file." << endl;
        return 1;
    }

    int N;
    file >> N;

    vector<vector<int>> matrixA(N, vector<int>(N));
    vector<vector<int>> matrixB(N, vector<int>(N));

    // Read Matrix A
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> matrixA[i][j];
        }
    }

    // Read Matrix B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> matrixB[i][j];
        }
    }

    file.close();

    // Question 1
    cout << "\nMatrix A:" << endl;
    printMatrix(matrixA);

    cout << "\nMatrix B:" << endl;
    printMatrix(matrixB);

    // Question 2
    cout << "\nMatrix Addition:" << endl;
    vector<vector<int>> sum = addMatrices(matrixA, matrixB);
    printMatrix(sum);

    // Question 3
    cout << "\nMatrix Multiplication:" << endl;
    vector<vector<int>> product = multiplyMatrices(matrixA, matrixB);
    printMatrix(product);

    // Question 4
    cout << "\nDiagonal Sums of Matrix A:" << endl;
    diagonalSums(matrixA);

    // Question 5
    int row1, row2;
    cout << "\nEnter two row indices to swap: ";
    cin >> row1 >> row2;

    cout << "Matrix A after row swap:" << endl;
    swapRows(matrixA, row1, row2);

    // Question 6
    int col1, col2;
    cout << "\nEnter two column indices to swap: ";
    cin >> col1 >> col2;

    cout << "Matrix A after column swap:" << endl;
    swapColumns(matrixA, col1, col2);

    // Question 7
    int row, col, value;
    cout << "\nEnter row, column, and new value: ";
    cin >> row >> col >> value;

    cout << "Matrix A after update:" << endl;
    updateElement(matrixA, row, col, value);

    return 0;
}