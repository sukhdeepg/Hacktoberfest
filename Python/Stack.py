## class representing a NODE
class Node(object):
    def __init__(self, value):
        self.value = value
        self.next = None

## Class representing Linked list
class LinkedList:
    def __init__(self, head=None):
        self.head = head
        pass
    
    def append(self, node):
        """
        append a node to list
        """
        current = self.head
        if self.head:
            while current.next:
                current = current.next
            current.next = node
        else:
            self.head = node
    
    def get_position(self, position):
        """
        get element at specific index
        """
        counter = 0
        current = self.head
        if not self.head or position < 0 or position > self.size():
            return None
        
        while current:
            if counter == position:
                return current
            current = current.next
            counter +=1
        return None
    
    def size(self):
        """
        get the size of linked list
        """
        i = 0
        if not self.head:
            return 0
        
        current = self.head
        while current:
            i += 1
            current = current.next
        
        return i
    
    def delete(self, value):
        """
        delete the first occuring value
        """
        if not self.head:
            return None
        current = self.head
        previous = None
        
        while current.value != value and current.next:
            previous = current
            current = current.next
            
        if current.value == value:
            if previous:
                previous.next = current.next
            else:
                self.head = current.next
        
    def insert(self, node, position):
        """
        inserting element at particular location
        """
        counter = 0
        current = self.head
        if position > 0:
            while current and counter < position:
                if counter == position - 1:
                    node.next = current.next
                    current.next = node
                current = current.next
                counter += 1
        elif position == 0:
            node.next = self.head
            self.head = node
    
    def __str__(self):
        if self.head:
            data = []
            current = self.head
            while current:
                data.append(str(current.value))
                current = current.next
            return " -> ".join(data)
        else:
            return "No element"
    pass


class Stack:
    def __init__(self):
        self.stack = LinkedList()
    
    def echo(self):
        print(self.stack)
        pass
    
    def size(self):
        """
        get the size of stack
        """
        return self.stack.size()
    
    def empty(self):
        """
        check if stack is empty
        """
        return self.size() == 0
    
    def peek(self):
        """
        get the top most element
        """
        return self.stack.get_position(0).value
    
    def pop(self):
        """
        remove element from top
        """
        v = self.peek()
        self.stack.delete(v)
        return v
                
    def push(self, node):
        """
        add element to top
        """
        self.stack.insert(node, 0)
        pass
    
    
myStack = Stack()

# creating values
n1 = Node(10)
n2 = Node(20)
n3 = Node(30)

# Operating
print("[1] Stack is empty" if myStack.empty() else "[1] Stack is not empty")

print("[2] Pushing {} to stack".format(n1.value))
myStack.push(n1)
print("[3] Pushing {} to stack".format(n2.value))
myStack.push(n2)

print("[4] Stack is empty" if myStack.empty() else "[4] Stack is not empty")

print("[5] Current Size of Stack is", myStack.size())

print("[6] Peeking value", myStack.peek())

print("[7] Poping value {}".format(myStack.pop()))

print("[8] Current Size of Stack is", myStack.size())

print("[9] Pushing {} to stack".format(n2.value))
myStack.push(n3)

print("[!] The Stack is")
myStack.echo()
