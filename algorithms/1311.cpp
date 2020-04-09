class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<string> vec;
        queue<pair<int, int>> que;
        que.push({id, 0});
        unordered_set<int> vis;
        vis.insert(id);
        vector<int> kFriends;
        while (!que.empty()) {
            int cur = que.front().first;
            int dis = que.front().second;
            que.pop();
            if (dis == level) {
                kFriends.push_back(cur);
                continue;
            }
            for (int i = 0; i < friends[cur].size(); ++i) {
                if (vis.count(friends[cur][i]) == 0) {
                    que.push({friends[cur][i], dis + 1});
                    vis.insert(friends[cur][i]);
                }
            }
        }
        map<string, int> cnt;
        for (int i = 0; i < kFriends.size(); ++i) {
            for (int j = 0; j < watchedVideos[kFriends[i]].size(); ++j)
                ++cnt[watchedVideos[kFriends[i]][j]];
        }
        set<pair<int, string>> s;
        for (auto o : cnt) {
            s.insert({o.second, o.first});
        }
        vector<string> ans;
        for (auto o : s) 
            ans.push_back(o.second);
        return ans;
    }
};