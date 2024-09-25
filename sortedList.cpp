#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

        Node(int data)
         :data{data},next{nullptr} {}
};

class LinkedList{
    public:
        LinkedList()
         : head{nullptr} {}

         void insertNode(int val);
         void sortList();
         void printList() const;

    private:
       Node *head;
};
void LinkedList::printList()const{
    Node *curr = head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
    }
    cout<<endl;
}
void LinkedList::insertNode(int val){
    Node *newNode = new Node(val);
    if (head == nullptr){
        head = newNode;
    }
    else{
        Node *curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
    }
}
void LinkedList::sortList(){
    int max = head->data;
    
}