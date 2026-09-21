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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixCount;
        prefixCount[0] = 1;  // empty prefix, sum = 0
        return dfs(root, 0LL, targetSum, prefixCount);
    }
    
private:
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixCount) {
        if (!node) return 0;
        
        currentSum += node->val;
        
        // how many prefixes exist such that currentSum - prefix == targetSum
        int count = 0;
        auto it = prefixCount.find(currentSum - targetSum);
        if (it != prefixCount.end()) {
            count = it->second;
        }
        
        // add current prefix sum to the map
        prefixCount[currentSum]++;
        
        // recurse into children
        count += dfs(node->left, currentSum, targetSum, prefixCount);
        count += dfs(node->right, currentSum, targetSum, prefixCount);
        
        // backtrack: remove current prefix sum before returning up
        prefixCount[currentSum]--;
        
        return count;
    }
};