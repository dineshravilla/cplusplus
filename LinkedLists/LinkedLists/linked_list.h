//
//  linked_list.h
//  LinkedLists
//
//  Created by Dinesh Ravilla on 4/8/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

using namespace std;

class node {
public:
    int val;
    node *next;
};


node *head;
int findPos = 1;        // Just a temp - to determine the position of key to delete based on the position - used in find(int) and delKey(int)


class linkedList {
public:
    node *tail;
    linkedList() {
        head = NULL;
        tail = NULL;
    }
    
    //insert functions
    void addNode(int);
    void append(int);
    void insert(int, int);  //(val, position)
    
    //search
    bool find(int);         // searches for key in the list. returns 1 if found
    
    //delete functions
    node* del(int);          //(position) - returns the new head if deleted successfully
    node* delKey(int);       //(val) - searches for val and deletes. returns the new head if deleted successfully
    void delAltNodesIter(node*);
    void delAltNodesRecursive(node*);
    
    //remove duplicates
    //-----------------
    
    
    //reverse
    void reverseIter(node*);
    void reverseRecursive(node*, node*);
    
    int  length(node *);
    void display(node *);
    
};


//add node to a list at the end
// 1->2->(new Node)
void linkedList:: addNode(int num) {
    node *temp = new node;
    temp->val = num;
    temp->next = NULL;
    
    if(head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = tail->next;
    }
}

//add node to a list at the end - same as addNode
// 1->2->(new Node)
void linkedList:: append(int num) {
    node *temp = new node;
    temp->val = num;
    temp->next = NULL;
    node *t = head;
    
    if(head == NULL) {
        head = temp;
        tail = temp;
    } else {
        while(t->next) {
            t = t->next;
        }
        t->next = temp;
    }
}

//inserts node with "num" at position "pos"
// 1->2->(new Node)->3->4->5
void linkedList:: insert(int num, int pos) {
    if(pos - this->length(head) > 1)
        return;
    node *temp = new node;
    temp->val = num;
    temp->next = NULL;
    
    node *t = head;
    
    if(pos == 0) {
        temp->next = head;
        head = temp;
    } else {
        for(int i = 0; i < pos-1; i++) {
            t = t->next;
        }
        temp->next = t->next;
        t->next = temp;
    }
}


//returns 1 if "key" is found in the list
bool linkedList:: find(int key) {
    node *t = head;
    if(t == NULL)
        return false;
    while(t) {
        if(t->val == key) {
            return true;
        }
        findPos++;
        t = t->next;
    }
    findPos = 0;
    return false;
}

//deletes node at position "pos" and returns true if deleted successfully
node* linkedList:: del(int pos) {
    if(pos > this->length(head))
        return head;
    if(head == NULL) {
        return NULL;
    } else if(head == tail && pos == 0) {
        delete head;
        return NULL;
    } else if(pos == 0 && head->next) {
        node *temp = head->next;
        delete head;
        head = temp;
        return head;
    } else {
        node *p = head;
        node *q = NULL;
        for(int i = 0; i < pos-1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
        return head;
    }
}

//searches for key and deletes if found - returns the new head
node* linkedList:: delKey(int key) {
    if(this->find(key)) {
        return del(findPos);
    } else {
        return head;
    }
}

// deletes alternate nodes in linked list - Iterative
//"p" in while is for even number of nodes in LL
//"p->next" in while is for odd number of nodes in LL
void linkedList:: delAltNodesIter(node *head) {
    node *q, *p;
    q = NULL;
    p = head;
    while(p && p->next) {
        q = p;
        p = p->next;
        q->next = p->next;
        delete p;
        p = q->next;
        
    }
}

//deletes alternate nodes in linked list - Recursion
void linkedList:: delAltNodesRecursive(node *head) {
    if(head == NULL)
        return;
    node *temp = head->next;
    if(temp == NULL)
        return;
    head->next = temp->next;
    delete temp;
    delAltNodesRecursive(head->next);
}

//reverses linked list iteratively - r, q, p - sliding pointers.
void linkedList:: reverseIter(node *p) {
    node *r = NULL;
    node *q = NULL;
    while(p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    //return head;
}

//reverses linked list recursively
void linkedList:: reverseRecursive(node *q, node *p) {
    if(p) {
        reverseRecursive(p, p->next);
        p->next = q;
    } else {
        head = q;
    }
}

//returns length of a list
int linkedList:: length(node *head) {
    int count = 0;
    if(head == NULL)
        return 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

//display linked_list
void linkedList:: display(node *head) {
    if(head == NULL)
        return;
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


#endif /* linked_list_h */
