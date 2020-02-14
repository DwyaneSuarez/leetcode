// 遍历每个数，将其对应下标位置（由于数字范围为0到n-1，必然不会越界）的数取相反数
// 如果操作完该位置上的数为正，则说明当前数字重复（出现一次相当于乘以-1变成负数，则第二次出现时会变回正数）
// 对于数字0单独处理

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (zero)
                    return 0;
                ++zero;
            } else {
                nums[abs(nums[i])] *= -1;
                if (nums[abs(nums[i])] > 0)
                    return abs(nums[i]);
            }
        }
        return 0;
    }
};
