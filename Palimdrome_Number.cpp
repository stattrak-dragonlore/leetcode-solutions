/*
   Palindrome Number
Determine whether an integer is a palindrome. Do this without extra space.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
    	long long pow = 1;
		while (pow <= x) {
			pow *= 10;
		}
		pow /= 10;

		while (x >= 10) {
			if (x / pow != x % 10)
				return false;
			x %= pow;
			x /= 10;
			pow /= 100;
		}
		return true;
    }
};
