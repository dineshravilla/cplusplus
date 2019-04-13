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

int findPos = 1;

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
    
    //search
    bool find(int);
    
    //delete
    void del(int);
    void delKey(int);
    
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


//Search
bool doublyLL:: find(int key) {
    node *p = head;
    while(p) {
        if(p->val == key) {
            return true;
        }
        p = p->next;
        findPos++;
    }
    return false;
}


//Delete based on position
void doublyLL:: del(int pos) {
    int len = this->length();
    if(pos > len) {
        cout << "Length < position.";
        return;
    }
    if(pos <= 0) {
        cout << "Not 0 indexed.";
        return;
    }
    node *p = head;
    node *q = tail;
    if(pos == 1) {
        head = p->next;
        if(p->next)
            p->next->prev = NULL;
        delete p;
    } else if(pos == len) {
        tail = q->prev;
        tail->next = NULL;
        delete q;
    } else {
        int i = 1;
        while(i < pos) {
            p = p->next;
            i++;
        }
        if(p->prev)
            p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        delete p;
    }
}


//Delete based on the key element
void doublyLL:: delKey(int key) {
    if(this->find(key)) {
        del(findPos);
    } else {
        cout << "Element not found" << endl;
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
