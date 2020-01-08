class Solution {
public:
    long long sigma(int x) {
        long long ret = x;
        ret = ret * (ret + 1) / 2;
        return ret;
    }
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = n;
        if (n == 1)
            return ans;
        int state = 1;
        int l = 0, r = 0;
        int i = 0;
        while (i < n) {
            if (state == 1) {
                if (i == n - 1) {
                    ans += sigma(l);
                    break;
                }
                if (ratings[i] < ratings[i + 1])
                    l++;
                else if (ratings[i] == ratings[i + 1])
                    ans += sigma(l), l = r = 0;
                else
                    state = -1, r = 1;
            } else if (state == -1) {
                if (i == n - 1 || ratings[i] <= ratings[i + 1]) {
                    ans += sigma(max(l, r)) + sigma(min(l, r) - 1);
                    if (i == n - 1)
                        break;
                    l = ratings[i] < ratings[i + 1]; r = 0;
                    state = ratings[i] < ratings[i + 1] ? 1 : 0;
                } else
                    r++;
            } else {
                if (i == n - 1)
                    break;
                if (ratings[i] < ratings[i + 1])
                    l = 1, state = 1;
                else if (ratings[i] > ratings[i + 1])
                    r = 1, state = -1;
            }
            ++i;
        }
        return ans;
    }
};
