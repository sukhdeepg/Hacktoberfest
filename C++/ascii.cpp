//This is so useful yet such basic code I use this a lot instead of googling for ascii values.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;

    while(i<255)
    {
        printf("\n \a %d = %c ",i,i);
        i=i+1;
    }
    getchar();
    return 0;
}
