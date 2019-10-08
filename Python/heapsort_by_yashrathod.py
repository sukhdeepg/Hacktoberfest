#Hi name==Yash Rathod institute==VIER
#This sorting technique is awesome cuz its supercool and shares good complexity so solve DS

def upheap(list, index):
    while index > 0:
        p = (index-1)//2
        if list[p] < list[index]:
            list[p], list[index] = list[index], list[p]
            index = p
        else:
            break




def buildHeap(list):

    if len(list) <= 1:
        return
    for i in range(1, len(list)):
        upheap(list, i)

    return

def heapSort(list):
    for i in range(len(list)):
        list[0], list[len(list)-1-i] = list[len(list)-1-i], list[0]
        for j in range(len(list)-i-1):
            upheap(list,j)





if __name__ == '__main__':
    list = [1, 8, 2, 23, 7, 1, 18, 23, 42, 37, 2]
    buildHeap(list)
    print list
    heapSort(list)
    print list
