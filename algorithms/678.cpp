class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if (n == 0)
            return true;
        int star = 0;
        int left = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*')
                ++star;
            else if (s[i] == '(')
                ++left;
            else {
                if (left + star == 0)
                    return false;
                if (left > 0)
                    --left;
                else
                    --star;
            }
        }
        star = 0, left = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '*')
                ++star;
            else if (s[i] == ')')
                ++left;
            else {
                if (left + star == 0)
                    return false;
                if (left > 0)
                    --left;
                else
                    --star;
            }
        }
        return true;
    }
};