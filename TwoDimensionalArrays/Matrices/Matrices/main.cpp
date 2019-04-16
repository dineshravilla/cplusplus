//
//  main.cpp
//  Matrices
//
//  Created by Dinesh Ravilla on 4/16/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//

#define ROWS 3
#define COLS 3

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> row;
typedef vector<row> matrix;

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void readMatrix(matrix &m) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int x;
            cout << "Enter m[" << i << "][" << j << "]: ";
            cin >> x;
            m[i][j] = x;
        }
    }
}

void printMatrix(const matrix &m) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrix(matrix &m1, matrix &m2) {
    matrix result(ROWS, row(COLS));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    printMatrix(result);
}

void transposeMatrix(matrix &m) {
    //just upper and lower trianlge in the matrix
    //should be a square matrix
    //it is assumed the matrix is square
    for(int i = 0; i < ROWS-1; i++) {
        for(int j = i+1; j < ROWS; j++) {
            swap(m[i][j], m[j][i]);
        }
    }
}

bool isSymmetric(const matrix &m) {
    for(int i = 0; i < ROWS-1; i++) {
        for(int j = i+1; j < ROWS; j++) {
            if(m[i][j] != m[j][i])
                return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    matrix m1(ROWS, row(COLS));
    matrix m2(ROWS, row(COLS));
    readMatrix(m1);
    cout << endl << "Second Matrix." << endl;
    //readMatrix(m2);
    
    //addMatrix(m1, m2);
    //transposeMatrix(m1);
    //printMatrix(m1);
    //printMatrix(m2);
    
    /*
    if(isSymmetric(m1))
        cout << "Symmetric.";
    else
        cout << "Not Symmetric.";
    cout << endl;
    */
    
    return 0;
}
