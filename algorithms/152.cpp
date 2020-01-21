class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int ans = 0;
        int b = 0, e = 0;
        while (e < nums.size()) {
            if (nums[e] == 0 || e + 1 == nums.size()) {
                if (e + 1 == nums.size() && nums[e] != 0)
                    ++e;
                int cnt = 0;
                if (b == e) {
                    ++e;
                    b = e;
                    continue;
                }
                for (int i = b; i < e; ++i)
                    if (nums[i] < 0)
                        ++cnt;
                if (cnt & 1) {
                    int first = b;
                    for (int i = b; i < e; ++i) {
                        if (nums[i] < 0) {
                            first = i;
                            break;
                        }
                    }
                    int last = e - 1;
                    for (int i = e - 1; i >= b; --i) {
                        if (nums[i] < 0) {
                            last = i;
                            break;
                        }
                    }
                    if (first + 1 < e) {
                        int cur = 1;
                        for (int i = first + 1; i < e; ++i)
                            cur *= nums[i];
                        ans = max(ans, cur);
                    }
                    if (b < last) {
                        int cur = 1;
                        for (int i = b; i < last; ++i)
                            cur *= nums[i];
                        ans = max(ans, cur);
                    }
                } else {
                    int cur = 1;
                    for (int i = b; i < e; ++i)
                        cur *= nums[i];
                    ans = max(ans, cur);
                }
                ++e;
                b = e;
            } else
                ++e;
        }
        return ans;
    }
};
