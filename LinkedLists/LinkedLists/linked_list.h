//
//  linked_list.h
//  LinkedLists
//
//  Created by Dinesh Ravilla on 4/8/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <unordered_set>

using namespace std;

class node {
public:
    int val;
    node *next;
    node() {
        this->val = 0;
        this->next = NULL;
    }
};

//node *head;
int findPos = 1;        // Just a temp - to determine the position of key to delete based on the position - used in find(int) and delKey(int)

class linkedList {
public:
    node *tail;
    node *head;
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
    void delAltNodesIter();
    void delAltNodesRecursive(node*);
    
    //remove duplicates
    void removeDups1(node*);
    void removeDups2(node*);
    
    //reverse
    node* reverseIter(node*);
    void reverseRecursive(node*, node*);
    void reverseSubList(node*, int, int);               // EPI #7.2 (head, start of sublist, end of sublist); Leetcode #92
    
    //merging
    node* mergeTwoSortedLists(node*, node*);            // EPI #7.1
    node* mergeEvenOdd(node*);                          // EPI #7.10
    
  
    //reorder
    void reorderList(node*, node*);
    
    //swap
    node* swapNodePairs(node*);       // Leetcode #24
    
    //rotate
    node* rotateRight(node*, int);    // Leetcode #61 (head, num of times to rotate right)
    
    //partition
    node* partition(node*, int);      // Leetcode #86 (head, x) <nodes_lessthan_x> x <nodes_greaterthan_x>
    
    //cycle detection
    bool detectCycle(node*);          // EPI #7.3; Leetcode #141
    
    //return head
    node* retHead();
    
    int  length();
    void display();
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
    if(pos - this->length() > 1)
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
    if(pos > this->length())
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
void linkedList:: delAltNodesIter() {
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
node* linkedList:: reverseIter(node *p) {
    node *r = NULL;
    node *q = NULL;
    while(p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    //head = q;
    return q;
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

//reverses sublist in a singly linked list
//(node *head, int start of sublist, int end of sublist)
//EPI #7.2; Leetcode #92
void linkedList:: reverseSubList(node *p, int start, int end) {
    node *sublistHead = NULL;
    p = head;
    int k = 1;
    while(k++ < start) {
        sublistHead = p;
        p = p->next;
    }
    
    node *sublistIter = sublistHead->next;
    while(start++ < end) {
        node *temp = sublistIter->next;
        sublistIter->next = temp->next;
        temp->next = sublistHead->next;
        sublistHead->next = temp;
    }
}

//removes duplicates two loops O(n^2)
void linkedList:: removeDups1(node *p) {
    node *q;
    node *temp;
    while(p && p->next) {
        q = p;
        while(q->next) {
            if(p->val == q->next->val) {
                temp = q->next;
                q->next = q->next->next;
                delete(temp);
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }    
}

//removes duplicates using hashset
void linkedList:: removeDups2(node *p) {
    node *q;
    //p = head;
    q = NULL;
    unordered_set<int> hashSet;
    while(p) {
        if(hashSet.find(p->val) != hashSet.end()) {
            q->next = p->next;
            delete(p);
        } else {
            hashSet.insert(p->val);
            q = p;
        }
        p = q->next;
    }
}

//returns head of the list
node* linkedList:: retHead() {
    return this->head;
}

//merges two sorted results
node* linkedList:: mergeTwoSortedLists(node *p, node *q) {
    
    node* mergedHead, *temp;
    
    if(p == NULL)
        return q;
    if(q == NULL)
        return p;
    if(p == NULL && q == NULL)
        return NULL;
    
    if(p->val < q->val) {
        mergedHead = p;
        p = p->next;
    } else {
        mergedHead = q;
        q = q->next;
    }
    
    temp = mergedHead;
    
    while(p && q) {
        if(p->val < q->val) {
            temp->next = p;
            temp = p;
            p = p->next;
        } else {
            temp->next = q;
            temp = q;
            q = q->next;
        }
    }
    
    if(p)
        temp->next = p;
    if(q)
        temp->next = q;
    
    return mergedHead;
}

//merge even->odd; EPI #7.10
node* linkedList:: mergeEvenOdd(node *p) {
    if(p == NULL)
        return NULL;
    node *evenBefore = new node;
    node *oddBefore = new node;
    node *even = evenBefore;
    node *odd = oddBefore;
    
    while(p) {
        even->next = p;
        even = even->next;
        
        odd->next = p->next;
        odd = odd->next;
        
        p = p->next->next;
    }
    odd->next = NULL;
    even->next = oddBefore->next;
    return evenBefore->next;
}


//reorder list; Leetcode #143
void linkedList:: reorderList(node *actualHead, node *revHead) {
    int len = length();
    cout << len;
}

//Swap nodes in pairs - leetcode #24
node* linkedList:: swapNodePairs(node *p) {
    if(p == NULL || p->next == NULL)
        return p;
    node *firstNode = p;
    node *secondNode = p->next;
    firstNode->next = secondNode->next;
    secondNode->next = firstNode;
    p = secondNode;
    //head = secondNode;
    //cout << endl << p->val << endl;
    p->next->next = swapNodePairs(p->next->next);
    return p;
}

//Rotate list - leetcode #61
node* linkedList:: rotateRight(node *p, int k) {
    //make it circular list first
    int len = 1;
    if(p == NULL)
        return NULL;
    while(p->next) {
        len++;
        p = p->next;
    }
    p->next = head;
    k = k % len;
    for(int i = 0; i < len-k; i++) {
        p = p->next;
    }
    node *newHead = p->next;
    p->next = NULL;
    return newHead;
}

//Partition list
//nodes less than x - x - nodes greater than x
node* linkedList:: partition(node *p, int x) {
    
    node *beforeHead = new node;
    node *afterHead = new node;
    node *before = beforeHead;
    node *after = afterHead;
    
    while(p) {
        if(p->val < x) {
            before->next = p;
            before = before->next;
        } else {
            after->next = p;
            after = after->next;
        }
        p = p->next;
    }
    after->next = NULL;
    before->next = afterHead->next;
    delete afterHead;
    return beforeHead->next;
}

//cycle detection
//EPI #7.3
//Leetcode #141
bool linkedList:: detectCycle(node *p) {
    //slow and fast pointers
    if(p == NULL || p->next == NULL)
        return false;
    node *slow = p;
    node *fast = p->next;
    while(slow != fast) {
        if(fast == NULL || fast->next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

//returns length of a list
int linkedList:: length() {
    node *p = head;
    int count = 0;
    if(p == NULL)
        return 0;
    while(p) {
        count++;
        p = p->next;
    }
    return count;
}

//display linked_list
void linkedList:: display() {
    node *p = head;
    if(p == NULL)
        return;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}


#endif /* linked_list_h */
