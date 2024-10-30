// Function to check if a given node is a leaf node
bool isLeaf(TreeNode<int>* node) {
    // A node is a leaf if both its left and right children are NULL
    if (node->left == NULL && node->right == NULL)
        return true;
    return false;
}

// Function to add the left boundary nodes, excluding leaf nodes
void addLeftTree(TreeNode<int>* root, vector<int>& ans) {
    TreeNode<int>* temp = root->left;
    // Traverse the left boundary of the tree
    while (temp) {
        // Add the node data if it's not a leaf
        if (!isLeaf(temp))
            ans.push_back(temp->data);
        // Move to the next left node if available; otherwise, move to the right
        if (temp->left)
            temp = temp->left;
        else
            temp = temp->right;
    }
}

// Function to add all leaf nodes in a tree using recursion
void addLeaves(TreeNode<int>* root, vector<int>& ans) {
    // If the node is a leaf, add its data to the answer vector
    if (isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }
    // Recursively traverse the left and right subtrees
    if (root->left) addLeaves(root->left, ans);
    if (root->right) addLeaves(root->right, ans);
}

// Function to add the right boundary nodes, excluding leaf nodes
void addRightBoundary(TreeNode<int>* root, vector<int>& ans) {
    stack<int> st; // Temporary stack to store right boundary in reverse order
    auto temp = root->right;
    // Traverse the right boundary of the tree
    while (temp) {
        // Add the node data to the stack if it's not the root and not a leaf
        if (temp != root && !isLeaf(temp))
            st.push(temp->data);
        // Move to the next right node if available; otherwise, move to the left
        if (temp->right)
            temp = temp->right;
        else
            temp = temp->left;
    }
    // Pop all elements from the stack and add them to the answer vector
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
}

// Main function to traverse and collect the boundary nodes in a vector
vector<int> traverseBoundary(TreeNode<int>* root) {
    vector<int> ans;
    // Add the root node data
    ans.push_back(root->data);
    // Add left boundary, leaf nodes, and right boundary to the answer vector
    addLeftTree(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);

    return ans;
}
