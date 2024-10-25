#include"SLL.cpp"
#include<iostream>
using namespace std;

// detect loop in  list
bool hasLoop(LinkedList *head) {
    // two pointer approach
    // 1. slow pointer moves one step at a time
    // 2. fast pointer moves two steps at a time
    // 3. if they meet, there is a loop
    // 4. if fast pointer reaches the end of the list, there is no loop

    // 1. Check if the list is empty or has only one node
    if (!head || !head->next) {
        return false;
    }
    if (!head || !head->next) {  // Check if the list is empty or has only one node
        return false;
    }

    LinkedList *slow = head;
    LinkedList *fast = head;

    while (fast && fast->next) {
        if (slow == fast) {
            return true;  // Loop detected
        }
        slow = slow->next;       // Move slow pointer by 1
        fast = fast->next->next; // Move fast pointer by 2
    }

    return false;  // No loop found  
    
}
int main() {
    LinkedList *head = new LinkedList();
    // Add nodes to the list, create a loop if needed
    // Example: head->next->next = head;

    if (hasLoop(head)) {
        cout << "Loop detected!" << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    // Free allocated memory, if necessary
    return 0;
}
