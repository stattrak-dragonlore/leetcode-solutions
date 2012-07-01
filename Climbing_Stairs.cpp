/*
Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/*  //recursive version

int cache[1000000];

int go(int n)
{
    if (cache[n] != -1)
        return cache[n];
    if (n == 0 || n == 1)
        return 1;
    cache[n] = go(n-1) + go(n-2);
    return cache[n];
}

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(cache, -1, sizeof(cache));
        return go(n);
    }
};
*/


class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (n == 0 || n == 1)
			return 1;
		int a = 1;
		int b = 1;
		int c;
		for (int i = 2; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		return c;
    }
};
