class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> rec;
        int cur = 0;
        int ans = 0;
        queue<char> que;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (rec.count(ch) == 0) {
                ++cur;
                ans = max(ans, cur);
            } else {
                cur = i - rec[ch];
                ans = max(ans, cur);
                while (!que.empty()) {
                    char f = que.front();
                    que.pop();
                    rec.erase(f);
                    if (f == ch)
                        break;
                }
            }
            rec[ch] = i;
            que.push(ch);
        }
        return ans;
    }
};