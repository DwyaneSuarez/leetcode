class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return;
        int i = 0;
        int cnt = 0;
        for (i = 0; i < n; ++i) {
            cnt += 1 + (arr[i] == 0);
            if (cnt >= n)
                break;
        }
        int q = n;
        if (cnt > n) {
            arr[--q] = arr[i];
            cnt -= 2;
            --i;
        }
        for (; i >= 0; --i) {
            if (arr[i] == 0) {
                arr[--q] = 0;
                arr[--q] = 0;
            } else
                arr[--q] = arr[i];
        }
    }
};