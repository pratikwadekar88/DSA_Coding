// Helper function to perform reverse postorder traversal and collect left view nodes
void helper(TreeNode<int> *node, int level, vector<int> &ans) {
    // Base case: if the node is null, return
    if (!node)
        return;

    // If the current level matches the size of the answer vector, 
    // it means we are visiting this level for the first time (leftmost node of this level)
    if (level == ans.size())
        ans.push_back(node->data); // Add the node's data to the result

    // Recursively traverse the left subtree first (to ensure left view)
    helper(node->left, level + 1, ans);

    // Then traverse the right subtree
    helper(node->right, level + 1, ans);
}

// Function to return the left view of the binary tree
vector<int> getLeftView(TreeNode<int> *root) {
    // Vector to store the left view elements
    vector<int> ans;

    // Use the helper function to fill the vector with left view nodes
    helper(root, 0, ans);

    // Return the resulting left view
    return ans;
}
