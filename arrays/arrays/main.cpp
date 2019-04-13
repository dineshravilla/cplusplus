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
    
    arr1.create({1, 7, 5, 3, 2});
    
    
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
    
    arr1.display();
    return 0;
}
