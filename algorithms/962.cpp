class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (s.empty() || A[i] < A[s.top()])
                s.push(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && A[i] >= A[s.top()]) {
                ans = max(ans, i - s.top());
                s.pop();
            }
        }
        return ans;
    }
};