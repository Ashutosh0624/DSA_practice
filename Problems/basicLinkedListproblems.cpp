#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        

        // Node class constructor
        Node(int data)
            : data{data}, next{nullptr}{}
};

class LinkedList{

    private:
        Node *head;
        Node *tail;
        int length;
    public:
        LinkedList(int val) {
            Node *newNode = new Node(val);
            head = newNode;
            tail = newNode;
            length+=1;
        }
        void displayList()const;
        void insertNodeAtHead(int val);
        void insertNodeAtTail(int val);
        void insertNodeAtIndex(int val, int index);
        int LengthList();
};
void LinkedList::displayList()const{
    if (head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    Node *curr = head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
void LinkedList::insertNodeAtHead(int val){
    Node *newNode = new Node(val);
    if (head == nullptr){
        head = newNode;
        return;
    }
    else{
        newNode->next = head;
        head = newNode;
        return;
    }
}
void LinkedList::insertNodeAtTail(int val){
    Node *newNode = new Node(val);
    if (head == nullptr){
        head = newNode;
        return;
    }
    else{
        Node *curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
        return;
    }
}
void LinkedList::insertNodeAtIndex(int val, int index){
    if(index < 0){
        cout<<"Index can't be negative";
        return;
    }

    if(index == 0){
        insertNodeAtHead(val);
    }

    int len = LengthList();
    if (index >= len){
        cout<<"index > length of list, node will be inserted at the end."<<endl;
        index = len;
    }
    Node *curr = head;
    Node *newNode = new Node(val);
    for (int i = 0; i<(index - 1); i++){
        if (curr != nullptr){
            curr = curr->next;
        }
        else{
            cout<<"Index out of bound"<<endl;
            return;
        }
    }
    // now at one node before the target indexed node
    newNode->next = curr->next;
    curr->next = newNode;
}
int LinkedList::LengthList(){
    int counter = 0;
    Node *curr = head;
    while(curr!=nullptr){
        counter +=1;
        curr = curr->next;
    }
    return counter;
}