/*
Restore IP Addresses
Given a string containing only digits, restore it by
returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

void search(string s, vector<string> picked, vector<string> &result)
{
    if (s.size() == 0) {
        if (picked.size() == 4) {
            string ip = picked[0];
            for (int i = 1; i < 4; i++) {
                ip += "." + picked[i];
            }

            result.push_back(ip);
        }
        return;
    }

    if (picked.size() == 4)
        return;

    for (int i = 1; i <= s.size() && i <= 3; i++) {
        string sec = s.substr(0, i);
        if (sec[0] == '0') { //begins with 0
            if (i > 1)
                break;
        }
        int num;
        stringstream(sec) >> num;
        if (num > 255)
            break;
        picked.push_back(sec);
        search(s.substr(i), picked, result);
        picked.pop_back();
    }
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> picked;
        search(s, picked, result);
        return result;
    }
};
