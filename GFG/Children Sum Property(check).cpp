int isSumProperty(Node* root) {
    // Base case: if the root is NULL, the tree satisfies the sum property
    if (root == NULL)
        return 1;

    int sum = 0;

    // Calculate the sum of left and right child values if they exist
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;

    // If the node has at least one child, check the sum property
    if (root->left || root->right) {
        // If the sum of child values is equal to the root's data,
        // recursively check the sum property for the left and right subtrees
        if (sum == root->data)
            return isSumProperty(root->left) && isSumProperty(root->right);
        else
            // If the sum property is violated, return 0 (false)
            return 0;
    } else {
        // If the node is a leaf, it trivially satisfies the sum property
        return 1;
    }
}
