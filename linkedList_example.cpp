#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

        // Constructor
        Node(int data)
          : data{}, next{nullptr} {}  
};

class LinkedList{
    public:
        LinkedList()
            : head{nullptr} {}

            void printList()const;
            void insertNodeAtHead(int val);
            void insertNodeAtTail(int val);
            void insertNodeAtIndex(int val, int index);
            void deleteHeadNode();
            void deleteKthNode(int k);
            void deleteTailNode();
            int LengthList();
        
    private:
        Node *head;
};

void LinkedList::printList()const{
    Node *curr = head;
    while (curr!=nullptr){
           cout<<curr->data<<" ";
    }
    cout<<endl;
}

void LinkedList::insertNodeAtHead(int val){
    Node *newNode = new Node(val);
    if (head == nullptr){
        cout<<"List is empty"<<endl;
        head = newNode;
        return;}
    else{
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::insertNodeAtTail(int val){
     // check the edge condition
     Node *newNode = new Node(val);

     if(head==nullptr){
        insertNodeAtHead(val);
     }
     else{
        // traverse to the last node
        Node *curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
     }
}

void LinkedList::insertNodeAtIndex(int val, int index){
    Node *newNode = new Node(val);

    if (index == 0){
        insertNodeAtHead(val);
        return;
    }

    if(index <0){
        cout<<"Index can't be negative."<<endl;
        return;
    }

    int len = LengthList();

    if (index >= len){
        cout<<"Index is greater than the total no of nodes in the list. The new node will be added at the end."<<endl;
        index = len;
    }

    // traverse to the node just before the insertion point

    Node *curr = head;
    for (int i = 0; i<(index - 1); i++){
        if (curr !=nullptr){
            curr = curr->next;}
            else{
                cout<<"Index out of bound"<<endl;
                return;
            }
        }
    
    // Case 2: Insertion in the middle or at the end
    newNode->next = curr->next;
    curr->next = newNode;
    
}
