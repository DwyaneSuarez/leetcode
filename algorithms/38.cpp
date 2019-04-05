class Solution {
public:
    string num2str(int num) {
        string ans;
        if (num == 0)
            ans = "0";
        while (num > 0) {
            char ch = num % 10 + '0';
            ans += ch;
            num /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string countAndSay(int n) {
        string cur("1");
        if (n == 1)
            return cur;
        for (int i = 2; i <= n; i++) {
            string nxt;
            int p = 1, cnt = 1, len = cur.size();
            char ch = cur[0];
            while (p < len) {
                if (cur[p] == ch) {
                    cnt++;
                } else {
                    nxt += num2str(cnt);
                    nxt += ch;
                    cnt = 1;
                    ch = cur[p];
                }
                p++;
            }
            nxt += num2str(cnt);
            nxt += ch;
            cur = nxt;
        }
        return cur;
    }
};
