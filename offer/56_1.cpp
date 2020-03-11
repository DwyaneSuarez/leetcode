class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int xorsum = 0;
        for (auto num : nums)
            xorsum ^= num;
        int lb = xorsum & (-xorsum);
        int num1 = 0, num2 = 0;
        for (auto num : nums)
            if (num & lb)
                num1 ^= num;
            else
                num2 ^= num;
        return {num1, num2};
    }
};