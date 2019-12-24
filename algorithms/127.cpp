class Solution {
public:
    bool can(const string &s1, const string &s2) {
        int count = 0;
        for (int i = 0; i < s1.size(); ++i)
            count += s1[i] != s2[i];
        return count == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> que;
        que.push(beginWord);
        unordered_map<string, vector<string>> par;

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())
            return 0;

        unordered_map<string, int> step = {{beginWord, 1}};
        int len = 0;

        unordered_map<string, vector<string>> graph;
        for (const auto &word : dict)
            if (can(beginWord, word))
                graph[beginWord].emplace_back(word);
        for (const auto &word1 : dict) 
            for (const auto &word2 : dict)
                if (can(word1, word2))
                    graph[word1].emplace_back(word2);

        while (!que.empty()) {
            ++len;
            for (int i = que.size(); i > 0; --i) {
                string t = que.front(); que.pop();
                for (const auto &word : graph[t]) {
                    if (!can(word, t))
                        continue;
                    if (word == endWord) {
                        return len + 1;
                    }
                    if (step.count(word) && len < step[word]) {
                        par[word].emplace_back(t);
                    }
                    if (!step.count(word)) {
                        par[word].emplace_back(t);
                        step[word] = len + 1;
                        que.push(word);
                    }
                }
            }
        }

        return 0;
    }
};