class Node:
    def __init__(self, data, link = None):
        self.data = data
        self.link = link

class LinkedList:
    def __init__(self):
        self.head = None

    def sethead(self, val):
        newnode = Node(val)

        if self.head is None:
            self.head = newnode
            return
        newnode.link = self.head
        self.head = newnode
        return

    def printlist(self):
        curr = self.head
        while curr:
            print(curr.data, end=" ")
            curr = curr.link
        print()

    def settail(self, val):
        newnode = Node(val)
        if self.head is None:
            self.sethead(val)
            return
        curr = self.head
        while curr.link:
            curr = curr.link
        curr.link = newnode
        return


l1 = LinkedList()
l1.sethead(56)
l1.settail(67)
l1.settail(89)
l1.sethead(77)
l1.printlist()
