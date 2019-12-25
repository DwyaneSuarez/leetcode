class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto &num : nums)
            hash.insert(num);
        int ans = 0;
        for (auto num : nums) {
            if (!hash.count(num))
                continue;
            int cur = 1;
            int x = num;
            while (hash.count(--x))
                ++cur, hash.erase(x);
            x = num;
            while (hash.count(++x))
                ++cur, hash.erase(x);
            hash.erase(x);
            ans = max(ans, cur);
        }
        return ans;
    }
};