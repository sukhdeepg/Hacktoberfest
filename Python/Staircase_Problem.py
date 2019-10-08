#A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.


def stair(n):
  if(n<3): 
    return n
  if(n==3):
    return 4
  else:
    return stair(n-1)+stair(n-2)+stair(n-3)
n=int(input())
print(stair(n))