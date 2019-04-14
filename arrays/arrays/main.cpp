//
//  main.cpp
//  arrays
//
//  Created by Dinesh Ravilla on 4/13/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//

#include <iostream>

#include "array.h"

int main(int argc, const char * argv[]) {
    
    
    arrayOperations arr1;
    
    //arr1.create();
    
    arr1.create({1, 7, 5, 3, 2, 6, 4, 0});
    
    //arr1.create({1, 7, 5, 3, 2, 10, 9, 8, 7, 8, 1, 5, 4, 3, 2, 5, 0, 2, 12, 34, 32, 31, 19});

    /*
     // ...binary search test lines
    if(arr1.binarySearchIterative(0)) {
        cout << "Found at: " << arr1.pos << endl;
    } else {
        cout << "Not found." << endl;
    }
    
    arr1.bubbleSort();
    
    int key = 5;
    
    int result = arr1.binarySearchRecursive(0, arr1.size()-1, key);
    
    if(result == -1) {
        cout << "Not found" << endl;
    } else {
        cout << "Found at: " << result << endl;
    }
     */
    
    //arr1.bubbleSort();
    
    
    /*
     // ...isSorted test lines
    if(arr1.isSorted()) {
        cout << "sorted";
    } else {
        cout << "not sorted";
    }
     */
    
    /*
     // ...linear search test lines
    if(arr1.linearSearch(53)) {
        cout << "Found at:" << arr1.pos << endl;
    } else {
        cout << "Not found" << endl;
    }
     */
    
    //arr1.selectionSort();
    
    //arr1.insertionSort();
    
    //arr1.quickSort(0, arr1.size());
    
    //cout << "MIN: " << arr1.getMin() << endl;
    //cout << "MAX: " << arr1.getMax() << endl;
    
    //arr1.display();
    
    //arr1.reverse();
    //arr1.rotate(2);
    //arr1.leftShift(5);
    //arr1.rightShift(2);
    
    //cout << "Second min:" << arr1.getSecondMin() << endl;
    
    //cout << "Second max: " << arr1.getSecondMax() << endl;
    
    //cout << "Third min:" << arr1.getKthMin(8) << endl;
    
    //cout << "Third max: " << arr1.getKthMax(8) << endl;
    
    arr1.display();
    
    return 0;
}
