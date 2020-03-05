/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* dfs(vector<vector<int>> &grid, int x, int y, int s) {
        Node *ret = new Node();
        int cnt1 = 0;
        for (int i = x; i < x + s; ++i)
            for (int j = y; j < y + s; ++j)
                if (grid[i][j] == 1)
                    ++cnt1;
        if (cnt1 == s * s) {
            ret->isLeaf = true;
            ret->val = true;
            return ret;
        }
        if (cnt1 == 0) {
            ret->isLeaf = true;
            ret->val = false;
            return ret;
        }
        ret->val = true;
        ret->topLeft = dfs(grid, x, y, s / 2);
        ret->topRight = dfs(grid, x, y + s / 2, s / 2);
        ret->bottomLeft = dfs(grid, x + s / 2, y, s / 2);
        ret->bottomRight = dfs(grid, x + s / 2, y + s / 2, s / 2);
        return ret;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0)
            return NULL;
        return dfs(grid, 0, 0, n);
    }
};