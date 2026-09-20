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
    int goodNodes(TreeNode* root) {
        return countGood(root, root->val);
    }
    
private:
    int countGood(TreeNode* node, int maxSoFar) {
        if (!node) return 0;
        
        int count = (node->val >= maxSoFar) ? 1 : 0;
        int newMax = max(maxSoFar, node->val);
        
        count += countGood(node->left, newMax);
        count += countGood(node->right, newMax);
        
        return count;
    }
};