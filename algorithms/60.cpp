class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num(n, 0), fac;
        fac.push_back(1);
        for (int i = 1; i <= n; i++) {
            fac.push_back(fac[i - 1] * i);
        }
        string ans;
        int x = k - 1;
        for (int i = n - 1; i >= 0; i--) {
            int cur = x / fac[i];
            x %= fac[i];
            int cnt = -1;
            for (int j = 0; j < n; j++) {
                if (num[j] == 0)
                    cnt++;
                if (cnt == cur) {
                    ans += char('1' + j);
                    num[j] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};
