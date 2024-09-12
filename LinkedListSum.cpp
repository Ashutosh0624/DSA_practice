#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

        Node(int data)
          : data{data}, next{nullptr}{}
};
class LinkedList{
    public:
        LinkedList()
            :head{nullptr} {}
        void insertNode(int val);   // Function to insert a node
        int elementSum();           // Function to calculate  the sum of elements

    private:
       Node *head;
};

void LinkedList::insertNode(int val){
    Node *newNode = new Node(val);
    if (head == nullptr){
        cout<<("List is empty, node will be added as the first node.");
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

int LinkedList::elementSum(){
    int sum = 0;
    Node *curr = head;
    while(curr!=nullptr){
        sum += curr->data;
        curr = curr->next;
    }
    return sum;
}

int main(){
    LinkedList L1;

    // inserting elements
    L1.insertNode(12);
    L1.insertNode(45);
    L1.insertNode(67);
    L1.insertNode(56);
    int sum = L1.elementSum();
    cout<<"Sum of elements of the linked list : "<<sum<<endl;
    return 0;
}

