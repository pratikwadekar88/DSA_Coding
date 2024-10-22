class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // If the root is NULL, return an empty result.
        if(root == NULL)
            return {};

        // Initialize a queue to hold nodes at each level for processing.
        queue<TreeNode *> q;

        // Start by pushing the root node into the queue.
        q.push(root);

        // Initialize the result vector which will hold the level-wise node values.
        vector<vector<int>> ans;

        // While there are nodes to process in the queue.
        while(!q.empty()) {
            // Get the number of nodes at the current level (queue size).
            int size = q.size();
            cout << size << endl;  // Optional: Print the size for debugging purposes.

            // Temporary vector to store the current level's values.
            vector<int> temp;

            // Process each node in the current level.
            for(int i = 0; i < size; i++) {
                // Get the front node in the queue.
                TreeNode* node = q.front();

                // Add the node's value to the temporary vector.
                temp.push_back(node->val);

                // Remove the processed node from the queue.
                q.pop();

                // If the node has a left child, push it to the queue for future processing.
                if(node->left)
                    q.push(node->left);

                // If the node has a right child, push it to the queue for future processing.
                if(node->right) {
                    q.push(node->right);
                }
            }

            // After processing all nodes at the current level, add the temporary vector
            // to the result vector.
            ans.push_back(temp);
        }

        // Return the result vector containing level-wise values.
        return ans;
    }
};
