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
    
    doublyLL dll;
    
    dll.append(12);
    dll.append(32);
    dll.append(54);
    dll.append(86);
    
    
    dll.insertAtBegin(23);
    dll.insertAtEnd(24);
    
    
    dll.display();
}
