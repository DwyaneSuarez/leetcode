class Solution {
public:
    static bool cmp(int num1, int num2) {
        string str1 = to_string(num1);
        string str2 = to_string(num2);
        return str1 + str2 < str2 + str1;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return "";
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for (int i = n - 1; i >= 0; --i) {
            ans += nums[i] || !ans.empty() ? to_string(nums[i]) : "";
        }
        return ans.empty() ? "0" : ans;
    }
};