/*
   Pow(x, n)
   Implement pow(x, n).
*/

class Solution {
public:
    double pow(double x, int n) {
		double p = x;
		double result = 1;

		if (n < 0) {
			return 1/pow(x, -n);
		}

		for (int bit = 0; bit < sizeof(int)*8; bit++) {
			if ((n >> bit) & 1) {
				result *= p;
			}
			p *= p;
		}
		return result;
    }
};
