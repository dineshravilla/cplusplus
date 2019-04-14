//
//  main.cpp
//  PlusOne_EPI#5.2
//
//  Created by Dinesh Ravilla on 4/14/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//

#include <iostream>
#include "array.h"

arrayOperations number;
arrayOperations result;

void plusOne(int *temp) {
    
    for(int i = number.size() - 1; i >= 0; i--) {
        if(temp[i] < 9) {
            temp[i]++;
            number.display();
            return;
        }
        temp[i] = 0;
    }
    
    result.create(number.size()+1, 0);
    result.arr[0] = 1;
    result.display();
}

int main(int argc, const char * argv[]) {
    
    
    number.create({1,9,9,3,9,9});
    
    //int *result;
    
    plusOne(number.arr);
    
    //result.display();
    
    return 0;
}
