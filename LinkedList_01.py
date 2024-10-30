class Node:
    def __init__(self, data, nextP = None):
        self.data = data
        self.nextP = None

class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        curr = self.head
        while curr:
            print(curr.data, end=" ")
            curr = curr.nextP
        print()

    def setHead(self, val):
        newNode = Node(val)
        if self.head is None:
            self.head = newNode
            return
        newNode.nextP = self.head
        self.head = newNode
        return
    def setTail(self, val):
        newNode = Node(val)
        if self.head is None:
            self.head = newNode
            return
        curr = self.head
        while curr.nextP:
            curr = curr.nextP
        curr.nextP = newNode
        return

    def setNthNode(self, index, val):
        newNode = Node(val)
        if index < 0:
            return "negative index not allowed"
        if index == 0:
            self.setHead(val)
            return
        lenlist  = self.lengthList()
        if index >= lenlist:
            self.setTail(val)
            return
        curr = self.head
        for i in range(index-1):
            curr = curr.nextP
        newNode.nextP = curr.nextP
        curr.nextP = newNode
        return

    def lengthList(self):
        count = 0
        curr = self.head
        while curr:
            count +=1
            curr = curr.nextP
        return count

    def deleteHead(self):
        if self.head is None:
            return "Linked List is empty"
        temp = self.head
        self.head = self.head.nextP
        temp = None
        del temp
        return

    def deleteTail(self):
        if self.head is None:
            return "Linked List is empty"
        if self.head.nextP is None:
            self.head  = None
            return
        curr = self.head
        while curr.nextP.nextP:
            curr = curr.nextP
        temp = curr.nextP
        curr.nextP = None
        del temp
        return

    def deleteNthNode(self, index):
        if self.head is None or index < 0:
            return "List is empty Or negative index is not allowed"
        if index == 0:
            self.deleteHead()
            return
        if index >= self.lengthList():
            return "invalid access"
        curr = self.head
        for i in range(index-1):
            if curr.nextP:
                curr = curr.nextP
        temp = curr.nextP
        if curr.nextP:
            curr.nextP = temp.nextP
            temp.nextP = None
            del temp
            return






l1 = LinkedList()
l1.setHead(67)
l1.setTail(88)
l1.setHead(66)
l1.setTail(55)
l1.printList()
l1.setNthNode(1, 22)
l1.setNthNode(2, 11)
l1.printList()
l1.deleteHead()
l1.printList()
l1.deleteTail()
l1.printList()
l1.deleteNthNode(2)
l1.printList()
l1.deleteNthNode(1)
l1.printList()