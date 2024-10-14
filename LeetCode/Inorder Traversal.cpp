/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // Default constructor initializing value to 0 and left, right to nullptr
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor initializing value to x and left, right to nullptr
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // Constructor initializing value to x, left and right pointers
 * };
 */

class Solution {
public:

    // We will solve this problem using Morris Inorder Traversal, which has O(1) space complexity (excluding the output).

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; // Vector to store the inorder traversal result
        TreeNode* cur = root; // Start traversal from the root node
        while (cur != NULL) { // Continue until we traverse the entire tree
            if (cur->left == NULL) { // If there is no left subtree, visit the current node
                ans.push_back(cur->val); // Add the current node's value to the result
                cur = cur->right; // Move to the right subtree
            } else {
                TreeNode *prev = cur->left; // Find the rightmost node in the left subtree (predecessor)
                while (prev->right && prev->right != cur) { // Traverse to find the inorder predecessor
                    prev = prev->right; // Keep moving to the rightmost node
                }
                if (prev->right == NULL) { // If the right pointer of predecessor is NULL
                    prev->right = cur; // Make a temporary link from predecessor to current node
                    cur = cur->left; // Move to the left subtree
                } else { // If the right pointer of predecessor is already pointing to current node (indicating we've visited the left subtree)
                    prev->right = NULL; // Remove the temporary link
                    ans.push_back(cur->val); // Visit the current node
                    cur = cur->right; // Move to the right subtree
                }
            }
        }
        return ans; // Return the result of inorder traversal
    }

    // The following is the normal recursive method for inorder traversal, but it uses O(n) stack space for recursion.

    // vector<int> ans; // Vector to store the result
    // void inorder(TreeNode* node) {
    //     if (node == NULL) {
    //         return; // Base case: return if the node is NULL
    //     }
    //     inorder(node->left); // Recursively traverse the left subtree
    //     ans.push_back(node->val); // Visit the current node
    //     inorder(node->right); // Recursively traverse the right subtree
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     inorder(root); // Start recursive inorder traversal from the root
    //     return ans; // Return the result
    // }
};
