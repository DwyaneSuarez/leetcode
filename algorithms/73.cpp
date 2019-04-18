class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0)
            return;
        int m = matrix[0].size();
        if (m == 0)
            return;
        bool row = false;
        for (int i = 0; i < n; i++)
            if (!matrix[i][0]) {
                row = true;
                break;
            }
        bool col = false;
        for (int i = 0; i < m; i++)
            if (!matrix[0][i]) {
                col = true;
                break;
            }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for (int i = 1; i < n; i++)
            if (!matrix[i][0])
                for (int j = 1; j < m; j++)
                    matrix[i][j] = 0;
        for (int i = 1; i < m; i++)
            if (!matrix[0][i])
                for (int j = 1; j < n; j++)
                    matrix[j][i] = 0;
        if (row)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        if (col)
            for (int i = 0; i < m; i++)
                matrix[0][i] = 0;
    }
};
