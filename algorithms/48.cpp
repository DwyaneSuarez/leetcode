class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int scale = len;
        for (int i = 0; i < len / 2; i++) {
            for (int j = i; j < len - i - 1; j++) {
                int x = i, y = j, pre = matrix[x][y];
                for (int k = 0; k < 4; k++) {
                    int nx = y;
                    int ny = scale - 1 - x + 2 * i;
                    int tmp = matrix[nx][ny];
                    matrix[nx][ny] = pre;
                    x = nx;
                    y = ny;
                    pre = tmp;
                }
            }
            scale -= 2;
        }
    }
};
