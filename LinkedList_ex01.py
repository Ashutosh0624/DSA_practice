class Node:
    def __init__(self, data, next = None):
        self.data = data 
        self.next = next

# create a class LinkedList
class LinkedList:
    def __init__(self):
        self.head = None
    
    def printList(self):
        curr = self.head
        while curr:
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
        while curr.next:
            curr = curr.next
        curr.next = newNode
        return 
    
    def setNthNode(self, val, index):
        if self.head is None:
            self.setHead(val)
            return
        if index < 0:
            raise ValueError("Index can't be negative")
        if index >= self.lengthList():
            self.setTail(val)
            return
        curr = self.head 
        for i in range(index - 1):
            if curr.next:
                curr = curr.next
        # pointer is pointing at index-1th node 
        newNode = Node(val)
        if curr.next is not None:
            newNode.next = curr.next
            curr.next = newNode
            return
    
    def lengthList(self):
        count = 0
        curr = self.head
        while curr:
            count = count + 1
            curr = curr.next
        return count
    
    def deleteHead(self):
        if self.head is None:
            return "List is empty"
        temp = self.head 
        self.head = self.head.next
        temp.next = None
        return
    
    def deleteTail(self):
        if self.head is None:
            return "List is empty"
        if self.head.next is None:
            self.head = None
            return
        curr = self.head 
        while curr.next.next:  # to reach to the second last node 
            curr = curr.next
        temp = curr.next
        curr.next = None
        return 
        
    def deleteNthNode(self, index):
        if index < 0 or index >= self.lengthList() or self.head is None:
            return "invalid operation"
        if index==0:
            self.deleteHead()
            return
        curr = self.head 
        for i in range(index - 1):
            if curr.next:
                curr = curr.next
        # pointer is pointing to index - 1 node 
        temp = curr.next  # storing the indexth node in a temp variable 
        if temp.next:
            curr.next = temp.next
            temp.next = None 
            return 
        
l1 = LinkedList()
l1.setHead(22)
l1.setTail(33)
l1.printList()
l1.setHead(12)
l1.setTail(23)
l1.printList()
l1.setNthNode(99, 1)
l1.setNthNode(100, 2)
l1.setNthNode(101, 1)
l1.printList()
l1.setNthNode(104, l1.lengthList())
l1.printList()

l1.deleteHead()
l1.printList()

l1.deleteNthNode(3)
l1.printList()

l1.deleteNthNode(1)
l1.printList()


l1.deleteNthNode(2)
l1.printList()

l1.deleteHead()
l1.printList()

l1.deleteTail()
l1.printList()