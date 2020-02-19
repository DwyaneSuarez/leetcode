class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int countDigit(int x) {
        int ret = 0;
        while (x > 0) {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
    int movingCount(int m, int n, int k) {
        unordered_set<int> vis;
        vector<bool> vec(n * m);
        for (int i = 0; i < n * m; ++i) {
            if (countDigit(i / n) + countDigit(i % n) <= k)
                vec[i] = true;
        }
        queue<int> q;
        q.push(0);
        vis.insert(0);
        while (!q.empty()) {
            int x = q.front() / n;
            int y = q.front() % n;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && vec[nx * n + ny] && vis.find(nx * n + ny) == vis.end()) {
                    q.push(nx * n + ny);
                    vis.insert(nx * n + ny);
                }
            }
        }
        return vis.size();
    }
};