class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len == 0)
            return 0;
        int *dp = new int[len];
        stack<int> st;
        if (s[0] == '(')
            st.push(0);
        dp[0] = 0;
        int ans = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == '(') {
                dp[i] = 0;
                st.push(i);
            } else {
                if (st.empty()) {
                    dp[i] = 0;
                } else {
                    int tp = st.top();
                    st.pop();
                    dp[i] = dp[max(tp - 1, 0)] + (i - tp + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
