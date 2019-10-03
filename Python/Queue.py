class Queue():
    def __init__(self):
        self.data = []
        self.length = 0

    def size(self):
        return self.length
    
    def is_empty(self):
        return self.length == 0
    
    def dequeue(self):
        if self.is_empty():
            raise RuntimeError("Queue is empty")
        self.length -= 1
        return self.data.pop()
    
    def enqueue(self, item):
        self.data = [item] + self.data
        self.length += 1

    def peek(self):
        if self.is_empty():
            raise RuntimeError("Queue is empty")
        return self.data[self.length - 1]
    
    def last(self):
        if self.is_empty():
            raise RuntimeError("Queue is empty")
        return self.data[0]

    def __repr__(self):
        return self.__str__()
    
    def __str__(self):
        stack_str = '['
        for i in range(self.length - 1):
            stack_str += str(self.data[i]) + ', '
        return stack_str + str(self.data[self.length - 1]) + ']'
