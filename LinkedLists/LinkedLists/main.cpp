//
//  main.cpp
//  LinkedLists
//
//  Created by Dinesh Ravilla on 4/8/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//


#include <iostream>
#include "linked_list.h"
#define NODES 10

using namespace std;

int main(int argc, const char * argv[]) {
    
    linkedList list;
    
    for(int i = 1; i <= NODES; i++) {
        list.append(i);
    }
    list.append(2);
    list.append(2);
    list.append(10);
    //node *temp = list.del(20);          // position
    //node *temp = list.delKey(10);       // key
    
    //cout << endl << list.find(11) << endl;
    
    //list.delAltNodesIter(head);
    //list.delAltNodesRecursive(head);
    
    //list.reverseIter(head);
    //list.reverseRecursive(NULL, head);
    
    list.display(head);
    
    list.removeDups2(head);
    
    list.display(head);
    
    return 0;
}
