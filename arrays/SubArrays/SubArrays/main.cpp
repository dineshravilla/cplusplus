//
//  main.cpp
//  SubArrays
//
//  Created by Dinesh Ravilla on 4/22/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//


#include <iostream>
#include "array.h"

int main(int argc, const char * argv[]) {
    
    arrayOperations array;
    array.create({-2,1,-3,4,-1,2,1,-5,4});
    
    cout << "sub array max:" << array.maxSubArray(array.arr, array.size()) << endl;
    
    return 0;
}
