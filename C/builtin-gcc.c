#include <stdio.h> 
int main() 
{ 
    int n = 5; 
      
    printf("Count of 1s in binary of %d is %d ", n, __builtin_popcount(n)); 
    printf("Parity of %d is %d ", n, __builtin_parity(n));
    printf("Count of leading zeros  before 1 in %d is %d", n, __builtin_clz(n)); 
    printf("Count of trailing zeros after 1 in %d is  %d",n, __builtin_ctz(n)); 
    
    return 0; 
}
