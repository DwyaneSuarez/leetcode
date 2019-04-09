class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.size();
        int len2 = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans(len1 + len2, '0');
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int cur = (num1[i] - '0') * (num2[j] - '0') + ans[i + j] - '0';
                int idx = i + j;
                while (true) {
                    ans[idx] = cur % 10 + '0';
                    if (cur < 10)
                        break;
                    cur = cur / 10 + ans[++idx] - '0';
                }
            }
        }
        int idx = len1 + len2 - 1;
        while (ans[idx] == '0')
            idx--;
        ans = ans.substr(0, idx + 1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
