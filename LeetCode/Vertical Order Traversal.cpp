class Solution {
public:
    // Function to perform vertical traversal of a binary tree.
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // Create a map to hold nodes, where:
        // - The key is the vertical position (horizontal distance from the root).
        // - The value is another map that contains:
        //   - The key is the level (depth) of the node.
        //   - The value is a multiset that stores node values at that vertical and level.
        map<int,map<int,multiset<int>>> nodes;

        // Queue to perform breadth-first search (BFS).
        // Each element in the queue is a pair containing:
        // - A pointer to the current TreeNode.
        // - A pair containing the vertical position and level of the node.
        queue<pair<TreeNode*,pair<int,int>>> que;

        // Initialize the queue with the root node, which is at vertical 0 and level 0.
        que.push({root,{0,0}});

        // Continue processing nodes until the queue is empty.
        while(!que.empty()){
            // Get the front element of the queue.
            auto temp = que.front();
            // Remove the front element from the queue.
            que.pop();

            // Extract the node, vertical position, and level from the temp variable.
            auto node = temp.first;              // Current node being processed.
            int vertical = temp.second.first;    // Vertical position of the current node.
            int level = temp.second.second;      // Level (depth) of the current node.

            // Insert the current node's value into the corresponding position in the nodes map.
            // This organizes the values based on their vertical position and level.
            nodes[vertical][level].insert(node->val);

            // If the current node has a left child, add it to the queue:
            // - The left child is at the vertical position -1 (to the left).
            // - The level of the left child is incremented by 1 (deeper in the tree).
            if(node->left){
                que.push({node->left,{vertical-1,level+1}});
            }

            // If the current node has a right child, add it to the queue:
            // - The right child is at the vertical position +1 (to the right).
            // - The level of the right child is incremented by 1.
            if(node->right){
                que.push({node->right,{vertical+1,level+1}});
            }
        }

        // Prepare a vector to hold the final result of vertical traversal.
        vector<vector<int>> ans;

        // Iterate through the nodes map to build the final answer:
        for(auto v : nodes){
            // Create a vector to hold all values for the current vertical column.
            vector<int> col;

            // For each level in the current vertical position:
            for(auto mst : v.second){
                // Insert all values stored in the multiset into the column vector.
                // The multiset ensures that values are sorted, including duplicates.
                col.insert(col.end(),mst.second.begin(),mst.second.end());
            }

            // Add the completed column to the final answer vector.
            ans.push_back(col);
        }

        // Return the final result containing all vertical columns.
        return ans;
    }
};
