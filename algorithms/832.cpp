class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        for (int i = 0; i < n; ++i) {
            int l = 0, r = n - 1;
            while (l < r) {
                if (A[i][l] == A[i][r]) {
                    A[i][l] = 1 - A[i][l];
                    A[i][r] = 1 - A[i][r];
                }
                ++l; --r;
            }
            if (l == r)
                A[i][l] = 1 - A[i][l];
        }
        return A;
    }
};