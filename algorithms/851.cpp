class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> cnt(n);
        vector<vector<int>> G(n);
        for (int i = 0; i < richer.size(); ++i) {
            ++cnt[richer[i][1]];
            G[richer[i][0]].push_back(richer[i][1]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = i;
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) que.push(i);
        }
        while (!que.empty()) {
            int cur = que.front();
            que.pop();            
            for (int i = 0; i < G[cur].size(); ++i) {
                if (--cnt[G[cur][i]] == 0)
                    que.push(G[cur][i]);
                if (quiet[ans[cur]] < quiet[ans[G[cur][i]]]) {
                    ans[G[cur][i]] = ans[cur];
                }
            } 
        }
        return ans;
    }
};