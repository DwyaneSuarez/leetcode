class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        if (len == 0)
            return false;
        int l = 0;
        while (l < len && s[l] == ' ')
            l++;
        if (l == len)
            return false;
        int r = len - 1;
        while (r >= 0 && s[r] == ' ')
            r--;
        s = s.substr(l, r - l + 1);
        len = s.size();
        int state = 0;
        bool e = false;
        bool digit = false;
        bool dot = false;
        for (int i = 0; i < len; i++) {
            if (state == 0) {
                if (isdigit(s[i])) {
                    state = 1;
                    digit = true;
                } else if (s[i] == '-' || s[i] == '+')
                    state = 2;
                else if (s[i] == '.') {
                    state = 3;
                    dot = true;
                } else
                    return false;
            } else if (state == 1) {
                if (s[i] == '.' && !e && !dot) {
                    state = 3;
                    dot = true;
                } else if (isdigit(s[i])) {
                    state = 1;
                    digit = true;
                } else if (s[i] == 'e' && !e) {
                    state = 4;
                    e = true;
                } else
                    return false;
            } else if (state == 2) {
                if (isdigit(s[i])) {
                    state = 1;
                    digit = true;
                } else if (s[i] == '.' && !dot && !e) {
                    state = 3;
                    dot = true;
                } else
                    return false;
            } else if (state == 3) {
                if (isdigit(s[i])) {
                    state = 1;
                    digit = true;
                } else if (s[i] == 'e' && !e && digit) {
                    state = 4;
                    e = true;
                } else
                    return false;
            } else if (state == 4) {
                if (isdigit(s[i])) {
                    state = 1;
                    digit = true;
                } else if (s[i] == '+' || s[i] == '-')
                    state = 2;
                else
                    return false;
            }
        }
        if (state == 2 || state == 4)
            return false;
        if (state == 3 && !digit)
            return false;
        return true;
    }
};
