class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int cur = 0;
        int tot = 0;
        while (true) {
            ++cur;
            tot += cur;
            if (tot > target)
                break;
        }
        tot -= cur;
        --cur;
        vector<vector<int>> ret;
        while (cur > 1) {
            int rest = target - tot;
            if (rest % cur == 0) {
                ret.push_back(vector<int>());
                for (int i = 0; i < cur; ++i)
                    ret.back().push_back(rest / cur + i + 1);
            }
            tot -= cur;
            --cur;
        }
        return ret;
    }
};