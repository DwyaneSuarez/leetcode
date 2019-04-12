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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int len = intervals.size();
        if (len == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        if (newInterval.start > intervals[len - 1].end) {
            for (int i = 0; i < len; i++)
                ans.push_back(intervals[i]);
            ans.push_back(newInterval);
            return ans;
        } else if (newInterval.end < intervals[0].start) {
            ans.push_back(newInterval);
            for (int i = 0; i < len; i++)
                ans.push_back(intervals[i]);
            return ans;
        }
        int l = 0;
        for (int i = l; i < len; i++) {
            if (intervals[i].end >= newInterval.start) {
                l = i;
                break;
            }
        }
        int r = len - 1;
        for (int i = r; i >= 0; i--) {
            if (intervals[i].start <= newInterval.end) {
                r = i;
                break;
            }
        }
        for (int i = 0; i < l; i++)
            ans.push_back(intervals[i]);
        ans.push_back(Interval(min(intervals[l].start, newInterval.start), max(intervals[r].end, newInterval.end)));
        for (int i = r + 1; i < len; i++)
            ans.push_back(intervals[i]);
        return ans;
    }
};
