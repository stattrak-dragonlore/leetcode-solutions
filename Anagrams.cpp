/*
Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
input	output	expected
[""]	[]	[]

["a"]	[]	[]

["","b"]	[]	[]

["c","c"]	["c","c"]	["c","c"]

["ant","ant"]	["ant","ant"]	["ant","ant"]

["and","dan"]	["and","dan"]	["and","dan"]

["ape","and","cat"]	[]	[]

["ape","pea","tax"]	["ape","pea"]	["ape","pea"]

["ate","eat","tea"]	["ate","eat","tea"]	["ate","eat","tea"]

["tea","and","ate","eat","den"]	["tea","ate","eat"]	["tea","ate","eat"]

["tea","and","ate","eat","dan"]	["tea","and","ate","eat","dan"]	["tea","and","ate","eat","dan"]

["tea","and","ace","ad","eat","dans"]	["tea","eat"]	["tea","eat"]

*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		map<string, int> m;
        vector<string> result;
		int n = strs.size();
		for (int i = 0; i < n; i++) {
			string s2 = strs[i];
			sort(s2.begin(), s2.end());
			m[s2]++;
		}
		for (int i = 0; i < n; i++) {
			string s2 = strs[i];
			sort(s2.begin(), s2.end());
			if (m[s2] > 1)
				result.push_back(strs[i]);
		}
        return result;
    }
};
