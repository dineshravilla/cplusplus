//
//  main.cpp
//  DeleteDups_EPI#5.5
//
//  Created by Dinesh Ravilla on 4/14/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//


//Time complexity - O(nlogn) - to sort
//                  O(n) - to traverse

//To do without sorting - O(n^2)

#include <iostream>
#include "array.h"

int main(int argc, const char * argv[]) {
    
    arrayOperations array;
    array.create({2,3,5,5,7,11,11,11,13});
    
    int j = 1;
    for(int i = 1; i < array.size(); i++) {
        if(array.arr[j-1] != array.arr[i]) {
            array.arr[j] = array.arr[i];
            j++;
        }
    }
    
    cout << endl;
    array.display();
    cout << "Unique Elements:" << j << endl;
    return 0;
}
