
# Program to find the mid element of a linked list

class Node:
    
    #initializing the node
    
    def __init__(self, data):
        self.data = data
        self.next = None

def midpoint_linkedlist(head):

    slow=head #1st pointer
    fast=head  #2nd pointer
    while fast.next is not None and fast.next.next is not None:
        slow=slow.next
        fast=fast.next.next
    return slow

def ll(arr): # creating linked list out of the input(elements)
    if len(arr)==0:
        return None
    head = Node(arr[0])
    last = head
    for data in arr[1:]:
        last.next = Node(data)
        last = last.next
    return head

# Main
# expected -1 when no more inputs and all the elements are inputted separated by space
arr=list(int(i) for i in input().strip().split(' '))
# Creating a Linked list after removing -1 from list
l = ll(arr[:-1])
node = midpoint_linkedlist(l)
if node:
    print(node.data)
