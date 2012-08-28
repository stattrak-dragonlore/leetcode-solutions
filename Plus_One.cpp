/*
   Plus One
   Given a number represented as an array of digits, plus one to the number.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        int one = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += one;
                one = 0;
                break;
            }
        }
        if (one) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
