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

//spiral order of a matrix (helper) and caller function - recursive
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

void spiralTraversalRecursive(const matrix &m) {
    vector<int> result;
    if(m.size() == 0 || m[0].size() == 0)
        return;
    spiralTraversalHelper(m, 0, (int)m.size()-1, 0, (int)m[0].size()-1, result);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

//spiral traversal - iterative
void spiralTraversalIterative(const matrix &m) {
    vector<int> result;
    int r1 = 0, r2 = (int)m.size()-1;
    int c1 = 0, c2 = (int)m[0].size()-1;
    while(r1 <= r2 && c1 <= c2) {
        for(int c = c1; c <= c2; c++)
            result.push_back(m[r1][c]);
        for(int r = r1+1; r <= r2; r++)
            result.push_back(m[r][c2]);
        if(r1 < r2 && c1 < c2) {
            for(int c = c2-1; c > c1; c--)
                result.push_back(m[r2][c]);
            for(int r = r2; r > r1; r--)
                result.push_back(m[r][c1]);
        }
        r1++;
        r2--;
        c1++;
        c2--;
    }
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
}

//rotate matrix - 90 degree rotation
// ith row => ith column
void rotateMatrix(matrix &m) {
    int size = (int)m.size()-1;
    for(int i = 0; i < m.size()/2; i++) {
        for(int j = i; j < size-i; j++) {
            int temp1 = m[size-j][i];
            int temp2 = m[size-i][size-j];
            int temp3 = m[j][size-i];
            int temp4 = m[i][j];
            m[i][j] = temp1;
            m[size-j][i] = temp2;
            m[size-i][size-j] = temp3;
            m[j][size-i] = temp4;
        }
    }
    printMatrix(m);
}

//pascal's triangle
//(no. of rows)
void pascalTriangle(int n) {
    vector<vector<int>> result;
    result.push_back({1});
    for(int i = 1; i < n; i++) {
        vector<int> temp;
        temp.push_back(1);
        for(int j = 1; j < i; j++) {
            temp.push_back(result[i-1][j-1] + result[i-1][j]);
        }
        temp.push_back(1);
        result.push_back(temp);
    }
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

//matrix multiplication
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
    
    //matrix m1(ROWS, row(COLS));
    //matrix m2(ROWS, row(COLS));
    //readMatrix(m1);
    
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
    
    //spiralTraversalRecursive(m1);
    
    //spiralTraversalIterative(m1);
    
    //rotateMatrix(m1);
    pascalTriangle(10);
    
    return 0;
}
