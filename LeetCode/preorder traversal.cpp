/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // Default constructor initializing value to 0 and pointers to nullptr
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor initializing value to x, left and right pointers to nullptr
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // Constructor initializing value to x, left and right pointers
 * };
 */

class Solution {
public:

    // The following commented-out code is a recursive method for preorder traversal, but it uses O(n) stack space.
    // vector<int> ans;
    // void preorder(TreeNode* node) {
    //     if (node == NULL) { // Base case: return if node is NULL
    //         return;
    //     }
    //     ans.push_back(node->val); // Visit the current node
    //     preorder(node->left); // Recursively traverse the left subtree
    //     preorder(node->right); // Recursively traverse the right subtree
    // }

    // This method performs Morris Preorder Traversal, using O(1) space (excluding the output)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; // Vector to store the preorder traversal result
        TreeNode* cur = root; // Start traversal from the root node

        while (cur) { // Continue until the entire tree is traversed
            ans.push_back(cur->val); // Visit the current node
            if (cur->left == NULL) { // If there is no left subtree
                cur = cur->right; // Move directly to the right subtree
            } else {
                TreeNode *prev = cur->left; // Find the rightmost node in the left subtree (predecessor)
                while (prev->right && prev->right != cur) { // Traverse to find the rightmost node of the left subtree
                    prev = prev->right; // Move to the rightmost node
                }
                if (prev->right == NULL) { // If the right pointer of predecessor is NULL
                    prev->right = cur; // Make a temporary link to the current node
                    cur = cur->left; // Move to the left subtree
                } else { // If the right pointer of predecessor is already pointing to the current node
                    prev->right = NULL; // Remove the temporary link
                    ans.pop_back(); // Remove the current node's value (as it was already visited)
                    cur = cur->right; // Move to the right subtree
                }
            }
        }

        // Uncommented recursive method
        // preorder(root); // Perform recursive preorder traversal
        return ans; // Return the result of the preorder traversal
    }
};
