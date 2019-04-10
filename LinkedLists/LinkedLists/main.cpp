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
    
    linkedList list1, list2;
    
    
    list1.addNode(5);
    for(int i = 1; i <= NODES; i++) {
        list1.append(i);
    }
    
    list1.append(12);
    list1.append(45);
    list1.append(56);
    
    list2.append(21);
    list2.append(34);
    list2.append(70);
    
    //cout << list1.retHead()->next->val;
    //cout << list2.retHead()->next->val;
    
    //node *newHead = list1.mergeTwoSortedLists(list1.retHead(), list2.retHead());
    
    /*while(newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }*/
    
    //list.append(2);
    //list.append(2);
    //list.append(10);
    //node *temp = list.del(20);          // position
    //node *temp = list.delKey(10);       // key
    
    //cout << endl << list.find(11) << endl;
    
    //list1.delAltNodesIter();
    //list.delAltNodesRecursive(head);
    
    //list.reverseIter(head);
    //list.reverseRecursive(NULL, head);
    
    //list1.removeDups2(head);
    
    list1.display();
    //list2.display();
    
    list1.reverseSubList(NULL, 2, 4);
    list1.display();
    
    return 0;
}
