/*
   Maximal Rectangle
Given a 2D binary matrix filled with 0's and 1's, find
the largest rectangle containing all ones and return its area.

 */
#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:

    /* O(N^3) algorithm */
    int maximalRectangle2(vector<vector<char> > &matrix) {
        int nr = matrix.size();
        if (nr == 0)
            return 0;

        int nc = matrix[0].size();
        if (nc == 0)
            return 0;

        //preprocessing
        vector<vector<int> > count(nr);
        for (int i = 0; i < nr; i++) {
            vector<int> v(nc);
            for (int j = nc - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    v[j] = 1;
                    if (j + 1 < nc) {
                        v[j] += v[j+1];
                    }

                } else {
                    v[j] = 0;
                }
            }
            count[i] = v;
        }

        int result = 0;
        for (int j = 0; j < nc; j++) {
			for (int rs = 0; rs < nr; rs++) {
				if (matrix[rs][j] == '0')
					continue;

				int width = count[rs][j];
				int height = 1;
				result = max(result, width * height);
				for (int re = rs + 1; re < nr; re++) {
					if (matrix[re][j] == '0') {
						break;
					} else {
						width = min(count[re][j], width);
						height++;
						result = max(result, width * height);
					}
				}
            }
        }
        return result;
    }


	/* O(N^2) algorithm */
    int maximalRectangle(vector<vector<char> > &matrix) {
        int nr = matrix.size();
        if (nr == 0)
            return 0;

        int nc = matrix[0].size();
        if (nc == 0)
            return 0;

        //preprocessing
        vector<vector<int> > count(nr);
        for (int i = 0; i < nr; i++) {
            vector<int> v(nc);
            for (int j = nc - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    v[j] = 1;
                    if (j + 1 < nc) {
                        v[j] += v[j+1];
                    }

                } else {
                    v[j] = 0;
                }
            }
            count[i] = v;
        }

        int result = 0;
        for (int j = 0; j < nc; j++) {

			stack<int> left;
			stack<int> right;
			vector<int> height(nr, 0);

			// >= count[i][j] on the left side
			for (int i = 0; i < nr; i++) {
                while (!left.empty() && count[i][j] <= count[left.top()][j]) {
                    left.pop();
                }
                if (left.empty()) // all the left elements are larger than count[i][j]
                    height[i] = i;
                else
                    height[i] = i - left.top() - 1;
                left.push(i);
			}

			// >= count[i][j] on the right side
			for (int i = nr - 1; i >= 0; i--) {
                while (!right.empty() && count[i][j] <= count[right.top()][j]) {
                    right.pop();
                }
                if (right.empty())
                    height[i] += nr - i - 1;
                else
                    height[i] += (right.top() - i - 1);
                right.push(i);
			}

			for (int i = 0; i < nr; i++) {
				result = max(result, (height[i] + 1) * count[i][j]);
			}
        }
        return result;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
	vector<vector<char> > m(4);
	string s0 = "1";
	string s1 = "1";
	string s2 = "0";
	string s3 = "1";
	vector<char> v(s0.begin(), s0.end());
	vector<char> v2(s1.begin(), s1.end());
	vector<char> v3(s2.begin(), s2.end());
	vector<char> v4(s3.begin(), s3.end());
	m[0] = v;
	m[1] = v2;
	m[2] = v3;
	m[3] = v4;
	cout << s.maximalRectangle(m) << endl;;
    return 0;
}
