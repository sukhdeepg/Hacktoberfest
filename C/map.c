//This function maps a value from one range to another.

#include <stdio.h>

int map(int input, int inMin, int inMax, int outMin, int outMax) {
    return (input - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

void main() {
    printf("%i\n",map(100, 50, 255, 0, 9));
}
