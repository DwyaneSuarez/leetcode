class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
        vector<int> vec(s.size());
        if (s[0] == '0')
            return 0;
        vec[0] = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (s[i - 1] > '2' || s[i - 1] == '0')
                    return 0;
                else
                    vec[i] = i - 2 >= 0 ? vec[i - 2] : 1;
                continue;
            }
            else
                vec[i] = vec[i - 1];
            if (s[i - 1] == '1' && s[i] >= '1' && s[i] <= '9')
                vec[i] += i - 2 >= 0 ? vec[i - 2] : 1;
            else if (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')
                vec[i] += i - 2 >= 0 ? vec[i - 2] : 1;
        }
        return vec[s.size() - 1];
    }
};
