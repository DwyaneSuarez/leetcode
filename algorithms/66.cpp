class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if (len == 0)
            return digits;
        vector<int> ans(digits);
        reverse(ans.begin(), ans.end());
        ans[0]++;
        int carry = 0;
        for (int i = 0; i < len; i++) {
            ans[i] += carry;
            if (ans[i] >= 10) {
                carry = ans[i] / 10;
                ans[i] %= 10;
            } else
                carry = 0;
        }
        if (carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
