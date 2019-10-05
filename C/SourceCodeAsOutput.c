// This is my favorite code snippet because it helps us to see the source code of a particular file.
#include <stdio.h>
int main() {
    FILE *fp;
    int c;
    fp = fopen(__FILE__,"r");
    do {
         c = getc(fp);
         putchar(c);
    }
    while(c != EOF);
    fclose(fp);
    return 0;
}
