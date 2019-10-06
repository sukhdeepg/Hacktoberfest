//This is my favorite code snippet because it use recursion to calculate the power of a particular number.
#include <iostream>
using namespace std;
int calculatePower(int, int);
int main()
{
    int base, powerRaised, result;
    cout << "Enter base number: ";
    cin >> base;
    cout << "Enter power number(positive integer): ";
    cin >> powerRaised;
    result = calculatePower(base, powerRaised);
    cout << base << "^" << powerRaised << " = " << result;
    return 0;
}
int calculatePower(int base, int powerRaised)
{
    if (powerRaised != 0)
        return (base*calculatePower(base, powerRaised-1));
    else
        return 1;
}
