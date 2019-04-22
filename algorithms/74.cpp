class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
        int x = 0, y = 0;
        while (true) {
            if (matrix[x][y] == target)
                return true;
            if (x + 1 < m && matrix[x + 1][y] <= target)
                ++x;
            else if (y + 1 < n && matrix[x][y + 1] <= target)
                ++y;
            else
                return false;
        }
        return false;
    }
};
