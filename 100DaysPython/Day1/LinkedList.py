class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = next
        
class LinkedList:
    def __init__(self):
        self.head = None
        
    def printList(self):
        curr = self.head
        while(curr):
            print(curr.data, end=" ")
            curr = curr.next
        print()
        
    def setHead(self, val):
        newNode = Node(val)
        if self.head is None:
            self.head = newNode
            return
        newNode.next = self.head
        self.head = newNode
        return
    
    def setTail(self, val):
        if self.head is None:
            self.setHead(val)
            return
        newNode = Node(val)
        curr = self.head 
        while(curr.next):
            curr = curr.next
        curr.next = newNode
        return
    
    def setNthNode(self, val, index):
        newNode = Node(val)
        if self.head is None:
            self.setHead(val)
            return
        
        if index<0:
            return "index cant be negative"
        len = self.lengthList()
        if(index >= len):
            self.setTail(val)
            return
        curr = self.head 
        for i in range(index-1):
            curr = curr.next
        newNode.next = curr.next
        curr.next = newNode
        return
    
    def lengthList(self):
        count = 0
        curr = self.head
        while curr:
            count = count + 1
            curr =curr.next 
        return count 
    
    def deleteHead(self):
        if self.head is None:
            return "Linked List is empty"
        temp = self.head
        self.head = self.head.next
        del temp 
        return self.head 
        
    def deleteTail(self):
        if self.head is  None:
            return "Linked list is empty"
        
        #edge case 2 : if list has just one node 
        if self.head.next is None:
            temp = self.head 
            self.head = None
            del temp
            return self.head
            
        curr = self.head 
        while curr.next.next:
            curr = curr.next
        temp = curr.next
        curr.next = None
        del temp
        return self.head 
        
    def deleteNthNode(self, index):
        if(index < 0 or index >= self.lengthList() or self.head is None):
            return "Invalid delete operation"
          
        if index == 0:
            return self.deleteHead()
            
        curr = self.head 
        for i in range(index-1):
            if curr.next is not None:
                curr = curr.next
        
        temp = curr.next 
        if curr.next is not None:
            curr.next = temp.next 
            del temp
            return self.head
        
            
        
        
        
        
        
        
    
l1 = LinkedList();
l1.setHead(45)
l1.setTail(56)
l1.printList()
l1.setHead(55)
l1.setTail(78)
l1.printList()
l1.setNthNode(23, 1)
l1.setNthNode(29, 3)
l1.printList()