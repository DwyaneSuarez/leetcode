class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int lena = a.size();
        int lenb = b.size();
        string ans(max(lena, lenb), '0');
        int carry = 0;
        for (int i = 0; i < max(lena, lenb); i++) {
            int cur = carry;
            if (i < lena)
                cur += a[i] - '0';
            if (i < lenb)
                cur += b[i] - '0';
            if (cur >= 2) {
                carry = cur / 2;
                cur %= 2;
            } else
                carry = 0;
            ans[i] = cur + '0';
        }
        if (carry)
            ans += carry + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
