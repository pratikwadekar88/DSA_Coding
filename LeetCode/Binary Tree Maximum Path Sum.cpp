class Solution {
public:
    // Helper function to calculate the maximum path sum for a given subtree
    int maxPath(TreeNode* root, int &maxSum) {
        // Base case: if the node is null, return 0 (no contribution to the path sum)
        if (root == NULL)
            return 0;

        // Recursively find the maximum path sum for the left and right subtrees
        int leftSum = maxPath(root->left, maxSum);
        int rightSum = maxPath(root->right, maxSum);

        // If either left or right subtree sum is negative, reset it to 0
        // as negative sums would reduce the path sum
        if (leftSum < 0) leftSum = 0;
        if (rightSum < 0) rightSum = 0;

        // Update maxSum with the maximum path sum that passes through the current root node
        maxSum = max(maxSum, leftSum + rightSum + root->val);

        // Return the maximum sum of the path that includes the current node and one of its subtrees
        return root->val + max(leftSum, rightSum);
    }

    // Function to find the maximum path sum in the binary tree
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize maxSum to the smallest possible integer
        maxPath(root, maxSum); // Call helper function to update maxSum
        return maxSum; // Return the maximum path sum
    }
};
