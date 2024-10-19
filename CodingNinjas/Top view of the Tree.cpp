#include<bits/stdc++.h>

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;                  // Data value for the node
        TreeNode<T> *left;       // Pointer to the left child
        TreeNode<T> *right;      // Pointer to the right child

        TreeNode(T dat)          // Constructor to initialize the node
        {
            this->data = dat;
            left = NULL;         // Initialize left child as NULL
            right = NULL;        // Initialize right child as NULL
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root)
{
    // Map to store the first node data for each vertical level
    map<int, int> mpp;
    
    // Queue to store the pair of node and its vertical level
    queue<pair<TreeNode<int>*, int>> q;
    
    // Push the root node with vertical level 0
    q.push({root, 0});
    
    // Traverse the tree using level-order traversal
    while(!q.empty()) {
        // Get the front element from the queue
        auto temp = q.front();
        q.pop();
        
        // Extract node and its vertical level
        auto node = temp.first;
        int vertical = temp.second;
        
        // If this vertical level is encountered for the first time, store the node data
        if(mpp.find(vertical) == mpp.end()) {
            mpp[vertical] = node->data;
        }
        
        // If the left child exists, push it to the queue with vertical level decreased by 1
        if(node->left)
            q.push({node->left, vertical - 1});
        
        // If the right child exists, push it to the queue with vertical level increased by 1
        if(node->right)
            q.push({node->right, vertical + 1});
    }

    // Vector to store the result of the top view
    vector<int> ans;
    
    // Traverse the map and collect the node data in vertical order
    for(auto i : mpp) {
        ans.push_back(i.second);
    }
    
    // Return the final result containing the top view of the binary tree
    return ans;
}
