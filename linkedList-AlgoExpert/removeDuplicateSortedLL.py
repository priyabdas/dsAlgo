
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None

def removeDuplicatesFromLinkedList(linkedList):
    currentNode = linkedList
    while currentNode is not None:
        nextDistinctNode = currentNode.next
        print ("nextdis ", nextDistinctNode.value)
        while nextDistinctNode is not None and nextDistinctNode.value == currentNode.value:
            nextDistinctNode = nextDistinctNode.next
        currentNode.next = nextDistinctNode
        currentNode = nextDistinctNode 
        return linkedList

def printList(root):
    while root is not None:
        print(root.value)
        root = root.next


if __name__ == '__main__':
    root = LinkedList(1)
    root.next = LinkedList(1)
    root.next.next = LinkedList(2)
    root.next.next.next = LinkedList(3)
    root.next.next.next.next = LinkedList(3)
    root.next.next.next.next.next = LinkedList(4)
    root = removeDuplicatesFromLinkedList(root)
    printList(root)