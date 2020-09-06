class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        int ans = A[n - 1] - A[0];
        for (int i = 0; i + 1 < n; ++i) {
            int high = max(A[i] + K, A[n - 1] - K);
            int low = min(A[i + 1] - K, A[0] + K);
            ans = min(ans, high - low);
        }
        return ans;
    }
};