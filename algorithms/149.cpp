class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const {
            return hash<T1>()(p.first) ^ hash<T2>()(p.second);
        }
    };
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int base = 1;
            int out = 0;
            unordered_map<pair<int, int>, int, pair_hash> cnt;
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) {
                    ++base;
                } else if (dx == 0) {
                    ++cnt[{0, 1}];
                    out = max(out, cnt[{0, 1}]);
                } else if (dy == 0) {
                    ++cnt[{1, 0}];
                    out = max(out, cnt[{1, 0}]);
                } else {
                    int div = __gcd(dx, dy);
                    dx /= div;
                    dy /= div;
                    ++cnt[{dx, dy}];
                    out = max(out, cnt[{dx, dy}]);
                }
            }
            ans = max(ans, out + base);
        }
        return ans;
    }
};
