class Node:
    def __init__(self, data, link = None):
        self.data = data
        self.link = link

class LinkedList:
    def __init__(self):
        self.head = None

    def setHead(self, val):
        newNode = Node(val)

        if self.head is None:
            self.head = newNode
            return
        newNode.link = self.head
        self.head = newNode
        return

    def printList(self):
        curr = self.head
        while curr:
            print(curr.data, end=" ")
            curr = curr.link
        print()

    def setTail(self, val):
        newNode = Node(val)
        if self.head is None:
            self.setHead(val)
            return
        curr = self.head
        while curr.link:
            curr = curr.link
        curr.link = newNode
        return


l1 = LinkedList()
l1.setHead(56)
l1.setTail(67)
l1.setTail(89)
l1.setHead(77)
l1.printList()
