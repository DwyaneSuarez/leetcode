class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int num = 0;
        int start = 0;
        int bound = n;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = i; j < bound; j++)
                ans[i][j] = ++num;
            for (int j = i + 1; j < bound; j++)
                ans[j][bound - 1] = ++num;
            for (int j = bound - 2; j >= i; j--)
                ans[bound - 1][j] = ++num;
            for (int j = bound - 2; j > i; j--)
                ans[j][i] = ++num;
            bound--;
        }
        return ans;
    }
};
