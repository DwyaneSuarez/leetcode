class Solution {
public:
    bool check(vector<int> &postorder, int l, int r, int lb, int ub) {
        if (l > r)
            return true;
        int root = postorder[r];
        if (root < lb || root > ub)
            return false;
        int pivot = r - 1;
        while (pivot >= 0 && postorder[pivot] > root)
            --pivot;
        return check(postorder, l, pivot, lb, min(ub, root)) && check(postorder, pivot + 1, r - 1, max(lb, root), ub);
    }
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        if (n == 0)
            return true;
        return check(postorder, 0, n - 1, INT_MIN, INT_MAX);
    }
};