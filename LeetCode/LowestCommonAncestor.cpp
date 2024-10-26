class Solution {
public:

    // Function to find the lowest common ancestor (LCA) of two nodes, p and q, in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base cases: if root is NULL, or root matches either p or q, return root
        if (root == NULL || root == p || root == q)
            return root;

        // Recursively search for p and q in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If p and q are found in different subtrees, root is their lowest common ancestor
        if (left == NULL)
            return right; // p and q are in the right subtree
        else if (right == NULL)
            return left; // p and q are in the left subtree
        else
            return root; // p is in one subtree and q is in the other, so root is LCA
    }
};
