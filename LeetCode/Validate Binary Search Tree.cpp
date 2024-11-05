class Solution {
public:
    // Helper function to validate the BST property recursively
    bool helper(TreeNode* root, long long left, long long right) {
        // Base case: if the current node is NULL, it is valid
        if (root == NULL)
            return true;

        // Check if the current node's value lies within the valid range (left, right)
        // and recursively check the left and right subtrees
        return (root->val > left && root->val < right) &&
               helper(root->left, left, root->val) &&  // Check left subtree with updated right bound
               helper(root->right, root->val, right);  // Check right subtree with updated left bound
    }

    // Main function to check if a tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // An empty tree is a valid BST by definition
        if (root == NULL)
            return true;

        // Call the helper function with the initial range set to the minimum and maximum values
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
