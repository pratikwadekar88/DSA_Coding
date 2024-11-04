void changeTree(BinaryTreeNode<int>* root) {
    // Base case: if the root is NULL, there's nothing to change
    if (root == NULL)
        return;

    int child = 0;

    // Calculate the sum of the child nodes
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    // If the sum of children is greater than or equal to the root's data,
    // update the root's data to the children's sum
    if (child >= root->data)
        root->data = child;
    else {
        // If root's data is greater, propagate the root's value to its children
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    // Recursively apply the transformation to the left and right subtrees
    changeTree(root->left);
    changeTree(root->right);

    // After updating subtrees, adjust the current root node's data
    int total = 0;

    // Sum the updated values of the children
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;

    // If the node has at least one child, set its data to the sum of the children's values
    if (root->left || root->right)
        root->data = total;
}
