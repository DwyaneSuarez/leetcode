class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.size() == 0)
            return ans;
        unordered_map<string, int> cnt_words;
        for (auto &str : words)
            cnt_words[str]++;
        int len_s = s.size();
        int len_w = words[0].size();
        int num_w = words.size();
        for (int i = 0; i <= len_s - len_w * num_w; i++) {
            unordered_map<string, int> cnt_cur;
            cnt_cur.clear();
            bool contain = true;
            for (int j = 0; j < num_w; j++) {
                string tmp = s.substr(i + j * len_w, len_w);
                if (cnt_words.find(tmp) == cnt_words.end()) {
                    contain = false;
                    break;
                } else {
                    cnt_cur[tmp]++;
                    if (cnt_cur[tmp] > cnt_words[tmp]) {
                        contain = false;
                        break;
                    }
                }
            }
            if (contain) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
