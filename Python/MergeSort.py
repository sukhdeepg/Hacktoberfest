def mergesort(a):
    if len(a) < 2:
        return
    mid = len(a)//2
    L = a[:mid]
    R = a[mid:]
    mergesort(L)
    mergesort(R)
    i = j = k = 0
    while i < len(L) and j < len(R):
        if L[i] < R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
        k += 1
    while i < len(L):
        a[k] = L[i]
        k += 1
        i += 1
    while j < len(R):
        a[k] = R[j]
        k += 1
        j += 1

arr = [-1, 9, 2, -5, 4, 8, 10, 7, 6, 3]
print("Before Sorting =", arr)
print("-----------------Sorting--------------------------")
mergesort(arr)
print("After Sorting =", arr)