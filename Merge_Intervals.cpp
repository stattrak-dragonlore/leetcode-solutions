/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 bool mycmp(Interval a, Interval b)
 {
     return a.start < b.start;
 }

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), mycmp);
        vector<Interval> result;
        int i = 0;
        while (i < intervals.size()) {
            Interval c = intervals[i];
            int next = i + 1;
            while (next < intervals.size()) {
                if (intervals[next].start <= c.end) { //overlap
                    c.end = max(c.end, intervals[next].end);
                    next++;
                } else {
                    break;
                }
            }
            result.push_back(c);
            i = next;
        }
        return result;
    }
};
