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

//read matrix
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

//display matrix
void printMatrix(const matrix &m) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

//matrix addition
void addMatrix(matrix &m1, matrix &m2) {
    matrix result(ROWS, row(COLS));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    printMatrix(result);
}

//transpose matrix
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

//symmetric matrix
bool isSymmetric(const matrix &m) {
    //just upper and lower trianlge in the matrix
    //should be a square matrix
    //it is assumed the matrix is square
    for(int i = 0; i < ROWS-1; i++) {
        for(int j = i+1; j < ROWS; j++) {
            if(m[i][j] != m[j][i])
                return false;
        }
    }
    return true;
}

//spiral order of a matrix (helper) and caller function
void spiralTraversalHelper(const matrix &m, const int top, const int bottom, const int left, const int right, vector<int> &result) {    
    if(left > right || top > bottom)
        return;
    for(int i = left; i <= right; i++) {
        result.push_back(m[top][i]);
    }
    for(int i = top+1; i <= bottom && top != bottom; i++) {
        result.push_back(m[i][right]);
    }
    for(int i = right-1; i >= left && top != bottom; i--) {
        result.push_back(m[bottom][i]);
    }
    for(int i = bottom-1; i >= top+1 && top != bottom && left != right; i--) {
        result.push_back(m[i][left]);
    }
    spiralTraversalHelper(m, top+1, bottom-1, left+1, right-1, result);
}

void spiralTraversal(const matrix &m) {
    vector<int> result;
    if(m.size() == 0 || m[0].size() == 0)
        return;
    spiralTraversalHelper(m, 0, (int)m.size()-1, 0, (int)m[0].size()-1, result);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

void multiplyMatrix(const matrix &m1, const matrix &m2) {
    //r1, c1 - m1
    //r2, c2 - m2
    //assumed c1 == r2 => did not check this condition
    matrix result(ROWS, row(COLS));                         // ROWS = r1; COLS = c2
    for(int i = 0; i < ROWS; i++) {                         // ROWS = r1
        for(int j = 0; j < COLS; j++) {                     // COLS = c2
            for(int k = 0; k < COLS; k++) {                 // COLS = c1
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    printMatrix(result);
}

int main(int argc, const char * argv[]) {
    
    matrix m1(ROWS, row(COLS));
    //matrix m2(ROWS, row(COLS));
    readMatrix(m1);
    
    //cout << endl << "Second Matrix." << endl;
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
    
    //multiplyMatrix(m1, m2);
    
    spiralTraversal(m1);
    
    return 0;
}
