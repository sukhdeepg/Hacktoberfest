/* program to convert a string to lowercase
 * time complexity: O(n), where n is the number of characters in the string
 * space complexity: O(1)
 */

#include <iostream>
using namespace std;

string ToLowerCase(string& str) {
	for (char& c : str) {
		if (c >= 'A' && c <= 'Z') {
			c = 'a' + (c - 'A');
		}
	}
	return str;
}

int main() {
	string str;
	cin >> str;
	cout << ToLowerCase(str) << endl;
	return 0;
}
