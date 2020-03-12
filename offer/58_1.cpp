class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n = s.size();
        int e = n - 1;
        while (e >= 0) {
            while (e >= 0 && isspace(s[e]))
                --e;
            if (e < 0)
                break;
            int b = e;
            while (b >= 0 && !isspace(s[b]))
                --b;
            if (b + 1 <= e) {
                if (!ans.empty())
                    ans += ' ';
                ans += s.substr(b + 1, e - b);
            }
            e = b;
        }
        return ans;
    }
};