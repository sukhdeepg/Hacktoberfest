from LinkedListQueue import queue


class bst:
    class _Node(object):
        __slots__ = '_data', '_left', '_right'


        def __init__(self, value, left = None, right = None):
            self._data = value
            self._left = left
            self._right = right


    def __init__(self):
        self._root = None
        self._size = 0


    def insert(self, value):
        troot = self._root
        ttroot = None
        while troot:
            ttroot = troot
            if value < troot._data:
                troot = troot._left
            elif value > troot._data:
                troot = troot._right
        node = self._Node(value)
        if self._root:
            if value < ttroot._data:
                ttroot._left = node
            elif value > ttroot._data:
                ttroot._right = node
        else:
            self._root = node


    def recursive_insert(self, value, root):
        if root == None:
            node = self._Node(value)
            return node
        if root._data > value:
            root._left = self.recursive_insert(value, root._left)
        elif root._data < value:
            root._right = self.recursive_insert(value, root._right)
        return root


    def search(self, value):
        temp = self._root
        while temp:
            if value > temp._data:
                temp = temp._right
            elif value < temp._data:
                temp = temp._left
            else:
                return True
        return False


    def levelorder(self):
        temp = self._root
        q = queue()
        print(temp._data, end=' ')
        q.push(temp)
        while not q.is_empty():
            temp = q.pop()
            if temp._left:
                print(temp._left._data, end=' ')
                q.push(temp._left)
            if temp._right:
                print(temp._right._data, end=' ')
                q.push(temp._right)


    def inorder(self, root):
        if root:
            self.inorder(root._left)
            print(root._data, end=' ')
            self.inorder(root._right)


    def preorder(self, root):
        if root:
            print(root._data, end=' ')
            self.preorder(root._left)
            self.preorder(root._right)


    def postorder(self, root):
        if root:
            self.postorder(root._left)
            self.postorder(root._right)
            print(root._data, end=' ')


tree1 = bst()
tree1._root = tree1.recursive_insert(50, None)
tree1.recursive_insert(30, tree1._root)
tree1.recursive_insert(10, tree1._root)
tree1.recursive_insert(20, tree1._root)
tree1.recursive_insert(70, tree1._root)
tree1.recursive_insert(31, tree1._root)
tree1.recursive_insert(39, tree1._root)

print("-------------Tree1------------")
print("Inorder", end='=')
tree1.inorder(tree1._root)
print()
print("Preorder", end='=')
tree1.preorder(tree1._root)
print()
print("Postorder", end='=')
tree1.postorder(tree1._root)
print()
print("Levelorder", end='=')
tree1.levelorder()
print("\n")


tree2 = bst()
tree2.insert(50)
tree2.insert(30)
tree2.insert(10)
tree2.insert(20)
tree2.insert(70)
tree2.insert(31)
tree2.insert(39)


print("-------------Tree2------------")
print("Inorder", end='=')
tree1.inorder(tree1._root)
print()
print("Preorder", end='=')
tree1.preorder(tree1._root)
print()
print("Postorder", end='=')
tree1.postorder(tree1._root)
print()
print("Levelorder", end='=')
tree1.levelorder()