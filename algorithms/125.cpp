class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for (const auto ch : s)
            if (isdigit(ch))
                tmp += ch;
            else if (isalpha(ch))
                tmp += tolower(ch);
        string tmprev = tmp;
        reverse(tmprev.begin(), tmprev.end());
        return tmp == tmprev;
    }
};