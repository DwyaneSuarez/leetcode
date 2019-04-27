class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        stack<pair<int, int>> s;
        s.push({0, heights[0]});
        int ans = 0;
        for (int i = 1; i < heights.size(); ++i) {
            int t = s.top().second;
            if (t < heights[i]) {
                s.push({i, heights[i]});
            } else if (t > heights[i]) {
                pair<int, int> p;
                while (!s.empty() && s.top().second > heights[i]) {
                    p = s.top();
                    ans = max(ans, (i - p.first) * p.second);
                    s.pop();
                }
                s.push({p.first, heights[i]});
            }
        }
        while (!s.empty()) {
            pair<int, int> p = s.top();
            ans = max(ans, (int(heights.size()) - p.first) * p.second);
            s.pop();
        }
        return ans;
    }
};
