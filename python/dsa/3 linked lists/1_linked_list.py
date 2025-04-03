# Singly Linked List -> Node saves location of next node

class SinglyLinkedList:
    def __init__(self, data):
        self.data = data
        self.next = None
    
    def traverseAndPrint(head):
        currentNode = head
        while currentNode:
            print(currentNode.data, end=" -> ")
            currentNode = currentNode.next
        print("null")

Snode1 = SinglyLinkedList(3)
Snode2 = SinglyLinkedList(5)
Snode3 = SinglyLinkedList(13)
Snode4 = SinglyLinkedList(2)

Snode1.next = Snode2
Snode2.next = Snode3
Snode3.next = Snode4

currentNode = Snode1
while currentNode:
    print(currentNode.data, end=" -> ")
    currentNode = currentNode.next
print("null")


# Singly Linked List -> Node saves location of previous node and next node

class DoublyLinkedList:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
    
Dnode1 = DoublyLinkedList(3)
Dnode2 = DoublyLinkedList(5)
Dnode3 = DoublyLinkedList(13)
Dnode4 = DoublyLinkedList(2)

Dnode1.next = Dnode2

Dnode2.prev = Dnode1
Dnode2.next = Dnode3

Dnode3.prev = Dnode2
Dnode3.next = Dnode4

Dnode4.prev = Dnode3

currentNode = Dnode1
while currentNode:
    print(currentNode.data, end=" -> ")
    currentNode = currentNode.next
print("null")

print("\nTraversing backward:")
currentNode = Dnode4
while currentNode:
    print(currentNode.data, end=" -> ")
    currentNode = currentNode.prev
print("null")


# Circular Singly Linked List -> Each node points to the next node. Tail points to the head of the list
class CircularNode:
    def __init__(self, data):
        self.data = data
        self.next = None
    
Cnode1 = CircularNode(3)
Cnode2 = CircularNode(5)
Cnode3 = CircularNode(13)
Cnode4 = CircularNode(2)

Cnode1.next = Cnode2
Cnode2.next = Cnode3
Cnode3.next = Cnode4
Cnode4.next = Cnode1

currentNode = Cnode1
startNode = Cnode1
print(currentNode.data, end=" -> ") 
currentNode = currentNode.next 

while currentNode != startNode:
    print(currentNode.data, end=" -> ")
    currentNode = currentNode.next

print("...")


# Circular Linked List -> Each node points to the next node and previous node.Tail points to the head of the list. Hwad points to the tail.
class CircularDoublyNode:
    def __init__(self, data):
        self.data = data
        self.next = None
    
Cdnode1 = CircularDoublyNode(3)
Cdnode2 = CircularDoublyNode(5)
Cdnode3 = CircularDoublyNode(13)
Cdnode4 = CircularDoublyNode(2)

Cdnode1.prev = Cdnode4
Cdnode1.next = Cdnode2

Cdnode2.prev = Cdnode1
Cdnode2.next = Cdnode3

Cdnode3.prev = Cdnode2
Cdnode3.next = Cdnode4

Cdnode4.prev = Cdnode3
Cdnode4.next = Cdnode1

print("\nTraversing forward:")
currentNode = Cdnode1
startNode = Cdnode1
print(currentNode.data, end=" -> ")
currentNode = currentNode.next

while currentNode != startNode:
    print(currentNode.data, end=" -> ")
    currentNode = currentNode.next
print("...")

print("\nTraversing backward:")
currentNode = Cdnode4
startNode = Cdnode4
print(currentNode.data, end=" -> ")
currentNode = currentNode.prev

while currentNode != startNode:
    print(currentNode.data, end=" -> ")
    currentNode = currentNode.prev
print("...")



# ---------------0----------------Operations on Linked List---------------------------
def traverseAndPrint(head):
    currentNode = head
    while currentNode:
        print(currentNode.data, end=" -> ")
        currentNode = currentNode.next
    print("null")

def DeleteNode(head, nodeToDelete):

    if head == nodeToDelete:
        return head.next

    currentNode = head
    while currentNode.next and currentNode.next != nodeToDelete:
        currentNode = currentNode.next

    if currentNode.next is None:
        return head

    currentNode.next = currentNode.next.next

    return head

def insertNodeAtPosition(head, newNode, position):
    if position == 1:
        newNode.next = head
        return newNode
    
    currentNode = head
    for _ in range(position - 2):
        if currentNode is None:
            break
        currentNode = currentNode.next

    newNode.next = currentNode.next
    currentNode.next = newNode
    return head

def findLowestValue(head):
    minValue = head.data
    currentNode = head.next
    while currentNode:
        if currentNode.data < minValue:
            minValue = currentNode.data
        currentNode = currentNode.next
    return minValue

