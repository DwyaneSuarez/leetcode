class Solution {
public:
    long long seq(int first, int last, int n) {
        long long ret = first + last;
        ret *= n;
        ret /= 2;
        return ret;
    }
    vector<int> distributeCandies(int candies, int num_people) {
        int r = 0;
        int n = num_people;
        while (true) {
            ++r;
            int cur = n * n * r * r + n * r;
            if (cur > candies * 2)
                break;
        }
        --r;
        vector<int> ans(num_people);
        for (int i = 0; i < num_people; ++i)
            ans[i] = seq(i + 1, (r - 1) * num_people + i + 1, r);
        candies -= (n * n * r * r + n * r) / 2;
        ++r;
        for (int i = 0; i < num_people; ++i) {
            int d = (r - 1) * num_people + i + 1;
            ans[i] += min(d, candies);
            candies -= d;
            if (candies <= 0)
                break;
        }
        return ans;
    }
};