class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Found the node to delete
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // Node has two children:
                // Find the smallest node in the right subtree (in-order successor)
                TreeNode* successor = root->right;
                while (successor->left != nullptr) {
                    successor = successor->left;
                }
                // Copy successor's value to this node
                root->val = successor->val;
                // Delete the successor from the right subtree
                root->right = deleteNode(root->right, successor->val);
            }
        }
        
        return root;
    }
};