class Solution {
public:

    // Helper function to calculate the height of the tree and update the diameter
    int helper(TreeNode* node, int &maxi) {
        // Base case: if the node is NULL, return 0 (height of an empty tree is 0)
        if (!node)
            return 0;
        
        // Recursively calculate the height of the left subtree
        int lh = helper(node->left, maxi);
        // Recursively calculate the height of the right subtree
        int rh = helper(node->right, maxi);
        
        // Update the maximum diameter by comparing the current diameter (left height + right height)
        maxi = max(maxi, lh + rh);
        
        // Return the height of the current node (1 + max of left and right subtree heights)
        return 1 + max(lh, rh);
    }

    // Main function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0; // Variable to store the maximum diameter
        helper(root, maxi); // Call the helper function to calculate the diameter
        return maxi; // Return the maximum diameter found
    }
};
