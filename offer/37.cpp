/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        string ret = "[";
        bool first = true;
        while (!que.empty()) {
            TreeNode *cur = que.front();
            que.pop();
            if (!first)
                ret += ",";
            ret += cur ? to_string(cur->val) : "null";
            if (cur) {
                que.push(cur->left);
                que.push(cur->right);
            }
            first = false;
        }
        if (ret.find(',') != string::npos && ret[ret.size() - 1] == 'l') {
            while (ret[ret.size() - 1] == 'l')
                ret.resize(ret.size() - 5);
        }
        ret += "]";
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        queue<TreeNode*> que;
        int pos = data.find(',');
        if (pos == string::npos)
            pos = data.find(']');
        string head = data.substr(1, pos - 1);
        TreeNode *root = NULL;
        if (head != "null") {
            root = new TreeNode(stoi(head));
            que.push(root);
        }
        if (data[pos] == ']')
            return root;
        while (!que.empty()) {
            TreeNode *cur = que.front();
            que.pop();
            if (cur) {
                int tmp = pos + 1;
                pos = data.find(',', tmp);
                if (pos == string::npos)
                    pos = data.find(']');
                string str = data.substr(tmp, pos - tmp);
                if (str != "null") {
                    TreeNode *lch = new TreeNode(stoi(str));
                    cur->left = lch;
                    que.push(lch);
                }
                if (data[pos] == ']')
                    break;
                tmp = pos + 1;
                pos = data.find(',', tmp);
                if (pos == string::npos)
                    pos = data.find(']');
                str = data.substr(tmp, pos - tmp);
                if (str != "null") {
                    TreeNode *rch = new TreeNode(stoi(str));
                    cur->right = rch;
                    que.push(rch);
                }
                if (data[pos] == ']')
                    break;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));