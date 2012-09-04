/*
Largest Rectangle in Histogram
Given n non-negative integers representing the histogram's bar
height where the width of each bar is 1, find the area of largest
rectangle in the histogram.

*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack <int> left;
        stack <int> right;
        int n = height.size();
        vector<int> width(n, 0);
        for (int i = 0; i < height.size(); i++) {
            while (!left.empty() && height[i] <= height[left.top()])
                left.pop();
            if (left.empty())
                width[i] = i;
            else
                width[i] = i - left.top() - 1;
            left.push(i);
        }

        for (int i = height.size() - 1; i >= 0; i--) {
            while (!right.empty() && height[i] <= height[right.top()])
                right.pop();
            if (right.empty())
                width[i] += height.size() - i - 1;
            else
                width[i] += right.top() - i - 1;
            right.push(i);
        }

        int result = 0;
        for (int i = 0; i < height.size(); i++) {
            result = max(result, (width[i] + 1) * height[i]);
        }
        return result;
    }
};
