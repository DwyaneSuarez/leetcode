class Solution {
public:
    void update(vector<int> &vec, int a, int val) {
        while (a < vec.size()) {
            vec[a] += val;
            a += lowbit(a);
        }
    }
    int query(vector<int> &vec, int a) {
        int ret = 0;
        while (a > 0) {
            ret += vec[a];
            a -= lowbit(a);
        }
        return ret;
    }
    int lowbit(int a) {
        return a&(-a);
    }
    int reversePairs(vector<int>& nums) {
        vector<int> vec(nums);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        int id = 0;
        unordered_map<int, int> hash;
        for (auto x : vec)
            hash[x] = ++id;
        int ans = 0;
        vector<int> bit(vec.size() + 1);
        for (auto i = nums.rbegin(); i != nums.rend(); ++i) {
            int x = *i;
            ans += query(bit, hash[x] - 1);
            update(bit, hash[x], 1);
        }
        return ans;
    }
};