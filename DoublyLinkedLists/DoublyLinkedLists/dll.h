//
//  dll.h
//  DoublyLinkedLists
//
//  Created by Dinesh Ravilla on 4/12/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//

#ifndef dll_h
#define dll_h

using namespace std;

class node {
public:
    int val;
    node *next;
    node *prev;
    node(int x) {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class doublyLL {
public:
    node *head, *tail;
    doublyLL() {
        head = NULL;
        tail = NULL;
    }
    
    //insert functions
    void append(int);
    void insertAtBegin(int);
    void insertAtEnd(int);
    void insertAfterNode(int, int);
    void insertBeforeNode(int, int);
    
    //length
    int length();
    
    //create doubly LL
    void createdoublyLL();
    
    //display doubly LL
    void display();
};


//Append
void doublyLL:: append(int ins) {
    node *temp = new node(ins);
    
    node *t = head;
    
    if(head == NULL) {
        head = temp;
        tail = temp;
    } else {
        while(t->next) {
            t = t->next;
        }
        t->next = temp;
        temp->prev = t;
        tail = temp;
    }
}


//Insert At Beginning
void doublyLL:: insertAtBegin(int ins) {
    node *temp = new node(ins);
    
    temp->next = head;
    head->prev = temp;
    temp->prev = NULL;
    head = temp;
}


//Insert At End
void doublyLL:: insertAtEnd(int ins) {
    node *temp = new node(ins);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}


//Insert After Node(position)
//(position, value)
void doublyLL:: insertAfterNode(int pos, int ins) {
    node *p = head;
    node *temp = new node(ins);
    int i = 1;
    while(i < pos) {
        p = p->next;
        i++;
    }
    //cout << p->val;
    temp->next = p->next;
    temp->prev = p;
    
    if(p->next) {
        p->next->prev = temp;
    } else {
        tail = temp;
    }
    p->next = temp;
    
}

//Insert Before Node(position)
//(position, value)
void doublyLL:: insertBeforeNode(int pos, int ins) {
    node *p = head;
    node *temp = new node(ins);
    int i = 1;
    while(i < pos) {
        p = p->next;
        i++;
    }
    temp->prev = p->prev;
    p->prev = temp;
    temp->next = p;
    if(temp->prev) {
        temp->prev->next = temp;
    } else {
        head = temp;
    }
}


//Length
int doublyLL:: length() {
    node *p = head;
   
    int count = 0;
    while(p) {
        p = p->next;
        count++;
    }
    return count;
}

//Display
void doublyLL:: display() {
    node *p = head;
    node *last = new node(0);
    while(p) {
        cout << p->val << " ";
        last = p;
        p = p->next;
    }
    cout << endl << "----------------------"
                 << endl << "Reversed List" << endl;
    //reverse display
    while(last) {
        cout << last->val << " ";
        last = last->prev;
    }
    cout << endl;
}

#endif /* dll_h */
