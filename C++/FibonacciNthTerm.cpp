#include<iostream>
using namespace std;

int main() {
    int s;
    cout <<"Enter total number of terms: ";
    cin >> s;
    cin.sync();
    int f[s];
    f[0] = 0, f[1] = 1;
    for(int i=2; i<s; i++) f[i] = f[i-1] + f[i-2];
    cout <<"Last term : "<< f[s-1];
    return 0;
}