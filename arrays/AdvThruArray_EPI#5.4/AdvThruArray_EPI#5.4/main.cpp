//
//  main.cpp
//  AdvThruArray_EPI#5.4
//
//  Created by Dinesh Ravilla on 4/14/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//

#include <iostream>
#include "array.h"

int main(int argc, const char * argv[]) {
    
    arrayOperations array;
    array.create({3, 2, 0, 0, 2, 0, 1});
    
    int furthestReach = 0;
    int lastIndex = array.size() - 1;
    
    for(int i = 0; i <= furthestReach && furthestReach < lastIndex; i++) {
        furthestReach = max(furthestReach, array.arr[i] + i);
    }
    
    if(furthestReach >= lastIndex) {
        cout << "can reach";
    }
    else {
        cout << "cannot reach";
    }
    return 0;
}
