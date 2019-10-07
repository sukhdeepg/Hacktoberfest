def reverse(s): 
    return s[::-1] 
  
def Palindrome(s): 
    rev = reverse(s) 
    if (s == rev): 
        return True
    return False
ans = Palindrome(s) 
  
if ans == 1: 
    print("Yes") 
else: 
    print("No") 
