class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> vec(n, 1);
        int mul = 1;
        for (int i = 0; i < n; ++i) {
            vec[i] *= mul;
            mul *= a[i];
        }
        mul = 1;
        for (int i = n - 1; i >= 0; --i) {
            vec[i] *= mul;
            mul *= a[i];
        }
        return vec;
    }
};