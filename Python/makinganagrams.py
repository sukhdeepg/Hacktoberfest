#!/bin/python3
#makeAnagrams  return an integer representing the
#minimum total characters that must be deleted to make the strings anagrams.
#makeAnagram has the following parameter(s): a: a string, b: a string
import math
import os
import random
import re
import sys
def makeAnagram(a, b):
    a1 = [0] * 26
    b1 = [0] * 26
    sum = 0
    start = ord('a')
    for i in a:
        a1[ord(i)-start] += 1
    for i in b:
        b1[ord(i)-start] +=1
    for i in range(0, len(a1)):
        sum+= abs(a1[i]-b1[i])
    return sum
a = input()
b = input()
res = makeAnagram(a, b)
print(str(res) + '\n')
