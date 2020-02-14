// 以二维数组右上角为起点，如果目标比当前数小，则向左走，比当前数大则向下走
// 二叉搜索树

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
            return false;
        int m = matrix[0].size();
        if (m == 0)
            return false;
        int x = 0, y = m - 1;
        while (1) {
            if (matrix[x][y] == target)
                return true;
            if (target < matrix[x][y]) {
                --y;
                if (y < 0)
                    return false;
            } else {
                ++x;
                if (x >= n)
                    return false;
            }
        }
        return false;
    }
};
