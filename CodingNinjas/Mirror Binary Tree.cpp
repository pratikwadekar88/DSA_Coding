void mirrorBinaryTree(BinaryTreeNode<int>* node) {
    // Base case: if the node is null, there is nothing to mirror
    if (node == NULL)
        return;

    // Recursively mirror the left subtree
    mirrorBinaryTree(node->left);

    // Recursively mirror the right subtree
    mirrorBinaryTree(node->right);

    // Swap the left and right children of the current node
    BinaryTreeNode<int>* temp = node->left;
    node->left = node->right;
    node->right = temp;
}
