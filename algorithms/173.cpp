/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            lcStack.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int ret = lcStack.top()->val;
        TreeNode *cur = lcStack.top();
        lcStack.pop();
        cur = cur->right;
        while (cur) {
            lcStack.push(cur);
            cur = cur->left;
        }
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return lcStack.size() > 0;
    }
private:
    stack<TreeNode*> lcStack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */