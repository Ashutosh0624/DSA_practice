#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data): data{data}, next{nullptr} {}
};

class LinkedList{
    public:
    Node *head;

    LinkedList(): head{nullptr} {}
    
    void printList() const;
    void setHead(int val);
    void setTail(int val);
    void setNthNode(int val, int index);
    void deleteHead();
    void deleteTail();
    void deleteNthNode(int index);
    int lenghtList();
};

void LinkedList::printList() const{
    Node *curr = head;
    while(curr)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

void LinkedList::setHead(int val){
    Node *newNode = new Node(val);
    if(head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
    // Time Complexity: O(1)
}
void LinkedList::setTail(int val){
    Node *newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node *curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = newNode;
    return;
    // Time Complexity: O(n)
}
void LinkedList::setNthNode(int val, int index){
    if(index < 0) return;
    Node *newNode = new Node(val);
    if(index == 0){
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *curr = head;
    for(int i=0; i<index-1 && curr; i++){
        curr = curr->next;
    }
    if(curr == nullptr) return;
    newNode->next = curr->next;
    curr->next = newNode;
    return;
    // Time Complexity: O(n)
}
void LinkedList::deleteHead(){
    if(head == nullptr) return;
    Node *temp = head;
    head = head->next;
    delete temp;
    return;
    // Time Complexity: O(1)
}       
void LinkedList::deleteTail(){
    if(head == nullptr) return;
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node *curr = head;
    while(curr->next->next){
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
    return;
    // Time Complexity: O(n)
}
void LinkedList::deleteNthNode(int index){
    if(index < 0) return;
    if(index == 0){
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *curr = head;
    for(int i=0; i<index-1 && curr; i++){
        curr = curr->next;
    }
    if(curr == nullptr || curr->next == nullptr) return;
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return;
    // Time Complexity: O(n)
}
int LinkedList::lenghtList(){
    int count = 0;
    Node *curr = head;
    while(curr){
        count++;
        curr = curr->next;
    }
    return count;
    // Time Complexity: O(n)
}
int main(){
    LinkedList list;
    list.setHead(10);
    list.setTail(20);
    list.setNthNode(30, 1);
    list.printList();
    cout<<"Length of the list: "<<list.lenghtList()<<endl;
    list.deleteHead();
    list.printList();
    list.deleteTail();
    list.printList();
    list.deleteNthNode(0);
    list.printList();
    return 0;
}