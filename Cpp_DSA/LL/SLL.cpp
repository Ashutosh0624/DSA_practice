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
    
    LinkedList(): head{nullptr} {}
    
    void printList()const;
    void setHead(int val);
    void setTail(int val);
    void setNthNode(int val, int index);
    
    // deletion operation
    
    void deleteHead();
    void deleteTail();
    void deleteNthNode(int index);
    
    int lengthList();
};
void LinkedList::printList() const{
    Node *curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

void LinkedList::setHead(int val){
    Node *newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

void LinkedList::setTail(int val){
    Node *newNode = new Node(val);
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
void LinkedList::setNthNode(int val, int index){
    Node *newNode = new Node(val);
    if(head == nullptr){
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
    Node *curr = head;
    for(int i=0; i<index-1; i++){
        curr = curr->next;
    }
    if(curr->next != nullptr){
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void LinkedList::deleteHead(){
    if(head == nullptr){
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
}
void LinkedList::deleteTail(){
    if(head == nullptr){
        return;
    }
    // if list has just one element
    if(head->next == nullptr){
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
    return;
}
void LinkedList::deleteNthNode(int index){
    int len = lengthList();
    if(head == nullptr || index < 0 || index >= len){
        return;
    }
    if(head->next == nullptr){
        Node *temp = head;
        head = nullptr;
        delete temp;
        return;
    }
    Node *curr = head;
    for(int i=0; i<index-1 && curr->next; i++ ){
        curr = curr->next;
    }
    Node *temp = curr->next;
    if(curr->next){
        curr->next = temp->next;
        temp->next = nullptr;
        delete temp;
        return;
    }
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
    l1.setHead(3);
    l1.setHead(56);
    l1.setTail(67);
    l1.printList();
    l1.setHead(86);
    l1.setTail(97);
    l1.setHead(76);
    l1.setTail(37);
    l1.setNthNode(51, 3);
    l1.printList();
    l1.setNthNode(661, l1.lengthList());
    l1.printList();
    l1.setNthNode(202, l1.lengthList()-4);
    l1.printList();
    l1.deleteHead();
    l1.printList();
    l1.deleteTail();
    l1.printList();
    l1.deleteNthNode(3);
    l1.printList();
    return 0;
}