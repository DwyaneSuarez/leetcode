class Solution {
public:
    struct TrieNode {
        TrieNode *children[26];
        int count;
        TrieNode() {
            for (int i = 0; i < 26; ++i)
                children[i] = NULL;
            count = 0;
        }
        TrieNode *get(char c) {
            if (children[c - 'a'] == NULL) {
                children[c - 'a'] = new TrieNode();
                ++count;
            }
            return children[c - 'a'];
        }
    };
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode *trie = new TrieNode();
        vector<TrieNode*> vec;
        vec.reserve(words.size());
        unordered_map<TrieNode*, int> hash;
        for (const auto &word : words) {
            int len = word.size();
            TrieNode *cur = trie;
            for (int i = len - 1; i >= 0; --i) {
                cur = cur->get(word[i]);
                if (i == 0) {
                    if (hash.count(cur) == 0) {
                        hash[cur] = len;
                        vec.push_back(cur);
                    }
                }
            }
        }
        int ans = 0;
        for (const auto &node : vec) {
            if (node->count == 0) {
                ans += hash[node] + 1;
            }
        }
        return ans;
    }
};