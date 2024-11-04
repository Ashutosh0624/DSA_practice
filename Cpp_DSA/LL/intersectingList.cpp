#include<iostream>
#include<unordered_map>
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
    
    LinkedList() : head{nullptr} {}
    
    void setHead(int val);
    void setTail(int val);
    void printList() const;
};

void LinkedList::setHead(int val) {
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
    Node *newNode =  new Node(val);
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

void LinkedList::printList() const{
    Node *curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

bool isIntersecting(LinkedList *l1, LinkedList *l2){
    std::unordered_map<Node*, int>map;
    Node *curr = l1->head;
    while(curr){
        map[curr] = 1;
        curr = curr->next;
    }
    curr = l2->head;
    while(curr){
        if(map.find(curr) != map.end()){
            cout<<"Node found, list has intersecting nodes"<<endl;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int main(){
    LinkedList l1;
    LinkedList l2;
    
    // Setting up the first list
    l1.setHead(23);
    l1.setTail(56);
    l1.setHead(22);
    l1.setTail(55);
    
    // Setting up the second list
    l2.setHead(66);
    l2.setTail(11);
    
    // Creating an intersection manually
    // Making l2's last node point to l1's second node (56)
    l2.head->next->next = l1.head->next->next; // Point l2's last node to a node in l1

    // Printing both lists
    cout << "List 1: ";
    l1.printList();
    cout << "List 2: ";
    l2.printList();
    
    // Checking for intersection
    bool result = isIntersecting(&l1, &l2);
    cout << "Do the lists intersect? " << (result ? "Yes" : "No") << endl;

    return 0;
    
    
}