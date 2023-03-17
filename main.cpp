#include <iostream>
#include <immintrin.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int SIZE = 10;

int sse_add(unsigned int* A, unsigned int* B) {

    for (int i = 0; i < SIZE; i+=32) {
//        __m256i c_line = _mm256_setzero_si256();
//        _m256i a_line = _mm256_load_si256(&A[i]);
//        _m256i b_line = _mm256_load_si256(&B[i]);

    }
    return 0;
}

void printMatrix(int **matrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int **transpose(int **matrix) {
    int **res = new int *[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        res[i] = new int[SIZE];
        for (int j = 0; j < SIZE; ++j) {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}


int **generateMatrix(int size) {

    int **matrix = new int *[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 6;
        }
    }

    return matrix;
}

int **multiplyMatrix(int **matrix, int **other) {
    int **res = new int *[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        res[i] = new int[SIZE];
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                res[i][j] += matrix[i][k] * other[k][j];
            }
        }
    }
    return res;
}

int main() {
    auto start = high_resolution_clock::now();

    int **matrix;
    cout << "First matrix" << "\n";
    matrix = generateMatrix(SIZE);
    printMatrix(matrix);

    int **transposed;
    transposed = transpose(matrix);
    cout << "\n";
    printMatrix(transposed);
//
//    cout << "\n" << "Second matrix" << "\n";
//    int **other;
//    other = generateMatrix(SIZE);
////    printMatrix(other);
//
//    cout << "\n" << "Multiplication result" << "\n";
//    int **result;
//    result = multiplyMatrix(matrix, other);
//    printMatrix(result);
//
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);

//    cout << " \n Execution time " << duration.count() << " ms ";
    return 0;
}