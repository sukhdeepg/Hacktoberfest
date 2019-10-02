/* program to reverse an integer
 * time complexity: O(log(x)) because there are log10(x) digits in x
 * space complexity: O(1)
 */

#include <iostream>
using namespace std;

int GetReverse(int x) {
	int rev = 0;
	while (x != 0) {
		// make sure the reverse fits into an integer type
		if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
			return 0;
		}
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	return rev;
}

int main() {
	int number;
	cin >> number;
	cout << GetReverse(number) << endl;
	return 0;
}
