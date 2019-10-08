#!/bin/python3

import math
import os
import random
import re
import sys

# Problem statement:
# You are given an array of integers and must compute the maximum difference between any item and any lower indexed
# smaller item for the possible pairs, i.e., for a given array a find the maximum value of a[j] – a[i] for all i, j 
# where 0 <= i < j < n and a[i] < a[j]. If no item has smaller item with lower index then return -1.

# For example given an array [1, 2, 6, 4]. you will first compare 2 to the elements to its left. 1 is smaller , 
# so calculate the difference 2 – 1 = 1, 6 is bigger than 2 and 1. so calculate the differences 4 and 5, 
# for is only bigger than 2 and 1, and the differences are 2 and 3. The largest difference was 6 – 1 = 5.


def maxDifference(arr):
    diff = -1
    for index, val in enumerate(arr[1:]):
        left = arr[:index+1]
        minimum = min(left)
        if minimum < val:
            minimum = val - minimum
            if minimum > diff:
                diff = minimum
    return diff
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = maxDifference(arr)

    fptr.write(str(res) + '\n')

    fptr.close()
