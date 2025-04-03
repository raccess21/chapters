# Stack using list

class StackList:
    def __init__(self) -> None:
        self.stack = []

    def isEmpty(self):
        return len(self.stack) == 0

    def push(self, val):
        self.stack.append(val)

    def pop(self):
        if not self.isEmpty():
            return self.stack.pop()
    
    def peek(self):
        if not self.isEmpty():
            return self.stack[-1]
        
    def size(self):
        return len(self.stack)
    

# Stack using linked list
class Node:
    def __init__(self, val) -> None:
        self.value = val
        self.next = None

class StackLinkedList:
    def __init__(self) -> None:
        self.head = None
        self.size = 0

    def isEmpty(self):
        return self.size == 0
    
    def push(self, val):
        newNode = Node(val)
        if self.head:
            newNode.next = self.head
        self.head = newNode
        self.size += 1
    
    def pop(self):
        if self.isEmpty():
            print("Stack is empty")
            return None
    
        val = self.head.value
        self.head = self.head.next
        self.size -= 1
        return val
    
    def peek(self):
        if self.isEmpty():
            print("Stack is empty")
            return None
        
        return self.head.value
    
    def size(self):
        return self.size


class QueueLinkedList(StackLinkedList):
    def __init__(self) -> None:
        super().__init__()

    def pop(self):
        if self.isEmpty():
            print("Queue is Empty.")
            return None
        
        