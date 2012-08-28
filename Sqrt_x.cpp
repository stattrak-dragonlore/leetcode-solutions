/*
  Implement int sqrt(int x).

Compute and return the square root of x.

 sqrt(1) = 1
 sqrt(3) = 1
 sqrt(5) = 2
*/
//http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binarySearch
//true, true, true, false, false
//binary search the last true index

class Solution {
public:
    int sqrt(int x) {
		// x >= 0
		long long lo = 0, hi = x;
		while (lo < hi) {
			long long mid = (lo + hi + 1) / 2;
			long long s = mid * mid;
			if (s <= x) { // good
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}
		return lo;
    }
};
