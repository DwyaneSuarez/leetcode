class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        if (nums.size() == 0)
            return ret;
        sort(nums.begin(), nums.end());

        vector<int> newnums, cnt;
        int len = nums.size();
        int cur = nums[0], curcnt = 1;
        for (int i = 1; i < len; ++i) {
            if (nums[i] != cur) {
                newnums.push_back(cur);
                cnt.push_back(curcnt);
                curcnt = 1;
                cur = nums[i];
            } else
                ++curcnt;
        }
        newnums.push_back(cur);
        cnt.push_back(curcnt);

        int p = 0, q = 1;
        vector<int> idx = {0};
        while (p < q) {
            for (int i = idx[p]; i < newnums.size(); ++i) {
                for (int j = 1; j <= cnt[i]; ++j) {
                    vector<int> tmp(ret[p]);
                    for (int k = 0; k < j; ++k) tmp.emplace_back(newnums[i]);
                    ret.emplace_back(tmp);
                    idx.emplace_back(i + 1);
                    ++q;
                }
            }
            ++p;
        }
        return ret;
    }
};
