class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int n = matrix.size();
        if (n == 0)
            return ret;
        int m = matrix[0].size();
        if (m == 0)
            return ret;
        int dir = 0;
        int cnt = 0;
        int x = 0, y = 0;
        int up = 1, down = n - 1, left = 0, right = m - 1;
        for (int i = 0; i < n * m; ++i) {
            ret.push_back(matrix[x][y]);
            if (dir == 0) {
                if (y == right) {
                    ++x;
                    dir = 1;
                    --right;
                } else
                    ++y;
            } else if (dir == 1) {
                if (x == down) {
                    --y;
                    dir = 2;
                    --down;
                } else
                    ++x;
            } else if (dir == 2) {
                if (y == left) {
                    --x;
                    dir = 3;
                    ++left;
                } else
                    --y;
            } else {
                if (x == up) {
                    ++y;
                    dir = 0;
                    ++up;
                } else
                    --x;
            }
        }
        return ret;
    }
};