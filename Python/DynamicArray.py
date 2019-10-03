class DynamicArray:

    def __init__(self, capacity):
        self.len = 0
        self.capacity = capacity
        self.items = [None for i in range(self.capacity)]
    
    def size(self):
        return self.len
    
    def get(self, index):
        return self.items[index]
    
    def set(self, index, item):
        self.items[index] = item 

    def clear(self):
        self.items = [None for i in range(self.len)]
    
    def add(self, item):
        if self.len + 1 >= self.capacity:
            if self.capacity == 0:
                self.capacity = 1
            else:
                self.capacity *= 2

            new_arr = [None for i in range(self.capacity)]
            for i in range(self.len):
                new_arr[i] = self.items[i]
        
            self.items = new_arr
        
        self.items[self.len] = item
        self.len += 1

    def remove_at(self, index):
        if index >= self.len or index < 0:
            raise IndexError
        data = self.items[index]
        new_arr = [None for i in range(self.len - 1)]
        i, j = 0, 0

        while i < self.len:
            if i == index:
                j -= 1
            else:
                new_arr[j] = self.items[i]
            i += 1
            j += 1

        self.items = new_arr
        self.len -= 1
        self.capacity = self.len

        return data

    def index_of(self, item):
        for i in range(self.len):
            if item is None and self.items[i] is None:
                return i
            elif self.items[i] == item:
                return i
        return -1

    def remove(self, item):
        index = self.index_of(item)
        if index == -1:
            return False
        self.remove_at(index)
        return True

    def contains(self, item):
        return self.index_of(item) != -1

    def __repr__(self): 
        return self.__str__()

    def __str__(self):
        arr_str = '['
        for i in range(0, self.len - 1):
            arr_str += str(self.items[i]) + ','
        return arr_str + str(self.items[self.len - 1]) + ']' if arr_str != '' else arr_str
