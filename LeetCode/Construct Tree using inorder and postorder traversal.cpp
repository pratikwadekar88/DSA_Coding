class Solution {
public:
    // Helper function to build the binary tree from inorder and postorder traversals
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd, map<int, int>& mpp) {

        // Base case: if there are no elements left to build the subtree
        if (inStart > inEnd || postStart < postEnd) 
            return NULL;

        // Create the root node using the current end of postorder traversal
        TreeNode* node = new TreeNode(postorder[postStart]);

        // Find the index of this root value in the inorder traversal
        int inidx = mpp[postorder[postStart]];

        // Calculate the number of nodes in the right subtree
        int rightLen = inEnd - inidx;

        // Recursively build the left subtree
        node->left = build(inorder, inStart, inidx - 1, postorder, postStart - rightLen - 1, postEnd, mpp);

        // Recursively build the right subtree
        node->right = build(inorder, inidx + 1, inEnd, postorder, postStart - 1, postStart - rightLen, mpp);

        return node; // Return the constructed subtree rooted at 'node'
    }

    // Main function to build the binary tree from inorder and postorder traversals
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Map to store the index of each value in the inorder traversal for quick access
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        // Call the helper function to build the tree
        return build(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1, 0, mpp);
    }
};
