#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int data) : data{data}, next{nullptr} {}
};

class LinkedList{
    public:
    Node *head;
    
    LinkedList() : head{nullptr} {}
    
    void printList() const;
    void setHead(int val);
    void setTail(int val);
    
};

void LinkedList::printList() const{
    Node *curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

void LinkedList::setTail(int val){
    Node *newNode = new  Node(val);
    if(head == nullptr){
        setHead(val);
        return;
    }
    Node *curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = newNode;
    return;
}

void LinkedList::setHead(int val){
    Node *newNode = new Node(val);
    if (head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

void concatenateList(LinkedList* l1, LinkedList* l2){
    if(l1->head == nullptr){
        return;
    }
    Node* curr = l1->head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = l2->head;
}

int  main(){
    LinkedList l1;
    l1.setHead(45);
    l1.setTail(44);
    l1.printList();
    LinkedList l2;
    l2.setHead(41);
    l2.setTail(43);
    l2.printList();
    
    concatenateList(&l1, &l2);
    l1.printList();
    return 0;
}