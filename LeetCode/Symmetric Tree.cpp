class Solution {
public:
    // Helper function to check if two subtrees are mirror images of each other
    bool helper(TreeNode* left, TreeNode* right) {
        // Base case: if either of the nodes is null, check if both are null (symmetric)
        if (!left || !right)
            return left == right;

        // If the values of the current nodes are not the same, they aren't symmetric
        if (left->val != right->val) 
            return false;

        // Recursively check the left and right subtrees in mirrored positions
        return helper(left->left, right->right) && helper(left->right, right->left);
    }

    // Main function to determine if the tree is symmetric
    bool isSymmetric(TreeNode* root) {
        // A tree is symmetric if it's empty or if its left and right subtrees are mirror images
        return root == NULL || helper(root->left, root->right);
    }
};
