/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    // Returns {longest zigzag ending here going left, ...going right}
    pair<int,int> dfs(TreeNode* node, int& ans) {
        if (!node) return {-1, -1};

        auto leftRes = dfs(node->left, ans);
        auto rightRes = dfs(node->right, ans);

        // If we go left from node, the streak continues from a "go right" streak at left child
        int goLeft = leftRes.second + 1;
        // If we go right from node, the streak continues from a "go left" streak at right child
        int goRight = rightRes.first + 1;

        ans = max({ans, goLeft, goRight});

        return {goLeft, goRight};
    }
};