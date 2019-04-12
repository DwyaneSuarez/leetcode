/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval& i1, const Interval& i2) {
        return i1.start != i2.start ? i1.start < i2.start : i1.end < i2.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        int len = intervals.size();
        if (len == 0)
            return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int pre = INT_MIN;
        for (int i = 0; i < len; i++) {
            if (intervals[i].start <= pre)
                ans[ans.size() - 1].end = max(intervals[i].end, pre);
            else
                ans.push_back(intervals[i]);
            pre = max(intervals[i].end, pre);
        }
        return ans;
    }
};
