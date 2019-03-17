class Solution {
public:
    int longestMountain(vector<int>& A) {
        int len = A.size();
        if (len < 3)
            return 0;
        int ans = 0;
        int p = 0, q = 1;
        int flag = 0;
        while (q < len) {
            if (flag == 0) {
                if (A[q - 1] < A[q]) {
                    flag = 1;
                    q++;
                } else {
                    p = q++;
                }
            } else if (flag == 1) {
                if (A[q - 1] < A[q]) {
                    q++;
                } else if (A[q - 1] == A[q]) {
                    p = q++;
                    flag = 0;
                } else {
                    flag = -1;
                    q++;
                }
            } else {
                if (A[q - 1] <= A[q]) {
                    ans = max(ans, q - p);
                    p = q - 1;
                    flag = 0;
                } else {
                    q++;
                }
            }
        }
        if (flag == -1)
            ans = max(ans, q - p);
        return ans;
    }
};
