class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> mono;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int last = i;
            while (!mono.empty() && mono.top().first >= heights[i]) {
                ans = max(ans, mono.top().first * (i - mono.top().second));
                last = mono.top().second;
                mono.pop();
            }
            mono.push({heights[i], last});
        }
        while (!mono.empty()) {
            ans = max(ans, mono.top().first * (n - mono.top().second));
            mono.pop();
        }
        return ans;
    }
};