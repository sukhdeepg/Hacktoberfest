#Program to swap two nodes of linked list present at i and j


class Node:
    def __init__(self, data):
        #initializing the node
        self.data = data
        self.next = None
 
def swap_nodes(head, i, j): #i,j are nodes to be swapped
    
    x=i # node at i
    y=j # node at j
    i=min(x,y)
    j=max(x,y)
    if head is None or head.next is None:
        return head
    count1=0
    p1=None
    c1=head
    while count1!=i:
        p1=c1
        c1=c1.next
        count1+=1
    count2=0
    p2=None
    c2=head
    while count2!=j:
        p2=c2
        c2=c2.next
        count2+=1
    if c1==None or c2==None:
        return
    if i==j:
        return 
    temp=c2.next
    if p1 is not None and p2 is not None:
        p1.next=c2
        p2.next=c1
        c2.next=c1.next
        c1.next=temp
    if p1==None:
        p2.next=c1
        c2.next=c1.next
        c1.next=temp
        head=c2  
    if c2.next==None:
        p2.next=c1
        p1.next=c2
        c1.next=None
        c2.next=temp
    return head
 
def ll(arr):
    # creating the linked list
    
    if len(arr)==0:
        return None
    head = Node(arr[0])
    last = head
    for data in arr[1:]:
        last.next = Node(data)
        last = last.next
    return head
 
def printll(head):
    # printing the linked list
    while head:
        print(head.data, end=' ')
        head = head.next
    print()
 
# Main
 
# Reading the link list elements including -1 (-1 to terminate)
arr=list(int(i) for i in input().strip().split(' '))
# Creating a Linked list after removing -1 from list
l = ll(arr[:-1])
i, j=list(int(i) for i in input().strip().split(' '))
l = swap_nodes(l, i, j)
printll(l)