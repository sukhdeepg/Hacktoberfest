import numpy
from LinkedListQueue import queue
class Graph:
    def __init__(self, vertices):
        self._vertices = vertices
        self._adjmatrix = numpy.zeros((vertices, vertices))
        self._size = 0
    def addEdge(self, u, v, w = 1):
        self._adjmatrix[u][v] = w
    def deleteEdge(self, u, v):
        self._adjmatrix[u][v] = 0
    def bfs(self, source):
        i = source
        q = queue()
        q.push(source)
        l = [0]*self._vertices
        l[i] = 1
        print(i, end= '->')
        while not q.is_empty():
            i = q.pop()
            for j in range(self._vertices):
                if self._adjmatrix[i][j] == 1 and l[j] == 0:
                    print(j, end='->')
                    q.push(j)
                    l[j] = 1
g = Graph(7)
g.addEdge(0, 1)
g.addEdge(0, 5)
g.addEdge(0, 4)
g.addEdge(0, 2)
g.addEdge(2, 5)
g.addEdge(2, 3)
g.addEdge(6, 3)
g.addEdge(1, 3)
g.addEdge(6, 4)
g.addEdge(1, 6)
print(g._adjmatrix)
g.bfs(0)