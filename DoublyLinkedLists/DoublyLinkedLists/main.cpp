//
//  main.cpp
//  DoublyLinkedLists
//
//  Created by Dinesh Ravilla on 4/12/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//

#include <iostream>
#include "dll.h"

int main(int argc, const char * argv[]) {
    
    doublyLL d1;
    
    d1.append(12);
    d1.append(32);
    d1.append(54);
    d1.append(86);
    d1.append(43);
    d1.append(98);
    
    /* ---------------------
     // insert test lines
     
    d1.insertAtBegin(23);
    d1.insertAtEnd(24);
    d1.insertAfterNode(3, 87);
    d1.insertBeforeNode(4, 87);
    
    d1.insertBeforeNode(1, 54);                   //head
    d1.insertAfterNode(d1.length(), 65);          //tail
    
    cout << d1.length() << endl; */
    
    /* ---------------------
     // delete test lines
    d1.del(1);
    d1.del(d1.length());
    d1.del(2);
    d1.del(3);
    d1.del(1);
    d1.delKey(98); */
    
    
    /* ---------------------
     // search test lines
    if(d1.find(86)) {
        cout << "Found" << findPos << " ";
    } else {
        cout << "Not Found";
    }*/
    d1.reverse();
    d1.display();
}
