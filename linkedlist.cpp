#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next = nullptr;
        
        // constructor
        Node(int data)
            :data{data} {}
};

class LinkedList{
    public:
        LinkedList()
           :head{nullptr} {}
        // insertion operation
        void insertNodeatHead(int val);
        void insertNodeatTail(int val);
        void insertNodeAtIndex(int val, int index);

        // deletion operation
        void deleteFirstNode();
        void deleteTailNode();
        void deleteKthNode(int k);
        // traversing and printing the list elements
        void printList()const;
        int LengthList()const;
    
    private:
         Node *head;
};
void LinkedList::printList() const{
    Node *curr = head;
    while (curr!=nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;

}
void LinkedList::insertNodeatHead(int val){
    //Node newNode = Node(val); 
    // instead this use dynamic memory allocation, as new node objects and its address being used might show undefined behaviour 
    // after it goes out of scope.
    Node *newNode = new Node(val); // Allocating memory dynamically
    if(head==nullptr){
        cout<<"list is empty, new node will be the first node and the head"<<endl;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}
void LinkedList::insertNodeatTail(int val){
    //Node newNode = Node(val);
    Node *newNode = new Node(val);
    if (head==nullptr){
        insertNodeatHead(val);
        return;
    }
    else{ 
        // traverse to the last node
        Node *curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        // inserting the node at tail position
        curr->next = newNode;
    }
}

void LinkedList::insertNodeAtIndex(int val, int index){
    // Node newNode = Node(val);
    Node *newNode = new Node(val);
    // check the edge condition
    if (index<0){
        cout<<"Index can not be negative"<<endl;
        return;
    }
    if (head==nullptr){
        cout<<"List is empty."<<endl;
        if(index == 0){
            head = newNode; // added the new node at index = 0, the first node 
        }
        else{
            cout<<"Index other than 0, node can not be inserted as list is empty, hence the preceeding nodes to  the given index does not exist."<<endl;
            return ;
        }   
    }
    // if list is not empty , index > 0. Check the index value for out of bound error
    int len = LengthList();
    if(index >= len){
        cout<<"index > length of the list, inserting the node at the end of the list."<<endl;
        index = len;}
    
    Node *curr = head;
    for(int i = 0; i<(index - 1); i++){
        if(curr!=nullptr){
            curr = curr->next;
        }
        else{
            cout<<"Index out of bound."<<endl;
        }
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

int LinkedList::LengthList() const{
    int counter = 0;
    Node *curr = head;
    while(curr!=nullptr){
        counter +=1;
        curr = curr->next;
    }
    return counter;
}

void LinkedList::deleteFirstNode(){
    // edge condition 
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    else{
        head = head->next;
    }
}
void LinkedList::deleteTailNode(){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        // traverse to the last node
        Node *curr = head;
        while(curr->next->next!=nullptr){
            curr= curr->next;
        }
        curr->next = nullptr;
    }
}
void LinkedList::deleteKthNode(int k){
    if(head == nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    int len = LengthList();
    if (k==0){
        deleteFirstNode();
    }
    if(k>=len){
        cout<<"Index out  of bound."<<endl;
        return;
    }
    if(k<0){
        cout<<"Negative index does not exist"<<endl;
        return;
    }
    Node *curr = head;
    for(int i = 0; i<(k-1); i++){
        if(curr!=nullptr){
            curr = curr->next;
        }
        else{
            cout<<"Index out of bound"<<endl;
            return;
        }
    }
    if (curr->next==nullptr){
        cout<<"index out of bound"<<endl;
    }
    curr->next = curr->next->next;
}