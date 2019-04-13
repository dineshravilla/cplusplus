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
    
    /*
    //d1.insertAtBegin(23);
    d1.insertAtEnd(24);
    d1.insertAfterNode(3, 87);
    d1.insertBeforeNode(4, 87);
    
    d1.insertBeforeNode(1, 54);                    //head
    d1.insertAfterNode(d1.length(), 65);          //tail
    
    cout << d1.length() << endl;
    */
    
    d1.display();
}
