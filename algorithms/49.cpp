class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> hash;
        vector<string> emp;
        vector<vector<string>> ans;
        int idx = 0;
        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if (!hash[tmp]) {
                hash[tmp] = ++idx;
                ans.push_back(emp);
                ans[hash[tmp] - 1].push_back(str);
            } else {
                ans[hash[tmp] - 1].push_back(str);
            }
        }
        return ans;
    }
};
