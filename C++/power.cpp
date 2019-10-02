/* calculate power of given number in O(log n) time */

#include<iostream>
using namespace std;

int power(int base, int expo){
if (base == 0){
  return 0;
}

if (expo == 0){ 
  return 1;}

if (expo % 2 == 0){
  return power(base, expo/2)*power(base, expo/2);
}
else{
  return base*power(base, expo/2)*power(base, expo/2);
}

}


int main() {
int base, expo;
cin >> base >> expo;
cout << power(base, expo) << "\n";
return 0;
}
