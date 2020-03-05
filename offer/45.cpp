class Solution {
public:
    static bool cmp(const int num1, const int num2) {
        string str1 = to_string(num1);
        string str2 = to_string(num2);
        return str1 + str2 < str2 + str1;
    }
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ret;
        for (auto num: nums)
            ret += to_string(num);
        return ret;
    }
};