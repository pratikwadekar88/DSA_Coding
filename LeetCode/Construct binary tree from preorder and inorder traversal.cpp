class Solution {
public:
    // Helper function to build the binary tree from preorder and inorder traversals
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd, map<int, int>& mpp) {

        // Base case: if there are no elements to construct the subtree
        if (preStart > preEnd || inStart > inEnd) 
            return NULL;

        // Create the root node with the current value in preorder traversal
        TreeNode* node = new TreeNode(preorder[preStart]);

        // Find the index of this root value in the inorder traversal
        int inidx = mpp[preorder[preStart]];

        // Calculate the number of nodes in the left subtree
        int leftCnt = inidx - inStart;

        // Recursively build the left subtree
        node->left = build(preorder, preStart + 1, preStart + leftCnt,
                           inorder, inStart, inidx - 1, mpp);

        // Recursively build the right subtree
        node->right = build(preorder, preStart + leftCnt + 1, preEnd,
                            inorder, inidx + 1, inEnd, mpp);

        return node; // Return the constructed subtree rooted at 'node'
    }

    // Main function to build the binary tree from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each value in the inorder traversal for quick access
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        // Call the helper function to build the tree
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, mpp);
    }
};
