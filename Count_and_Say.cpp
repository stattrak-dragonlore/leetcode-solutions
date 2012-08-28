/*
Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


string next(string &s)
{
	int i = 0;
	int n = s.size();
	string r;
	while (i < n) {
		int j = i + 1;
		while (j < n && s[j] == s[i])
			j++;

		r += ('0' + j - i);
		r += s[i];

		i = j;
	}
	return r;
}

class Solution {
public:
    string countAndSay(int n) {
		string s = "1";
		while (--n) {
			s = next(s);
		}
		return s;
    }
};


int main(int argc, char *argv[])
{
	Solution s;
	cout << s.countAndSay(4);
	return 0;
}
