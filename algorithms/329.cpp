// bfs + memory
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        vector<vector<int>> mem(n, vector<int>(m, 0));
        queue<int> que;
        int ans = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                mem[i][j] = 1;
                que.push(i * m + j);
            }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            int x = cur / m;
            int y = cur % m;
            ans = max(ans, mem[x][y]);
            for (int i = 0; i < 4; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && matrix[xx][yy] > matrix[x][y] && mem[x][y] + 1 > mem[xx][yy]) {
                    mem[xx][yy] = mem[x][y] + 1;
                    que.push(xx * m + yy);
                }
            }
        }
        return ans;
    }
};

// topo sort
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        vector<vector<int>> mem(n, vector<int>(m, 0));
        queue<int> que;
        vector<int> indeg(n * m);
        vector<vector<int>> G(n * m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m - 1; ++j) {
                int cur = i * m + j;
                if (matrix[i][j] < matrix[i][j + 1]) {
                    indeg[cur + 1]++;
                    G[cur].push_back(cur + 1);
                } else if (matrix[i][j] > matrix[i][j + 1]) {
                    indeg[cur]++;
                    G[cur + 1].push_back(cur);
                }
            }
        for (int i = 0; i < n - 1; ++i) 
            for (int j = 0; j < m; ++j) {
                int cur = i * m + j;
                if (matrix[i][j] < matrix[i + 1][j]) {
                    indeg[cur + m]++;
                    G[cur].push_back(cur + m);
                } else if (matrix[i][j] > matrix[i + 1][j]) {
                    indeg[cur]++;
                    G[cur + m].push_back(cur);
                }
            }
        int ans = 1;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) {
                mem[i][j] = 1;
                int cur = i * m + j;
                if (indeg[cur] == 0) que.push(cur);
            }
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            int x = cur / m;
            int y = cur % m;
            ans = max(ans, mem[x][y]);
            for (int i = 0; i < G[cur].size(); ++i) {
                int xx = G[cur][i] / m;
                int yy = G[cur][i] % m;
                mem[xx][yy] = max(mem[xx][yy], mem[x][y] + 1);
                if (--indeg[G[cur][i]] == 0) que.push(G[cur][i]);
            }
        }
        return ans;
    }
};