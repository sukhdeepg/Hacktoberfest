# Python program for brute force method to calculate stock span values 

# Fills list S[] with span values 
def calculateSpan(price, n, S): 

    # Span value of first day is always 1 
    S[0] = 1

    # Calculate span value of remaining days by linearly  
    # checking previous days 
    for i in range(1, n, 1): 
        S[i] = 1   # Initialize span value 

        # Traverse left while the next element on left is 
        # smaller than price[i] 
        j = i - 1
        while (j>= 0) and (price[i] >= price[j]) : 
            S[i] += 1
            j -= 1

# A utility function to print elements of array 
def printArray(arr, n): 

    for i in range(n): 
        print(arr[i], end = " ") 
    
price = [10, 4, 5, 90, 120, 80] 
n = len(price) 
S = [None] * n 

# Fill the span values in list S[] 
calculateSpan(price, n, S) 

# print the calculated span values 
printArray(S, n) 