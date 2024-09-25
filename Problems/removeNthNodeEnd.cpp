#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

        Node(int data)
         : data{data}, next{nullptr} {}
};

class LinkedList{
    public:
        LinkedList()
         : head{nullptr} {}

        int lengthList();
        void printList() const;
        void deleteNthNodeFromEnd(int n);


    private: 
       Node *head;
};

void LinkedList::printList() const{
    if(head==nullptr){
        cout<<"list is empty"<<endl;
    }
    Node *curr = head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

int LinkedList::lengthList() {
    int counter = 0;
    Node *curr = head;
    while(curr!=nullptr){
        counter +=1;
        curr = curr->next;
    }
    return counter;
}

void LinkedList::deleteNthNodeFromEnd(int n){
    if(head == nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    if(n<0){
        cout<<"Invalid index"<<endl;
        return;
    }
    int len = lengthList();

    if(n>len){
        cout<<"Invalid index"<<endl;
        return;
    }

    // nth node from end = kth node from begining by calculating len - n + 1
    int targetpos = len - n + 1;

    // edge cases for the targetpso
    if(targetpos == 1){
        // delete the first node
        head = head->next;
        return;
    }


    Node *curr = head;
    for(int i = 0; i<(targetpos - 1); i++){
          if(curr!=nullptr){
            curr = curr->next;
          }
    }
    // now at the n-1th node
    curr->next = curr->next->next;
}