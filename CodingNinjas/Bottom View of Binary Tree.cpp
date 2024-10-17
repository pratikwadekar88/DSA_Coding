#include <map>
#include <vector>
#include <queue> // Include necessary headers

// Function to compute the bottom view of a binary tree.
vector<int> bottomView(TreeNode<int> * root) {
    // Initialize a vector to hold the final bottom view result.
    vector<int> ans;

    // Map to hold the vertical position as key and the corresponding node value as value.
    // This will help to track the most recently encountered node at each vertical position.
    map<int,int> mpp;

    // Queue for breadth-first traversal, storing pairs of:
    // - A pointer to the current TreeNode.
    // - An integer representing the vertical position of the node.
    queue<pair<TreeNode<int>*,int>> q;

    // Push the root node into the queue with a vertical position of 0.
    q.push({root, 0});

    // Process the queue until it is empty.
    while(!q.empty()){
        // Get the front element of the queue.
        auto temp = q.front();
        // Remove the front element from the queue.
        q.pop();

        // Extract the node and its vertical position from the temp variable.
        auto node = temp.first;              // Current node being processed.
        int vertical = temp.second;          // Vertical position of the current node.

        // Update the map with the current node's value at the vertical position.
        // This ensures that the last node encountered at each vertical is stored,
        // which corresponds to the bottom view of the tree.
        mpp[vertical] = node->data;

        // If the current node has a left child, push it to the queue:
        // - The left child is at the vertical position -1 (moving left).
        if(node->left) {
            q.push({node->left, vertical - 1});
        }

        // If the current node has a right child, push it to the queue:
        // - The right child is at the vertical position +1 (moving right).
        if(node->right) {
            q.push({node->right, vertical + 1});
        }
    }

    // After processing all nodes, build the final answer vector from the map.
    // Iterate through the map and collect all values in the order of their vertical positions.
    for(auto node : mpp) {
        ans.push_back(node.second);
    }

    // Return the final result containing the bottom view of the binary tree.
    return ans;
}
