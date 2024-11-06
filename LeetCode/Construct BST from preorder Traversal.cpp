class Solution {
public:
    // Helper function to construct the BST from preorder traversal
    TreeNode* helper(vector<int> &preorder, int ub, int &i) {
        // Base case: return NULL if index is out of bounds or the current value exceeds the upper bound
        if (i == preorder.size() || preorder[i] > ub)
            return NULL;

        // Create a new TreeNode with the current value from preorder
        TreeNode* root = new TreeNode(preorder[i++]);

        // Recursively construct the left subtree with the upper bound set to the current node's value
        root->left = helper(preorder, root->val, i);

        // Recursively construct the right subtree with the original upper bound
        root->right = helper(preorder, ub, i);

        return root;
    }

    // Main function to initiate the BST construction from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Handle edge case of an empty input
        if (preorder.size() == 0)
            return NULL;

        int i = 0;  // Index to track the current position in the preorder vector
        return helper(preorder, INT_MAX, i);  // Call helper with initial upper bound set to maximum int value

        // Alternative approach:
        // vector<int> inorder = preorder;
        // sort(inorder.begin(), inorder.end()); // Construct BST using preorder and sorted inorder
    }
};
