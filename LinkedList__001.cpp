/*

Implementation of the Basic data structures and Algorithms
DS :- Linked List 
   Funtions : Insert opeartions, delete operations, print elements and reverse etc.
*/
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
       Node *head;

       LinkedList()
         : head{nullptr} {}

       void printList() const;
       void setHead(int val);
       void setTail(int val);
       void setNthNode(int val, int index);
       void deleteHead();
       void deleteTail();
       void deleteNthNode(int n);
       int lengthList();
};
void LinkedList::setHead(int val){
    Node *newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        return;}
    newNode->next = head;
    head = newNode;
    return;
}
void LinkedList::setTail(int val){
    Node *newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node *curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = newNode;
    return;
}
void LinkedList::setNthNode(int val, int index){
    Node *newNode = new Node(val);
    if(index == 0){
        setHead(val);
        return;
    }
    if(index < 0){
        return;
    }
    int len = lengthList();
    if(index >= len){
        setTail(val);
        return;
    }
    // Traversing to the second last node to the given index
    Node *curr = head;
    for(int i = 0; i<index-1; i++){
        curr = curr->next;
    }

    // curr pointer is pointing to the second last node
    newNode->next = curr->next;
    curr->next = newNode;
    return;
}
void LinkedList::deleteHead(){
    if(head == nullptr){
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteTail(){
    if(head == nullptr){
        return;
    }
    if(head->next = nullptr){
        Node *temp = head;
        head = nullptr;
        delete temp;
        return;
    }
    Node *curr = head;
    while(curr->next->next != nullptr){
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = nullptr;
    delete temp;
}
void LinkedList::deleteNthNode(int index){
    if((head == nullptr) || (index <0)){
        return;
    }
    if(index == 0){
    deleteHead();
    return;
    }
    int len = lengthList();
    if(index >= len){
        return;
    }
    Node *curr = head;
    for(int i = 0; i<index-1; i++){
        curr = curr->next;
    }

    // if index is out of bound, do nothing
    if(curr == nullptr || curr->next == nullptr){
        return;
    }

    Node *temp = curr->next;
    curr->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return;
}
void LinkedList::printList() const{
    if(head == nullptr){
        return;
    }
    Node *curr = head;
    while(curr){
        std::cout<<curr->data<<" ";
        curr = curr->next;
    }
    std::cout<<std::endl;
}
int LinkedList::lengthList(){
    int count = 0;
    Node *curr = head;
    while(curr){
        count++;
        curr = curr->next;
    }
    return count;
}
int main(){
    LinkedList l1;
    l1.setHead(56);
    l1.setHead(33);
    l1.setTail(62);
    l1.setTail(90);
    l1.printList();
    l1.setNthNode(12, 1);
    l1.printList();
    l1.deleteHead();
    l1.printList();
    l1.deleteTail();
    l1.printList();
    return 0 ;

}