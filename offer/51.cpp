// BIT
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

// MergeSort
class Solution {
public:
    int mergeSort(vector<int> &nums, vector<int> &tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int mid = (l + r) / 2;
        int cnt = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                cnt += j - (mid + 1);
                tmp[pos++] = nums[i];
                ++i;
            } else {
                tmp[pos++] = nums[j];
                ++j;
            }
        }
        while (i <= mid) {
            cnt += j - (mid + 1);
            tmp[pos++] = nums[i];
            ++i;
        }
        while (j <= r) {
            tmp[pos++] = nums[j];
            ++j;
        }
        for (i = l; i <= r; ++i)
            nums[i] = tmp[i];
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};