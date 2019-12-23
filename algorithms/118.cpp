class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec(numRows);
        if (numRows <= 0)
            return vec;
        vec[0].emplace_back(1);
        for (int i = 1; i < numRows; ++i) {
            vec[i].emplace_back(1);
            for (int j = 1; j < i; ++j)
                vec[i].emplace_back(vec[i - 1][j - 1] + vec[i -1][j]);
            vec[i].emplace_back(1);
        }
        return vec;
    }
};