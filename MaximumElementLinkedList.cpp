#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        
        Node(int data)
         :data{data}, next{nullptr} {}
};
class LinkedList{
    public:
        LinkedList()
          : head{nullptr} {}

        void insertNode(int val);
        int MaxElementList();


    private:
       Node *head;
};

void LinkedList::insertNode(int val){
    Node *newNode = new Node(val);

    if (head==nullptr){
        head = newNode;
    }
    else{
        Node *curr = head;
        while(curr->next !=nullptr){
            curr =curr->next;
        }
        curr->next = newNode;
    }
}

int LinkedList::MaxElementList(){
    int max = 0;
    Node *curr = head;
    while(curr->next!=nullptr){
        if(curr->data > max){
            max = curr->data;
            }
        curr = curr->next;
    }
    return max;
}
int main(){
    LinkedList l1;
    l1.insertNode(12);
    l1.insertNode(24);
    l1.insertNode(78);
    l1.insertNode(10);
    l1.insertNode(5);
    int max = l1.MaxElementList();
    cout<<max<<endl;
    return 0;
}