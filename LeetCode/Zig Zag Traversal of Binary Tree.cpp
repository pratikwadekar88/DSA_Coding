/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // If the tree is empty, return an empty result
        if (root == NULL)
            return {};
        
        // Stack to store the current level nodes
        stack<TreeNode*> st;
        st.push(root); // Push the root node onto the stack
        
        int dir = 0; // Direction flag: 0 means left to right, 1 means right to left
        
        vector<vector<int>> ans; // Final answer to store the zigzag level order traversal
        
        // Loop while there are nodes in the current level stack
        while (!st.empty()) {
            int size = st.size(); // Get the number of nodes at the current level
            stack<TreeNode*> st2; // Stack to hold the nodes for the next level
            vector<int> temp; // Temporary vector to hold the current level's values
            
            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                // If the direction is left to right
                if (dir == 0) {
                    TreeNode* node = st.top(); // Get the top node from the stack
                    st.pop(); // Remove it from the stack
                    temp.push_back(node->val); // Add the node's value to the current level result
                    
                    // Push the left child first, then the right child to the next level stack
                    if (node->left) {
                        st2.push(node->left);
                    }
                    if (node->right) {
                        st2.push(node->right);
                    }
                } 
                // If the direction is right to left
                else {
                    TreeNode* node = st.top(); // Get the top node from the stack
                    st.pop(); // Remove it from the stack
                    temp.push_back(node->val); // Add the node's value to the current level result
                    
                    // Push the right child first, then the left child to the next level stack
                    if (node->right) {
                        st2.push(node->right);
                    }
                    if (node->left) {
                        st2.push(node->left);
                    }
                }
            }
            
            // Toggle the direction for the next level
            if (dir == 0) 
                dir = 1;
            else 
                dir = 0;
            
            // Add the current level's result to the final answer
            ans.push_back(temp);
            
            // Move to the next level by setting st to the stack of the next level nodes
            st = st2;
        }
        
        return ans; // Return the zigzag level order traversal
    }
};
