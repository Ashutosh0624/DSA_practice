class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = next 

class Stack:
    def __init__(self):
        self.head = None

    def printStack(self):
        if self.head is None:
            return "stack is empty"
        curr = self.head 
        while curr:
            print(curr.data, end=" ")
            curr = curr.next
        print() 
    
    def isEmpty(self):
        return self.head is None 
    
    def peek(self):
        return self.head.data 
    
    def push(self, val):
        newNode =Node(val)
        newNode.next = self.head
        self.head = newNode
        return self.head
    
    def pop(self):
        if self.head is None:
            return "stack is empty"
        poppedNode = self.head
        self.head = self.head.next
        poppedNode.next = None
        del poppedNode
        return self.head
    
    def stackLength(self):
        count = 0
        curr = self.head
        while curr:
            count += 1
            curr = curr.next
        return count