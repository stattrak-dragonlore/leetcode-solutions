/*
Add Binary
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/


class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int size = max(a.size(), b.size());
		if (a.size() < size) {
			string prefix(size-a.size(), '0');
			a = prefix + a;
		}
		if (b.size() < size) {
			string prefix(size-b.size(), '0');
			b = prefix + b;
		}
		string result;
		int carry = 0;
		for (int i = 0; i < size; i++) {
			int p = a[size - i - 1] - '0';
			int q = b[size - i - 1] - '0';
			char c = (p + q + carry) % 2 + '0';
			carry = (p + q + carry) / 2;

			result = c + result;
		}
		if (carry) {
			result = '1' + result;
		}
		return result;
    }
};
