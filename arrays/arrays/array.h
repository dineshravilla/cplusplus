//
//  array.h
//  arrays
//
//  Created by Dinesh Ravilla on 4/13/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//

#ifndef array_h
#define array_h

#include <vector>

using namespace std;

class arrayOperations {
public:
    
    int *arr;
    int s = 0;
    int pos;
    
    //create functions
    void create();
    void create(vector<int>);
    
    //swap
    void swap(int*, int*);
    
    //returns size of the array
    int size();
    
    //returns true if key found - linear search
    bool linearSearch(int);
    bool binarySearchIterative(int);
    int binarySearchRecursive(int, int, int);
    
    //isSorted
    bool isSorted();
    
    //sort functions
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void quickSort(int, int);
    int partition(int, int);
    
    //min
    int getMin();
    
    //max
    int getMax();
    
    //reverse
    void reverse();
    
    //rotate
    void rotate(int);
    void leftShift(int);
    void rightShift(int);
    
    //display
    void display();
    
};


//reads number of elements to be inserted in the array
//also reads the elements
void arrayOperations:: create() {
    cout << "Enter the number of elements in the array:" << endl;
    cin >> s;
    arr = new int[s];
    
    cout << "Enter the elements:" << endl;
    
    for(int i = 0; i < s; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
}


//creates an array with vector<int> as arg
void arrayOperations:: create(vector<int> v) {
    s = (int)v.size();
    arr = new int[s];
    for(int i = 0; i < s; i++) {
        arr[i] = v[i];
    }
}


//swaps 2 numbers
void arrayOperations:: swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//returns size
int arrayOperations:: size() {
    return s;
}


//returns true if found - linear search
bool arrayOperations:: linearSearch(int key) {
    pos = 0;
    for(int i = 0; i < this->size(); i++) {
        if(arr[i] == key) {            
            return true;
        }
        pos = pos + 1;
    }
    return false;
}


//returns true if found - binary search
bool arrayOperations:: binarySearchIterative(int key) {
    if(!isSorted()) {
        bubbleSort();
    }
    pos = 0;
    int start = 0;
    int end = this->size();
    int mid = 0;
    while(start <= end) {
        mid = start + (end - start)/2;
        //mid = (start+end)/2;
        if(key == arr[mid]) {
            pos = mid;
            return true;
        } else if(key < arr[mid]) {
            end = mid-1;
        } else {
            start = mid+1;
        }
        //pos++;
    }    
    return false;
}


//binary search recursive
int arrayOperations:: binarySearchRecursive(int start, int end, int key) {
    if(start <= end) {
        int mid = start + (end - start)/2;
        if(key == arr[mid]) {
            return mid;
        }
        if(key < arr[mid]) {
            return binarySearchRecursive(start, mid-1, key);
        }
        return binarySearchRecursive(mid+1, end, key);
    }
    
    return -1;
}


bool arrayOperations:: isSorted() {
    for(int i = 0; i < s-1; i++) {
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}


//bubble sort
void arrayOperations:: bubbleSort() {
    for(int i = 0; i < s-1; i++) {
        for(int j = 0; j < s-i-1; j++) {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}


//selection sort
void arrayOperations:: selectionSort() {
    int minIndex;
    for(int i = 0; i < s-1; i++) {
        minIndex = i;
        for(int j = i+1; j < s; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(&arr[minIndex], &arr[i]);
    }
}


//insertion sort
void arrayOperations:: insertionSort() {
    int key;
    for(int i = 1; i < s; i++) {
        key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}


//partition() for quickSort()
int arrayOperations:: partition(int start, int end) {
    int pivot = arr[start];
    int i = start;
    int j = end;
    
    do {        
        do {
            i++;
        } while(arr[i] <= pivot);
        
        do {
            j--;
        } while(arr[j] > pivot);
        
        if(i < j)
            swap(&arr[i], &arr[j]);
    } while(i < j);
    
    swap(&arr[start], &arr[j]);
    return j;
}


//quickSort
void arrayOperations:: quickSort(int start, int end) {
    int part;
    if(start < end) {
        part = partition(start, end);
        quickSort(start, part);
        quickSort(part+1, end);
    }
}


//get minimum
int arrayOperations:: getMin() {
    int min = INT_MAX;
    for(int i = 0; i < s; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}


//get maximum
int arrayOperations:: getMax() {
    int max = INT_MIN;
    for(int i = 0; i < s; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


//reverse
void arrayOperations:: reverse() {
    int *tempArr;
    tempArr = new int[s];
    int j = 0;
    for(int i = s-1; i >= 0; i--) {
        tempArr[j] = arr[i];
        j++;
    }
    arr = tempArr;
}


//rotate (times to rotate)
//1 7 5 3 2 ==> 2 1 7 5 3
void arrayOperations:: rotate(int times) {
    for(int i = 1; i <= times % s; i++) {
        int temp = arr[s-1];
        for(int j = s-1; j > 0; j--) {
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }
}


//left shift (times to shift)
// 1 7 5 3 2 ==> 7 5 3 2 0
void arrayOperations:: leftShift(int times) {
    if(times >= s) {
        for(int i = 0; i < s; i++) {
            arr[i] = 0;
        }
        return;
    }
    for(int i = 1; i <= times; i++) {
        for(int j = 0; j < s-1; j++) {
            arr[j] = arr[j+1];
        }
        arr[s-1] = 0;
    }
}


//right shift (times to shift)
// 1 7 5 3 2 ==> 0 1 7 5 3
void arrayOperations:: rightShift(int times) {
    if(times >= s) {
        for(int i = 0; i < s; i++) {
            arr[i] = 0;
        }
        return;
    }
    for(int i = 1; i <= times; i++) {
        for(int j = s-1; j > 0; j--) {
            arr[j] = arr[j-1];
        }
        arr[0] = 0;
    }
}


//traverses and display the array
void arrayOperations:: display() {
    for(int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

#endif /* array_h */
