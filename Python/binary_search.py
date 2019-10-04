import random
arr = []
n = int(input("enter no of terms: "))
for i in range(n):
    arr.append(int(input("enter no: ")))
arr.sort()
x = int(input("enter no to be searched: "))


def binarysearch(a, l, m, s):
    mid = (l + m)//2
    if l <= m:
        if a[mid] == s:
            return mid
        else:
            if a[mid] < s:
                l = mid+1
            else:
                m = mid-1
            return binarysearch(a, l, m, s)
    else:
        return -1


print(binarysearch(arr, 0, len(arr) - 1, x))
 
