class Solution {
public:
    string reformat(string s) {
        string digit, alphabet;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) digit += s[i];
                else if (isalpha(s[i])) alphabet += s[i];
        }
        int dlen = digit.size();
        int alen = alphabet.size();
        if (abs(dlen - alen) > 1)
            return "";
        if (dlen < alen) swap(digit, alphabet);
        string ans;
        for (int i = 0; i < digit.size(); ++i) {
            ans += digit[i];
            if (i < alphabet.size()) ans += alphabet[i];
        }
        return ans;
    }
};